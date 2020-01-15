#include "SwitchButton.hpp"
#include <QPainter>
#include <QRectF>
#include <QEvent>

/// 默认配色
const QColor SwitchButton::DEFAULT_ON_BG_COLOR {QColor(0x63, 0xBA, 0xFF)};
const QColor SwitchButton::DEFAULT_OFF_BG_COLOR {QColor(0xE7, 0xE3, 0xE7)};
const QColor SwitchButton::DEFAULT_ON_SLIDER_COLOR {QColor(Qt::white)};
const QColor SwitchButton::DEFAULT_OFF_SLIDER_COLOR {QColor(Qt::white)};
const QColor SwitchButton::DEFAULT_DISABLED_ON_BG_COLOR {QColor(0xA0, 0xA0, 0xA0)};
const QColor SwitchButton::DEFAULT_DISABLED_OFF_BG_COLOR {QColor(0xC0, 0xC0, 0xC0)};
const QColor SwitchButton::DEFAULT_DISABLED_ON_SLIDER_COLOR {QColor(0xE0, 0xE0, 0xE0)};
const QColor SwitchButton::DEFAULT_DISABLED_OFF_SLIDER_COLOR {QColor(0xE0, 0xE0, 0xE0)};

SwitchButton::SwitchButton(QWidget *parent) :
    QAbstractButton(parent)
{
    QAbstractButton::setCheckable(true);
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
}

SwitchButton::~SwitchButton()
{

}

void SwitchButton::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing);
    painter.setRenderHint(QPainter::SmoothPixmapTransform);

    QRectF offRect(height() * 0.05, height() * 0.05, height() * 0.9, height() * 0.9);
    QRectF onRect(width() - height() * 0.95, height() * 0.05, height() * 0.9, height() * 0.9);

    if (!isEnabled() && !isChecked()) {  //未启用
        painter.setPen(QPen(DEFAULT_DISABLED_OFF_BG_COLOR));
        painter.setBrush(QBrush(DEFAULT_DISABLED_OFF_BG_COLOR));
        drawBackground(&painter);

        painter.setPen(QPen(DEFAULT_DISABLED_OFF_SLIDER_COLOR));
        painter.setBrush(QBrush(DEFAULT_DISABLED_OFF_SLIDER_COLOR));
        drawSlider(&painter, offRect);
    } else if (!isEnabled() && isChecked()) {
        painter.setPen(QPen(DEFAULT_DISABLED_ON_BG_COLOR));
        painter.setBrush(QBrush(DEFAULT_DISABLED_ON_BG_COLOR));
        drawBackground(&painter);

        painter.setPen(QPen(DEFAULT_DISABLED_ON_SLIDER_COLOR));
        painter.setBrush(QBrush(DEFAULT_DISABLED_ON_SLIDER_COLOR));
        drawSlider(&painter, onRect);
    } else if (isChecked()) {
        painter.setPen(QPen(_onBgColor));
        painter.setBrush(QBrush(_onBgColor));
        drawBackground(&painter);

        painter.setPen(QPen(_onSliderColor));
        painter.setBrush(QBrush(_onSliderColor));
        drawSlider(&painter, onRect);
    } else {
        painter.setPen(QPen(_offBgColor));
        painter.setBrush(QBrush(_offBgColor));
        drawBackground(&painter);

        painter.setPen(QPen(_offSliderColor));
        painter.setBrush(QBrush(_offSliderColor));
        drawSlider(&painter, offRect);
    }

    return QWidget::paintEvent(event);
}

void SwitchButton::mouseMoveEvent(QMouseEvent *event)
{
    setCursor(Qt::PointingHandCursor);

    return QWidget::mouseMoveEvent(event);
}

void SwitchButton::drawBackground(QPainter *painter)
{
    painter->drawEllipse(0, 0, height(), height());
    painter->drawEllipse(width() - height(), 0, height(), height());
    painter->drawRect(height() / 2, 0, width() - height(), height());
}

void SwitchButton::drawSlider(QPainter *painter, const QRectF &rect)
{
    painter->drawEllipse(rect);
}
