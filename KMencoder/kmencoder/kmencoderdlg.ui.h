/****************************************************************************
** ui.h extension file, included from the uic-generated form implementation.
**
** If you wish to add, delete or rename slots use Qt Designer which will
** update this file, preserving your code. Create an init() slot in place of
** a constructor, and a destroy() slot in place of a destructor.
*****************************************************************************/

void kmencoderdlgForm::start()
{
    start_encode = TRUE;
    endpos = endpositionCheckBox->isChecked();
    turn.setOutputFileName( otputKURLRequester->url() );
    
    prebegin();   
}

void kmencoderdlgForm::readFromStdout()
{
    //Write to the STDOUT TextEdit
    outputTextEdit->append( proc->readStdout() ); 
}



void kmencoderdlgForm::manageSourceComboBox()
{
    if( sourceComboBox->currentText () == "Select Source")
	selected = srcSELECT_SOURCE;
    if( sourceComboBox->currentText () == "File")
	selected = srcFILE;
    if( sourceComboBox->currentText () == "PlayList")
	selected = srcPLAYLIST;
    if( sourceComboBox->currentText () == "URL")
	selected = srcURL;
    if( sourceComboBox->currentText () == "TV")
	selected = srcTV;
    if( sourceComboBox->currentText () == "VCD")
	selected = srcVCD;
    if( sourceComboBox->currentText () == "DVD")
	selected = srcDVD;
    
    kmenselected.setSource( selected );
    
    switch( kmenselected.getSource() ) {
	case srcSELECT_SOURCE: {
	    break;
	}
	case srcFILE: {
	    turn.setEnabled( "FILE" );
	    default_settings();
	    
	    getFileGroupStuff();
	    break;
	}
	case srcPLAYLIST: {
	    turn.setEnabled( "PLAYLIST" );
	    default_settings();
	    break;
	}
	case srcURL: {
	    turn.setEnabled( "URL" );
	    default_settings();
	    break;
	}
	case srcTV: {
	    turn.setEnabled( "TV" );
	    default_settings();    
	    break;
	}
	case srcVCD: {
	    turn.setEnabled( "VCD" );
	    default_settings();
	    
	    vcd_scan();
	    break;
	}
	case srcDVD: {
	    turn.setEnabled( "DVD" );
	    default_settings();
	     
	    //Clear the DVD info combo boxes
	    achannelComboBox->clear();
	    subtitleComboBox->clear();

	    dvd_scan();
	    break;
	}
	default: {
	    default_settings();
	    break;
	}
    }
  
    setgroups();
    
}


void kmencoderdlgForm::helpkPushButton()
{
helpMenu = new KHelpMenu(this, KGlobal::instance()->aboutData(), false);

HelpKPushButton->setAutoRepeat( FALSE );
HelpKPushButton->setPopup(helpMenu->menu());
}


