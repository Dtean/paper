#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qcustomplot.h"
#include <QVector>
#include <QString>
#include <QDebug>
#include <QList>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    showMaximized();

    //按键逻辑状态设置
    ui->button_Start->setEnabled(true);
    ui->button_End->setEnabled(false);

    //信号与槽的链接
    connect(ui->plot_1,SIGNAL(mouseMove(QMouseEvent*)),this,SLOT(my_positiondisplay1(QMouseEvent*)));
    connect(ui->plot_2,SIGNAL(mouseMove(QMouseEvent*)),this,SLOT(my_positiondisplay2(QMouseEvent*)));
    connect(ui->plot_3,SIGNAL(mouseMove(QMouseEvent*)),this,SLOT(my_positiondisplay3(QMouseEvent*)));
    connect(ui->plot_4,SIGNAL(mouseMove(QMouseEvent*)),this,SLOT(my_positiondisplay4(QMouseEvent*)));


}

MainWindow::~MainWindow()
{
    delete ui;
    delete timer;
}
/*************************************************************************
*  函数名称：setupPlot1
*  功能说明：绘制坐标图1
*  参数说明：无
*  函数返回：无
*  备    注：第一幅图为时间电流图
*************************************************************************/

void MainWindow::setupPlot1() //坐标图1的绘制
{
    //setRange()用来设置坐标轴的范围和对其情况
    ui->plot_1->xAxis->setRange(0, 14, Qt::AlignLeft);
    ui->plot_1->yAxis->setRange(0, 10,Qt::AlignLeading);
    //setLabel()为x，y轴设置标签
    ui->plot_1->xAxis->setLabel("时间(S)");
    ui->plot_1->yAxis->setLabel("电流(A)");

    ui->plot_1->addGraph();//在QCustomPlot控件中添加一幅图
    ui->plot_1->graph()->setPen(QPen(Qt::blue)); //设置笔的颜色

    QVector<double> x(1000), y(1000);  //定义数组，让点更细腻

    for(int i = 0; i < 1000; i++)
    {
        x[i] = time[i]; //让坐标轴自变量细腻而又正负值
        y[i] = A[i]; //真正的函数关系式
    }

    ui->plot_1->graph()->setData(x,y); //注意setData函数两个传参都为地址
    ui->plot_1->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom); //坐标轴范围可拉伸，可缩放

    ui->plot_1->replot(QCustomPlot::rpQueuedReplot); //动态显示刷新
}

/*************************************************************************
*  函数名称：setupPlot2
*  功能说明：绘制坐标图2
*  参数说明：无
*  函数返回：无
*  备    注：第二幅图为时间电压图
*************************************************************************/

void MainWindow::setupPlot2() //坐标图2的绘制
{
    //setRange()用来设置坐标轴的范围和对其情况
    ui->plot_2->xAxis->setRange(0, 14, Qt::AlignLeft);
    ui->plot_2->yAxis->setRange(0, 300,Qt::AlignLeading);
    //setLabel()为x，y轴设置标签
    ui->plot_2->xAxis->setLabel("时间(S)");
    ui->plot_2->yAxis->setLabel("电压(V)");

    ui->plot_2->addGraph();//在QCustomPlot控件中添加一幅图
    ui->plot_2->graph()->setPen(QPen(Qt::blue)); //设置笔的颜色

    QVector<double> x(1000), y(1000);  //定义数组，让点更细腻

    for(int i = 0; i < 1000; i++)
    {
        x[i] = time[i]; //让坐标轴自变量细腻而又正负值
        y[i] = V[i]; //真正的函数关系式
    }

    ui->plot_2->graph()->setData(x,y); //注意setData函数两个传参都为地址
     ui->plot_2->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom); //坐标轴范围可拉伸，可缩放
     ui->plot_2->replot(QCustomPlot::rpQueuedReplot); //动态显示刷新
}

/*************************************************************************
*  函数名称：setupPlot3
*  功能说明：绘制坐标图3
*  参数说明：无
*  函数返回：无
*  备    注：第三幅图为时间温度图
*************************************************************************/

