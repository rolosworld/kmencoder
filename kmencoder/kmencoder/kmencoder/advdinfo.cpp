/***************************************************************************
                          advdinfo.cpp  -  description
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

#include "advdinfo.h"

ADVDinfo::ADVDinfo(){
}
ADVDinfo::~ADVDinfo(){
  delete chan;
  delete lang;
  delete frmt;
}
/** Set the Audio Channel Channel */
void ADVDinfo::setChannel( QString channel ){
  chan = new QString( channel );
}
/** Set the Audio Channel Language */
void ADVDinfo::setLanguage( QString language ){
  lang = new QString( language );
}
/** Set the Audio Channel Format */
void ADVDinfo::setFormat( QString format ){
  frmt = new QString( format );
}
/** Set the Audio Channel Index */
void ADVDinfo::setIndex( int index ){
  indx = index;
}
/** Get the Audio Channel Channel */
QString ADVDinfo::getChannel(){
  return *chan;
}
/** Get the Audio Channel Language */
QString ADVDinfo::getLanguage(){
  return *lang;
}
/** Get the Audio Channel Format */
QString ADVDinfo::getFormat(){
  return *frmt;
}
/** Get the Audio Channel Index */
int ADVDinfo::getIndex(){
  return indx;
}
