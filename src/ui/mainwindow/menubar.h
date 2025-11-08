#ifndef MENUBAR_H
#define MENUBAR_H

#include <QMenuBar>
#include <QAction>
#include <QMenu>
#include <QWidgetAction>
#include <QLabel>
#include <QHBoxLayout>
#include <QWidget>
#include <QMouseEvent>

enum class VcsType {
    None,
    Git,
    Svn,
    Mercurial
};

struct VcsStatus {
    VcsType type = VcsType::None;
    QString branch = "";
    bool hasChanges = false;
};

class MenuBar : public QMenuBar
{
    Q_OBJECT
public:
    explicit MenuBar(QWidget *parent = nullptr);
    ~MenuBar() = default;
private:
    const QVector<QString>MenuNames={"Files","Build","Run","VCS","Help"};
    const QVector<QVector<QString>>ActionNameMatrix={
        {"New","Open","Settings","Exit"},
        {"Build","ReBuild","Clean"},
        {"Run","Debug"},
        {"Create Git Repository"},
        {"What is new in QLion","About"}
        };

};

#endif // MENUBAR_H