void kmencoderdlgForm::default_settings()
{
    // proc_not_loaded = TRUE;
    
    //Set the Default Disabled CheckBoxes.
    setendpositiongroup( FALSE );
    
    //Set the DEFAULT Disabled GroupBoxes.
    setdvdgroup( FALSE );
    setfilegroup( FALSE ); 
    setplaylistgroup( FALSE );
    seturlgroup( FALSE ); 
    setvcdgroup( FALSE );
    settvgroup( FALSE ); 
    setvideogroup( FALSE );
    lamemp3GroupBox->setEnabled( FALSE ); 

    //Set the Default data values.
    cacheSpinBox->setValue( (miscinfo.getMiscCache()).toInt() ); 
    divx4qualitySpinBox->setValue( 5 );
    videobitrateSpinBox->setValue( 800 );
    lameSpinBox->setValue( 128 );
    lamecompresratioSpinBox->setValue( 1 );
    endpositionmegaSpinBox->setValue( 650 );
    endpositionhourSpinBox->setValue( 0 );
    endpositionminutesSpinBox->setValue( 0 );
    endpositionsecondsSpinBox->setValue( 0 );
        
    //Set the Default Checked CheckBoxes.
    noskipCheckBox->setChecked( FALSE );
    verboseCheckBox->setChecked( FALSE );
    nosoundCheckBox->setChecked( FALSE );
    lavchighqualityCheckBox->setChecked( FALSE );
    
    //Set the Default ComboBox item.
    videosizeComboBox->setCurrentItem( 0 );
    aspectComboBox->setCurrentText( videoinfo.getVideoAspectMode() );
    vqualityComboBox->setCurrentItem( 0 );
    audioqualityComboBox->setCurrentItem( 0 );
    bitrateComboBox->setCurrentItem( 0 );
    amodeComboBox->setCurrentItem( 0 );
    endpositionComboBox->setCurrentItem( 0 );
    lavccodecComboBox->setCurrentItem( 0 );
    
    //Set the Default Slider position.
    subtitlepositionSlider->setValue( 0 );
    volumeSlider->setValue( 0 );
    
    //Set Combo Box Defaults.
    manageEnableControls();
    
    manageVideoSizeComboBox(); 
    manageWidthChanged();
    manageDivx4CodecChanged();
    manageLavcCodecChanged();
    
    manageAudioQualityCombobox();
    manageMp3Changed();
    
    manageEndPositionComboBox();
    manageMiscChanged();
    
    //manageSelectAudioChannel();
    //manageSubTitlesComboBox();
    //manageTitleChanged();
    
    manageSoundOnCheckBox();
    
    manageDVDChanged();
    manageCdromChanged();
}


void kmencoderdlgForm::dvd_scan()
{
    new_proc();
    
    QString home_env = getenv( "HOME" );
    home_env = home_env + "/.kmencoder";
    
    if( access( home_env, R_OK | W_OK | X_OK | F_OK ) != 0 ){
	if( mkdir( home_env,  S_IRWXU ) != 0 ) {
	    QMessageBox::critical( 0, "Error", "Error with config directory!" );
	    return;
	}
    }
    home_env = home_env + "/tmp";
    if( access( home_env, R_OK | W_OK | X_OK | F_OK ) != 0 ) {
	if( mkdir( home_env,  S_IRWXU ) != 0 ) {
	    QMessageBox::critical( 0, "Error", "Error with tmp directory!" );
	    return;
	}
    }
    home_env = home_env + "/kmencoder_test.avi";
    
    proc->addArgument( "mencoder" );
    proc->addArgument( "-dvd-device" );
    proc->addArgument( dvdinfo.getDVDDevice() );
    proc->addArgument( "-dvd" );
    proc->addArgument( "1" ) ;
    proc->addArgument( "-v" );
    proc->addArgument( "-o" );
    proc->addArgument( home_env );

    proc->setCommunication ( 0x04 );

    connect( proc, SIGNAL(readyReadStderr()),
	     this, SLOT(getDVDInfo() ));    

    //Sart the process.
    if ( !proc->start() ) {
	// error handling
	QMessageBox::critical( 0,
			       "Error",
			       "Could not scan the DVD!" );
    } 
}


