#include "trackmanager.h"
#include "ui_trackmanager.h"

TrackManager::TrackManager(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TrackManager)
{
    ui->setupUi(this);

    QString TEMP_USER{"genericmail@gmail.it"};
    QString TEMP_POWER{"Admin"};

    /*  Declaration status bar & title window  */
    // m_statusbar = new QStatusBar();
    m_titlebar = new WindowFrame(TEMP_USER, TEMP_POWER, this);

    QVBoxLayout* window_layout = qobject_cast<QVBoxLayout*>(this->layout());
    window_layout->insertWidget(0, m_titlebar);
    //window_layout->insertWidget(0, m_statusbar);
}







TrackManager::~TrackManager()
{
    delete ui;
}








/*                     TOOL BAR BUTTON                               */
void TrackManager::on_id_tbtn_clicked(bool checked)
{
    qDebug() << "id button clicked: " << checked;
}


void TrackManager::on_hist_tbtn_clicked(bool checked)
{
    qDebug() << "hist button clicked: " << checked;
}


void TrackManager::on_mail_tbtn_clicked(bool checked)
{
    qDebug() << "mail button clicked: " << checked;
}


void TrackManager::on_chat_tbtn_clicked(bool checked)
{
    qDebug() << "chat button clicked: " << checked;
}


void TrackManager::on_settings_tbtn_clicked(bool checked)
{
    qDebug() << "settings button clicked: " << checked;
}


void TrackManager::on_profile_tbtn_clicked(bool checked)
{
    qDebug() << "profile button clicked: " << checked;
}

