/***************************************************************************
                          kmencoder.h  -  description
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

#ifndef KMENCODER_H
#define KMENCODER_H

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <kapp.h>

#include <qwidget.h>
#include <qtextedit.h>

#include "kmencoderdlg.h"

/** KMencoder is the base class of the project */
class KMencoder : public kmencoderdlgForm
{
  Q_OBJECT 
  public:
    /** construtor */
    KMencoder(QWidget* parent=0, const char *name=0);
    /** destructor */
    ~KMencoder();
};
#endif