void kmencoderdlgForm::manageVideoSizeComboBox()
{
    if(videosizeComboBox->currentText () == "Auto")
	vselected = videoAUTO;
    if(videosizeComboBox->currentText () == "Aspect")
	vselected = videoASPECT;
    if(videosizeComboBox->currentText () == "Width/Auto Height")
	vselected = videoWIDTH;
    if(videosizeComboBox->currentText () == "Width/Height")
	vselected = videoWIDTHHEIGHT;
    
    kmenselected.setVideo( vselected );
    
    switch( vselected ) {
	case videoAUTO: {
	    aspectComboBox->setEnabled( FALSE );
	    widthheightGroupBox->setEnabled( FALSE );
	    videosizeDefaults();
	    break;
	}
	case videoASPECT: {
	    widthheightGroupBox->setEnabled( FALSE );
	    aspectComboBox->setEnabled( TRUE );
	    videosizeDefaults();
	    break;
	}
	case videoWIDTH: {
	    aspectComboBox->setEnabled( FALSE ); 
	    widthheightGroupBox->setEnabled( TRUE );
	    widthSpinBox->setEnabled( TRUE );
	    heightSpinBox->setEnabled( FALSE ); 
	    videosizeDefaults();
	    break;
	}
	case videoWIDTHHEIGHT: {
	    aspectComboBox->setEnabled( FALSE ); 
	    widthheightGroupBox->setEnabled( TRUE );
	    widthSpinBox->setEnabled( TRUE );
	    heightSpinBox->setEnabled( TRUE ); 
	    videosizeDefaults();
	    break;
	}
	default: break;
    }    
    manageWidthChanged();
    
}


void kmencoderdlgForm::videosizeDefaults()
{
    widthSpinBox->setValue( ( videoinfo.getVideoWidth() ).toInt() );
    heightSpinBox->setValue( ( videoinfo.getVideoHeight() ).toInt() );
}


void kmencoderdlgForm::videoQualityOutput()
{
    if(vqualityComboBox->currentText () == "Exact Copy")
	vqselected = vqEXACTCOPY;
    if(vqualityComboBox->currentText () == "DivX 4")
	vqselected = vqDIVX4;
    if(vqualityComboBox->currentText () == "lavc")
	vqselected = vqLAVC;
    
    kmenselected.setVideoQuality( vqselected );
    
    switch( vqselected ){
	case vqEXACTCOPY: {
	    videobitrateSpinBox->setEnabled( FALSE ); 
	    divx4GroupBox->setEnabled( FALSE ); 
	    lavcGroupBox->setEnabled( FALSE ); 
	    aspectComboBox->setEnabled( FALSE );
	    widthheightGroupBox->setEnabled( FALSE );
	    videosizeComboBox->setEnabled( FALSE );
	    videosizeComboBox->setCurrentItem( 0 );
//	    videosizeDefaults();
	    break;
	}
	case vqDIVX4: {
	    manageDivx4CodecChanged();
	    
	    videosizeComboBox->setEnabled( TRUE ); 
	    lavcGroupBox->setEnabled( FALSE ); 
	    divx4GroupBox->setEnabled( TRUE ); 
	    videobitrateSpinBox->setEnabled( TRUE );  
	    break;
	}
	case vqLAVC: {
	    manageLavcCodecChanged();
	    
	    videosizeComboBox->setEnabled( TRUE ); 
	    lavcGroupBox->setEnabled( TRUE ); 
	    divx4GroupBox->setEnabled( FALSE ); 
	    videobitrateSpinBox->setEnabled( TRUE );  
	    break;
	}
	default: break;
    }   
}


void kmencoderdlgForm::manageAudioQualityCombobox()
{
    if(audioqualityComboBox->currentText () == "Exact Copy")
	aqselected = aqEXACTCOPY;
    if(audioqualityComboBox->currentText () == "MP3")
	aqselected = aqMP3;
    
    kmenselected.setAudioQuality( aqselected );
    
    switch( aqselected ){
	case aqEXACTCOPY: {
	    lamemp3GroupBox->setEnabled( FALSE ); 
	    break;
	}
	case aqMP3: {
	    manageMp3Changed();
	    
	    lamemp3GroupBox->setEnabled( TRUE ); 	    
	    bitrateComboBox->setEnabled( TRUE ); 
	    lameSpinBox->setEnabled( TRUE ); 
	    amodeComboBox->setEnabled( TRUE ); 
	    lamecompresratioSpinBox->setEnabled( TRUE ); 
	    volumeSlider->setEnabled( TRUE ); 
	    break;
	}
	default: break;
    }   
}


