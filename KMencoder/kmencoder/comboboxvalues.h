/***************************************************************************
                          comboboxvalues.h  -  description
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

#ifndef COMBOBOXVALUES_H
#define COMBOBOXVALUES_H

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif
#include "kmencombobox.h"

enum SRCCOMBOBOX { srcSELECT_SOURCE, srcFILE, srcPLAYLIST, srcURL, srcTV, srcVCD, srcDVD };

enum VIDEOCOMBOBOX { videoAUTO, videoASPECT, videoWIDTH, videoWIDTHHEIGHT };

enum VQUALITYCOMBOBOX { vqEXACTCOPY, vqDIVX4, vqLAVC };

enum AQUALITYCOMBOBOX { aqEXACTCOPY, aqMP3 };

enum EPOSITIONCOMBOBOX { epMEGABYTES, epTIME };

static SRCCOMBOBOX selected;
static VIDEOCOMBOBOX vselected;
static VQUALITYCOMBOBOX vqselected;
static AQUALITYCOMBOBOX aqselected;
static EPOSITIONCOMBOBOX epselected;

#endif
