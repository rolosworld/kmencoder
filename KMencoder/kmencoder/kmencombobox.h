/***************************************************************************
                          kmencombobox.h  -  description
                             -------------------
    begin                : Tue Jul 9 2002
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

#ifndef KMENCOMBOBOX_H
#define KMENCOMBOBOX_H


/**
  *@author Rolando
  */

class KMenComboBox {
public: 
	KMenComboBox();
	~KMenComboBox();
  /** No descriptions */
  void setEndPos( int epos );
  /** No descriptions */
  void setAudioQuality( int aud_q );
  /** No descriptions */
  void setVideoQuality( int vid_q );
  /** No descriptions */
  void setVideo( int vid );
  /** No descriptions */
  void setSource( int src );

  /** No descriptions */
  int getEndPos();
  /** No descriptions */
  int getAudioQuality();
  /** No descriptions */
  int getVideoQuality();
  /** No descriptions */
  int getVideo();
  /** No descriptions */
  int getSource();

protected: // Protected attributes
  /**  */
  int cb_endpos;
  /**  */
  int cb_audio_quality;
  /**  */
  int cb_video_quality;
  /**  */
  int cb_video;
  /**  */
  int cb_source;
};

#endif
