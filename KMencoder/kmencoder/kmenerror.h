/***************************************************************************
                          kmenerror.h  -  description
                             -------------------
    begin                : Sun Jul 14 2002
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

#ifndef KMENERROR_H
#define KMENERROR_H

#include <qstring.h>
#include <qmessagebox.h>
#include <klocale.h>

/**
  *@author Rolando
  */

class KMenError {
public: 
	KMenError( QString err );
	virtual ~KMenError();
  /** No descriptions */
  virtual void PrintError();

protected: // Protected attributes
  /**  */
  QString err_str;
};

#endif