void kmencoderdlgForm::manageEndPositionComboBox()
{
   // manageMiscChanged();
    if(endpositionComboBox->currentText () == "Mega Bytes")
	epselected = epMEGABYTES;
    if(endpositionComboBox->currentText () == "Time")
	epselected = epTIME;
    
    kmenselected.setEndPos( epselected );
    
    switch( epselected ){
	case epMEGABYTES: {
	    endpositionmegaSpinBox->setEnabled( TRUE ); 
	    endpositionhourSpinBox->setEnabled( FALSE ); 
	    endpositionminutesSpinBox->setEnabled( FALSE ); 
	    endpositionsecondsSpinBox->setEnabled( FALSE ); 
	    break;
	}
	case epTIME: {
	    endpositionmegaSpinBox->setEnabled( FALSE ); 
	    endpositionhourSpinBox->setEnabled( TRUE ); 
	    endpositionminutesSpinBox->setEnabled( TRUE ); 
	    endpositionsecondsSpinBox->setEnabled( TRUE ); 	    
	    break;
	}
	default: break;
    }
}


void kmencoderdlgForm::setdvdgroup( bool set_it )
{
    dvdGroupBox->setEnabled( set_it ); 	
    dvdvideoGroupBox->setEnabled( set_it ); 
    dvdaudioGroupBox->setEnabled( set_it ); 
    dvdtittleSpinBox->setEnabled( set_it ); 
    dvdangleSpinBox->setEnabled( set_it ); 
    dvd1stchapterSpinBox->setEnabled( set_it );
    dvdlastchapterSpinBox->setEnabled( set_it );
    enablesubCheckBox->setEnabled( set_it );
    enablesubCheckBox->setChecked( FALSE );
    subtitleComboBox->setDisabled( set_it ); 
    subtitlepositionSlider->setEnabled( set_it ); 
    achannelComboBox->setEnabled( set_it );
    audiolanguageLineEdit->setEnabled( set_it );
    audioformatLineEdit->setEnabled( set_it );
    dvddeviceKURLRequester->setEnabled( TRUE );
	    
    dvdtittleSpinBox->setValue( (dvdinfo.getDVDTitle_selected() ).toInt() );
    dvdangleSpinBox->setValue( (dvdinfo.getDVDAngle_selected() ).toInt() ); 
    dvd1stchapterSpinBox->setValue( (dvdinfo.getDVD1stChapter() ).toInt() ); 
    dvdlastchapterSpinBox->setValue( (dvdinfo.getDVDLastChapter() ).toInt() );
    
    dvddeviceKURLRequester->setURL( dvdinfo.getDVDDevice() );
}


void kmencoderdlgForm::setendpositiongroup( bool set_it )
{
    endpositionCheckBox->setEnabled( set_it  );
   // endpositionComboBox->setEnabled( set_it  );    
   // endpositionGroupBox->setEnabled( set_it  );
    endpositionCheckBox->setChecked( FALSE );
}


void kmencoderdlgForm::setfilegroup( bool set_it )
{
    fileGroupBox->setEnabled( set_it ); 
    fileKURLRequester->setEnabled( set_it );
}


void kmencoderdlgForm::setplaylistgroup( bool set_it )
{
    playlistGroupBox->setEnabled( set_it );
}


void kmencoderdlgForm::seturlgroup( bool set_it )
{
    urlGroupBox->setEnabled( set_it ); 
    urlKURLRequester->setEnabled( set_it );    
}


void kmencoderdlgForm::setvcdgroup( bool set_it )
{
    vcdGroupBox->setEnabled( set_it );
    vcdtrackSpinBox->setEnabled( set_it );
    cdromdeviceKURLRequester->setEnabled( TRUE );
    
    cdromdeviceKURLRequester->setURL( vcdinfo.getVCDDevice() );
}


void kmencoderdlgForm::settvgroup( bool set_it )
{
    tvGroupBox->setEnabled( set_it ); 
}


