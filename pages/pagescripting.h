/*
    Copyright 2021 Benjamin Vedder	benjamin@vedder.se

    This file is part of VESC Tool.

    VESC Tool is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    VESC Tool is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
    */

#ifndef PAGESCRIPTING_H
#define PAGESCRIPTING_H

#include <QWidget>
#include <QDebug>

#include "vescinterface.h"
#include "mobile/qmlui.h"

namespace Ui {
class PageScripting;
}

class PageScripting : public QWidget
{
    Q_OBJECT

public:
    explicit PageScripting(QWidget *parent = nullptr);
    ~PageScripting();

    VescInterface *vesc() const;
    void setVesc(VescInterface *vesc);
    void reloadParams();

signals:
    void reloadQml(QString str);

public slots:
    void debugMsgRx(QtMsgType type, const QString msg);

protected:
    void keyPressEvent(QKeyEvent *event);

private slots:
    void on_runButton_clicked();
    void on_stopButton_clicked();
    void on_runWindowButton_clicked();
    void on_fullscreenButton_clicked();
    void on_openFileButton_clicked();
    void on_saveButton_clicked();
    void on_saveAsButton_clicked();
    void on_openRecentButton_clicked();
    void on_removeSelectedButton_clicked();
    void on_clearRecentButton_clicked();
    void on_openExampleButton_clicked();
    void on_helpButton_clicked();
    void on_searchEdit_textChanged(const QString &arg1);
    void on_searchHideButton_clicked();
    void on_searchNextButton_clicked();
    void on_replaceThisButton_clicked();
    void on_replaceAllButton_clicked();
    void on_searchPrevButton_clicked();

    void on_searchCaseSensitiveBox_toggled(bool checked);

private:
    Ui::PageScripting *ui;
    VescInterface *mVesc;
    QmlUi mQmlUi;
    QStringList mRecentFiles;

    void updateRecentList();

};

#endif // PAGESCRIPTING_H