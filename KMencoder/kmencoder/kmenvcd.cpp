/***************************************************************************
                          kmenvcd.cpp  -  description
                             -------------------
    begin                : Fri Jul 19 2002
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

#include "kmenvcd.h"

KMenVCD::KMenVCD(){
  vcd_device = new QString( "/dev/cdrom" );
  vcd_track = new QString( "1" );
}

KMenVCD::~KMenVCD(){
  delete vcd_device;
  delete vcd_track;
}

/** No descriptions */
void KMenVCD::setVCDDevice( QString vcddevice ){
  vcd_device = new QString( vcddevice );
}

/** No descriptions */
QString KMenVCD::getVCDDevice(){
  return *vcd_device;
}

/** No descriptions */
QString KMenVCD::getVCDTrack(){
  return *vcd_track;
}

/** No descriptions */
void KMenVCD::setVCDTrack( QString track ){
  vcd_track = new QString( track );
}

/** No descriptions */
void KMenVCD::setVCDArguments( QProcess *procs ){
  procs->addArgument( "-cdrom-device" );
  procs->addArgument( *vcd_device );
  procs->addArgument( "-vcd" );
  procs->addArgument( *vcd_track );
}
