/***************************************************************************
                          kmendvd.h  -  description
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

#ifndef KMENDVD_H
#define KMENDVD_H

#include <qstring.h>
#include <qprocess.h>

/**
  *@author Rolando
  */

class KMenDVD {
public: 
	KMenDVD();
	~KMenDVD();

  /** Set the DVD Titles */
  void setTitles( QString titles );

  /** Set the DVD Chapters */
  void setChapters( QString chapters );

  /** Get the DVD Angles as int */
  int getAngles();

  /** Get the DVD Chapters as int */
  int getChapters();

  /** Get the DVD Titles as int */
  int getTitles();

  /** Set the DVD Angles */
  void setAngles( QString angles );

  /** Get the SELECTED DVD Title as QString */
  QString getDVDTitle_selected();

  /** Get the SELECTED DVD Angle as QString */
  QString getDVDAngle_selected();

  /** Get the SELECTED DVD Chapter as QString */
  QString getDVDChapter_selected();

  /** Set the SELECTED dvd angle */
  void setDVDAngle_selected( QString angle );

  /** Set the SELECTED dvd title */
  void setDVDTitle_selected( QString title );

  /** Set the SELECTED dvd chapters */
  void setDVDChapter_selected( QString first_chapter, QString last_chapter );

  /** No descriptions */
  QString getDVDAudioChannel();

  /** No descriptions */
  QString getDVDSubTitle();

  /** No descriptions */
  void setDVDAudioChannel( QString audio_chan );

  /** No descriptions */
  void setDVDSubTitle( QString subtitle );

  /** No descriptions */
  QString getDVDSubPos();

 /** No descriptions */
  void setDVDSubPos( int subpos );

  /** No descriptions */
  void setDVDDevice( QString device );

  /** No descriptions */
  QString getDVDDevice();

  /** No descriptions */
  QString getDVD1stChapter();

  /** No descriptions */
  QString getDVDLastChapter();

  /** No descriptions */
  void setDVDArguments( bool, bool, QProcess *);

protected: // Protected attributes

  /** Stores the DVD Titles as int */
  int dvdtitles;

  /** Stores the DVD Chapters as int */
  int dvdchapters;

  /** Stores the DVD Angles as int */
  int dvdangles;

  /** Store the DVD subtitle as QString */
  QString *dvd_subtitle;

  /** Stores the DVD Titles as QString */
  QString *dvd_title;

  /** Stores the DVD Chapters as QString */
  QString *dvd_chapter;

  /** Stores the DVD Angles and sub position as QString */
  QString *dvd_subpos;
  QString *dvd_angle;

  /**  */
  QString *dvd_device;

  /**  */
  QString *dvd_1st_chapter;

  /** Stores the DVD Audio Channel as QString */
  QString *dvd_audio_chan;

  /**  */
  QString *dvd_last_chapter;
};

#endif
