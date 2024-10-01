#ifndef PROFILEBANNER_H
#define PROFILEBANNER_H

#include <QWidget>
#include <QString>
#include <QPixmap>
#include <QPainter>
#include <QPainterPath>
#include <QPen>
#include <QBrush>


namespace Ui {
class ProfileBanner;
}

class ProfileBanner : public QWidget
{
    Q_OBJECT

public:
    ProfileBanner(QString& UserName, QString& UserPrivilage, QWidget *parent = nullptr);
    ~ProfileBanner();

    enum UserRole
    {
        Admin,
        User
    };


    /* GETTER */
    QString avatarPath() const { return m_avatar_path; };
    QString userName()   const { return m_user; };
    UserRole privilage() const { return m_userRole; };
    QPixmap avatarPixmap() const;

    /* SETTER */
    template <typename T>
    void changeAvatar(T& path, bool notify = true);

private:
    Ui::ProfileBanner *ui;
    const QString m_user;
    const UserRole m_userRole{this->UserRole::User};
    const QString DEFAULT_AVATAR{":/icons/avatar/avatar_2.png"};

    QString m_avatar_path;

signals:
    void profilePicModified(QString userName, QString imagePath);
};

#endif // PROFILEBANNER_H
