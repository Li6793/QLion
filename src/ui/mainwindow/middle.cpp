#include "middle.h"

void Middle::showEvent(QShowEvent *event) {
    QWidget::showEvent(event);
    int totalWidth = TopArea->width();
    m_topleftSplitter->setSizes({static_cast<int>(totalWidth * 0.3), static_cast<int>(totalWidth * 0.7)});
    int totalHeight = this->height();
    m_mainSplitter->setSizes({static_cast<int>(totalHeight * 0.7), static_cast<int>(totalHeight * 0.3)});
}

Middle::Middle(QWidget *parent)
    : QWidget{parent}
{
    this->setStyleSheet("background-color: #282c34;");

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);

    m_mainSplitter = new QSplitter(Qt::Vertical, this);
    m_mainSplitter->setHandleWidth(2);
    mainLayout->addWidget(m_mainSplitter);

    TopArea=new QWidget(this);
    TopArea->setStyleSheet("background-color: rgb(30,31,34);");
    QHBoxLayout* TopLayout=new QHBoxLayout;
    TopLayout->setContentsMargins(0, 0, 0, 0);
    TopLayout->setSpacing(0);
    m_topleftSplitter=new QSplitter(Qt::Horizontal,TopArea);
    m_topleftSplitter->setHandleWidth(2);
    TopLayout->addWidget(m_topleftSplitter);

//---------------------------------左上部分-------------------------------------------
    LeftTop=new QLeftTop(TopArea);
    //LeftTop->setStyleSheet("background-color: rgb(43,45,48);");

    QVBoxLayout *leftTopLayout = new QVBoxLayout(LeftTop);
    leftTopLayout->setContentsMargins(0, 0, 0, 0);
    leftTopLayout->setSpacing(0);
    m_topleftScrollArea=new QScrollArea();
    m_topleftScrollArea->setWidgetResizable(true);

    m_topleftScrollArea->setStyleSheet(R"(
        QScrollArea {
            background-color: #282c34; /* 深色背景，匹配CLion */
        }
        /* 滚动条样式美化（CLion风格：细、深色） */
        QScrollBar:vertical {
            border: none;
            background: #3a3f4b;
            width: 8px;
            margin: 0px;
        }
        QScrollBar::handle:vertical {
            background: #5c616c;
            border-radius: 4px;
        }
        QScrollBar::handle:vertical:hover {
            background: #7d848f;
        }
        QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical {
            border: none;
            background: none;
        }
    )");
    m_topleftContentWidget = new QWidget();//---------------------------------------内部容器
    QVBoxLayout *topleftContentLayout = new QVBoxLayout();//------------------------容器布局
    topleftContentLayout->setAlignment(Qt::AlignTop);

    QLabel *codeLine = new QLabel(QString("#include <iostream> // 代码行 %1").arg(1));
    codeLine->setStyleSheet(R"(
            color: white;
            font-family: Consolas, Monaco, monospace;
            font-size: 13px;
            padding: 2px 8px;
        )");
    topleftContentLayout->addWidget(codeLine);
    m_topleftContentWidget->setLayout(topleftContentLayout);
    m_topleftScrollArea->setWidget(m_topleftContentWidget);

    leftTopLayout->addWidget(m_topleftScrollArea);

