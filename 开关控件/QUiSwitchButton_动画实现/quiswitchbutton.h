#ifndef QUISWITCHBUTTON_H
#define QUISWITCHBUTTON_H

#include <QAbstractButton>
#include <QVariantAnimation>
#include <QStylePainter>
#include <QPointer>

#define MAX_NUM_AA 100

class Q_DECL_EXPORT  QUiSwitchButton : public QAbstractButton
{
    Q_OBJECT
       enum AnimationType
       {
           None= 0,      //静态状态下
           OnAnimation ,//打开动画从左向右滑动
           OffAnimation,    //关闭动画从右向左滑动
       };
   public:
       QUiSwitchButton(QWidget *parent = nullptr);
       ~QUiSwitchButton();
       //设置开状态下文本色
       void setSwitchOnTextColor(const QColor& clr);
       //设置关状态下文本色
       void setSwitchOffTextColor(const QColor& clr);
       //设置开状态下背景色
       void setSwitchOnColor(const QColor& clr);
       //设置关状态下背景色
       void setSwitchOffColor(const QColor& clr);
       //设置diasbale颜色
       void setSwitchDisableColor(const QColor& clr);
       //设置滑块背景色
       void setHandleColor(const QColor& clr);
   protected:
       void mouseReleaseEvent(QMouseEvent *pEvt) override;
       void paintEvent(QPaintEvent *e) override;
       void drawBackground(QStylePainter*);
       void drawHandler(QStylePainter*);
       void drawText(QStylePainter* p);
       //
       void startAnimation();
       double getCurAnimaValue()const;
       QColor styledBackgroundColor()const;
   protected slots:
       void handleAnimValueChanged(QVariant val);
       void handleAnimStateChanged(QVariantAnimation::State);
   private:
       QPointer<QVariantAnimation> m_pAnima;
       QColor m_clrOnText;
       QColor m_clrOffText;
       QColor m_clrOn;
       QColor m_clrOff;
       QColor m_clrDisable;
       QColor m_clrHandler;
       int m_iHandlerMargin;
       int m_dCurFrame;
       AnimationType m_eCurAniType;

};

#endif // QUISWITCHBUTTON_H
