#ifndef TRACKMANAGER_H
#define TRACKMANAGER_H

#include <QWidget>
#include <QDebug>
#include <QStatusBar>

#include "windowframe.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class TrackManager;
}
QT_END_NAMESPACE

class TrackManager : public QWidget
{
    Q_OBJECT

public:
    TrackManager(QWidget *parent = nullptr);
    ~TrackManager();

private slots:
    void on_id_tbtn_clicked(bool checked);

    void on_hist_tbtn_clicked(bool checked);

    void on_mail_tbtn_clicked(bool checked);

    void on_chat_tbtn_clicked(bool checked);

    void on_settings_tbtn_clicked(bool checked);

    void on_profile_tbtn_clicked(bool checked);

private:
    Ui::TrackManager *ui;
    WindowFrame* m_titlebar;
    QStatusBar* m_statusbar;
};
#endif // TRACKMANAGER_H
