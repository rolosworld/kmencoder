/***************************************************************************
                          kmenfile.cpp  -  description
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

#include "kmenfile.h"

KMenFile::KMenFile(){
  file_name = new QString( "" );
}

KMenFile::~KMenFile(){
  delete file_name;
}

/** set file name */
void KMenFile::setFileName( QString fname ){
  file_name = new QString( fname );
}

/** set file name */
QString KMenFile::getFileName(){
  return *file_name;
}
/** No descriptions */
bool KMenFile::setFileArguments( QProcess *procs ){
  if( *file_name != "" ) {
  procs->addArgument( *file_name );
  return TRUE;
  }
  else {
  QMessageBox::critical( 0, "Error",
                        "Specify INput File Name!" );
  return FALSE;
  }
}
