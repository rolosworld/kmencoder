/***************************************************************************
                          kmenvideo.h  -  description
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

#ifndef KMENVIDEO_H
#define KMENVIDEO_H

#include <qstring.h>
#include <qprocess.h>
#include "comboboxvalues.h"

/**
  *@author Rolando
  */

class KMenVideo {
public: 
	KMenVideo();

	~KMenVideo();

  /** No descriptions */
  void setVideoHeight( QString height );

  /** No descriptions */
  void setVideoWidth( QString width );

  /** No descriptions */
  void setVideoAspectMode( QString aspect );

  /** No descriptions */
  QString getVideoWidth();

  /** No descriptions */
  QString getVideoHeight();

  /** No descriptions */
  void setVideoLavcOpts( QString codec,
                         bool quality,
                         QString bitrate );

  /** No descriptions */
  void setVideoDivx4Opts( QString quality,
                          QString bitrate );

  /** No descriptions */
  QString getVideoLavcOpts();

  /** No descriptions */
  QString getVideoDivx4Opts();

  /** No descriptions */
  QString getVideoAspectMode();
  /** No descriptions */
  void setVideoArguments( QProcess *procs, KMenComboBox sel );
  /** No descriptions */
  void setVideoEncode_enabled( bool enabled );

protected: // Protected attributes

  /**  */
  QString *video_aspect;

  /**  */
  QString *video_lavc_opts;

  /**  */
  QString *video_divx4_opts;

  /**  */
  QString *video_width;

  /**  */
  bool video_encode;
  /**  */
  QString *video_height;
};

#endif
