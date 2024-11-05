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





