/***************************************************************************
                          kmennotset.h  -  description
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

#ifndef KMENNOTSET_H
#define KMENNOTSET_H

#include <kmenerror.h>
#include <qstring.h>
#include <qmessagebox.h>
/**
  *@author Rolando
  */

class KMenNotSet : public KMenError  {
public: 
	KMenNotSet( QString err );
	virtual ~KMenNotSet();
  /** No descriptions */
  virtual void PrintError();
};

#endif
