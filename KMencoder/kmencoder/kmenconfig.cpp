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

#define TEST_ARGS 0
unsigned short KMenConfig::stopped;
unsigned short KMenConfig::proc_loaded;

KMenConfig::KMenConfig(){
  enabled_input = new QString( "NONE" );
  exec = new QString( "mencoder" );
  out_file_name = new QString( "movie.avi" );
  encode = TRUE;
  conf_pass = FALSE;
  true_out_file_name = new QString( *out_file_name );
  tmp = new QString( "" );
  d = new QDir( "/" );
}

KMenConfig::~KMenConfig(){
  delete enabled_input;
  delete exec;
  delete out_file_name;
  delete true_out_file_name;
  delete tmp;
  delete d;
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
  if( encode == TRUE ) {
#if TEST_ARGS == 0
    exec = new QString( "mencoder" );
#else
    exec = new QString( "../test" );
#endif
  }
  else
    exec = new QString( "mplayer" );
}

/** No descriptions */
bool KMenConfig::getPreview(){
  return encode;
}

/** No descriptions */
void KMenConfig::setOutputFileName( QString file_name ){
  true_out_file_name = new QString( file_name );
}

/** No descriptions */
QString KMenConfig::getOutputFileName(){
  return *true_out_file_name;
}
/** No descriptions */
bool KMenConfig::setOutputFileArguments( QProcess *procs ){
  if( *out_file_name != "" ) {
    procs->addArgument( "-o" );
    if( conf_pass == FALSE )
      procs->addArgument( *out_file_name );
    else {
      procs->addArgument( "frameno.avi" );
      conf_pass = FALSE;
    }
    return TRUE;
  }
  else return FALSE;
}

/** No descriptions */
void KMenConfig::setConfPass( bool enabled ){
  conf_pass = enabled;
}

/** No descriptions */
void KMenConfig::deleteTmpFiles(){
  tmp = new QString( d->path() + "/" );

  d->setFilter( QDir::Files | QDir::Hidden );
  d->setSorting( QDir::Size | QDir::Reversed );

  const QFileInfoList *list = d->entryInfoList();
  QFileInfoListIterator it( *list );
  QFileInfo *fi;

  while ( (fi = it.current()) != 0 ) {
    *tmp = *tmp + fi->fileName();
    if( d->remove( fi->fileName() ) != TRUE )
      QMessageBox::critical( 0, tr2i18n( "Error" ), tr2i18n( "An Error Ocurred, removing: " ) + *tmp );

    ++it;
  }
}
/** No descriptions */
void KMenConfig::setConfOutRename(){
  if( d->rename( *out_file_name, *true_out_file_name, TRUE ) != TRUE )
      QMessageBox::critical( 0, tr2i18n( "Error" ), tr2i18n( "An Error Ocurred, renaming: " ) + *tmp );
}
/** No descriptions */
void KMenConfig::setConfDir( QString dir ){
  d = new QDir( dir );
}
/** No descriptions */
QString KMenConfig::getConfDir(){
  return d->path();
}
