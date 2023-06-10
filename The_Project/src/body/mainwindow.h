#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "myproxy.h"
#include "examplemodel.h"
#include "aboutdialog.h"
#include <QShortcut>

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);

    ~MainWindow();

private slots:
    QString extractDir(QString fileName);

    void saveCurrentFileName();

    void openDataFile(bool isInitial);

    void updateDataFile();

    void SaveAs();

    void SaveTo();

    void openAddRowDialog();

    void openEditRowDialog();

    void openAboutDialog();

    void highlightDataItem(const QModelIndex& index);

    void removeRow();

    void changeIsFavorite();

    void clearFilters();

    void undo();

    void add(QList<QVariant> data);

    void edit(int row, QList<QVariant> data);

private:
    MyProxy* _proxy;
    Ui::MainWindow* ui;
    ExampleModel* _model;
    AboutDialog* _aboutDialog;
    int _currentRow;
    QString _currentFile;
    QList<QList<QVariant>> _history;

    QShortcut* _shortcutSave;
    QShortcut* _shortcutRemove;
    QShortcut* _shortcutEdit;
    QShortcut* _shortcutAdd;
    QShortcut* _shortcutChangeFavorite;
    QShortcut* _shortcutInformation;
    QShortcut* _shortcutUndo;
};
#endif// MAINWINDOW_H