void kmencoderdlgForm::setvideogroup( bool set_it )
{
    videosizeComboBox->setEnabled( set_it );
    widthheightGroupBox->setEnabled( set_it );
    divx4GroupBox->setEnabled( set_it ); 
    lavcGroupBox->setEnabled( set_it ); 
    videosizeDefaults(); 
}


void kmencoderdlgForm::readFromStderr()
{
    //Write to the STDERR TextEdit
    stderrTextEdit->append( proc->readStderr() ); 
}

void kmencoderdlgForm::getDVDInfo()
{
    //GET Important Info of the DVD.  Titles, chapters, angles, audio channels, subtitles.
    uint i = 0;
    uint j = 0;
    uint audio = 0;
    uint subt = 0;

    KStringHandler catched;
    QString catched2 = "Start";
    QString catched3 = proc->readStderr();
    QString output_text = catched3.simplifyWhiteSpace();

    //Start Searching for mencoder output for info.
    while( output_text.length() > i ) {
	catched2 = catched.word( output_text , i);
	
	if (  catched2 == "There" && catched.word(output_text, i + 3) == "titles" )
	    dvdinfo.setTitles( catched.word(output_text, i + 2) );
	
	if (  catched2 == "There" && catched.word(output_text, i + 3) == "chapters" )
	    dvdinfo.setChapters( catched.word(output_text, i + 2) );
	
	if (  catched2 == "There" && catched.word(output_text, i + 3) == "angles" )
	    dvdinfo.setAngles( catched.word(output_text, i + 2) );
	
	if (  catched2 == "aid:" ) {
	    dvdAinfo[audio].setChannel( catched.word(output_text, i + 1) );
	    dvdAinfo[audio].setLanguage( catched.word(output_text, i - 1) );
	    dvdAinfo[audio].setFormat( catched.word(output_text, i - 3) );
	    dvdAinfo[audio].setIndex( audio );
	    audio++;
	}
	
	if( catched2 == "sid" ) {
	    dvdSinfo[ subt ].setID( catched.word(output_text, i + 2) );
	    dvdSinfo[ subt ].setLanguage( catched.word(output_text, i + 4) );
	    dvdSinfo[ subt ].setIndex( subt );
	    subt++;
	} 
	i++;
    }
    
    //set info limits.
    dvdtittleSpinBox->setMaxValue( dvdinfo.getTitles() ); 
    dvdangleSpinBox->setMaxValue( dvdinfo.getAngles() ); 
    dvd1stchapterSpinBox->setMaxValue( dvdinfo.getChapters() ); 
    dvdlastchapterSpinBox->setMaxValue( dvdinfo.getChapters() ); 
    
    for( j = 0; j < audio; j++)
	achannelComboBox->insertItem( dvdAinfo[j].getChannel() , dvdAinfo[j].getIndex() );
    if(audio != 0)
	manageSelectAudioChannel();
    
    for(j = 0; j < subt; j++)
	subtitleComboBox->insertItem( dvdSinfo[j].getID(), dvdSinfo[j].getIndex() ); 
    if(subt != 0)
	manageSubTitlesComboBox();
}


void kmencoderdlgForm::manageSelectAudioChannel()
{
    bool select = FALSE;
    uint i = 0;
    
    while( !select ){
	if( achannelComboBox->currentText () == dvdAinfo[i].getChannel() ) {
	    dvdinfo.setDVDAudioChannel( achannelComboBox->currentText () );
	    audiolanguageLineEdit->setText( dvdAinfo[i].getLanguage() );
	    audioformatLineEdit->setText( dvdAinfo[i].getFormat() );    
	    select = TRUE;  
	}
	i++;
    }
}


void kmencoderdlgForm::stop()
{
    if( proc_not_loaded == FALSE ) {
	if( proc->isRunning() == TRUE ){
	    proc->tryTerminate();
	    QTimer::singleShot( 5000, proc, SLOT( kill() ) );
	    delete proc;
	    proc_not_loaded = TRUE;
	}
	else {
	    delete proc;
	    proc_not_loaded = TRUE;
	}
    }
}


