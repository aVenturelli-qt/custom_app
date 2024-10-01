#include "windowframe.h"
#include "ui_windowframe.h"

WindowFrame::WindowFrame(QString& userName, QString& privilage, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::WindowFrame)
{
    ui->setupUi(this);
    this->setFixedHeight(52);
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setParent(parent);

    QHBoxLayout* h_lay = qobject_cast<QHBoxLayout*>(this->layout());

    m_profile_banner = new ProfileBanner(userName, privilage, this);
    h_lay->insertWidget(0, m_profile_banner);

    /* set central label to current day month week-of-year */
    ui->time_lbl->setText(m_today.toString("ddd d MMMM") + " - Week " + QString::number(m_today.weekNumber()));

}


/* CUSTOM METHODS */
ProfileBanner* WindowFrame::profileBanner()
{
    /* expose the inner widget to access
     * directly the profilePicChanged */
    return m_profile_banner;
}


/* WINDOW SPECIFIC */
WindowFrame::~WindowFrame()
{
    delete ui;
}


void WindowFrame::on_close_tbtn_clicked()
{
    this->close();
}


void WindowFrame::on_maximize_tbnt_clicked()
{
    if (this->isFullScreen())
    {
        emit showNormalClicked();
        ui->maximize_tbnt->setIcon(QIcon(":/icons/maximize_icon.svg"));
        return;
    }
    emit maximizedClicked();
    ui->maximize_tbnt->setIcon(QIcon(":/icons/normal_icon.svg"));
}


void WindowFrame::on_minimize_tbtn_clicked()
{
    emit minimizedClicked();
}


void WindowFrame::mousePressEvent(QMouseEvent *event)
{
    mPosition = event->pos();
    setCursor(QCursor(Qt::SizeAllCursor));
}


void WindowFrame::mouseMoveEvent(QMouseEvent *event)
{
    QPointF p = event->globalPosition();
    QPoint point(static_cast<int>(p.x()), static_cast<int>(p.y()) );
    window()->move(point - mPosition);
}


void WindowFrame::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    setCursor(QCursor(Qt::ArrowCursor));
}





