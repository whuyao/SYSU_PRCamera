/********************************************************************************
** Form generated from reading UI file 'sysu_prcamera.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYSU_PRCAMERA_H
#define UI_SYSU_PRCAMERA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SYSU_PRCameraClass
{
public:
    QAction *actionRunCamera;
    QAction *actionCloseCamera;
    QAction *actionSavePhoto;
    QAction *actionClearSettings;
    QAction *actionExportSamples;
    QAction *actionTrainSVM;
    QAction *actionLoadSVM;
    QAction *actionSVMPredict;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QSplitter *splitter;
    QLabel *cameralbl;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *utcLbl_3;
    QComboBox *cameraId;
    QPushButton *lunchCamera;
    QLabel *timeLbl;
    QLabel *utcLbl;
    QLabel *utcLbl_2;
    QComboBox *classCombo;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QTabWidget *tabs;
    QWidget *tab;
    QVBoxLayout *verticalLayout_3;
    QTextEdit *output;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_4;
    QTextEdit *featureList;
    QMenuBar *menuBar;
    QMenu *menuStart;
    QMenu *menuFile;
    QMenu *menuAlgo;
    QMenu *menuAbout;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SYSU_PRCameraClass)
    {
        if (SYSU_PRCameraClass->objectName().isEmpty())
            SYSU_PRCameraClass->setObjectName(QStringLiteral("SYSU_PRCameraClass"));
        SYSU_PRCameraClass->resize(1092, 836);
        SYSU_PRCameraClass->setMinimumSize(QSize(1092, 836));
        QFont font;
        font.setFamily(QStringLiteral("Consolas"));
        SYSU_PRCameraClass->setFont(font);
        QIcon icon;
        icon.addFile(QStringLiteral(":/SYSU_PRCamera/sysu1.ico"), QSize(), QIcon::Normal, QIcon::Off);
        SYSU_PRCameraClass->setWindowIcon(icon);
        SYSU_PRCameraClass->setWindowOpacity(0.9);
        actionRunCamera = new QAction(SYSU_PRCameraClass);
        actionRunCamera->setObjectName(QStringLiteral("actionRunCamera"));
        actionCloseCamera = new QAction(SYSU_PRCameraClass);
        actionCloseCamera->setObjectName(QStringLiteral("actionCloseCamera"));
        actionSavePhoto = new QAction(SYSU_PRCameraClass);
        actionSavePhoto->setObjectName(QStringLiteral("actionSavePhoto"));
        actionClearSettings = new QAction(SYSU_PRCameraClass);
        actionClearSettings->setObjectName(QStringLiteral("actionClearSettings"));
        actionExportSamples = new QAction(SYSU_PRCameraClass);
        actionExportSamples->setObjectName(QStringLiteral("actionExportSamples"));
        actionTrainSVM = new QAction(SYSU_PRCameraClass);
        actionTrainSVM->setObjectName(QStringLiteral("actionTrainSVM"));
        actionLoadSVM = new QAction(SYSU_PRCameraClass);
        actionLoadSVM->setObjectName(QStringLiteral("actionLoadSVM"));
        actionSVMPredict = new QAction(SYSU_PRCameraClass);
        actionSVMPredict->setObjectName(QStringLiteral("actionSVMPredict"));
        centralWidget = new QWidget(SYSU_PRCameraClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        cameralbl = new QLabel(splitter);
        cameralbl->setObjectName(QStringLiteral("cameralbl"));
        cameralbl->setMinimumSize(QSize(681, 471));
        cameralbl->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        splitter->addWidget(cameralbl);
        groupBox = new QGroupBox(splitter);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMinimumSize(QSize(271, 0));
        groupBox->setMaximumSize(QSize(271, 16777215));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        utcLbl_3 = new QLabel(groupBox);
        utcLbl_3->setObjectName(QStringLiteral("utcLbl_3"));
        utcLbl_3->setMinimumSize(QSize(51, 20));
        utcLbl_3->setMaximumSize(QSize(51, 20));

        horizontalLayout->addWidget(utcLbl_3);

        cameraId = new QComboBox(groupBox);
        cameraId->setObjectName(QStringLiteral("cameraId"));

        horizontalLayout->addWidget(cameraId);

        lunchCamera = new QPushButton(groupBox);
        lunchCamera->setObjectName(QStringLiteral("lunchCamera"));
        lunchCamera->setMinimumSize(QSize(61, 23));
        lunchCamera->setMaximumSize(QSize(61, 23));

        horizontalLayout->addWidget(lunchCamera);


        verticalLayout_2->addLayout(horizontalLayout);

        timeLbl = new QLabel(groupBox);
        timeLbl->setObjectName(QStringLiteral("timeLbl"));

        verticalLayout_2->addWidget(timeLbl);

        utcLbl = new QLabel(groupBox);
        utcLbl->setObjectName(QStringLiteral("utcLbl"));

        verticalLayout_2->addWidget(utcLbl);

        utcLbl_2 = new QLabel(groupBox);
        utcLbl_2->setObjectName(QStringLiteral("utcLbl_2"));

        verticalLayout_2->addWidget(utcLbl_2);

        classCombo = new QComboBox(groupBox);
        classCombo->setObjectName(QStringLiteral("classCombo"));
        classCombo->setEditable(true);
        classCombo->setMaxVisibleItems(15);

        verticalLayout_2->addWidget(classCombo);

        verticalSpacer = new QSpacerItem(20, 252, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(231, 71));
        label->setMaximumSize(QSize(231, 71));
        label->setPixmap(QPixmap(QString::fromUtf8(":/Images/Resources/147832221417159333.png")));
        label->setScaledContents(true);

        horizontalLayout_2->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_2);

        splitter->addWidget(groupBox);

        verticalLayout->addWidget(splitter);

        tabs = new QTabWidget(centralWidget);
        tabs->setObjectName(QStringLiteral("tabs"));
        tabs->setMinimumSize(QSize(1051, 201));
        QFont font1;
        font1.setFamily(QStringLiteral("Consolas"));
        font1.setBold(true);
        font1.setWeight(75);
        tabs->setFont(font1);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout_3 = new QVBoxLayout(tab);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        output = new QTextEdit(tab);
        output->setObjectName(QStringLiteral("output"));
        QFont font2;
        font2.setFamily(QStringLiteral("Consolas"));
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setWeight(75);
        output->setFont(font2);
        output->setAutoFillBackground(false);
        output->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);"));
        output->setFrameShape(QFrame::NoFrame);

        verticalLayout_3->addWidget(output);

        tabs->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        verticalLayout_4 = new QVBoxLayout(tab_2);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        featureList = new QTextEdit(tab_2);
        featureList->setObjectName(QStringLiteral("featureList"));
        QFont font3;
        font3.setFamily(QStringLiteral("Consolas"));
        font3.setPointSize(8);
        featureList->setFont(font3);
        featureList->setStyleSheet(QLatin1String("background-color: rgb(0, 85, 0);\n"
"color: rgb(255, 255, 255);"));
        featureList->setFrameShape(QFrame::NoFrame);
        featureList->setAutoFormatting(QTextEdit::AutoNone);
        featureList->setLineWrapMode(QTextEdit::WidgetWidth);
        featureList->setOverwriteMode(true);
        featureList->setCursorWidth(1);

        verticalLayout_4->addWidget(featureList);

        tabs->addTab(tab_2, QString());

        verticalLayout->addWidget(tabs);

        SYSU_PRCameraClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SYSU_PRCameraClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1092, 21));
        menuStart = new QMenu(menuBar);
        menuStart->setObjectName(QStringLiteral("menuStart"));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuAlgo = new QMenu(menuBar);
        menuAlgo->setObjectName(QStringLiteral("menuAlgo"));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QStringLiteral("menuAbout"));
        SYSU_PRCameraClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SYSU_PRCameraClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        SYSU_PRCameraClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(SYSU_PRCameraClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        SYSU_PRCameraClass->setStatusBar(statusBar);

        menuBar->addAction(menuStart->menuAction());
        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuAlgo->menuAction());
        menuBar->addAction(menuAbout->menuAction());
        menuStart->addAction(actionRunCamera);
        menuStart->addAction(actionCloseCamera);
        menuStart->addSeparator();
        menuStart->addAction(actionClearSettings);
        menuFile->addAction(actionSavePhoto);
        menuFile->addSeparator();
        menuFile->addAction(actionExportSamples);
        menuAlgo->addSeparator();
        menuAlgo->addAction(actionTrainSVM);
        menuAlgo->addAction(actionLoadSVM);
        menuAlgo->addSeparator();
        menuAlgo->addAction(actionSVMPredict);
        mainToolBar->addAction(actionRunCamera);
        mainToolBar->addAction(actionCloseCamera);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionSavePhoto);
        mainToolBar->addAction(actionExportSamples);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionTrainSVM);
        mainToolBar->addAction(actionLoadSVM);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionSVMPredict);

        retranslateUi(SYSU_PRCameraClass);

        tabs->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SYSU_PRCameraClass);
    } // setupUi

    void retranslateUi(QMainWindow *SYSU_PRCameraClass)
    {
        SYSU_PRCameraClass->setWindowTitle(QApplication::translate("SYSU_PRCameraClass", "SYSU Semantic Video Recognition ", 0));
        actionRunCamera->setText(QApplication::translate("SYSU_PRCameraClass", "Run Camera", 0));
        actionCloseCamera->setText(QApplication::translate("SYSU_PRCameraClass", "Close Camera", 0));
        actionSavePhoto->setText(QApplication::translate("SYSU_PRCameraClass", "Take Sample (Ctrl+T)", 0));
        actionClearSettings->setText(QApplication::translate("SYSU_PRCameraClass", "Clear Settings", 0));
        actionExportSamples->setText(QApplication::translate("SYSU_PRCameraClass", "Export Samples", 0));
        actionTrainSVM->setText(QApplication::translate("SYSU_PRCameraClass", "Train SVM", 0));
        actionLoadSVM->setText(QApplication::translate("SYSU_PRCameraClass", "Load SVM", 0));
        actionSVMPredict->setText(QApplication::translate("SYSU_PRCameraClass", "SVM Predict (Ctrl+P)", 0));
        cameralbl->setText(QString());
        groupBox->setTitle(QString());
        utcLbl_3->setText(QApplication::translate("SYSU_PRCameraClass", "Camera", 0));
        lunchCamera->setText(QApplication::translate("SYSU_PRCameraClass", "Launch", 0));
        timeLbl->setText(QApplication::translate("SYSU_PRCameraClass", "Current Time", 0));
        utcLbl->setText(QApplication::translate("SYSU_PRCameraClass", "UTC", 0));
        utcLbl_2->setText(QApplication::translate("SYSU_PRCameraClass", "Cur. Photo Class", 0));
        label->setText(QString());
        tabs->setTabText(tabs->indexOf(tab), QApplication::translate("SYSU_PRCameraClass", "Console", 0));
        tabs->setTabText(tabs->indexOf(tab_2), QApplication::translate("SYSU_PRCameraClass", "Features", 0));
        menuStart->setTitle(QApplication::translate("SYSU_PRCameraClass", "Start", 0));
        menuFile->setTitle(QApplication::translate("SYSU_PRCameraClass", "File", 0));
        menuAlgo->setTitle(QApplication::translate("SYSU_PRCameraClass", "ML", 0));
        menuAbout->setTitle(QApplication::translate("SYSU_PRCameraClass", "About", 0));
    } // retranslateUi

};

namespace Ui {
    class SYSU_PRCameraClass: public Ui_SYSU_PRCameraClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSU_PRCAMERA_H
