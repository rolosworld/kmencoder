/***************************************************************************
                          kmenmisc.cpp  -  description
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

#include "kmenmisc.h"

KMenMisc::KMenMisc(){
  misc_cache = new QString( "8000" );
  misc_endpos = new QString( "650mb" );
  misc_noskip = FALSE;
  misc_verbose = FALSE;

}

KMenMisc::~KMenMisc(){
  delete misc_endpos;
  delete misc_cache;
}

/** No descriptions */
void KMenMisc::setMiscVerbose( bool verbose ){
  misc_verbose = verbose;
}

/** No descriptions */
void KMenMisc::setMiscNoSkip( bool noskip ){
  misc_noskip = noskip;
}

/** No descriptions */
void KMenMisc::setMiscEndPosMega( QString mega ){
  misc_endpos = new QString( mega );
}

/** No descriptions */
void KMenMisc::setMiscEndPosTime( QString hour,
                                  QString minute,
                                  QString second ){
  int h = hour.toInt();
  int m = minute.toInt();
  int s = second.toInt();

  QString cero = "0";
  QString dp = ":";
  QString tmp;

  if( h < 10 ) hour = cero + hour;
  if( m < 10 ) minute = cero + minute;
  if( s < 10 ) second = cero + second;

  tmp = hour + dp;
  tmp = tmp + minute;
  tmp = tmp + dp;
  tmp = tmp + second;

  misc_endpos = new QString( tmp );
}

/** No descriptions */
void KMenMisc::setMiscCache( QString cache ){
  misc_cache = new QString( cache );
}

/** No descriptions */
QString KMenMisc::getMiscCache(){
  return *misc_cache;
}

/** No descriptions */
bool KMenMisc::getMiscNoSkip(){
  return misc_noskip;
}

/** No descriptions */
QString KMenMisc::getMiscEndPos(){
  return *misc_endpos;
}

/** No descriptions */
bool KMenMisc::getMiscVerbose(){
  return misc_verbose;
}
/** No descriptions */
void KMenMisc::setMiscArguments( QProcess *procs ){
  procs->addArgument( "-cache" );
  procs->addArgument( *misc_cache );

  if( misc_verbose == TRUE )
    procs->addArgument( "-v" );

  if( misc_noskip == TRUE )
    procs->addArgument( "-noskip" );

  if( misc_endpos_enabled == TRUE ) {
    procs->addArgument( "-endpos" );
    procs->addArgument( *misc_endpos );
  }
}
/** No descriptions */
void KMenMisc::setEndPos_enabled( bool enabled ){
  misc_endpos_enabled = enabled;
}
/** No descriptions */
bool KMenMisc::getEndPos_enabled(){
return misc_endpos_enabled;
}
