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

class Middle : public QWidget
{
    Q_OBJECT
public:
    explicit Middle(QWidget *parent = nullptr);
    ~Middle() = default;

private:
    QSplitter *m_mainSplitter;
    QScrollArea *m_topScrollArea;
    QWidget *m_topContentWidget;
    QWidget *m_consoleWidget;
    QTextEdit *m_consoleOutput;
    QLineEdit *m_consoleInput;
};



#endif // MIDDLE_H
