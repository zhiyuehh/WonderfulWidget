#include "flowlightbutton.h"
#include <QPainterPath>
#include <QPainter>
#include <QLinearGradient>
#include <cstdio>

FlowLightButton::FlowLightButton(QWidget *parent) : QFrame(parent)
{
    initFrame();
}

FlowLightButton::~FlowLightButton()
{

}

void FlowLightButton::initFrame()
{
    this->setGeometry(QRect(290,280,300,100));
    this->setStyleSheet("QFrame{background-color:rgba(255,255,255,0);}"
                           "*{border:none;border-radius:10px;}"
                           "QPushButton{color:rgba(255,255,255,255)}");  //Rborder-width:5px;
    m_btn=new QPushButton(this);
    m_btn->setGeometry(5,5,300 - 5 * 2,100 - 5 * 2);
    QFont font;
    font.setPointSize(25);
    m_btn->setFont(font);
    m_btn->setText("flow light");

    m_rect1_offset=0;
    m_rect2_offset=0;
    m_rect1_start=0;
    m_rect2_start=-this->width();
    m_initx=-this->width();

    m_timer=new QTimer();
//    m_timer->setInterval(1000);

    connect(m_timer,&QTimer::timeout,this,[&]() {
        update();
    });

    m_timer->start(10);

    m_flag=false;
}

void FlowLightButton::paintEvent(QPaintEvent *)
{
    QPainterPath path;
     path.addRoundedRect(0,0,this->width(),this->height(),10,10);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setClipPath(path);

    QLinearGradient grd1(m_rect1_start+m_rect1_offset,0,m_rect1_start+m_rect1_offset+this->width(),0);
    grd1.setColorAt(0, QColor(0, 164, 128, 230));
    grd1.setColorAt(0.166, QColor(13, 88, 166, 230));
    grd1.setColorAt(0.333, QColor(118, 8, 170, 230));
    grd1.setColorAt(0.5, QColor(255, 144, 0, 230));
    grd1.setColorAt(0.666, QColor(255, 255, 0, 230));
    grd1.setColorAt(0.833, QColor(165, 239, 0, 230));
    grd1.setColorAt(1, QColor(83, 223, 0, 230));
    painter.setBrush(grd1);
    painter.drawRect(m_rect1_start+m_rect1_offset,0,this->width(),this->height());

    QLinearGradient grd2(m_rect2_start+m_rect2_offset,0,m_rect2_start+m_rect2_offset+this->width(),0);
    grd2.setColorAt(0, QColor(0, 164, 128, 230));
    grd2.setColorAt(0.166, QColor(13, 88, 166, 230));
    grd2.setColorAt(0.333, QColor(118, 8, 170, 230));
    grd2.setColorAt(0.5, QColor(255, 144, 0, 230));
    grd2.setColorAt(0.666, QColor(255, 255, 0, 230));
    grd2.setColorAt(0.833, QColor(165, 239, 0, 230));
    grd2.setColorAt(1, QColor(83, 223, 0, 230));
    painter.setBrush(grd2);
    painter.drawRect(m_rect2_start+m_rect2_offset,0,this->width(),this->height());

    if (m_rect1_offset >= this->width() &&!m_flag)
    {
        m_rect1_offset = 0;
        m_rect1_start =m_initx;
        m_flag = true;
    }

    if (m_rect1_offset >= this->width()*2 &&m_flag)
    {
        m_rect1_offset = 0;
        m_rect1_start =m_initx;
    }

    if (m_rect2_offset >= this->width()*2)
    {
        m_rect2_offset = 0;
        m_rect2_start =m_initx;
    }
    m_rect1_offset+=3;
    m_rect2_offset+=3;


}
