#include "qlion.h"
#include "MenuBar.h"
#include "middle.h"
#include <QWidget>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QLabel>
#include <QDebug>
#include <QStatusBar>


QLion::QLion(QWidget *parent)
    : QMainWindow{parent}
{
    initUI();
    initButtonsandQss();
    connectMenuBarSignals();
}

QLion::~QLion(){}

void QLion::initUI()
{
    this->statusBar()->hide();
    this->setStatusBar(nullptr);
    setWindowIcon(QIcon(":/icons/images/q.png"));
    CLion_Bar=new MenuBar(this);
    this->setMenuBar(CLion_Bar);

    QWidget* centralWidget=new QWidget(this);
    this->setCentralWidget(centralWidget);

    QHBoxLayout *centralLayout=new QHBoxLayout();
    centralLayout->setContentsMargins(0, 0, 0, 0);
    centralLayout->setSpacing(0);
    FixedLeft=new QWidget(this);
    middle =new Middle(this);
    FixedRight=new QWidget(this);
    FixedLeft->setFixedWidth(50);
    FixedRight->setFixedWidth(50);
    centralLayout->addWidget(FixedLeft);
    centralLayout->addWidget(middle,1);
    centralLayout->addWidget(FixedRight);
    centralWidget->setLayout(centralLayout);
    this->resize(1000,800);
}

void QLion::initButtonsandQss(){
    FixedLeft->setStyleSheet("border:2px solid black;background-color:rgb(43,45,48);");
    FixedRight->setStyleSheet("border:2px solid black;background-color:rgb(43,45,48);");
    Project=new QPushButton(FixedLeft);
    Project->setStyleSheet("background-color:transparent;");
    Project->setIcon(QIcon(":/icons/images/Project.png"));
    Project->setFixedSize(50,50);
    Project->move(0,0);
}

void QLion::connectMenuBarSignals(){

}