//-----------------------------------------------------------------------------------



    m_topScrollArea = new QScrollArea();
    m_topScrollArea->setWidgetResizable(true);
    m_topScrollArea->setStyleSheet(R"(
        QScrollArea {
            background-color: #282c34;
        }
        QScrollBar:vertical {
            border: none;
            background: #3a3f4b;
            width: 8px;
            margin: 0px;
        }
        QScrollBar::handle:vertical {
            background: #5c616c;
            border-radius: 4px;
        }
        QScrollBar::handle:vertical:hover {
            background: #7d848f;
        }
        QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical {
            border: none;
            background: none;
        }
    )");

    m_topContentWidget = new QWidget();
    QVBoxLayout *topContentLayout = new QVBoxLayout(m_topContentWidget);
    topContentLayout->setAlignment(Qt::AlignTop);
    m_topScrollArea->setWidget(m_topContentWidget);


    for (int i = 0; i < 50; ++i) {
        QLabel *codeLine = new QLabel(QString("#include <iostream> // 代码行 %1").arg(i+1));
        codeLine->setStyleSheet(R"(
            color: #abb2bf; /* 文本颜色：浅灰 */
            font-family: Consolas, Monaco, monospace; /* 等宽字体，模拟代码 */
            font-size: 13px;
            padding: 2px 8px;
        )");
        topContentLayout->addWidget(codeLine);
    }

    m_consoleWidget = new QWidget();
    m_consoleWidget->setStyleSheet("background-color: #1e1e1e;");
    QVBoxLayout *consoleLayout = new QVBoxLayout(m_consoleWidget);
    consoleLayout->setContentsMargins(0, 0, 0, 0);
    consoleLayout->setSpacing(0);

    m_consoleOutput = new QTextEdit();
    m_consoleOutput->setReadOnly(true);
    m_consoleOutput->setLineWrapMode(QTextEdit::NoWrap);
    m_consoleOutput->setStyleSheet(R"(
        QTextEdit {
            color: #dcdcaa; /* 控制台文本颜色：浅黄 */
            font-family: Consolas, Monaco, monospace;
            font-size: 12px;
            background-color: #1e1e1e;
            border: none;
            padding: 4px 8px;
        }
    )");

    m_consoleOutput->append("[INFO] 程序启动成功");
    m_consoleOutput->append("[DEBUG] 加载配置文件 config.json");
    m_consoleOutput->append("[WARNING] 未设置日志路径，使用默认路径");
    m_consoleOutput->append("[ERROR] 连接数据库失败：连接超时");

    m_consoleInput = new QLineEdit();
    m_consoleInput->setPlaceholderText("输入命令并按回车...");
    m_consoleInput->setStyleSheet(R"(
        QLineEdit {
            color: #abb2bf;
            font-family: Consolas, Monaco, monospace;
            font-size: 12px;
            background-color: #252526;
            border: none;
            border-top: 1px solid #3a3a3a; /* 顶部分割线 */
            padding: 4px 8px;
        }
        QLineEdit:focus {
            border-top: 1px solid #4d90fe; /* 聚焦时高亮顶部线 */
            outline: none;
        }
    )");
    m_topleftSplitter->addWidget(LeftTop);
    m_topleftSplitter->addWidget(m_topScrollArea);
    TopArea->setLayout(TopLayout);

    consoleLayout->addWidget(m_consoleOutput);
    consoleLayout->addWidget(m_consoleInput);


    m_mainSplitter->addWidget(TopArea);
    m_mainSplitter->addWidget(m_consoleWidget);


    int totalHeight = this->height();
    int topInitHeight = totalHeight * 0.7;
    int consoleInitHeight = totalHeight * 0.3;
    m_mainSplitter->setSizes({topInitHeight, consoleInitHeight});

    int middleWidth=TopArea->width();
    m_topleftSplitter->setSizes({(int)(middleWidth*0.3),(int)(middleWidth*0.7)});


    m_mainSplitter->setChildrenCollapsible(false);
    m_topleftSplitter->setChildrenCollapsible(false);
    m_topScrollArea->setMinimumHeight(100);
    m_consoleWidget->setMinimumHeight(80);

//background-color: #3a3f4b; /* 分割线默认颜色 */
    m_mainSplitter->setStyleSheet(R"(
        QSplitter::handle:vertical {
            background-color: black; /* 分割线默认颜色 */
        }
        QSplitter::handle:vertical:hover {
            background-color: #4d90fe; /* hover时高亮（CLion蓝） */
            cursor: ns-resize; /* 鼠标样式：上下拖动 */
        }
    )");
}




