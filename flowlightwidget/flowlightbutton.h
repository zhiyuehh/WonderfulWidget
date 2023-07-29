#ifndef FLOWLIGHTBUTTON_H
#define FLOWLIGHTBUTTON_H

#include <QWidget>
#include <QFrame>
#include <QPushBUtton>
#include <QTimer>

class FlowLightButton:public QFrame
{
    Q_OBJECT
public:
    FlowLightButton(QWidget *parent=nullptr);
    ~FlowLightButton();

private:
    void initFrame();

protected:
    virtual void paintEvent(QPaintEvent *) override;

private:
    QPushButton *m_btn;
    int m_rect1_offset,m_rect2_offset,m_rect1_start,m_rect2_start;
    int m_initx;
    bool m_flag;
    QTimer *m_timer;
};

#endif // FLOWLIGHTBUTTON_H
