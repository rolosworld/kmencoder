/***************************************************************************
                          sdvdinfo.cpp  -  description
                             -------------------
    begin                : Sat Jul 6 2002
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

#include "sdvdinfo.h"

SDVDinfo::SDVDinfo(){
  i_d = new QString( "" );
  lang = new QString( "" );
}

SDVDinfo::~SDVDinfo(){
delete i_d;
delete lang;
}

/** Set the Substitle ID */
void SDVDinfo::setID( QString id ){
i_d = new QString( id );
}

/** Set the Substitle Language */
void SDVDinfo::setLanguage( QString language ){
lang = new QString( language );
}

/** Set the Substitle Index */
void SDVDinfo::setIndex( int index ){
idx = index;
}

/** Returns the Substitle ID */
QString SDVDinfo::getID(){
return *i_d;
}

/** Returns the Substitle Language */
QString SDVDinfo::getLanguage(){
return *lang;
}

/** Returns the Substitle Index */
int SDVDinfo::getIndex(){
return idx;
}
