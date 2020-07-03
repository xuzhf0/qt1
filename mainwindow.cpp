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
    initSerialSettingPart();
    initReceivePart();
    initSendPart();




    textBrowser = new QTextBrowser();
    textEdit = new QTextEdit();
    lineEdit1 = new QLineEdit;
    serialInput = new QPlainTextEdit;
    serialInput->setMaximumHeight(40);

    grid1 = new QGridLayout();
    grid1->addWidget(textBrowser,0,2,3,3);
    grid1->addWidget(serialInput,3,2,1,2);
    grid1->addWidget(sendBtn,3,4,1,1);
    grid1->addWidget(groupBoxSerialSetting,0,0,4,2);
    grid1->addWidget(groupBoxReceive,3,0,2,2);

    grid1->setAlignment(groupBoxSerialSetting,Qt::AlignTop);
    grid1->setAlignment(groupBoxReceive,Qt::AlignTop);


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
QGroupBox * MainWindow::initReceivePart()
{
    showasc = new QRadioButton("ASCII");
    showhex = new QRadioButton("hex");

    showRecTime =new QCheckBox("接收时间");
    autoLineBreak = new QCheckBox("自动换行");

    QGridLayout *grid = new QGridLayout;
    grid->addWidget(showasc,0,0,1,1);
    grid->addWidget(showhex,0,1,1,1);
    grid->addWidget(showRecTime,1,0,1,1);
    grid->addWidget(autoLineBreak,2,0,1,1);
    groupBoxReceive= new QGroupBox("接收设置");
    groupBoxReceive->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);

    groupBoxReceive->setLayout(grid);
    return groupBoxReceive;
}
QGroupBox *MainWindow::initSendPart()
{

    return Q_NULLPTR;
}
QGroupBox *MainWindow::initSerialSettingPart()
{
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
    serialSetting->addRow(serialLable,serialLableBox);
    serialSetting->addRow(serialBaudRate,serialBaudRateBox);
    serialSetting->addRow(serialDateBit,serialDateBitBox);
    serialSetting->addRow(serialStopBit,serialStopBitBox);
    serialSetting->addRow(serialFlowCtrl,serialFlowCtrlBox);
    serialSetting->addRow(serialcheckMode,serialcheckModeBox);

    groupBoxSerialSetting= new QGroupBox("串口设置");
    groupBoxSerialSetting->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    groupBoxSerialSetting->setLayout(serialSetting);
    return groupBoxSerialSetting;
}
