/***************************************************************************
                          kmenurl.cpp  -  description
                             -------------------
    begin                : Wed Jul 10 2002
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

#include "kmenurl.h"

KMenURL::KMenURL(){
  url_name = new QString( "" );
}

KMenURL::~KMenURL(){
  delete url_name;
}

/** set url */
void KMenURL::setURLName( QString uname ){
  url_name = new QString( uname );
}

/** get url */
QString KMenURL::getURLName(){
  return *url_name;
}
/** No descriptions */
bool KMenURL::setURLArguments( QProcess *procs ){
  if( *url_name != "" ) {
  procs->addArgument( *url_name );
    return TRUE;
  }
  else return FALSE;
}
