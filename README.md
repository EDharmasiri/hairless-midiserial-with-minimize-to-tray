This is a fork of ProjectGus' Hairless MIDI Serial (https://projectgus.github.io/hairless-midiserial/).

If you've build a custom midi controller using a microbit/arduino/microcontroller, you've probably been directed to installing Hairless MIDI Serial and LoopMIDI in order to bridge your controller to your DAW.

This fork extends the functionality of the original program by including a 'Start minimised to tray' checkbox, and updating the codebase to work with QT 5.15.2.
If you keep your controller plugged into your PC at all times, you can add the program to your startup folder and use it without having an additional window open.

![image](https://user-images.githubusercontent.com/12570294/149517727-a0fa5256-3285-404e-9dd9-e0e84f81e267.png)

This release was built with Qt 5.15.2.

# To build a static release of QT (on Windows)
Instructions modified from [this guide](https://wiki.qt.io/Building_a_static_Qt_for_Windows_using_MinGW)
## Prerequisites
- MinGW-w64 8.1.0 (I used MSYS2)
- Python 2.7.18
- Ruby 2.6.9 (Newer versions will probably work)
- Perl (Strawberry 5.32)
- Unzipping tool
- [Qt 5.15.2 source code](https://download.qt.io/archive/qt/5.15/5.15.2/single/) (Pick the zip file)

## Build Instructions
1. Extract the source code zip file
2. Open command prompt
3. Navigate to the extracted folder
4. Run this snippet: 
```configure -static -release -platform win32-g++ -opensource -qt-tiff -confirm-license -prefix "C:\Qt\Static\5.15.2" -qt-zlib -qt-libpng -qt-webp -qt-libjpeg -qt-freetype  -no-opengl -skip qt3d -skip qtactiveqt -skip qtandroidextras -skip qtcharts -skip qtconnectivity -skip qtdatavis3d -skip qtdeclarative -skip qtdoc -skip qtgamepad -skip qtlocation -skip qtlottie -skip qtmacextras -skip qtmultimedia -skip qtnetworkauth -skip qtpurchasing -skip qtquick3d -skip qtquickcontrols -skip qtquickcontrols2 -skip qtquicktimeline -skip qtremoteobjects -skip qtscript -skip qtsensors -skip qtspeech -skip qtsvg -skip qtwayland -skip qtwebglplugin -skip qtwebview -skip webengine -make libs -nomake tools -nomake examples -nomake tests```
5. Run ```mingw32-make```
6. Run ```mingw32-make install```
7. Configure the kit in QT using [this guide](https://tadeubento.com/2020/qt-static-builds-under-windows/)

# Description from the original program below.

# Building Hairless Bridge from source

(Note again, prebuilt versions *are available for download* at the above URL.)

Hairless uses git submodules for library dependencies, so you should use `git clone --recursive URL` when cloning from Github. Alternatively, you can run `git submodule update --init` in order to fetch the submodules to an already-cloned directory.

~~Hairless Midiserial Bridge release 0.4 was built with Qt 4.7.3. It's also been built and run under Qt 4.7.4 & 4.8.6. Newer Qt version 5.0 will probably require code changes in order to compile and/or run.


The Qt package should contain all dependencies, the graphical IDE "Qt Creator" or the program "qmake" can be used to compile the project hairless-midiserial.pro.

~~On Windows I recommend building with the [MingGW compiler](http://www.mingw.org/), Visual Studio has not been tested. Neither the MinGW site nor Qt's new owners Digia still distribute older MinGW builds, and MinGW 4.7 is too new for precompiled Qt 4.7.x, so it can be a bit hard to find a prebuilt combination that work. Recently I downloaded `mingw-static-4.4.5-all.7z` from [this Google Code project](https://code.google.com/p/qp-gcc/downloads/list), and can confirm that works.

(For the Windows release builds I actually [cross-build under Linux using wine, as described here](http://projectgus.com/2011/09/developing-qt-apps-for-windows-using-linux-wine/).)

# Libraries

* [qextserialport](https://code.google.com/p/qextserialport/) is hosted on Github and is linked into the source tree as a git submodule.

* [The RtMidi library](https://github.com/thestk/rtmidi) is hosted on Github and is linked into the source tree as a git submodule.

Both libraries are small so they compiled as source files directly into Hairless Bridge, not linked as libraries.

# Release builds

The official releases are static linked, so they've actually been built against Qt versions that were compiled from source, configured with `-static` for static linking.
