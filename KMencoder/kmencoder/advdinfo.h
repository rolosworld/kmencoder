/***************************************************************************
                          advdinfo.h  -  description
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

#ifndef ADVDINFO_H
#define ADVDINFO_H

#include <qstring.h>

/**
  *@author Rolando
  */

class ADVDinfo {
public: 
	ADVDinfo();
	~ADVDinfo();

  /** Set Audio Channel Index */
  void setIndex( int index );

  /** Set Audio Channel Format.  ie.  ac3  dts  */
  void setFormat( QString format );

  /** Set Audio Channel Language */
  void setLanguage( QString language );

  /** Set Audio Channels Channel */
  void setChannel( QString channel );

  /** Returns the current Audio Channel Index */
  int getIndex();

  /** Returns the current Audio Channel Format. */
  QString getFormat();

  /** No Returns the current Audio Channel Language */
  QString getLanguage();

  /** Returns the current Audio Channel Channel. */
  QString getChannel();

protected: // Protected attributes

  /** Stores the Audio Channels Channel */
  QString *chan;

  /** Stores the Audio Channels Language */
  QString *lang;

  /** Stores the Audio Channels Format */
  QString *frmt;

  /** Stores the Audio Channels Index */
  int indx;
};

#endif
