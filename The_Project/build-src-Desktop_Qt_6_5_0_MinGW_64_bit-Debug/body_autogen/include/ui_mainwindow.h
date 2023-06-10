/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionInformation;
    QAction *actionSave;
    QAction *actionOpenFile;
    QAction *actionAbout;
    QAction *actionSaveAs;
    QAction *actionSaveTo;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTableView *tableView;
    QGroupBox *groupBoxProfile;
    QFormLayout *formLayout;
    QLabel *labelIDData;
    QLabel *labelTitle;
    QLabel *labelTitleData;
    QLabel *labelGenre;
    QLabel *labelGenreData;
    QLabel *labelYear;
    QLabel *labelYearData;
    QLabel *labelRunningTime;
    QLabel *labelRunningTimeData;
    QLabel *labeType;
    QLabel *labelTypeData;
    QLabel *labelDescription;
    QLabel *labelDescriptionData;
    QSpacerItem *verticalSpacer_2;
    QLabel *labelID;
    QGridLayout *gridLayout_2;
    QPushButton *pushButtonAdd;
    QPushButton *pushButtonRemove;
    QPushButton *pushButtonEdit;
    QPushButton *pushButtonFavorite;
    QGridLayout *gridLayout_3;
    QLineEdit *lineEditFilterGenre;
    QSpinBox *spinBoxFilterMaxYear;
    QLineEdit *lineEditFilterTitle;
    QSpinBox *spinBoxFilterMinYear;
    QLabel *labelFilterGenre;
    QLabel *labelFilterMinYear;
    QLabel *labelFilterMaxYear;
    QLabel *labelFilterTitle;
    QCheckBox *checkBoxFilterFavorite;
    QPushButton *pushButtonClearFilters;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menuHelp;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(851, 573);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName("actionOpen");
        actionInformation = new QAction(MainWindow);
        actionInformation->setObjectName("actionInformation");
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName("actionSave");
        actionOpenFile = new QAction(MainWindow);
        actionOpenFile->setObjectName("actionOpenFile");
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName("actionAbout");
        actionSaveAs = new QAction(MainWindow);
        actionSaveAs->setObjectName("actionSaveAs");
        actionSaveTo = new QAction(MainWindow);
        actionSaveTo->setObjectName("actionSaveTo");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        tableView = new QTableView(centralwidget);
        tableView->setObjectName("tableView");
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableView->sizePolicy().hasHeightForWidth());
        tableView->setSizePolicy(sizePolicy);
        tableView->setMinimumSize(QSize(0, 500));
        tableView->setLayoutDirection(Qt::LeftToRight);
        tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableView->setSortingEnabled(true);
        tableView->horizontalHeader()->setDefaultSectionSize(85);
        tableView->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        tableView->horizontalHeader()->setStretchLastSection(false);
        tableView->verticalHeader()->setStretchLastSection(false);

        gridLayout->addWidget(tableView, 0, 0, 3, 2);

        groupBoxProfile = new QGroupBox(centralwidget);
        groupBoxProfile->setObjectName("groupBoxProfile");
        groupBoxProfile->setMinimumSize(QSize(300, 500));
        groupBoxProfile->setMaximumSize(QSize(600, 16777215));
        formLayout = new QFormLayout(groupBoxProfile);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(11, -1, 11, -1);
        labelIDData = new QLabel(groupBoxProfile);
        labelIDData->setObjectName("labelIDData");

        formLayout->setWidget(0, QFormLayout::FieldRole, labelIDData);

        labelTitle = new QLabel(groupBoxProfile);
        labelTitle->setObjectName("labelTitle");

        formLayout->setWidget(1, QFormLayout::LabelRole, labelTitle);

        labelTitleData = new QLabel(groupBoxProfile);
        labelTitleData->setObjectName("labelTitleData");
        labelTitleData->setWordWrap(true);

        formLayout->setWidget(1, QFormLayout::FieldRole, labelTitleData);

        labelGenre = new QLabel(groupBoxProfile);
        labelGenre->setObjectName("labelGenre");

        formLayout->setWidget(2, QFormLayout::LabelRole, labelGenre);

        labelGenreData = new QLabel(groupBoxProfile);
        labelGenreData->setObjectName("labelGenreData");

        formLayout->setWidget(2, QFormLayout::FieldRole, labelGenreData);

        labelYear = new QLabel(groupBoxProfile);
        labelYear->setObjectName("labelYear");

        formLayout->setWidget(3, QFormLayout::LabelRole, labelYear);

        labelYearData = new QLabel(groupBoxProfile);
        labelYearData->setObjectName("labelYearData");

        formLayout->setWidget(3, QFormLayout::FieldRole, labelYearData);

        labelRunningTime = new QLabel(groupBoxProfile);
        labelRunningTime->setObjectName("labelRunningTime");

        formLayout->setWidget(4, QFormLayout::LabelRole, labelRunningTime);

        labelRunningTimeData = new QLabel(groupBoxProfile);
        labelRunningTimeData->setObjectName("labelRunningTimeData");

        formLayout->setWidget(4, QFormLayout::FieldRole, labelRunningTimeData);

        labeType = new QLabel(groupBoxProfile);
        labeType->setObjectName("labeType");

        formLayout->setWidget(5, QFormLayout::LabelRole, labeType);

        labelTypeData = new QLabel(groupBoxProfile);
        labelTypeData->setObjectName("labelTypeData");

        formLayout->setWidget(5, QFormLayout::FieldRole, labelTypeData);

        labelDescription = new QLabel(groupBoxProfile);
        labelDescription->setObjectName("labelDescription");

        formLayout->setWidget(6, QFormLayout::LabelRole, labelDescription);

        labelDescriptionData = new QLabel(groupBoxProfile);
        labelDescriptionData->setObjectName("labelDescriptionData");
        labelDescriptionData->setEnabled(true);
        labelDescriptionData->setBaseSize(QSize(0, 0));
        labelDescriptionData->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);
        labelDescriptionData->setWordWrap(true);

        formLayout->setWidget(6, QFormLayout::FieldRole, labelDescriptionData);

        verticalSpacer_2 = new QSpacerItem(20, 80, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(8, QFormLayout::LabelRole, verticalSpacer_2);

        labelID = new QLabel(groupBoxProfile);
        labelID->setObjectName("labelID");

        formLayout->setWidget(0, QFormLayout::LabelRole, labelID);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        pushButtonAdd = new QPushButton(groupBoxProfile);
        pushButtonAdd->setObjectName("pushButtonAdd");

        gridLayout_2->addWidget(pushButtonAdd, 0, 4, 1, 1);

        pushButtonRemove = new QPushButton(groupBoxProfile);
        pushButtonRemove->setObjectName("pushButtonRemove");

        gridLayout_2->addWidget(pushButtonRemove, 0, 2, 1, 1);

        pushButtonEdit = new QPushButton(groupBoxProfile);
        pushButtonEdit->setObjectName("pushButtonEdit");

        gridLayout_2->addWidget(pushButtonEdit, 0, 0, 1, 1);

        pushButtonFavorite = new QPushButton(groupBoxProfile);
        pushButtonFavorite->setObjectName("pushButtonFavorite");

        gridLayout_2->addWidget(pushButtonFavorite, 0, 1, 1, 1);


        formLayout->setLayout(9, QFormLayout::SpanningRole, gridLayout_2);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        lineEditFilterGenre = new QLineEdit(groupBoxProfile);
        lineEditFilterGenre->setObjectName("lineEditFilterGenre");
        lineEditFilterGenre->setMinimumSize(QSize(0, 25));
        lineEditFilterGenre->setMaxLength(64);

        gridLayout_3->addWidget(lineEditFilterGenre, 3, 1, 1, 1);

        spinBoxFilterMaxYear = new QSpinBox(groupBoxProfile);
        spinBoxFilterMaxYear->setObjectName("spinBoxFilterMaxYear");
        spinBoxFilterMaxYear->setMinimumSize(QSize(0, 25));
        spinBoxFilterMaxYear->setMaximum(99999);
        spinBoxFilterMaxYear->setValue(3000);

        gridLayout_3->addWidget(spinBoxFilterMaxYear, 1, 1, 1, 1);

        lineEditFilterTitle = new QLineEdit(groupBoxProfile);
        lineEditFilterTitle->setObjectName("lineEditFilterTitle");
        lineEditFilterTitle->setMinimumSize(QSize(0, 25));
        lineEditFilterTitle->setMaxLength(32767);

        gridLayout_3->addWidget(lineEditFilterTitle, 2, 1, 1, 1);

        spinBoxFilterMinYear = new QSpinBox(groupBoxProfile);
        spinBoxFilterMinYear->setObjectName("spinBoxFilterMinYear");
        spinBoxFilterMinYear->setMinimumSize(QSize(0, 25));
        spinBoxFilterMinYear->setMaximum(99999);

        gridLayout_3->addWidget(spinBoxFilterMinYear, 0, 1, 1, 1);

        labelFilterGenre = new QLabel(groupBoxProfile);
        labelFilterGenre->setObjectName("labelFilterGenre");
        labelFilterGenre->setMinimumSize(QSize(0, 25));

        gridLayout_3->addWidget(labelFilterGenre, 3, 0, 1, 1);

        labelFilterMinYear = new QLabel(groupBoxProfile);
        labelFilterMinYear->setObjectName("labelFilterMinYear");
        labelFilterMinYear->setMinimumSize(QSize(0, 25));

        gridLayout_3->addWidget(labelFilterMinYear, 0, 0, 1, 1);

        labelFilterMaxYear = new QLabel(groupBoxProfile);
        labelFilterMaxYear->setObjectName("labelFilterMaxYear");
        labelFilterMaxYear->setMinimumSize(QSize(0, 25));

        gridLayout_3->addWidget(labelFilterMaxYear, 1, 0, 1, 1);

        labelFilterTitle = new QLabel(groupBoxProfile);
        labelFilterTitle->setObjectName("labelFilterTitle");
        labelFilterTitle->setMinimumSize(QSize(0, 25));

        gridLayout_3->addWidget(labelFilterTitle, 2, 0, 1, 1);

        checkBoxFilterFavorite = new QCheckBox(groupBoxProfile);
        checkBoxFilterFavorite->setObjectName("checkBoxFilterFavorite");
        checkBoxFilterFavorite->setMinimumSize(QSize(0, 25));

        gridLayout_3->addWidget(checkBoxFilterFavorite, 4, 1, 1, 1);

        pushButtonClearFilters = new QPushButton(groupBoxProfile);
        pushButtonClearFilters->setObjectName("pushButtonClearFilters");
        pushButtonClearFilters->setMinimumSize(QSize(0, 25));

        gridLayout_3->addWidget(pushButtonClearFilters, 4, 0, 1, 1);


        formLayout->setLayout(10, QFormLayout::SpanningRole, gridLayout_3);


        gridLayout->addWidget(groupBoxProfile, 0, 2, 1, 2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 851, 26));
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName("menuHelp");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menu->addAction(actionSave);
        menu->addAction(actionSaveAs);
        menu->addAction(actionSaveTo);
        menu->addAction(actionOpenFile);
        menuHelp->addAction(actionAbout);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        actionInformation->setText(QCoreApplication::translate("MainWindow", "Information", nullptr));
        actionSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        actionOpenFile->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        actionAbout->setText(QCoreApplication::translate("MainWindow", "Information", nullptr));
        actionSaveAs->setText(QCoreApplication::translate("MainWindow", "Save As", nullptr));
        actionSaveTo->setText(QCoreApplication::translate("MainWindow", "Save To", nullptr));
        groupBoxProfile->setTitle(QCoreApplication::translate("MainWindow", "Passenger profile", nullptr));
        labelIDData->setText(QCoreApplication::translate("MainWindow", "_", nullptr));
        labelTitle->setText(QCoreApplication::translate("MainWindow", "Title:", nullptr));
        labelTitleData->setText(QCoreApplication::translate("MainWindow", "_", nullptr));
        labelGenre->setText(QCoreApplication::translate("MainWindow", "Genre:", nullptr));
        labelGenreData->setText(QCoreApplication::translate("MainWindow", "_", nullptr));
        labelYear->setText(QCoreApplication::translate("MainWindow", "Year:", nullptr));
        labelYearData->setText(QCoreApplication::translate("MainWindow", "_", nullptr));
        labelRunningTime->setText(QCoreApplication::translate("MainWindow", "Running time:", nullptr));
        labelRunningTimeData->setText(QCoreApplication::translate("MainWindow", "_", nullptr));
        labeType->setText(QCoreApplication::translate("MainWindow", "Type:", nullptr));
        labelTypeData->setText(QCoreApplication::translate("MainWindow", "_", nullptr));
        labelDescription->setText(QCoreApplication::translate("MainWindow", "Description:", nullptr));
        labelDescriptionData->setText(QCoreApplication::translate("MainWindow", "_", nullptr));
        labelID->setText(QCoreApplication::translate("MainWindow", "ID:", nullptr));
        pushButtonAdd->setText(QCoreApplication::translate("MainWindow", "Add Row", nullptr));
        pushButtonRemove->setText(QCoreApplication::translate("MainWindow", "Remove", nullptr));
        pushButtonEdit->setText(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        pushButtonFavorite->setText(QCoreApplication::translate("MainWindow", "Add to / remove from favorites", nullptr));
        lineEditFilterTitle->setInputMask(QString());
        lineEditFilterTitle->setText(QString());
        labelFilterGenre->setText(QCoreApplication::translate("MainWindow", "Genre", nullptr));
        labelFilterMinYear->setText(QCoreApplication::translate("MainWindow", "Min year", nullptr));
        labelFilterMaxYear->setText(QCoreApplication::translate("MainWindow", "Max year", nullptr));
        labelFilterTitle->setText(QCoreApplication::translate("MainWindow", "Title", nullptr));
        checkBoxFilterFavorite->setText(QCoreApplication::translate("MainWindow", "Show favorites", nullptr));
        pushButtonClearFilters->setText(QCoreApplication::translate("MainWindow", "Clear filters", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
