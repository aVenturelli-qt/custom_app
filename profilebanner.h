/****************************************************************************
**
** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/
**
** This file is part of the QtSql module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this
** file. Please review the following information to ensure the GNU Lesser
** General Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU General
** Public License version 3.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of this
** file. Please review the following information to ensure the GNU General
** Public License version 3.0 requirements will be met:
** http://www.gnu.org/copyleft/gpl.html.
**
** Other Usage
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Nokia.
**
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

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
