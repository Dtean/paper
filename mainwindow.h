#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void setupPlot1();
    void setupPlot2();
    void setupPlot3();
    void setupPlot4();

private slots:
    void my_positiondisplay1(QMouseEvent* event); //鼠标移动信号对应的槽
    void my_positiondisplay2(QMouseEvent* event); //鼠标移动信号对应的槽
    void my_positiondisplay3(QMouseEvent* event); //鼠标移动信号对应的槽
    void my_positiondisplay4(QMouseEvent* event); //鼠标移动信号对应的槽
    void readData();

    void on_button_Start_clicked();

    void on_button_End_clicked();

private:
    Ui::MainWindow *ui;
    QSerialPort *my_serialport; //创建串口对象
    QByteArray requestData; //此私有成员用来存放接收到的数据
    QTimer  *timer; //创建定时器对象，用来完成定时读取数据工作
    double  time[1000] = {0};
    double  A[1000] = {0};
    double  V[1000] = {0};
    double  temperature[1000] = {0};
    double  W[1000] = {0};
    double  changeRate = 0;
    int count = 0;
};
#endif // MAINWINDOW_H
