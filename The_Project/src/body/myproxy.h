#ifndef MYPROXY_H
#define MYPROXY_H

#include <QSortFilterProxyModel>

class MyProxy : public QSortFilterProxyModel
{
    Q_OBJECT

public:
    explicit MyProxy(QObject* parent = nullptr);

    void setTitle(const QString& title);

    void setGenre(const QString& genre);

    void setMinYear(int minAge);

    void setMaxYear(int maxYear);

    void setFavorite(bool favorite);

    bool titleFitsFilter(QVariant dataAge) const;

    bool genreFitsFilter(QVariant dataAge) const;

    bool yearFitsFilter(QVariant dataAge) const;

    QVariant getData(int row, int column, const QModelIndex& sourceParent) const;

    bool filterAcceptsRow(int sourceRow, const QModelIndex& sourceParent) const override;

    void clearFilters();


private:
    QString _title;
    QString _genre;
    int _minYear;
    int _maxYear;
    bool _isFavorite;
};

#endif // MYPROXY_H
