/********************************************************************************
** Form generated from reading UI file 'trainsvmdlg.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRAINSVMDLG_H
#define UI_TRAINSVMDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_TrainSVMDlg
{
public:
    QVBoxLayout *verticalLayout;
    QSplitter *splitter;
    QLabel *label;
    QLineEdit *sampleFile;
    QPushButton *sampleBtn;
    QSplitter *splitter_2;
    QLabel *label_2;
    QLineEdit *svmFile;
    QPushButton *svmBtn;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QDoubleSpinBox *gamma;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QDoubleSpinBox *dC;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QDoubleSpinBox *train_rate;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *trainBtn;
    QPushButton *cancelBtn;

    void setupUi(QDialog *TrainSVMDlg)
    {
        if (TrainSVMDlg->objectName().isEmpty())
            TrainSVMDlg->setObjectName(QStringLiteral("TrainSVMDlg"));
        TrainSVMDlg->resize(449, 189);
        TrainSVMDlg->setMinimumSize(QSize(449, 189));
        TrainSVMDlg->setMaximumSize(QSize(449, 189));
        QFont font;
        font.setFamily(QStringLiteral("Consolas"));
        font.setBold(true);
        font.setWeight(75);
        TrainSVMDlg->setFont(font);
        TrainSVMDlg->setWindowOpacity(0.95);
        verticalLayout = new QVBoxLayout(TrainSVMDlg);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        splitter = new QSplitter(TrainSVMDlg);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        label = new QLabel(splitter);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(111, 16));
        label->setMaximumSize(QSize(111, 16));
        splitter->addWidget(label);
        sampleFile = new QLineEdit(splitter);
        sampleFile->setObjectName(QStringLiteral("sampleFile"));
        sampleFile->setReadOnly(true);
        splitter->addWidget(sampleFile);
        sampleBtn = new QPushButton(splitter);
        sampleBtn->setObjectName(QStringLiteral("sampleBtn"));
        sampleBtn->setMinimumSize(QSize(75, 23));
        sampleBtn->setMaximumSize(QSize(75, 23));
        splitter->addWidget(sampleBtn);

        verticalLayout->addWidget(splitter);

        splitter_2 = new QSplitter(TrainSVMDlg);
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
        label_3 = new QLabel(TrainSVMDlg);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(111, 16));
        label_3->setMaximumSize(QSize(111, 16));

        horizontalLayout->addWidget(label_3);

        gamma = new QDoubleSpinBox(TrainSVMDlg);
        gamma->setObjectName(QStringLiteral("gamma"));
        gamma->setMinimumSize(QSize(62, 22));
        gamma->setMaximumSize(QSize(62, 22));
        gamma->setDecimals(4);
        gamma->setMinimum(0.1);
        gamma->setValue(1);

        horizontalLayout->addWidget(gamma);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_4 = new QLabel(TrainSVMDlg);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(111, 16));
        label_4->setMaximumSize(QSize(111, 16));

        horizontalLayout_2->addWidget(label_4);

        dC = new QDoubleSpinBox(TrainSVMDlg);
        dC->setObjectName(QStringLiteral("dC"));
        dC->setMinimumSize(QSize(62, 22));
        dC->setMaximumSize(QSize(62, 22));
        dC->setDecimals(4);
        dC->setMinimum(0.1);
        dC->setValue(3);

        horizontalLayout_2->addWidget(dC);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_5 = new QLabel(TrainSVMDlg);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(111, 16));
        label_5->setMaximumSize(QSize(111, 16));

        horizontalLayout_3->addWidget(label_5);

        train_rate = new QDoubleSpinBox(TrainSVMDlg);
        train_rate->setObjectName(QStringLiteral("train_rate"));
        train_rate->setMinimumSize(QSize(62, 22));
        train_rate->setMaximumSize(QSize(62, 22));
        train_rate->setDecimals(4);
        train_rate->setMinimum(0.2);
        train_rate->setMaximum(1);
        train_rate->setValue(0.8);

        horizontalLayout_3->addWidget(train_rate);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        trainBtn = new QPushButton(TrainSVMDlg);
        trainBtn->setObjectName(QStringLiteral("trainBtn"));
        trainBtn->setMinimumSize(QSize(75, 23));
        trainBtn->setMaximumSize(QSize(75, 23));

        horizontalLayout_4->addWidget(trainBtn);

        cancelBtn = new QPushButton(TrainSVMDlg);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));
        cancelBtn->setMinimumSize(QSize(75, 23));
        cancelBtn->setMaximumSize(QSize(75, 23));

        horizontalLayout_4->addWidget(cancelBtn);


        verticalLayout->addLayout(horizontalLayout_4);


        retranslateUi(TrainSVMDlg);

        QMetaObject::connectSlotsByName(TrainSVMDlg);
    } // setupUi

    void retranslateUi(QDialog *TrainSVMDlg)
    {
        TrainSVMDlg->setWindowTitle(QApplication::translate("TrainSVMDlg", "Train SVM Classifier", 0));
        label->setText(QApplication::translate("TrainSVMDlg", "Input Samples", 0));
        sampleBtn->setText(QApplication::translate("TrainSVMDlg", "...", 0));
        label_2->setText(QApplication::translate("TrainSVMDlg", "Output SVM File", 0));
        svmBtn->setText(QApplication::translate("TrainSVMDlg", "...", 0));
        label_3->setText(QApplication::translate("TrainSVMDlg", "Gamma", 0));
        label_4->setText(QApplication::translate("TrainSVMDlg", "Penalty", 0));
        label_5->setText(QApplication::translate("TrainSVMDlg", "Training Ratio", 0));
        trainBtn->setText(QApplication::translate("TrainSVMDlg", "Train", 0));
        cancelBtn->setText(QApplication::translate("TrainSVMDlg", "Exit", 0));
    } // retranslateUi

};

namespace Ui {
    class TrainSVMDlg: public Ui_TrainSVMDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRAINSVMDLG_H
