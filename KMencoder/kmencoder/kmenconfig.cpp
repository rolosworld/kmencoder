/***************************************************************************
                          kmenconfig.cpp  -  description
                             -------------------
    begin                : Fri Jul 5 2002
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
#include "kmenconfig.h"

KMenConfig::KMenConfig(){
  enabled_input = new QString( "NONE" );
  exec = new QString( "mencoder" );
  out_file_name = new QString( "" );
  encode = TRUE;
}

KMenConfig::~KMenConfig(){
  delete enabled_input;
  delete exec;
  delete out_file_name;
}

/** No descriptions */
void KMenConfig::setEnabled( QString einput ){
  enabled_input = new QString( einput );
}
/** No descriptions */
QString KMenConfig::getEnabled(){
  return *enabled_input;
}

/** No descriptions */
QString KMenConfig::getExec(){
  return *exec;
}

/** No descriptions */
void KMenConfig::setPreview( bool start_encode ){
  encode = start_encode;
  if( encode == TRUE )
    exec = new QString( "mencoder" );
  else
    exec = new QString( "mplayer" );
}

/** No descriptions */
bool KMenConfig::getPreview(){
  return encode;
}

/** No descriptions */
void KMenConfig::setOutputFileName( QString file_name ){
  out_file_name = new QString( file_name );
}

/** No descriptions */
QString KMenConfig::getOutputFileName(){
  return *out_file_name;
}
/** No descriptions */
bool KMenConfig::setOutputFileArguments( QProcess *procs ){
  if( *out_file_name != "" ) {
  procs->addArgument( "-o" );
    procs->addArgument( *out_file_name );
    return TRUE;
  }
  else return FALSE;
}
