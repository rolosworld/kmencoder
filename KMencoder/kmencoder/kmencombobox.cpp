/***************************************************************************
                          kmencombobox.cpp  -  description
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

#include "kmencombobox.h"

KMenComboBox::KMenComboBox(){
  cb_endpos = 0;

  cb_audio_quality = 0;

  cb_video_quality = 0;

  cb_video = 0;

  cb_source = 0;
}
KMenComboBox::~KMenComboBox(){
}

/** No descriptions */
void KMenComboBox::setSource( int src ){
  cb_source = src;
}

/** No descriptions */
void KMenComboBox::setVideo( int vid ){
  cb_video = vid;
}

/** No descriptions */
void KMenComboBox::setVideoQuality( int vid_q ){
  cb_video_quality = vid_q;
}

/** No descriptions */
void KMenComboBox::setAudioQuality( int aud_q ){
  cb_audio_quality = aud_q;
}

/** No descriptions */
void KMenComboBox::setEndPos( int epos ){
  cb_endpos = epos;
}

/** No descriptions */
int KMenComboBox::getSource(){
  return cb_source;
}

/** No descriptions */
int KMenComboBox::getVideo(){
  return cb_video;
}

/** No descriptions */
int KMenComboBox::getVideoQuality(){
  return cb_video_quality;
}

/** No descriptions */
int KMenComboBox::getAudioQuality(){
  return cb_audio_quality;
}

/** No descriptions */
int KMenComboBox::getEndPos(){
  return cb_endpos;
}
