/***************************************************************************
                          kmenerror.cpp  -  description
                             -------------------
    begin                : Sun Jul 14 2002
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

#include "kmenerror.h"

KMenError::KMenError( QString err ) {
  err_str = err;
}
KMenError::~KMenError(){
}
/** No descriptions */
void KMenError::PrintError(){
     QMessageBox::critical( 0, tr2i18n( "Error" ), tr2i18n( "An Error Ocurred, with: " ) + err_str );
}