void kmencoderdlgForm::manageSubTitlesComboBox()
{
    bool select = FALSE;
    uint i = 0;

    while( !select ){
	if( subtitleComboBox->currentText () == dvdSinfo[i].getID() ) {
	    dvdinfo.setDVDSubTitle( subtitleComboBox->currentText () );	    
	    subposLineEdit->setText( dvdSinfo[i].getLanguage() );
	    select = TRUE;  
	}
	i++;
    }
}


void kmencoderdlgForm::manageWidthChanged()
{
    videoinfo.setVideoWidth( widthSpinBox->text() );
    videoinfo.setVideoHeight( heightSpinBox->text() );
    videoinfo.setVideoAspectMode( aspectComboBox->currentText () );
}
	

void kmencoderdlgForm::manageTitleChanged()
{
    dvdinfo.setDVDTitle_selected( dvdtittleSpinBox->text() );
    dvdinfo.setDVDAngle_selected( dvdangleSpinBox->text() );
    dvdinfo.setDVDChapter_selected( dvd1stchapterSpinBox->text(), dvdlastchapterSpinBox->text() );
    dvdinfo.setDVDSubPos( subtitlepositionSlider->value() );
}


void kmencoderdlgForm::manageLavcCodecChanged()
{
    videoinfo.setVideoLavcOpts( lavccodecComboBox->currentText (),
				lavchighqualityCheckBox->isChecked(),
				videobitrateSpinBox->text() );
}


void kmencoderdlgForm::manageDivx4CodecChanged()
{
    videoinfo.setVideoDivx4Opts( divx4qualitySpinBox->text(),
				 videobitrateSpinBox->text() );
}


void kmencoderdlgForm::manageMp3Changed()
{
    soundinfo.setSoundLameOpts( bitrateComboBox->currentText (),
				lameSpinBox->text(),
				amodeComboBox->currentText (),
				lamecompresratioSpinBox->text() ,
				volumeSlider->value() );
}


void kmencoderdlgForm::manageSoundOnCheckBox()
{
    soundinfo.setSoundON( ! nosoundCheckBox->isChecked() );
}


void kmencoderdlgForm::manageMiscChanged()
{
    miscinfo.setMiscNoSkip( noskipCheckBox->isChecked() );
    miscinfo.setMiscVerbose(verboseCheckBox->isChecked()  );
    miscinfo.setEndPos_enabled( endpositionCheckBox->isChecked() );
    
    miscinfo.setMiscCache( cacheSpinBox->text() );
    miscinfo.setMiscEndPosMega( endpositionmegaSpinBox->text() );
    miscinfo.setMiscEndPosTime( endpositionhourSpinBox->text(),
				endpositionminutesSpinBox->text(),
				endpositionsecondsSpinBox->text() );
}


void kmencoderdlgForm::preview()
{
    start_encode = FALSE;
    endpos = FALSE;
    prebegin();
}


