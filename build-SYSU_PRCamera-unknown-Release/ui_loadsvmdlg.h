/********************************************************************************
** Form generated from reading UI file 'loadsvmdlg.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOADSVMDLG_H
#define UI_LOADSVMDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_LoadSVMDlg
{
public:
    QVBoxLayout *verticalLayout;
    QSplitter *splitter_2;
    QLabel *label_2;
    QLineEdit *svmFile;
    QPushButton *svmBtn;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *loadBtn;
    QPushButton *cancelBtn;

    void setupUi(QDialog *LoadSVMDlg)
    {
        if (LoadSVMDlg->objectName().isEmpty())
            LoadSVMDlg->setObjectName(QStringLiteral("LoadSVMDlg"));
        LoadSVMDlg->resize(447, 72);
        QFont font;
        font.setFamily(QStringLiteral("Consolas"));
        font.setBold(true);
        font.setWeight(75);
        LoadSVMDlg->setFont(font);
        LoadSVMDlg->setWindowOpacity(0.95);
        verticalLayout = new QVBoxLayout(LoadSVMDlg);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        splitter_2 = new QSplitter(LoadSVMDlg);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        label_2 = new QLabel(splitter_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(111, 16));
        label_2->setMaximumSize(QSize(111, 16));
        splitter_2->addWidget(label_2);
        svmFile = new QLineEdit(splitter_2);
        svmFile->setObjectName(QStringLiteral("svmFile"));
        svmFile->setReadOnly(true);
        splitter_2->addWidget(svmFile);
        svmBtn = new QPushButton(splitter_2);
        svmBtn->setObjectName(QStringLiteral("svmBtn"));
        svmBtn->setMinimumSize(QSize(75, 23));
        svmBtn->setMaximumSize(QSize(75, 23));
        splitter_2->addWidget(svmBtn);

        verticalLayout->addWidget(splitter_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        loadBtn = new QPushButton(LoadSVMDlg);
        loadBtn->setObjectName(QStringLiteral("loadBtn"));
        loadBtn->setMinimumSize(QSize(75, 23));
        loadBtn->setMaximumSize(QSize(75, 23));

        horizontalLayout->addWidget(loadBtn);

        cancelBtn = new QPushButton(LoadSVMDlg);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));
        cancelBtn->setMinimumSize(QSize(75, 23));
        cancelBtn->setMaximumSize(QSize(75, 23));

        horizontalLayout->addWidget(cancelBtn);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(LoadSVMDlg);

        QMetaObject::connectSlotsByName(LoadSVMDlg);
    } // setupUi

    void retranslateUi(QDialog *LoadSVMDlg)
    {
        LoadSVMDlg->setWindowTitle(QApplication::translate("LoadSVMDlg", "Load SVM Classifier", 0));
        label_2->setText(QApplication::translate("LoadSVMDlg", "Input SVM File", 0));
        svmBtn->setText(QApplication::translate("LoadSVMDlg", "...", 0));
        loadBtn->setText(QApplication::translate("LoadSVMDlg", "Load", 0));
        cancelBtn->setText(QApplication::translate("LoadSVMDlg", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class LoadSVMDlg: public Ui_LoadSVMDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOADSVMDLG_H
