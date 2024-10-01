#include "profilebanner.h"
#include "ui_profilebanner.h"

ProfileBanner::ProfileBanner(QString& UserName, QString& UserPrivilage, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ProfileBanner),
    m_user{UserName},
    m_userRole{ (UserPrivilage == "Admin") ? UserRole::Admin : UserRole::User }
{
    ui->setupUi(this);
    this->changeAvatar(DEFAULT_AVATAR, false);
    ui->mail_lbl->setText(m_user);
    ui->privilage_lbl->setText(UserPrivilage);
}

ProfileBanner::~ProfileBanner()
{
    delete ui;
}

template <typename T>
void ProfileBanner::changeAvatar(T& path, bool notify)
{
    m_avatar_path = path;

    QPixmap profile_img = QPixmap(ui->profile_pic->size());
    profile_img.fill(Qt::transparent);

    QPainter my_painter(&profile_img);
    my_painter.setRenderHint(QPainter::Antialiasing, true);

    /* ellipse shape to fill info */
    const int ellipse_w{profile_img.width()};
    const int ellipse_h{profile_img.height()};
    const QRect rect(0, 0, ellipse_w, ellipse_h);
    const Qt::GlobalColor bg_color{Qt::darkBlue};

    /* clip the outside part of the pixmap */
    QPainterPath ellipse_path;
    ellipse_path.addEllipse(rect);
    my_painter.setClipPath(ellipse_path, Qt::IntersectClip);
    my_painter.setBrush(bg_color);
    my_painter.setPen(Qt::NoPen);
    my_painter.drawEllipse(rect);

    /* set the profile picture */
    QImage profile(path);
    profile = profile.scaled(ellipse_w, ellipse_h, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    my_painter.drawImage(rect, profile);

    /* update the label setting the pixmap */
    my_painter.end();
    ui->profile_pic->setPixmap(profile_img);
    this->update();

    if (notify)
    {
        emit profilePicModified(m_user, path);
    }
}


QPixmap ProfileBanner::avatarPixmap() const
{
    return ui->profile_pic->pixmap();
}
