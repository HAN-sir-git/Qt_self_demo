#include "quiswitchbutton.h"
#include<QDebug>

QUiSwitchButton::QUiSwitchButton(QWidget *parent)
    : QAbstractButton(parent)
    , m_clrOnText(QColor(255, 255, 255))
    , m_clrOffText(QColor(255, 255, 255))
    , m_clrOn(QColor(0, 85, 255))
    , m_clrOff(QColor(200, 200, 200))
    , m_clrDisable(QColor(200, 200, 200))
    , m_clrHandler(QColor(255, 255, 255))
    , m_iHandlerMargin(2)
    , m_dCurFrame(MAX_NUM_AA)
    , m_eCurAniType(None)
{
    setCheckable(true);
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    setFixedSize(60, 30);
}

QUiSwitchButton::~QUiSwitchButton()
{
}

void QUiSwitchButton::setSwitchOnTextColor(const QColor& clr)
{
    m_clrOnText = clr;
}

void QUiSwitchButton::setSwitchOffTextColor(const QColor& clr)
{
    m_clrOffText = clr;
}

void QUiSwitchButton::setSwitchOnColor(const QColor& clr)
{
    m_clrOn = clr;
}

void QUiSwitchButton::setSwitchOffColor(const QColor& clr)
{
    m_clrOff = clr;
}

void QUiSwitchButton::setSwitchDisableColor(const QColor& clr)
{
    m_clrDisable = clr;
}

void QUiSwitchButton::setHandleColor(const QColor& clr)
{
    m_clrHandler = clr;
}


void QUiSwitchButton::handleAnimStateChanged(QVariantAnimation::State curState)
{
    if (curState == QVariantAnimation::Stopped)
    {
        m_eCurAniType = None;
    }
    update();
}


void QUiSwitchButton::handleAnimValueChanged(QVariant val)
{
    m_dCurFrame = val.toInt();
    update();
}


void QUiSwitchButton::paintEvent(QPaintEvent *pEvt)
{
    Q_UNUSED(pEvt);
    QStylePainter paint(this);
    paint.setRenderHints(QPainter::Antialiasing);
    drawBackground(&paint);
    drawHandler(&paint);
    drawText(&paint);
}

void QUiSwitchButton::drawBackground(QStylePainter* paint)
{
    QRect rcFrame = contentsRect();
    QRect rcLeft = rcFrame;//左边圆弧
    QRect rcMiddle = rcFrame;//中间矩形
    QRect rcRight = rcFrame;//右边圆弧

    QPainterPath path;
    path.setFillRule(Qt::WindingFill);//设置填充规则
    //左
    rcLeft.setWidth(rcLeft.height());
    path.addEllipse(rcLeft);
    //中
    rcMiddle.adjust(rcLeft.width() / 2, 0, -rcLeft.width() / 2, 0);
    path.addRect(rcMiddle);
    //右
    rcRight.adjust(rcMiddle.width(), 0, 0, 0);
    path.addEllipse(rcRight);
    paint->fillPath(path, styledBackgroundColor());
}

void QUiSwitchButton::drawHandler(QStylePainter* paint)
{
    QRect rcFrame = contentsRect();
    int iAnimSpan = rcFrame.width() - rcFrame.height(); // 计算滑动范围
    // 使用当前动画值计算滑块中心位置
    double setp =  1.0 / MAX_NUM_AA ;
    int x = iAnimSpan * m_dCurFrame * setp; // 计算滑块 X 坐标
    QPoint ptCenter(x + rcFrame.height() / 2, rcFrame.height() / 2); // 滑块中心
    QRect rcHandler = QRect(ptCenter.x() - rcFrame.height() / 2, 0, rcFrame.height(), rcFrame.height());
    rcHandler = rcHandler.marginsRemoved(QMargins(m_iHandlerMargin, m_iHandlerMargin, m_iHandlerMargin, m_iHandlerMargin));
    QPainterPath path;
    path.addEllipse(rcHandler);
    paint->fillPath(path, m_clrHandler); // 绘制滑块
}

void QUiSwitchButton::startAnimation()
{
    if (m_pAnima.isNull())
    {
        m_pAnima = new QVariantAnimation(this);
        m_pAnima->setDuration(300); // 动画持续时间
        m_pAnima->setStartValue(0); // 开始值
        m_pAnima->setEndValue(MAX_NUM_AA); // 结束值

        //        QEasingCurve curve(QEasingCurve::InOutQuad);
        //        curve.addCubicBezierSegment(QPointF(0.1, 0.1), QPointF(0.3, 0.5), QPointF(0.6, 0.8));
        //        m_pAnima->setEasingCurve(curve);

        connect(m_pAnima.data(), &QVariantAnimation::valueChanged, this, &QUiSwitchButton::handleAnimValueChanged);
        connect(m_pAnima.data(), &QVariantAnimation::stateChanged, this, &QUiSwitchButton::handleAnimStateChanged);
    }

    m_pAnima->stop(); // 停止当前动画
    // 设置动画方向
    m_eCurAniType = isChecked() ? OnAnimation : OffAnimation;
    m_pAnima->setDirection(m_eCurAniType == OnAnimation ? QVariantAnimation::Forward : QVariantAnimation::Backward);
    m_pAnima->start(); // 启动动画
}

double QUiSwitchButton::getCurAnimaValue()const
{
    return m_dCurFrame;
}

QColor QUiSwitchButton::styledBackgroundColor()const
{
    if (!isEnabled())
    {
        return m_clrDisable;
    }
    if (m_eCurAniType == None)
    {
        return isChecked() ? m_clrOn : m_clrOff;
    }
    return m_eCurAniType == OnAnimation ? m_clrOn : m_clrOff;
}

void QUiSwitchButton::drawText(QStylePainter* p)
{
    QString text = "关闭状态11111";
    QRect rcFrame = contentsRect();
    QRect rcText = rcFrame;
    // 调整文字绘制起始位置
    if(m_dCurFrame == 0)
    {
        rcText.adjust(rcFrame.height(), 0, 0, 0);
        text = "开启状态11111";
    }

    p->setPen(isChecked() ? m_clrOnText : m_clrOffText);
    p->drawText(rcText, Qt::AlignLeft | Qt::AlignVCenter, text);


}

void QUiSwitchButton::mouseReleaseEvent(QMouseEvent *pEvt)
{
    startAnimation();
    QAbstractButton::mouseReleaseEvent(pEvt);
}

