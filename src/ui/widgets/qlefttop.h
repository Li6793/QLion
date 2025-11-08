#ifndef QLEFTTOP_H
#define QLEFTTOP_H

#include <QObject>
#include <QWidget>

class QLeftTop : public QWidget
{
    Q_OBJECT
public:
    explicit QLeftTop(QWidget *parent = nullptr);
    ~QLeftTop()=default;
signals:
};

#endif // QLEFTTOP_H
