/********************************************************************************
** Form generated from reading UI file 'FrameSwitchButtons.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRAMESWITCHBUTTONS_H
#define UI_FRAMESWITCHBUTTONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "switchbutton.h"

QT_BEGIN_NAMESPACE

class Ui_FrameSwitchButtons
{
public:
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    SwitchButton *switchBtn1;
    SwitchButton *switchBtn2;
    SwitchButton *switchBtn3;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *FrameSwitchButtons)
    {
        if (FrameSwitchButtons->objectName().isEmpty())
            FrameSwitchButtons->setObjectName(QStringLiteral("FrameSwitchButtons"));
        FrameSwitchButtons->resize(417, 310);
        horizontalLayout = new QHBoxLayout(FrameSwitchButtons);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(140, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        switchBtn1 = new SwitchButton(FrameSwitchButtons);
        switchBtn1->setObjectName(QStringLiteral("switchBtn1"));
        switchBtn1->setMinimumSize(QSize(100, 40));

        verticalLayout->addWidget(switchBtn1);

        switchBtn2 = new SwitchButton(FrameSwitchButtons);
        switchBtn2->setObjectName(QStringLiteral("switchBtn2"));
        switchBtn2->setMinimumSize(QSize(100, 40));

        verticalLayout->addWidget(switchBtn2);

        switchBtn3 = new SwitchButton(FrameSwitchButtons);
        switchBtn3->setObjectName(QStringLiteral("switchBtn3"));
        switchBtn3->setMinimumSize(QSize(100, 40));

        verticalLayout->addWidget(switchBtn3);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        horizontalLayout->addLayout(verticalLayout);

        horizontalSpacer_2 = new QSpacerItem(139, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        retranslateUi(FrameSwitchButtons);

        QMetaObject::connectSlotsByName(FrameSwitchButtons);
    } // setupUi

    void retranslateUi(QWidget *FrameSwitchButtons)
    {
        FrameSwitchButtons->setWindowTitle(QApplication::translate("FrameSwitchButtons", "FrameSwitchButtons", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FrameSwitchButtons: public Ui_FrameSwitchButtons {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRAMESWITCHBUTTONS_H
