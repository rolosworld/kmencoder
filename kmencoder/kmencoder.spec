# This spec file was generated using Kpp
# If you find any problems with this spec file please report
# the error to ian geiser <geiseri@msoe.edu>
Summary:   MPlayer/MEncoder FrontEnd
Name:      kmencoder
BuildPrereq: mplayer
Version:   0.1.2
Release:   1
Copyright: GPL
Vendor:    Rolando Gonzalez <rolando8@prtc.net>
Url:       http://www.sourceforge.net/projects/kmencoder

Packager:  Rolando Gonzalez <rolando8@prtc.net>
Group:     multimedia
Source:    kmencoder-0.1.2.tar.bz2
BuildRoot: %{_tmppath}/%{name}-buildroot

%description
MPlayer/MEncoder FrontEnd

%prep
%setup
CFLAGS="$RPM_OPT_FLAGS" CXXFLAGS="$RPM_OPT_FLAGS" ./configure \
#                --build=i386-linux --host=i386-linux --target=i386-linux  \
                $LOCALFLAGS
%build
# Setup for parallel builds
numprocs=`egrep -c ^cpu[0-9]+ /proc/stat || :`
if [ "$numprocs" = "0" ]; then
  numprocs=1
fi

make -j$numprocs

%install
make install-strip DESTDIR=$RPM_BUILD_ROOT

cd $RPM_BUILD_ROOT
find . -type d | sed '1,2d;s,^\.,\%attr(-\,root\,root) \%dir ,' > $RPM_BUILD_DIR/file.list.kmencoder
find . -type f | sed 's,^\.,\%attr(-\,root\,root) ,' >> $RPM_BUILD_DIR/file.list.kmencoder
find . -type l | sed 's,^\.,\%attr(-\,root\,root) ,' >> $RPM_BUILD_DIR/file.list.kmencoder

%clean
rm -rf $RPM_BUILD_ROOT/*
rm -rf $RPM_BUILD_DIR/kmencoder
rm -rf ../file.list.kmencoder


%files -f ../file.list.kmencoder
