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
