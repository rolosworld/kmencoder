/***************************************************************************
                          kmendvd.cpp  -  description
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

#include "kmendvd.h"

KMenDVD::KMenDVD(){
  dvd_angle = new QString( "1" );
  dvd_audio_chan = new QString( "" );
  dvd_1st_chapter = new QString( "1" );
  dvd_last_chapter = new QString( "0" );
  dvd_chapter = new QString( "1-0" );
  dvd_device = new QString( "/dev/dvd" );
  dvd_subpos = new QString( "" );
  dvd_subtitle = new QString( "" );
  dvd_title = new QString( "1" );
  dvdangles = 1;
  dvdchapters = 1;
  dvdtitles = 1;
}

KMenDVD::~KMenDVD(){
  delete dvd_angle;
  delete dvd_title;
  delete dvd_chapter;
  delete dvd_subpos;
  delete dvd_audio_chan;
  delete dvd_subtitle;
  delete dvd_1st_chapter;
  delete dvd_last_chapter;
  delete dvd_device;
}

/** Set the DVD Titles */
void KMenDVD::setTitles( QString titles ){
  dvdtitles = titles.toInt();
}

/** Set the DVD Chapters */
void KMenDVD::setChapters( QString chapters ){
  dvdchapters = chapters.toInt();
}

/** Set the DVD Angles */
void KMenDVD::setAngles( QString angles ){
  dvdangles = angles.toInt();
}

/** Returns the DVD Titles as int */
int KMenDVD::getTitles(){
  return dvdtitles;
}

/** Returns the DVD Chapters as int */
int KMenDVD::getChapters(){
  return dvdchapters;
}

/** Returns the DVD Angles as int */
int KMenDVD::getAngles(){
  return dvdangles;
}

/** Returns the DVD Title as QString */
QString KMenDVD::getDVDTitle_selected(){
  return *dvd_title;
}

/** Returns the DVD Chapter as QString */
QString KMenDVD::getDVDChapter_selected(){
  return *dvd_chapter;
}

/** Returns the DVD Angle as QString */
QString KMenDVD::getDVDAngle_selected(){
  return *dvd_angle;
}

/** Returns the SELECTED dvd title */
void KMenDVD::setDVDTitle_selected( QString title ){
  dvd_title = new QString( title );
}

/** Returns the SELECTED dvd angle */
void KMenDVD::setDVDAngle_selected( QString angle ){
  dvd_angle = new QString( angle );
}

/** Returns the SELECTED dvd chapter */
void KMenDVD::setDVDChapter_selected( QString first_chapter, QString last_chapter ){
  QString tmp = "-";

  dvd_1st_chapter = new QString( first_chapter );
  dvd_last_chapter = new QString( last_chapter );
  dvd_chapter = new QString;

  *dvd_chapter = *dvd_1st_chapter;
  *dvd_chapter = *dvd_chapter + tmp;
  *dvd_chapter = *dvd_chapter + *dvd_last_chapter;
}

/** Set the SELECTED DVD subtitle */
void KMenDVD::setDVDSubTitle( QString subtitle ){
  dvd_subtitle = new QString( subtitle );
}

/** Set the SELECTED DVD audio channel */
void KMenDVD::setDVDAudioChannel( QString audio_chan ){
  dvd_audio_chan = new QString( audio_chan );
}

/** returns the SELECTED DVD subtitle */
QString KMenDVD::getDVDSubTitle(){
return *dvd_subtitle;
}

/** returns the SELECTED DVD audio channel */
QString KMenDVD::getDVDAudioChannel(){
return *dvd_audio_chan;
}

/** No descriptions */
void KMenDVD::setDVDSubPos( int subpos ){
  QString tmp;
  tmp = tmp.setNum( subpos );
  dvd_subpos = new QString( tmp );
}

/** No descriptions */
QString KMenDVD::getDVDSubPos(){
return *dvd_subpos;
}

/** No descriptions */
void KMenDVD::setDVDDevice( QString device ){
  dvd_device = new QString( device );
}

/** No descriptions */
QString KMenDVD::getDVDDevice(){
  return *dvd_device;
}

/** No descriptions */
QString KMenDVD::getDVD1stChapter(){
  return *dvd_1st_chapter;
}

/** No descriptions */
QString KMenDVD::getDVDLastChapter(){
  return *dvd_last_chapter;
}
/** No descriptions */
void KMenDVD::setDVDArguments( bool audio, bool subt, QProcess *procs ){
  procs->addArgument( "-dvd-device" );
  procs->addArgument( *dvd_device );
  procs->addArgument( "-dvd" );
  procs->addArgument( *dvd_title );

  if( audio != TRUE ) {
    procs->addArgument( "-aid" );
    procs->addArgument( *dvd_audio_chan );
  }

  procs->addArgument( "-dvdangle" );
  procs->addArgument( *dvd_angle );
  procs->addArgument( "-chapter" );
  procs->addArgument( *dvd_chapter );

  if( subt == TRUE ) {
  procs->addArgument( "-sid" );
  procs->addArgument( *dvd_subtitle );
  procs->addArgument( "-subpos" );
  procs->addArgument( *dvd_subpos );
  }
}
