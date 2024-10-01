#ifndef WINDOWFRAME_H
#define WINDOWFRAME_H

#include <QWidget>
#include <QDate>
#include <QDebug>
#include <QMouseEvent>
#include "profilebanner.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class WindowFrame;
}
QT_END_NAMESPACE

class WindowFrame : public QWidget
{
    Q_OBJECT

public:
    WindowFrame(QString& userName, QString& privilage, QWidget *parent = nullptr);
    ~WindowFrame();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private slots:
    void on_close_tbtn_clicked();
    void on_maximize_tbnt_clicked();
    void on_minimize_tbtn_clicked();
    ProfileBanner* profileBanner();

signals:
    void maximizedClicked();
    void showNormalClicked();
    void minimizedClicked();

private:
    Ui::WindowFrame *ui;
    QDate m_today{QDate::currentDate()};
    QPoint mPosition;
    int mBorderSize;
    ProfileBanner* m_profile_banner;
};
#endif // WINDOWFRAME_H
