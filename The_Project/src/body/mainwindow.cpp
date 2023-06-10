#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "addrowdialog.h"
#include "editrowdialog.h"
#include "constants.h"
#include <QFileDialog>
#include <QInputDialog>
#include <QMessageBox>


MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    _model = new ExampleModel(this);
    _proxy = new MyProxy(this);
    _proxy->setSourceModel(_model);

    _aboutDialog = new AboutDialog(this);

    ui->tableView->setModel(_proxy);

    ui->tableView->setColumnWidth(Fields::id, 80);
    ui->tableView->setColumnWidth(Fields::title, 120);
    ui->tableView->setColumnWidth(Fields::genre, 102);
    ui->tableView->setColumnWidth(Fields::year, 50);
    ui->tableView->setColumnWidth(Fields::running_time, 50);
    ui->tableView->setColumnWidth(Fields::type, 50);

    ui->tableView->hideColumn(Fields::description);
    ui->tableView->hideColumn(Fields::isFavorite);

    _currentRow = -1;
    _currentFile = ".";
    QFile inputFile("./settings_file.txt");
    if (inputFile.open(QFile::ReadOnly | QFile::Text))
    {
        QTextStream inputStream(&inputFile);
        _currentFile = inputStream.readLine();
    }
    inputFile.close();

    QObject::connect(ui->actionOpenFile, &QAction::triggered, this, &MainWindow::openDataFile);
    QObject::connect(ui->actionAbout, &QAction::triggered, this, &MainWindow::openAboutDialog);
    QObject::connect(ui->actionSave, &QAction::triggered, this, &MainWindow::updateDataFile);
    QObject::connect(ui->actionSaveAs, &QAction::triggered, this, &MainWindow::SaveAs);
    QObject::connect(ui->actionSaveTo, &QAction::triggered, this, &MainWindow::SaveTo);


    QObject::connect(ui->pushButtonAdd, &QPushButton::clicked, this, &MainWindow::openAddRowDialog);
    QObject::connect(ui->pushButtonEdit, &QPushButton::clicked, this, &MainWindow::openEditRowDialog);
    QObject::connect(ui->pushButtonRemove, &QPushButton::clicked, this, &MainWindow::removeRow);
    QObject::connect(ui->pushButtonFavorite, &QPushButton::clicked, this, &MainWindow::changeIsFavorite);

    QObject::connect(ui->tableView, &QAbstractItemView::clicked, this, &MainWindow::highlightDataItem);
    QObject::connect(ui->tableView, &QAbstractItemView::doubleClicked, this, &MainWindow::changeIsFavorite);

    QObject::connect(ui->lineEditFilterTitle, &QLineEdit::textEdited, _proxy, &MyProxy::setTitle);
    QObject::connect(ui->lineEditFilterGenre, &QLineEdit::textEdited, _proxy, &MyProxy::setGenre);
    QObject::connect(ui->spinBoxFilterMinYear, &QSpinBox::valueChanged, _proxy, &MyProxy::setMinYear);
    QObject::connect(ui->spinBoxFilterMaxYear, &QSpinBox::valueChanged, _proxy, &MyProxy::setMaxYear);
    QObject::connect(ui->checkBoxFilterFavorite, &QCheckBox::stateChanged, _proxy, &MyProxy::setFavorite);
    QObject::connect(ui->pushButtonClearFilters, &QPushButton::clicked, this, &MainWindow::clearFilters);

    _shortcutSave = new QShortcut(QKeySequence(Qt::CTRL | Qt::Key_S), this);
    QObject::connect(_shortcutSave, &QShortcut::activated, this, &MainWindow::updateDataFile);
    _shortcutEdit = new QShortcut(QKeySequence(Qt::CTRL | Qt::Key_E), this);
    QObject::connect(_shortcutEdit, &QShortcut::activated, this, &MainWindow::openEditRowDialog);
    _shortcutAdd = new QShortcut(QKeySequence(Qt::CTRL | Qt::Key_A), this);
    QObject::connect(_shortcutAdd, &QShortcut::activated, this, &MainWindow::openAddRowDialog);
    _shortcutRemove = new QShortcut(QKeySequence(Qt::CTRL | Qt::Key_R), this);
    QObject::connect(_shortcutRemove, &QShortcut::activated, this, &MainWindow::removeRow);
    _shortcutChangeFavorite = new QShortcut(QKeySequence(Qt::CTRL | Qt::Key_F), this);
    QObject::connect(_shortcutChangeFavorite, &QShortcut::activated, this, &MainWindow::changeIsFavorite);
    _shortcutInformation = new QShortcut(QKeySequence(Qt::CTRL | Qt::Key_I), this);
    QObject::connect(_shortcutInformation, &QShortcut::activated, this, &MainWindow::openAboutDialog);
    _shortcutUndo = new QShortcut(QKeySequence(Qt::CTRL | Qt::Key_Z), this);
    QObject::connect(_shortcutUndo, &QShortcut::activated, this, &MainWindow::undo);

    this->openDataFile(true);
}

