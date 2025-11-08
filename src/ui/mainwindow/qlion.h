#ifndef QLION_H
#define QLION_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QHBoxLayout>
#include <QPushButton>
#include "middle.h"
#include "./widgets/qlefttop.h"
class MenuBar;
class QLion : public QMainWindow
{
    Q_OBJECT
public:
    explicit QLion(QWidget *parent = nullptr);
    ~QLion();

    QWidget* FixedLeft;
    QWidget* FixedRight;
    QPushButton* Project;
    QLeftTop* LeftTop;
private:

    void initUI();
    void initButtonsandQss();
    void connectMenuBarSignals();

private:
    MenuBar *CLion_Bar;
    Middle *middle;


signals:
};

#endif // QLION_H
