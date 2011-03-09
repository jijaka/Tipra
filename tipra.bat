@echo off
echo Setting up a git environment...
set PATH=C:\Program Files\Git\bin;%PATH%
git status
echo Setting up a Qt environment...
set QTDIR=C:\Qt\4.7.1
echo -- QTDIR set to %QTDIR%
set PATH=%QTDIR%\bin;%PATH%
echo -- Added %QTDIR%\bin to PATH
set QMAKESPEC=win32-msvc2010
echo -- QMAKESPEC set to %QMAKESPEC%
echo Project directory is %TPR_SRC%
%comspec% /k ""C:\Program Files\Microsoft Visual Studio 10.0\VC\vcvarsall.bat"" x86
