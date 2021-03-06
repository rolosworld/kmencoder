/***************************************************************************
                          kmenconfig.h  -  description
                             -------------------
    begin                : Fri Jul 5 2002
    copyright            : (C) 2002 by Rolando Gonzalez
    email                : rolando8@prtc.net
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/
#ifndef KMENCONFIG_H
#define KMENCONFIG_H
/**
  *@author Rolando
  */
#include <qstring.h>
#include <qprocess.h>
#include <qdir.h>
#include <qmessagebox.h>
#include <klocale.h>

class KMenConfig {
public: 
	KMenConfig();
	~KMenConfig();

  /** No descriptions */
  QString getEnabled();

  /** No descriptions */
  void setEnabled( QString einput );

  /** No descriptions */
  QString getExec();

  /** No descriptions */
  bool getPreview();

  /** No descriptions */
  void setPreview( bool disabled );
  /** No descriptions */
  void setOutputFileName( QString file_name );
  /** No descriptions */
  QString getOutputFileName();
  /** No descriptions */
  bool setOutputFileArguments( QProcess *procs );
  /** No descriptions */
  /** No descriptions */
  void deleteTmpFiles();
  void setConfPass( bool enabled );
  /** No descriptions */
  void setConfOutRename();
  /** No descriptions */
  void setConfDir( QString dir );
  /** No descriptions */
  QString getConfDir();
    /**  */
  static unsigned short proc_loaded;
  static unsigned short stopped;

protected: // Protected attributes

  /**  */
  QString *enabled_input;

  /**  */
  QString *exec;

  /**  */
  QString *out_file_name;
  /**  */
  bool encode;
  /**  */
  bool conf_pass;
  /**  */
  QString *true_out_file_name;
  /**  */
  QString *tmp;
  /**  */
  QDir *d;
};

#endif
