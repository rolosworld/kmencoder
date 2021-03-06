/***************************************************************************
                          kmenvideo.cpp  -  description
                             -------------------
    begin                : Mon Jul 8 2002
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

#include "kmenvideo.h"

KMenVideo::KMenVideo(){
  video_aspect = new QString( "16:9" );
  video_height = new QString( "480" );
  video_width = new QString( "640" );
  video_bitrate = new QString( "16000" );
  video_divx4_opts = new QString( "br=16000:q=5" );
  video_lavc_opts = new QString( "vcodec=mpeg4:vhq:vbitrate=16000" );
  video_pass_count = 0;
  video_pass = FALSE;
  video_pass_renamed = TRUE;
}

KMenVideo::~KMenVideo(){
  delete video_aspect;
  delete video_divx4_opts;
  delete video_height;
  delete video_width;
  delete video_lavc_opts;
  delete video_bitrate;
}

/** No descriptions */
void KMenVideo::setVideoAspectMode( QString aspect ){
  video_aspect = new QString( aspect );
}

/** No descriptions */
void KMenVideo::setVideoWidth( QString width ){
  video_width = new QString( width );
}

/** No descriptions */
void KMenVideo::setVideoHeight( QString height ){
  video_height = new QString( height );
}

/** No descriptions */
void KMenVideo::setVideoDivx4Opts( QString quality ){
  QString bit = "br=";
  QString q = ":q=";
  QString tmp = bit;

  tmp = tmp + *video_bitrate;
  tmp = tmp + q;
  tmp = tmp + quality;

  video_divx4_opts = new QString( tmp );
}

/** No descriptions */
void KMenVideo::setVideoLavcOpts( QString codec,
                                  bool quality ){
  QString vcodec = "vcodec=";
  QString vbitrate = ":vbitrate=";
  QString vhq = ":vhq";
  QString tmp = vcodec;
  QString tmp2;

  if( codec == "DivX 4/5" )       tmp2 = "mpeg4";
  if( codec == "DivX 3" )         tmp2 = "msmpeg4";
  if( codec == "Old Real Video" ) tmp2 = "rv10";
  if( codec == "Mpeg1" )          tmp2 = "mpeg1video";
  if( codec == "Motion JPG" )     tmp2 = "mjpeg";
  if( codec == "H263" )           tmp2 = "h263";
  if( codec == "H263 Plus" )      tmp2 = "h23p";

  tmp = tmp + tmp2;
  tmp = tmp + vbitrate;
  tmp = tmp + *video_bitrate;

  if( quality == TRUE)
    tmp = tmp + vhq;

  video_lavc_opts = new QString( tmp );

}

/** No descriptions */
QString KMenVideo::getVideoHeight(){
  return *video_height;
}

/** No descriptions */
QString KMenVideo::getVideoWidth(){
  return *video_width;
}

/** No descriptions */
QString KMenVideo::getVideoAspectMode(){
  return *video_aspect;
}

/** No descriptions */
QString KMenVideo::getVideoDivx4Opts(){
  return *video_divx4_opts;
}

/** No descriptions */
QString KMenVideo::getVideoLavcOpts(){
  return *video_lavc_opts;
}
/** No descriptions */
void KMenVideo::setVideoArguments( QProcess *procs, KMenComboBox sel ){
  QString passarg;
  // Set the video image size options.
  if( sel.getVideo() != videoAUTO ) {
   procs->addArgument( "-vop" );
   procs->addArgument( "scale" );
   procs->addArgument( "-zoom" );
    if( sel.getVideo() == videoASPECT ){
         procs->addArgument( "-aspect" );
         procs->addArgument( *video_aspect );
    }
    if( sel.getVideo() == videoWIDTH ) {
         procs->addArgument( "-xy" );
         procs->addArgument( *video_width );
    }
    if( sel.getVideo() == videoWIDTHHEIGHT ) {
         procs->addArgument( "-x" );
         procs->addArgument( *video_width );
         procs->addArgument( "-y" );
         procs->addArgument( *video_height );
    }
  }
  // Set the video encoding options
  if( video_encode == TRUE ) {
    procs->addArgument( "-ovc" );

    if( video_pass != TRUE) {
      if( sel.getVideoQuality() == vqEXACTCOPY )
       procs->addArgument( "copy" );

      if( sel.getVideoQuality() == vqDIVX4 ) {
       procs->addArgument( "divx4" );
       procs->addArgument( "-divx4opts" );
       procs->addArgument( *video_divx4_opts );
     }

     if( sel.getVideoQuality() == vqLAVC ) {
       procs->addArgument( "lavc" );
       procs->addArgument( "-lavcopts" );
       procs->addArgument( *video_lavc_opts );
     }
    }

    if( video_pass == TRUE && video_pass_count > 0 ) {
      if( video_pass_count == 2 ) {
         video_pass_count = 0;
         passarg = "2";
         video_pass = FALSE;
         video_pass_renamed = FALSE ;
     }
      else {
          video_pass_count++;
          passarg = "1";
      }

      procs->addArgument( "lavc" );
      procs->addArgument( "-lavcopts" );
      *video_lavc_opts =  *video_lavc_opts + ":vpass=";
      *video_lavc_opts =  *video_lavc_opts + passarg;
      procs->addArgument( *video_lavc_opts );
      }
   else if( video_pass ==TRUE && video_pass_count == 0 ) {
     procs->addArgument( "frameno" );
     video_pass_count++;
   }
  }
}

/** No descriptions */
void KMenVideo::setVideoEncode_enabled( bool enabled ){
  video_encode = enabled;
}

/** No descriptions */
void KMenVideo::setVideoPass( bool enabled ){
  video_pass = enabled;
}

/** No descriptions */
bool KMenVideo::getVideoPass(){
  return video_pass;
}

/** No descriptions */
void KMenVideo::setVideoBitrate( QString bitrate ){
  video_bitrate = new QString( bitrate );
}

/** No descriptions */
QString KMenVideo::getVideoBitrate(){
  return *video_bitrate;
}
/** No descriptions */
unsigned short KMenVideo::getVideoPassCount(){
  return video_pass_count;
}
/** No descriptions */
void KMenVideo::setVideoPassCount( unsigned short count ){
  video_pass_count = count;
}
/** No descriptions */
void KMenVideo::setVideoPassRenamed( bool done ){
  video_pass_renamed = done;
}
/** No descriptions */
bool KMenVideo::getVideoPassRenamed(){
  return video_pass_renamed;
}
