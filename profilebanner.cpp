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
