/***************************************************************************
                          main.cpp  -  description
                             -------------------
    begin                : Wed Jun 26 02:34:03 AST 2002
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

#include <kcmdlineargs.h>
#include <kaboutdata.h>
#include <klocale.h>
#include "kmenconfig.h"
#include "kmencoder.h"

static const char *description =
	I18N_NOOP("KMencoder");
// INSERT A DESCRIPTION FOR YOUR APPLICATION HERE
	
	
static KCmdLineOptions options[] =
{
  { 0, 0, 0 }
  // INSERT YOUR COMMANDLINE OPTIONS HERE
};

int main(int argc, char *argv[])
{
  KMenConfig::proc_loaded = 0;
  KMenConfig::stopped = 0;

  KAboutData aboutData( "kmencoder", I18N_NOOP( "KMencoder" ),
                                                VERSION, description, KAboutData::License_GPL,
                                                "(c) 2002, Rolando Gonzalez", 0 , 0 , "rolando8@prtc.net" );

  aboutData.addAuthor( "Rolando Gonzalez", 0, "rolando8@prtc.net" );

  aboutData.addAuthor( "Josue Irizarry", 0, "josue@vidalinux.com" );
  aboutData.setTranslator( I18N_NOOP( "_: NAME OF TRANSLATORS\nYour names" ) ,I18N_NOOP( "_: EMAIL OF TRANSLATORS\nYour emails" ) );

  KCmdLineArgs::init( argc, argv, &aboutData );
  KCmdLineArgs::addCmdLineOptions( options ); // Add our own options.

  KApplication a;
  KMencoder *kmencoder = new KMencoder();
  a.setMainWidget(kmencoder);
  kmencoder->show();  

  return a.exec();
}
