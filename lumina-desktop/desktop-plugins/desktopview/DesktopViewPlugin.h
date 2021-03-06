//===========================================
//  Lumina-DE source code
//  Copyright (c) 2014, Ken Moore
//  Available under the 3-clause BSD license
//  See the LICENSE file for full details
//===========================================
//  This plugin is a listing/launcher for things in the ~/Desktop folder
//===========================================
#ifndef _LUMINA_DESKTOP_DESKTOP_VIEW_PLUGIN_H
#define _LUMINA_DESKTOP_DESKTOP_VIEW_PLUGIN_H

#include <QListWidget>
#include <QVBoxLayout>
#include <QTimer>
#include <QFileSystemWatcher>
#include "../LDPlugin.h"

class DesktopViewPlugin : public LDPlugin{
	Q_OBJECT
public:
	DesktopViewPlugin(QWidget* parent, QString ID);
	~DesktopViewPlugin();
	
private:
	QListWidget *list;
	QFileSystemWatcher *watcher;

private slots:
	void runItem(QListWidgetItem*);
	void updateContents();


public slots:
	void LocaleChange(){
	  QTimer::singleShot(0,this, SLOT(updateContents()));
	}
	void ThemeChange(){
	  QTimer::singleShot(0,this, SLOT(updateContents()));
	}

};
#endif
