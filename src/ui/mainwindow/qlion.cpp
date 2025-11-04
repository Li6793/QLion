#include "qlion.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>

QLion::QLion(QWidget *parent)
    : QMainWindow{parent}
{
    // 方式 1：纯代码创建 UI（无需 Qt Designer）
    setWindowTitle("我的应用主窗口");
    setFixedSize(800, 600);  // 窗口大小

    // 中心部件（QMainWindow 必须有中心部件）
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    // 布局和组件
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);
    QLabel *label = new QLabel("Hello, 主窗口运行成功！", this);
    QPushButton *btn = new QPushButton("测试按钮", this);

    layout->addWidget(label, 0, Qt::AlignCenter);
    layout->addWidget(btn, 0, Qt::AlignCenter);

    // 信号槽（测试按钮点击事件）
    connect(btn, &QPushButton::clicked, this, []() {
        qDebug() << "按钮被点击！";
    });
}

QLion::~QLion(){}
