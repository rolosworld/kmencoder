/***************************************************************************
                          sdvdinfo.h  -  description
                             -------------------
    begin                : Sat Jul 6 2002
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

#ifndef SDVDINFO_H
#define SDVDINFO_H

#include <qstring.h>
/**
  *@author Rolando
  */

class SDVDinfo {
public: 
	SDVDinfo();
	~SDVDinfo();

  /** Get the Subtitles Index */
  int getIndex();

  /** Get the Subtitles Language */
  QString getLanguage();

  /** Get the Subtitles ID */
  QString getID();

  /** Set the Subtitles Index */
  void setIndex( int index );

  /** Set the Subtitles Language */
  void setLanguage( QString language );

  /** Set the Subtitles ID */
  void setID( QString id );

protected: // Protected attributes

  /** Stores the Subtitles id */
  QString *i_d;

  /** Stores the Substitle language */
  QString *lang;

  /** Stores the Substitle index */
  int idx;
};

#endif
