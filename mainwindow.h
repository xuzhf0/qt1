#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QDebug>
#include <QMainWindow>
#include <QLabel>
#include <QGridLayout>
#include <Qmenu>
#include <QMenuBar>
#include <QAction>
#include <QApplication>
#include <QPushButton>
#include <QTextBrowser>
#include <QDialog>
#include <QMenu>
#include <QMenuBar>
#include <QMessageBox>
#include <QStatusBar>
#include <QLineEdit>
#include <QGroupBox>
#include <QBoxLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTextEdit>
#include <QPlainTextEdit>

class MyWidget :public QWidget{
public:
    MyWidget(QWidget *parent =Q_NULLPTR):QWidget(parent){}
    ~MyWidget(){}
}
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void f1();
private:

    void createMenus();
    void createActions();
    void createButtons();
    void init();
    void initUI();
    QPushButton *btn1;
    QPushButton *btn2;

    QPushButton *sendBtn;
    QPushButton *clearBtn;

    QMenu *fileMenu,*helpMenu;
    QLabel *l1,*l2,*l3;

   QAction *openAct;
   QAction *aboutSoftware;
   QAction *aboutQt;

    QGridLayout *grid1;
    QTextBrowser *textBrowser;
    QTextEdit *textEdit;
    QLineEdit *lineEdit1;
    QPlainTextEdit *serialInput;

    QGroupBox *group1;
    QGroupBox *group2;
    QWidget *centerWidget;
};

#endif // MAINWINDOW_H
