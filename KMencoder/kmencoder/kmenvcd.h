/***************************************************************************
                          kmenvcd.h  -  description
                             -------------------
    begin                : Fri Jul 19 2002
    copyright            : (C) 2002 by Rolando  Gonzalez
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

#ifndef KMENVCD_H
#define KMENVCD_H

#include <qstring.h>
#include <qprocess.h>

/**
  *@author Rolando
  */

class KMenVCD {

public:
	KMenVCD();

	~KMenVCD();

  /** No descriptions */
  void setVCDDevice( QString device );

  /** No descriptions */
  void setVCDTrack( QString track );

  /** No descriptions */
  QString getVCDTrack();

  /** No descriptions */
  QString getVCDDevice();

  /** No descriptions */
  void setVCDArguments( QProcess *procs );

protected: // Protected attributes

  /**  */
  QString* vcd_device;

  /**  */
  QString* vcd_track;
};

#endif
