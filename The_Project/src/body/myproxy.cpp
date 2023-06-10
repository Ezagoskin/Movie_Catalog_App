#include "myproxy.h"
#include "constants.h"

MyProxy::MyProxy(QObject* parent)
    : QSortFilterProxyModel(parent)
{
    _title = "";
    _genre = "";
    _minYear = 0;
    _maxYear = 3000;
    _isFavorite = false;
}

void MyProxy::setTitle(const QString& title)
{
    this->_title = title;
    invalidateFilter();
}

void MyProxy::setGenre(const QString& genre)
{
    this->_genre = genre;
    invalidateFilter();
}

void MyProxy::setMinYear(int minYear)
{
    this->_minYear = minYear;
    invalidateFilter();
}

void MyProxy::setMaxYear(int maxYear)
{
    this->_maxYear = maxYear;
    invalidateFilter();
}

void MyProxy::setFavorite(bool isFavorite)
{
    this->_isFavorite = isFavorite;
    invalidateFilter();
}

QVariant MyProxy::getData(int row, int column, const QModelIndex& sourceParent) const
{
    QModelIndex index = sourceModel()->index(row, column, sourceParent);
    return sourceModel()->data(index);
}

bool MyProxy::filterAcceptsRow(int sourceRow, const QModelIndex& sourceParent) const
{
    bool acceptsTitle = getData(sourceRow, Fields::title, sourceParent).toString().contains(_title,
                                                                                            Qt::CaseInsensitive);
    bool acceptsGenre = getData(sourceRow, Fields::genre, sourceParent).toString().contains(_genre,
                                                                                            Qt::CaseInsensitive);
    QVariant dataYear = getData(sourceRow, Fields::year, sourceParent);
    bool acceptsYear = (_minYear <= dataYear.toInt() && dataYear.toInt() <= _maxYear);
    bool acceptsFavorite = (!_isFavorite) || getData(sourceRow, Fields::isFavorite, sourceParent).toBool();

    return acceptsTitle && acceptsYear && acceptsGenre && acceptsFavorite;
}

void MyProxy::clearFilters()
{
    _title = "";
    _genre = "";
    _minYear = 0;
    _maxYear = 3000;
    _isFavorite = false;
    invalidateFilter();
}
