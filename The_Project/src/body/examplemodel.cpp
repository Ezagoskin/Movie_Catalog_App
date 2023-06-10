#include "examplemodel.h"
#include "constants.h"
#include <QFile>
#include <QTextStream>
#include "qcolor.h"


ExampleModel::ExampleModel(QObject* parent)
        : QAbstractTableModel(parent)
{
    _header = {"ID", "Title", "Description", "Genre", "Year", "Time", "Type", "Favorite"};
}

QVariant ExampleModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Horizontal)
    {
        if (role == Qt::DisplayRole)
        {
            return _header[section];
        }
    }
    return QVariant();
}

int ExampleModel::rowCount(const QModelIndex& parent) const
{
    if (parent.isValid())
        return 0;
    return _data.size();
}

int ExampleModel::columnCount(const QModelIndex& parent) const
{
    if (parent.isValid())
        return 0;
    return _header.size();
}

QVariant ExampleModel::data(const QModelIndex& index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role == Qt::DisplayRole || role == Qt::EditRole)
    {
        return _data.at(index.row()).at(index.column());
    }
    else if (role == Qt::BackgroundRole && _data[index.row()][7].toBool())
        return QColor(255, 255, 204);
    else if (role == Qt::TextAlignmentRole &&
             (index.column() == Fields::id || index.column() == Fields::genre || index.column() == Fields::type))
        return {Qt::AlignCenter | Qt::AlignVCenter};
    return QVariant();
}

QList<QVariant> ExampleModel::getDataRow(int row) const
{
    if (row < _data.size())
    {
        return _data[row];
    }
    return QList<QVariant>();
}

QList<unsigned long long> ExampleModel::getIDs() const
{
    return _IDs;
}

QList<QVariant> ExampleModel::setRow(int row, const QList<QVariant>& values)
{
    if (_data[row] != values)
    {
        _data[row] = values;
        emit dataChanged(this->index(row, Fields::id), this->index(row, Fields::isFavorite));
    }
    return _data[row];
}

//Qt::ItemFlags ExampleModel::flags(const QModelIndex& index) const
//{
//    if (!index.isValid())
//        return Qt::NoItemFlags;

//    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
//}


bool ExampleModel::readDataFromFile(const QString& path)
{
    QList<QList<QVariant>> newData;
    QList<unsigned long long> newIDs;

    QFile inputFile(path);
    if (!inputFile.open(QFile::ReadOnly | QFile::Text))
    {
        return false;
    }
    QTextStream inputStream(&inputFile);
    while (!inputStream.atEnd())
    {
        QString line = inputStream.readLine();

        QList<QVariant> dataRow;
        QList<QString> items = line.split(";", Qt::KeepEmptyParts);
        if (items.size() != 8)
            return false;
        for (int i = 0; i < items.size(); ++i)
        {
            QVariant value;
            if (i == Fields::id)
            {
                value = items[i].toULongLong();
                newIDs.append(value.toULongLong());
            }
            else if (i == Fields::year || i == Fields::running_time)
            {
                value = items[i].toUShort();
            }
            else if (i == Fields::isFavorite)
            {
                value = (!(items[i] == "0" || items[i] == "" || items[i] == "FALSE" || items[i] == "false"));
            }
            else
            {
                value = items[i];
            }

            dataRow.append(value);
        }
        newData.append(dataRow);
    }
    inputFile.close();

    _IDs = newIDs;
    beginResetModel();
    _data = newData;
    endResetModel();
    return true;
}

bool ExampleModel::saveDataToFile(const QString& path)
{
    QFile outputFile(path);
    if (!outputFile.open(QFile::WriteOnly | QFile::Text))
    {
        return false;
    }
    QTextStream outputStream(&outputFile);
    for (const QList <QVariant>& row: _data)
    {
        bool first = true;
        for (const QVariant& item: row)
        {
            if (!first)
            {
                outputStream << ";";
            }
            outputStream << item.toString();
            first = false;
        }
        outputStream << "\n";
    }
    return true;
}

int ExampleModel::appendRow(const QList <QVariant>& newRow)
{
    beginInsertRows(QModelIndex(), _data.size(), _data.size());
    _data.append(newRow);
    endInsertRows();
    return _data.size() - 1;
}


QList<QVariant> ExampleModel::removeRow(int row)
{
    QList<QVariant> data = _data[row];
    beginRemoveRows(QModelIndex(), row, row);
    _data.removeAt(row);
    endRemoveRows();
    return data;
}

void ExampleModel::changeFavorite(int row)
{
    _data[row][Fields::isFavorite] = !(_data[row][Fields::isFavorite].toBool());
    emit dataChanged(this->index(row, Fields::id), this->index(row, Fields::isFavorite));
}