void kmencoderdlgForm::begin()
{
    new_proc();
    proc->addArgument( turn.getExec() );
    try {
	switch( kmenselected.getSource() ) {
	    case srcSELECT_SOURCE: {
		throw KMenNotSet( "SOURCE" );
		break;
	    }
	    case srcFILE: {
		if( fileinfo.setFileArguments( proc ) != TRUE )
		    throw KMenNotSet( "INput File" );
		break;
	    }
	    case srcPLAYLIST: {
		break;
	    }
	    case srcURL: {
		if ( urlinfo.setURLArguments( proc ) != TRUE )
		    throw KMenNotSet( "URL Address" ) ;
		break;
	    }
	    case srcTV: {
		break;
	    }
	    case srcVCD: {
		vcdinfo.setVCDArguments( proc );
		break;
	    }
	    case srcDVD: {
		dvdinfo.setDVDArguments( nosoundCheckBox->isChecked(),
					 enablesubCheckBox->isChecked(), proc );
		break;
	    }
	    default: {
		break;
	    }
	}
	
	miscinfo.setMiscArguments( proc );
	
	videoinfo.setVideoArguments( proc, kmenselected );  
	
	soundinfo.setSoundArguments( proc, kmenselected );
	
	if( start_encode == TRUE ) {
	    if( turn.setOutputFileArguments( proc ) != TRUE )
		throw KMenNotSet( "OUTput File" );
	    proc->setCommunication( 0x02 /* | 0x04 */ | 0x08  );
	    
	    //Get Stdout info.
	    connect( proc, SIGNAL(readyReadStdout()),
		     this, SLOT( manageProgressBar( )) );
	    
	    connect( proc, SIGNAL( processExited() ),
		     this, SLOT( manageListBoxDone() ) ); 
	}
	else {    
	    if( miscinfo.getMiscVerbose() == TRUE ) {
		proc->setCommunication( 0x02 /* | 0x04 */ | 0x08  );
		
		connect( proc, SIGNAL(readyReadStdout()),
			 this, SLOT( readFromStdout() ) );
		
		connect( proc, SIGNAL( processExited() ),
			 this, SLOT( manageEnableControls() ) ); 
	    }
	    else connect( proc, SIGNAL( processExited() ),
			  this, SLOT( manageEnableControls() ) ); 
	}
    }
    
    catch ( KMenError& theError )
    {
	stop();
	theError.PrintError();
	return;
    }
    catch ( ... )
    {
	stop();
	QMessageBox::critical( 0, "Error", "Not Identified Error!" );
	return;
    }
    
    //doneListBox->insertStringList( proc->arguments() );
    
    //START process
    if ( !proc->start() ) {
	// error handling
	if( start_encode == TRUE )
	QMessageBox::critical( 0,
			       "Error",
			       "Can't Begin mencoder!" );
	else QMessageBox::critical( 0,
			       "Error",
			       "Can't Begin mplayer!" );
    }  
    else {
	optionsTabWidget->setEnabled( FALSE );
	startPushButton->setEnabled( FALSE );
	previewPushButton->setEnabled( FALSE );
    }  
}


void kmencoderdlgForm::prebegin()
{
	    turn.setPreview( start_encode );

	    videoinfo.setVideoEncode_enabled( start_encode );
	    soundinfo.setSoundEncode_enabled( start_encode );
	    
	    miscinfo.setEndPos_enabled( endpos );
	    videoinfo.setVideoEncode_enabled( start_encode );
	    
	    begin();
	    
	    manageMiscChanged();
}


void kmencoderdlgForm::manageDVDChanged()
{
    dvdinfo.setDVDDevice( dvddeviceKURLRequester->url() );
}


void kmencoderdlgForm::manageListBoxDone()
{
    doneListBox->insertItem( otputKURLRequester->url(), 0 ) ;
    encodingProgressBar->reset();
    //encodingProgressBar->setProgress( 0 );
    progress_on = FALSE;
    manageEnableControls();
}


void kmencoderdlgForm::manageProgressBar()
{
    QString catched = proc->readStdout(); 
    QString output_text = catched.simplifyWhiteSpace();
   ushort indx = output_text.find( '%', 0, TRUE);
    catched = output_text.mid( indx - 2, 2 );
    indx = catched.toInt();
    if( indx > 99) indx = 100;
    if( indx <= 100 && indx > encodingProgressBar->progress()  || progress_on == FALSE )
    encodingProgressBar->setProgress( indx );
    //outputTextEdit->append( output_text );
    progress_on = TRUE;
}


void kmencoderdlgForm::manageEnableControls()
{
    startPushButton->setEnabled( TRUE );
    previewPushButton->setEnabled( TRUE );
    optionsTabWidget->setEnabled( TRUE );
}


void kmencoderdlgForm::getFileGroupStuff()
{
    fileinfo.setFileName( fileKURLRequester->url() );
}


