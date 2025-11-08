#include "MenuBar.h"
#include <QStyle>
#include <QCursor>
#include <QApplication>
#include <QPropertyAnimation>

MenuBar::MenuBar(QWidget *parent)
    : QMenuBar(parent)
{
    QMenu*Icon=new QMenu(this);
    Icon->setIcon(QIcon(":/images/q,png"));

    this->addMenu(Icon);
    for(int i=0;i<this->ActionNameMatrix.size();i++){
        auto &ActionList=ActionNameMatrix[i];
        QMenu* menu=new QMenu(this->MenuNames[i]);
        for(const auto &ActionName:ActionList){
            menu->addAction(new QAction(ActionName));
        }
        this->addMenu(menu);
    }
}

