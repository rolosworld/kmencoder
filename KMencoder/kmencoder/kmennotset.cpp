/***************************************************************************
                          kmennotset.cpp  -  description
                             -------------------
    begin                : Sun Jul 14 2002
    copyright            : (C) 2002 by Rolando  Gonzalez
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

#include "kmennotset.h"

KMenNotSet::KMenNotSet( QString err ) : KMenError( err ){
}

KMenNotSet::~KMenNotSet(){
}

/** No descriptions */
void KMenNotSet::PrintError(){
  QString tmp =  KMenError::err_str;
  tmp = tmp  + " Not Set!";
  QMessageBox::critical( 0, "Error",  tmp  );
}
