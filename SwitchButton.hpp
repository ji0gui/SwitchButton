#ifndef SWITCHBUTTON_HPP
#define SWITCHBUTTON_HPP

#include <QAbstractButton>

class SwitchButton : public QAbstractButton
{
    Q_OBJECT

public:
    SwitchButton(QWidget *parent = nullptr);
    ~SwitchButton() override;

    // 默认配色
    static const QColor DEFAULT_ON_BG_COLOR;
    static const QColor DEFAULT_OFF_BG_COLOR;
    static const QColor DEFAULT_ON_SLIDER_COLOR;
    static const QColor DEFAULT_OFF_SLIDER_COLOR;
    static const QColor DEFAULT_DISABLED_ON_BG_COLOR;
    static const QColor DEFAULT_DISABLED_OFF_BG_COLOR;
    static const QColor DEFAULT_DISABLED_ON_SLIDER_COLOR;
    static const QColor DEFAULT_DISABLED_OFF_SLIDER_COLOR;

    // 背景颜色
    QColor onBgColor() const { return _onBgColor; }
    void setOnBgColor(const QColor &color) { _onBgColor = color; repaint(); }
    QColor offBgColor() const { return _offBgColor; }
    void setOffBgColor(const QColor &color) { _offBgColor = color; repaint(); }

    // 滑块颜色
    QColor onSliderColor() const { return _onSliderColor; }
    void setOnSliderColor(const QColor &color) { _onSliderColor = color; repaint(); }
    QColor offSliderColor() const { return _offSliderColor; }
    void setOffSliderColor(const QColor &color) { _offSliderColor = color; repaint(); }

    virtual QSize sizeHint() const override { return QSize(fontMetrics().height() * 2, fontMetrics().height()); }

    /// 去除不需要的成员函数
    // 是否可选
    bool isCheckable() const = delete;
    void setCheckable(bool) = delete;
    // 文本
    QString text() const = delete;
    void setText(const QString &text) = delete;

signals:
    void checkStateChanged(bool checked);

protected:
    virtual void paintEvent(QPaintEvent *event) override;
    virtual void mouseMoveEvent(QMouseEvent *event) override;

private:
    void drawBackground(QPainter *painter);

    void drawSlider(QPainter *painter, const QRectF &rect);

    /// 暂时以字体尺寸作为默认尺寸
//    // 默认尺寸
//    static constexpr int DEFAULT_WIDTH {40};
//    static constexpr int DEFAULT_HEIGHT {20};

    QColor _onBgColor {DEFAULT_ON_BG_COLOR};
    QColor _offBgColor {DEFAULT_OFF_BG_COLOR};

    QColor _onSliderColor {DEFAULT_ON_SLIDER_COLOR};
    QColor _offSliderColor {DEFAULT_OFF_SLIDER_COLOR};
};

#endif // SWITCHBUTTON_HPP