void MainWindow::clearFilters()
{
    ui->lineEditFilterTitle->setText("");
    ui->lineEditFilterGenre->setText("");
    ui->spinBoxFilterMinYear->setValue(0);
    ui->spinBoxFilterMaxYear->setValue(3000);
    _proxy->clearFilters();
}

void MainWindow::openAboutDialog()
{
    _aboutDialog->show();
}

QString MainWindow::extractDir(QString fileName)
{
    try
    {
        if (fileName.right(4) == ".csv")
        {
            return fileName.left(fileName.lastIndexOf("/"));
        }
        if (fileName.right(4) == ".xlsx")
        {
            return fileName.left(fileName.lastIndexOf("/"));
        }
        if (fileName.right(4) == ".txt")
        {
            return fileName.left(fileName.lastIndexOf("/"));
        }
        return fileName;
    }
    catch (...)
    {
        return ".";
    }
}

void MainWindow::saveCurrentFileName()
{
    QFile outputFile("./settings_file.txt");
    if (outputFile.open(QFile::WriteOnly | QFile::Text))
    {
        QTextStream outputStream(&outputFile);
        outputStream << _currentFile;
    }
    outputFile.close();
}

void MainWindow::openDataFile(bool isInitial=false)
{
    if (!isInitial)
    {
        QString fileName = QFileDialog::getOpenFileName(this, "Open data file", extractDir(_currentFile), tr("*.csv *.xlsx *.txt"));
        if (fileName == "")
        {
            return;
        }
        _currentFile = fileName;
        this->saveCurrentFileName();
    }
    if (!_model->readDataFromFile(_currentFile))
    {
        _currentFile = extractDir(_currentFile);
        QMessageBox::warning(this, "Error", "Cannot open file", QMessageBox::Ok);
    }
}

void MainWindow::updateDataFile()
{
    if (!_model->saveDataToFile(_currentFile))
    {
        QMessageBox::warning(this, "Error", "Cannot open file", QMessageBox::Ok);
    }
}

void MainWindow::SaveTo()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open data file", extractDir(_currentFile), tr("*.csv *.xlsx *.txt"));
    if (fileName == "")
    {
        return;
    }
    _currentFile = fileName;
    this->saveCurrentFileName();
    this->updateDataFile();
}

void MainWindow::SaveAs()
{
    QString dirName = QFileDialog::getExistingDirectory(this, "Open data file", extractDir(_currentFile));
    if (dirName == "")
    {
        return;
    }
    QString fileName = ".csv";
    while (true)
    {
        fileName = QInputDialog::getText(this, "Chose file name",
                                         "Enter file name. Recomended extension is .csv. Allowed extensions are .csv, .xlsx, .txt.\n"
                                         "In case of incorrect file name .csv will be forced.", QLineEdit::Normal, fileName);
        if (fileName == "")
        {
            return;
        }
        if (fileName.size() < 4)
        {
            fileName += ".csv";
        }
        else if (fileName.size() == 4)
        {
            if (fileName != ".csv" && fileName != ".txt")
            {
                fileName += ".csv";
            }
        }
        else
        {
            QString extension = fileName.right(5);
            if (extension.right(4) != ".csv" && extension.right(4) != ".txt" && extension != ".xlsx")
            {
                fileName += ".csv";
            }
        }
        QString fullFileName = dirName + "/" + fileName;
        if (QFile::exists(fullFileName))
        {
            QMessageBox::StandardButton reply;
            reply = QMessageBox::question(this,"Note","File with such name already exists.\nDo you want to rewrite it?");
            if (reply == QMessageBox::Yes)
            {
                _currentFile = fullFileName;
                this->saveCurrentFileName();
                this->updateDataFile();
                return;
            }
        }
    }
}

