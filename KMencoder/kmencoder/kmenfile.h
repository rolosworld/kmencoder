/***************************************************************************
                          kmenfile.h  -  description
                             -------------------
    begin                : Wed Jul 10 2002
    copyright            : (C) 2002 by Rolando
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

#ifndef KMENFILE_H
#define KMENFILE_H

#include <qstring.h>
#include <qprocess.h>
#include <qmessagebox.h>

/**
  *@author Rolando
  */

class KMenFile {
public: 
	KMenFile();

	~KMenFile();

/** set file name */
QString getFileName();

/** set file name */
void setFileName( QString fname );
  /** No descriptions */
bool setFileArguments( QProcess *procs );

protected: // Protected attributes
  /** stores file name */
  QString *file_name;
};

#endif
