#ifndef QLION_H
#define QLION_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>

class QLion : public QMainWindow
{
    Q_OBJECT
public:
    explicit QLion(QWidget *parent = nullptr);
    ~QLion();

signals:
};

#endif // QLION_H
