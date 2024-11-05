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
