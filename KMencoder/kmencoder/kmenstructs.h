/***************************************************************************
                          kmenstructs.h  -  description
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
#ifndef KMENSTRUCTS_H
#define KMENSTRUCTS_H
/**
  *@author Rolando
  */

#include <qstring.h>
#include <qprocess.h>
#include "sdvdinfo.h"
#include "advdinfo.h"

//This Struct Stores Enable Status of IMPORTANT Widgets.
struct KMenabled {
  //IOPUT Stuff.
  bool KMenselect;
    bool KMenfile;
    bool KMenplaylist;
    bool KMenurl;
    bool KMentv;
    bool KMenvcd;
    bool KMendvd;

  bool KMenorequester;

  //File Stuff.
  bool KMenfilegroup;
    bool KMenfilerequester;

  //Play List Stuff.
  bool KMenplaylsgroup;

  //URL Stuff.
  bool KMenurlgroup;

  //TV Stuff.
  bool KMentvgroup;

  //VCD Stuff.
  bool KMenvcdgroup;

  //DVD Stuff.
  bool KMendvdgroup;
    bool KMendvdvgroup;
      bool KMendvdtitlespin;
      bool KMendvd1stchpspin;
      bool KMendvdlastchapspin;
      bool KMendvdanglespin;

      bool KMendvdsublangcheck;
      bool KMendvdsublangbox;

      bool KMendvdsubposslide;

    bool KMendvdagroup;
      bool KMendvdaudiobox;
      bool KMendvdlangline;
      bool KMendvdformatline;


  //Video Stuff.
  bool KMenvsizebox;
    bool KMenvsizeauto;
    bool KMenvsizeaspect;
    bool KMenvsizewidth;
    bool KMenvsizewidthheight;

  bool KMenvaspectbox;

  bool KMenvwidthheightgroup;
    bool KMenvwidthspin;
    bool KMenvheightspin;

  bool KMenvbitrate;

  bool KMenvdivx4optionsgroup;
    bool KMenvdivx4spin;

  bool KMenvqualitybox;
    bool KMenvqualityexact;
    bool KMenvqualitydivx4;
    bool KMenvqualitylavc;

  bool KMenvlavcoptionsgroup;

    bool KMenvlavccodecbox;
    bool KMenvlavccodecdivx5;
    bool KMenvlavccodecdivx3;
    bool KMenvlavccodecoldreal;
    bool KMenvlavccodecmpeg1;
    bool KMenvlavccodecmjpg;
    bool KMenvlavccodech263;
    bool KMenvlavccodech263plus;

  bool KMenvlavchquality;

  //Sound Stuff.
  bool KMenacheck;

  bool KMenaqualitybox;
    bool KMenaqualityexact;
    bool KMenaqualitymp3;

  bool KMenalamegroup;
    bool KMenalamebitratebox;
    bool KMenalamebitratevariable;
    bool KMenalamebitrateaverage;
    bool KMenalamebitrateconstant;

  bool KMenalamebitratespin;

  bool KMenalamemodebox;
    bool KMenalamemodeauto;
    bool KMenalamemodestereo;
    bool KMenalamemodejointstereo;
    bool KMenalamemodedualchannel;
    bool KMenalamemodemono;

  bool KMenalamecompressspin;

  bool KMenalamevolumeslide;

  //Misc Stuff.
  bool KMenmisccachespin;
  bool KMenmiscdvddevrequester;
  bool KMenmiscnoskipcheck;
  bool KMenmiscverbosecheck;

  bool KMenmiscendposcheck;
  bool KMenmiscendposchecked;
  bool KMenmiscendposgroup;
    bool KMenmiscendposbox;
      bool KMenmiscendposmegab;
      bool KMenmiscendpostime;

    bool KMenmiscendposmegabspin;
    bool KMenmiscendpostimehspin;
    bool KMenmiscendpostimemspin;
    bool KMenmiscendpostimesspin;

  //BOTTOM Stuff.
  bool KMenstart;
  bool KMenstop;
  bool KMenquit;
  bool KMenbottomlist;
  bool KMenbottomtext;
};

static ADVDinfo dvdAinfo[25];
static SDVDinfo dvdSinfo[25];

static struct KMenabled KMproceed;

static QString dvd_device_path;
static QString file_name;
static QProcess *proc;

#endif