void MainWindow::setupPlot3() //坐标图3的绘制
{
    //setRange()用来设置坐标轴的范围和对其情况
    ui->plot_3->xAxis->setRange(0, 14, Qt::AlignLeft);
    ui->plot_3->yAxis->setRange(0, 10,Qt::AlignLeading);
    //setLabel()为x，y轴设置标签
    ui->plot_3->xAxis->setLabel("时间(S)");
    ui->plot_3->yAxis->setLabel("温度(℃)");

    ui->plot_3->addGraph();//在QCustomPlot控件中添加一幅图
    ui->plot_3->graph()->setPen(QPen(Qt::blue)); //设置笔的颜色

    QVector<double> x(1000), y(1000);  //定义数组，让点更细腻

    for(int i = 0; i < 1000; i++)
    {
        x[i] = time[i]; //让坐标轴自变量细腻而又正负值
        y[i] = temperature[i]; //真正的函数关系式
    }

    ui->plot_3->graph()->setData(x,y); //注意setData函数两个传参都为地址
     ui->plot_3->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom); //坐标轴范围可拉伸，可缩放
     ui->plot_3->replot(QCustomPlot::rpQueuedReplot); //动态显示刷新
}

/*************************************************************************
*  函数名称：setupPlot4
*  功能说明：绘制坐标图4
*  参数说明：无
*  函数返回：无
*  备    注：第四幅图为时间功率图
*************************************************************************/

void MainWindow::setupPlot4() //坐标图4的绘制
{
    //setRange()用来设置坐标轴的范围和对其情况
    ui->plot_4->xAxis->setRange(0, 14, Qt::AlignLeft);
    ui->plot_4->yAxis->setRange(0, 2000,Qt::AlignLeading);
    //setLabel()为x，y轴设置标签
    ui->plot_4->xAxis->setLabel("时间(S)");
    ui->plot_4->yAxis->setLabel("功率(W)");

    ui->plot_4->addGraph();//在QCustomPlot控件中添加一幅图
    ui->plot_4->graph()->setPen(QPen(Qt::blue)); //设置笔的颜色

    QVector<double> x(1000), y(1000);  //定义数组，让点更细腻

    for(int i = 0; i < 1000; i++)
    {
        x[i] = time[i]; //让坐标轴自变量细腻而又正负值
        y[i] = W[i]; //真正的函数关系式
    }

    ui->plot_4->graph()->setData(x,y); //注意setData函数两个传参都为地址
     ui->plot_4->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom); //坐标轴范围可拉伸，可缩放
     ui->plot_4->replot(QCustomPlot::rpQueuedReplot); //动态显示刷新
}


/*************************************************************************
*  函数名称：my_positiondisplay1
*  功能说明：显示鼠标在坐标轴上对应的坐标
*  参数说明：无
*  函数返回：无
*  备    注：
*************************************************************************/
void MainWindow::my_positiondisplay1(QMouseEvent *event) //鼠标在图内坐标显示的实现
{
    //获取鼠标坐标点
    int x_pos = event->pos().x();
    int y_pos = event->pos().y();

    //把鼠标坐标点转为QCustomPlot内部坐标点（pixeToCoord函数）
    //coordToPixel函数把QCustomPlot坐标转换为鼠标坐标
    float x_val = ui->plot_1->xAxis->pixelToCoord(x_pos);
    float y_val = ui->plot_1->yAxis->pixelToCoord(y_pos);

    //将转换后的坐标打印在界面上(保留三位小数)
    QString x_str, y_str;
    ui->lb_position1->setText(x_str.setNum(x_val,'f',2) +  "," + y_str.setNum(y_val,'f',2));

    //ui->lb_position->setText(QString("%1,%2").arg(x_val).arg(y_val)); //这种方式也能是实现转换但不能限定保留位数

}
/*************************************************************************
*  函数名称：my_positiondisplay2
*  功能说明：显示鼠标在坐标轴上对应的坐标
*  参数说明：无
*  函数返回：无
*  备    注：
*************************************************************************/
void MainWindow::my_positiondisplay2(QMouseEvent *event) //鼠标在图内坐标显示的实现
{
    //获取鼠标坐标点
    int x_pos = event->pos().x();
    int y_pos = event->pos().y();

    //把鼠标坐标点转为QCustomPlot内部坐标点（pixeToCoord函数）
    //coordToPixel函数把QCustomPlot坐标转换为鼠标坐标
    float x_val = ui->plot_2->xAxis->pixelToCoord(x_pos);
    float y_val = ui->plot_2->yAxis->pixelToCoord(y_pos);

    //将转换后的坐标打印在界面上(保留三位小数)
    QString x_str, y_str;
    ui->lb_position2->setText(x_str.setNum(x_val,'f',2) +  "," + y_str.setNum(y_val,'f',2));

    //ui->lb_position->setText(QString("%1,%2").arg(x_val).arg(y_val)); //这种方式也能是实现转换但不能限定保留位数

}

