/***************************************************************************
                          kmenurl.h  -  description
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

#ifndef KMENURL_H
#define KMENURL_H

#include <qstring.h>
#include <qprocess.h>
#include <qmessagebox.h>

/**
  *@author Rolando
  */

class KMenURL {
public: 
	KMenURL();

	~KMenURL();

/** No descriptions */
QString getURLName();

/** No descriptions */
void setURLName( QString uname );
  /** No descriptions */
bool setURLArguments( QProcess *procs );

protected: // Protected attributes

  /**  */
  QString *url_name;
};

#endif
