/***************************************************************************
                          kmenmisc.h  -  description
                             -------------------
    begin                : Mon Jul 8 2002
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

#ifndef KMENMISC_H
#define KMENMISC_H

#include <qstring.h>
#include <qprocess.h>

/**
  *@author Rolando
  */

class KMenMisc {
public: 
	KMenMisc();

	~KMenMisc();

  /** No descriptions */
  void setMiscNoSkip( bool noskip );

  /** No descriptions */
  void setMiscVerbose( bool verbose );

  /** No descriptions */
  void setMiscCache( QString cache );

  /** No descriptions */
  void setMiscEndPosTime( QString hour,
                          QString minute,
                          QString second );

  /** No descriptions */
  void setMiscEndPosMega( QString mega );

  /** No descriptions */
  bool getMiscVerbose();

  /** No descriptions */
  QString getMiscEndPos();

  /** No descriptions */
  bool getMiscNoSkip();

  /** No descriptions */
  QString getMiscCache();

  /** No descriptions */
  void setMiscArguments( QProcess *);

  /** No descriptions */
  void setEndPos_enabled( bool enabled );

  /** No descriptions */
  bool getEndPos_enabled();
  /** No descriptions */
  bool getMiscVerbose_enabled();

protected: // Protected attributes

  /**  */
  bool misc_noskip;

  /**  */
  QString *misc_endpos;

  /**  */
  QString *misc_cache;

  /**  */
  bool misc_endpos_enabled;
  /**  */
  bool misc_verbose;
};

#endif
