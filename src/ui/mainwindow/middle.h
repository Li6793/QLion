#ifndef MIDDLE_H
#define MIDDLE_H

#include <QWidget>
#include <QSplitter>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QLabel>
#include <QTextEdit>
#include <QLineEdit>
#include <QStyleOption>
#include <QPainter>

#include "./widgets/qlefttop.h"
class Middle : public QWidget
{
    Q_OBJECT
public:
    explicit Middle(QWidget *parent = nullptr);
    ~Middle() = default;
    void showEvent(QShowEvent *event);

private:
    QSplitter *m_mainSplitter;
    QScrollArea *m_topScrollArea;
    QScrollArea* m_topleftScrollArea;
    QWidget *m_topContentWidget;
    QWidget *m_topleftContentWidget;
    QWidget *m_consoleWidget;
    QTextEdit *m_consoleOutput;
    QLineEdit *m_consoleInput;
    QWidget *TopArea;

    QSplitter *m_topleftSplitter;
    QLeftTop* LeftTop;
};



#endif // MIDDLE_H
