#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    init();
#if 0
    btn1= new QPushButton("btn1",this);
    l1  = new QLabel("l1",this);
    btn1->move(0,20);
    l1->move(0,80);
    connect(btn1,&QPushButton::clicked,[this](){
        static int i=0;
        qDebug()<<++i;

        qDebug()<<(this->l1)->size();
        (this->statusBar())->showMessage(QString::number(++i));
    });
#endif
    setMinimumSize(400,300);
}

MainWindow::~MainWindow()
{

}
void MainWindow::createActions()
{
    openAct =new QAction("&open",this);
    openAct->setShortcut(QKeySequence::New);

    aboutSoftware = new QAction ("about software",this);

     aboutQt = new QAction ("aboutQt",this);
    connect(aboutQt,&QAction::triggered,qApp,&QApplication::aboutQt);

}
void MainWindow::createMenus()
{
    fileMenu=menuBar()->addMenu("&File");
    helpMenu = menuBar()->addMenu("&Help");

    fileMenu->addAction(openAct);
    helpMenu->addAction(aboutSoftware);
    helpMenu->addAction(aboutQt);

}
void MainWindow::init()
{
    initUI();

}

void MainWindow::f1()
{
    static int i=0;
    l1->setText(QString::number(++i));
}
void MainWindow::initUI()
{
    createButtons();
    createActions();
    createMenus();

    group1 = new QGroupBox("串口设置");
    group2 = new QGroupBox("接收设置");
    group1->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    group2->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);


    serialLable =new QLabel("串口");
    serialBaudRate  =new QLabel("波特率");
    serialDateBit =new QLabel("数据位");
    serialStopBit =new QLabel("停止位");
    serialFlowCtrl = new QLabel("流控");
    serialcheckMode = new QLabel("校验位");

    serialLableBox =new QComboBox;
    serialBaudRateBox =new QComboBox;
    serialDateBitBox =new QComboBox;
    serialStopBitBox =new QComboBox;
    serialFlowCtrlBox =new QComboBox;
    serialcheckModeBox =new QComboBox;

    serialSetting =new QFormLayout();
    serialShow = new QFormLayout();

    serialSetting->addRow(serialLable,serialLableBox);
    serialSetting->addRow(serialBaudRate,serialBaudRateBox);
    serialSetting->addRow(serialDateBit,serialDateBitBox);
    serialSetting->addRow(serialStopBit,serialStopBitBox);
    serialSetting->addRow(serialFlowCtrl,serialFlowCtrlBox);
    serialSetting->addRow(serialcheckMode,serialcheckModeBox);







    textBrowser = new QTextBrowser();
    textEdit = new QTextEdit();
    lineEdit1 = new QLineEdit;
    serialInput = new QPlainTextEdit;
//    serialInput->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    serialInput->setMaximumHeight(40);

    grid1 = new QGridLayout();
    grid1->addWidget(textBrowser,0,2,3,3);
    grid1->addWidget(serialInput,3,2,1,2);
    grid1->addWidget(sendBtn,3,4,1,1);

    group1->setLayout(serialSetting);


    QHBoxLayout *vb1 = new QHBoxLayout();
    QHBoxLayout *vb2 = new QHBoxLayout();
    vb1 ->addWidget(btn1);
    vb1->addWidget(btn2);
    //group1->setLayout(vb1);

    vb2->addWidget(clearBtn);
    //vb2->addWidget(sendBtn);
    //group2->setLayout(vb2);

    grid1->addWidget(group1,0,0);
    grid1->setAlignment(group1,Qt::AlignTop );


//    grid1->addWidget(group2,1,0,2,1);
//    grid1->setAlignment(group2,Qt::AlignTop );

    grid1->setAlignment(sendBtn,Qt::AlignTop );




//    grid1->addWidget(btn1,0,0,1,1);
//    grid1->addWidget(btn2,0,1,1,1);
    //QWidget *left = new QWidget(this);




    centerWidget = new QWidget(this);
    setCentralWidget(centerWidget);
    centerWidget->setLayout(grid1);
}

void MainWindow::createButtons()
{
    sendBtn = new QPushButton("send");
    sendBtn->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    clearBtn = new QPushButton("clear");
    clearBtn->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);



    btn1 = new QPushButton("btn1");
    btn2  = new QPushButton("btn2");
    btn1->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    btn2->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
}