void MainWindow::highlightDataItem(const QModelIndex& clickIndex)
{
    _currentRow = clickIndex.row();
    QModelIndex index = _proxy->index(_currentRow, Fields::id);
    ui->labelIDData->setText(_proxy->data(index).toString());
    index = _proxy->index(_currentRow, Fields::title);
    ui->labelTitleData->setText(_proxy->data(index).toString());
    index = _proxy->index(_currentRow, Fields::description);
    ui->labelDescriptionData->setText(_proxy->data(index).toString());
    index = _proxy->index(_currentRow, Fields::genre);
    ui->labelGenreData->setText(_proxy->data(index).toString());
    index = _proxy->index(_currentRow, Fields::year);
    ui->labelYearData->setText(_proxy->data(index).toString());
    index = _proxy->index(_currentRow, Fields::running_time);
    ui->labelRunningTimeData->setText(_proxy->data(index).toString());
    index = _proxy->index(_currentRow, Fields::type);
    ui->labelTypeData->setText(_proxy->data(index).toString());
}

void MainWindow::openAddRowDialog()
{
    AddRowDialog dialog;
    while (true)
    {
        if (!dialog.exec())
        {
            return;
        }
        QList<QVariant> dataRow = dialog.getDataRow();
        if (_model->getIDs().contains(dataRow[0]))
        {
            QMessageBox::warning(this, "Error", "Record with such ID already exists.", QMessageBox::Ok);
            continue;
        }

        _history.append({"add", _model->appendRow(dataRow)});
        return;
    }
}

void MainWindow::add(QList<QVariant> data)
{
    _model->appendRow(data);
}

void MainWindow::edit(int row, QList<QVariant> data)
{
    _model->setRow(row, data);
}

void MainWindow::openEditRowDialog()
{
    if (_currentRow == -1)
    {
        qInfo() << "An attempt to edit row while none is chosen.";
        return;
    }
    int modelRow = _proxy->mapToSource(_proxy->index(_currentRow, 0)).row();
    QList<QVariant> dataRow = _model->getDataRow(modelRow);

    EditRowDialog dialog(dataRow);
    while (true)
    {
        if (!dialog.exec())
        {
            return;
        }
        QList<QVariant> data = dataRow;
        QList<QVariant> dataRow = dialog.getDataRow();
        if (_model->getIDs().contains(dataRow[0]) && dataRow[0] != _model->data(_model->index(modelRow,Fields::id), Qt::DisplayRole))
        {
            QMessageBox::warning(this, "Error", "Record with such ID already exists.", QMessageBox::Ok);
            continue;
        }
        _model->setRow(modelRow, dataRow);
        data.insert(0, modelRow);
        data.insert(0, "edit");
        _history.append(data);
        this->highlightDataItem(_model->index(_currentRow, 0));
        return;
    }
}

void MainWindow::removeRow()
{
    if (_currentRow == -1)
    {
        qInfo() << "An attempt to remove row while none is chosen.";
        return;
    }
    int modelRow = _proxy->mapToSource(_proxy->index(_currentRow, 0)).row();
    QList<QVariant> data = _model->removeRow(modelRow);
    _history.append({"remove", data[0], data[1], data[2], data[3], data[4], data[5], data[6], data[7]});
    _currentRow = -1;

    ui->labelIDData->setText("_");
    ui->labelTitleData->setText("_");
    ui->labelDescriptionData->setText("_");
    ui->labelGenreData->setText("_");
    ui->labelYearData->setText("_");
    ui->labelRunningTimeData->setText("_");
    ui->labelTypeData->setText("_");
}

void MainWindow::changeIsFavorite()
{
    if (_currentRow == -1)
    {
        qInfo() << "An attempt to add row to favorite while no row is chosen.";
        return;
    }
    int modelRow = _proxy->mapToSource(_proxy->index(_currentRow, 0)).row();
    _model->changeFavorite(modelRow);
    _history.append({"favorite", _currentRow});
}

void MainWindow::undo()
{
    if (_history.size() == 0)
    {
        return;
    }
    QList<QVariant> data = _history[_history.size() - 1];
    _history.removeLast();
    if (data[0] == "favorite")
    {
        _currentRow = data[1].toInt();
        this->changeIsFavorite();
    }
    else if (data[0] == "add")
    {
        _currentRow = _proxy->mapFromSource(_model->index(data[1].toInt(), 0)).row();
        this->removeRow();
    }
    else if (data[0] == "remove")
    {
        data.removeFirst();
        this->add(data);
    }
    else if (data[0] == "edit")
    {
        int row = data[1].toInt();
        data.removeFirst();
        data.removeFirst();
        this->edit(row, data);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
