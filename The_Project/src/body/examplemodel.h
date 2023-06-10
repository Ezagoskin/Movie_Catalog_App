#ifndef EXAMPLEMODEL_H
#define EXAMPLEMODEL_H

#include <QAbstractTableModel>

class ExampleModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit ExampleModel(QObject* parent = nullptr);

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;

    int columnCount(const QModelIndex& parent = QModelIndex()) const override;

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

    QList<unsigned long long> getIDs() const;

//    Qt::ItemFlags flags(const QModelIndex& index) const override;
    QList<QVariant> setRow(int row, const QList<QVariant>& values);

    QList <QVariant> getDataRow(int row) const;

    bool readDataFromFile(const QString& path);

    bool saveDataToFile(const QString& path);

    int appendRow(const QList<QVariant>& newRow);

    QList<QVariant> removeRow(int row);

    void changeFavorite(int row);

private:

    QList<QList<QVariant>> _data;
    QList<QString> _header;
    QList<unsigned long long> _IDs;
};

#endif // EXAMPLEMODEL_H
