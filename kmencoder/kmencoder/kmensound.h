/***************************************************************************
                          kmensound.h  -  description
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

#ifndef KMENSOUND_H
#define KMENSOUND_H

#include <qstring.h>
#include <qprocess.h>
#include "comboboxvalues.h"

/**
  *@author Rolando
  */

class KMenSound {
public: 

	KMenSound();

	~KMenSound();

  /** No descriptions */
  void setSoundON( bool sound );

  /** No descriptions */
  void setSoundLameOpts( QString bitrate_mode,
                         QString bitrate,
                         QString mode,
                         QString cmpratio,
                         int volgain );

  /** No descriptions */
  QString getSoundLameOpts();

  /** No descriptions */
  bool getSoundON();
  /** No descriptions */
  void setSoundArguments( QProcess *procs, KMenComboBox sel );
  /** No descriptions */
  void setSoundEncode_enabled( bool snd_enc );

  /**  */
  void setSoundPass( bool enabled );
  /** No descriptions */
  void setSoundPassCount( unsigned short count );

protected: // Protected attributes

  /**  */
  bool sound_on;

  /**  */
  QString *sound_lame_opts;
  /**  */
  bool sound_encode;
  /**  */
  unsigned short sound_pass_count;
  /**  */
  bool sound_pass;
};
#endif
