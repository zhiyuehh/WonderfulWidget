#include "flowlightwidget.h"
#include "flowlightbutton.h"

FlowLightWidget::FlowLightWidget(QWidget *parent)
    : QWidget(parent)
{
    FlowLightButton*btn=new FlowLightButton(this);
}

FlowLightWidget::~FlowLightWidget()
{
}