/*************************************************************************
*  函数名称：my_positiondisplay3
*  功能说明：显示鼠标在坐标轴上对应的坐标
*  参数说明：无
*  函数返回：无
*  备    注：
*************************************************************************/
void MainWindow::my_positiondisplay3(QMouseEvent *event) //鼠标在图内坐标显示的实现
{
    //获取鼠标坐标点
    int x_pos = event->pos().x();
    int y_pos = event->pos().y();

    //把鼠标坐标点转为QCustomPlot内部坐标点（pixeToCoord函数）
    //coordToPixel函数把QCustomPlot坐标转换为鼠标坐标
    float x_val = ui->plot_3->xAxis->pixelToCoord(x_pos);
    float y_val = ui->plot_3->yAxis->pixelToCoord(y_pos);

    //将转换后的坐标打印在界面上(保留三位小数)
    QString x_str, y_str;
    ui->lb_position3->setText(x_str.setNum(x_val,'f',2) +  "," + y_str.setNum(y_val,'f',2));

    //ui->lb_position->setText(QString("%1,%2").arg(x_val).arg(y_val)); //这种方式也能是实现转换但不能限定保留位数

}

/*************************************************************************
*  函数名称：my_positiondisplay4
*  功能说明：显示鼠标在坐标轴上对应的坐标
*  参数说明：无
*  函数返回：无
*  备    注：
*************************************************************************/
void MainWindow::my_positiondisplay4(QMouseEvent *event) //鼠标在图内坐标显示的实现
{
    //获取鼠标坐标点
    int x_pos = event->pos().x();
    int y_pos = event->pos().y();

    //把鼠标坐标点转为QCustomPlot内部坐标点（pixeToCoord函数）
    //coordToPixel函数把QCustomPlot坐标转换为鼠标坐标
    float x_val = ui->plot_4->xAxis->pixelToCoord(x_pos);
    float y_val = ui->plot_4->yAxis->pixelToCoord(y_pos);

    //将转换后的坐标打印在界面上(保留三位小数)
    QString x_str, y_str;
    ui->lb_position4->setText(x_str.setNum(x_val,'f',2) +  "," + y_str.setNum(y_val,'f',2));

    //ui->lb_position->setText(QString("%1,%2").arg(x_val).arg(y_val)); //这种方式也能是实现转换但不能限定保留位数

}



void MainWindow::readData()//读取串口传过来的数据（每1000ms会进来一次，所以如果串口未传入数据，则会得到“空”）
{
    requestData = my_serialport->readAll();  //读取串口数据(要求串口以ASCII码型发出)

    qDebug() << requestData;
    //数据处理
    QByteArrayList list = requestData.split(' ');

    if(count < 1000)
    {
        if(list.length() > 1)
        {
            V[count] = list.at(0).toDouble();
            A[count] = list.at(1).toDouble();
            W[count] = list.at(2).toDouble();
            time[count] = list.at(3).toDouble();
            time[count] += count;
            temperature[count] = list.at(4).toDouble();
            changeRate = list.at(5).toDouble();

            ui->le_temperature->setText(QString("%1℃").arg(temperature[count]));


            if(changeRate != 0)
            {
                ui->le_ChangeRate->setText(QString("%1%").arg(changeRate));
            }
            qDebug() << count;
            qDebug() << time[count] ;
            count++;
        }
    }

    setupPlot1();
    setupPlot2();
    setupPlot3();
    setupPlot4();

}

void MainWindow::on_button_Start_clicked()
{

    //实例化串口对象
    my_serialport= new QSerialPort();
    my_serialport->setPortName("COM3");
    //设置串口参数
    if(my_serialport->open(QIODevice::ReadWrite))                  //如果打开串口正确，则如下操作
    {
        //按键逻辑状态设置
        ui->button_Start->setEnabled(false);
        ui->button_End->setEnabled(true);

        my_serialport->setBaudRate(115200);  //波特率
        my_serialport->setDataBits(QSerialPort::Data8); //数据位
        my_serialport->setParity(QSerialPort::NoParity);//奇偶校验位
        my_serialport->setStopBits(QSerialPort::OneStop);//停止位
        my_serialport->setFlowControl(QSerialPort::NoFlowControl);//流控制

        //开定时器
        timer = new QTimer(this);
        connect(this->timer,SIGNAL(timeout()),this,SLOT(readData())); //定时溢出信号与槽的绑定
        timer->start(1000);//设置定时时间为1000ms

    }
    else //如果打开串口不正确，则跳出提示窗口
        QMessageBox::warning(NULL, "warning", "请确定串口链接正确");
}

void MainWindow::on_button_End_clicked()
{
    //按键逻辑状态设置
    ui->button_Start->setEnabled(true);
    ui->button_End->setEnabled(false);
    //删除串口对象
    delete my_serialport;
    //关定时器
    timer->stop();
    delete timer;
}