void kmencoderdlgForm::getURLGroupStuff()
{
    urlinfo.setURLName( urlKURLRequester->url() );
}


void kmencoderdlgForm::new_proc()
{
    stop();
    proc = new QProcess( this );
    proc_not_loaded = FALSE;
    proc->setCommunication( 0x02 | 0x04 | 0x08 );
}


void kmencoderdlgForm::setgroups()
{
    setdvdgroup( FALSE );
    setendpositiongroup( FALSE );
    setfilegroup( FALSE );
    setplaylistgroup( FALSE );
    seturlgroup( FALSE );
    setvcdgroup( FALSE );
    settvgroup( FALSE );
 
    switch( kmenselected.getSource() ) {
	case srcFILE: {
	    setfilegroup( TRUE );
	    setendpositiongroup( TRUE );	
	    break;
	}
	case srcPLAYLIST: {
	    setplaylistgroup( TRUE );
	    break;
	}
	case srcURL: {
	    seturlgroup( TRUE );
	    setendpositiongroup( TRUE );
	    break;
	}
	case srcTV: {
	    settvgroup( TRUE );
	    break;
	}
	case srcVCD: {
	    setvcdgroup( TRUE );
	    setendpositiongroup( TRUE );
	    break;
	}
	case srcDVD: {
	    setdvdgroup( TRUE );
	    setendpositiongroup( TRUE );
	    break;
	}
	default: break;
	     }
}


void kmencoderdlgForm::vcd_scan()
{
   new_proc();
    
    QString home_env = getenv( "HOME" );
    home_env = home_env + "/.kmencoder";
    
    if( access( home_env, R_OK | W_OK | X_OK | F_OK ) != 0 ){
	if( mkdir( home_env,  S_IRWXU ) != 0 ) {
	    QMessageBox::critical( 0, "Error", "Error with config directory!" );
	    return;
	}
    }
    home_env = home_env + "/tmp";
    if( access( home_env, R_OK | W_OK | X_OK | F_OK ) != 0 ) {
	if( mkdir( home_env,  S_IRWXU ) != 0 ) {
	    QMessageBox::critical( 0, "Error", "Error with tmp directory!" );
	    return;
	}
    }
    home_env = home_env + "/kmencoder_test.avi";
    
    proc->addArgument( "mencoder" );
    proc->addArgument( "-cdrom-device" );
    proc->addArgument( vcdinfo.getVCDDevice() );
    proc->addArgument( "-vcd" );
    proc->addArgument( "1" ) ;
    proc->addArgument( "-v" );
    proc->addArgument( "-o" );
    proc->addArgument( home_env );

    proc->setCommunication ( 0x04 );

    connect( proc, SIGNAL(readyReadStderr()),
	     this, SLOT(getVCDInfo() ));    

    //Sart the process.
    if ( !proc->start() ) {
	// error handling
	QMessageBox::critical( 0,
			       "Error",
			       "Could not scan the VCD!" );
    } 
}


void kmencoderdlgForm::getVCDInfo()
{
   //GET Important Info of the VCD. tracks 
    QString catched = proc->readStderr(); 
    QString output_text = catched.simplifyWhiteSpace();
    QString track = "track";
   ushort indx = output_text.find( track, 0, TRUE);
    catched = output_text.mid( indx + 6, 2 );
    indx = catched.toInt();
    
    if( catched != NULL ) vcdinfo.setVCDTrack( catched );

    //set info limits.
    vcdtrackSpinBox->setMaxValue( (vcdinfo.getVCDTrack()).toInt() );
    //vcdinfo.setVCDTrack( vcdtrackSpinBox->text() );
}


void kmencoderdlgForm::manageTrackChanged()
{
    vcdinfo.setVCDTrack( vcdtrackSpinBox->text() );
}


void kmencoderdlgForm::manageCdromChanged()
{
    vcdinfo.setVCDDevice( cdromdeviceKURLRequester->url() );
}
