/***************************************************************************
                          kmensound.cpp  -  description
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

#include "kmensound.h"

KMenSound::KMenSound(){
  sound_on = TRUE;
  setSoundLameOpts( "Average",
                    "128",
                    "",
                    "100",
                    0 );
}

KMenSound::~KMenSound(){
  delete sound_lame_opts;
}

/** No descriptions */
void KMenSound::setSoundON( bool sound ){
  sound_on = sound;
}

/** No descriptions */
void KMenSound::setSoundLameOpts( QString bitrate_mode,
                                  QString bitrate,
                                  QString mode,
                                  QString cmpratio,
                                  int volgain ){
  QString bit_mode;
  QString br = ":br=";
  QString ratio = ":ratio=";
  QString vol = ":vol=";
  QString mod = ":mode=";
  QString tmp, tmp2, tmp3, tmp4;
  tmp4 = ":q=0";

  bool mode_on = FALSE;

  tmp3 = tmp3.setNum( volgain );

  if( bitrate_mode == "Variable" )
    tmp = "vbr=2";
  if( bitrate_mode == "Average" )
    tmp = "abr";
  if( bitrate_mode == "Constant" )
    tmp = "cbr";

  tmp = tmp + br;
  tmp = tmp + bitrate;
  tmp = tmp + ratio;
  tmp = tmp + cmpratio;
  tmp = tmp + vol;
  tmp = tmp + tmp3;

  if( mode == "Stereo" ){
    tmp2 = "0";
    mode_on = TRUE;
  }
  if( mode == "Joint Stereo" ) {
    tmp2 = "1";
    mode_on = TRUE;
  }
  if( mode == "Dual Channel" ) {
    tmp2 = "2";
    mode_on = TRUE;
  }
  if ( mode == "Mono" ) {
    tmp2 = "3";
    mode_on = TRUE;
  }
  if( mode_on == TRUE ){
    tmp = tmp + mod;
    tmp = tmp + tmp2;
  }

  tmp = tmp + tmp4;

  sound_lame_opts = new QString( tmp );
}

/** No descriptions */
QString KMenSound::getSoundLameOpts(){
  return *sound_lame_opts;
}

/** No descriptions */
bool KMenSound::getSoundON(){
  return sound_on;
}
/** No descriptions */
void KMenSound::setSoundArguments( QProcess *procs, KMenComboBox sel ){
  //Set Sound Options
  if( sound_on == FALSE )
    procs->addArgument( "-nosound" );
  else {
    if( sound_encode == TRUE ) {
      procs->addArgument( "-oac" );

      if( sel.getAudioQuality() == aqEXACTCOPY )
        procs->addArgument( "copy" );

      if( sel.getAudioQuality() == aqMP3 ) {
        procs->addArgument( "mp3lame" );
        procs->addArgument( "-lameopts" );
        procs->addArgument( *sound_lame_opts );
      }
    }
  }
}

/** No descriptions */
void KMenSound::setSoundEncode_enabled( bool enable ){
  sound_encode = enable;
}
