@echo off
echo Setting up a git environment...
set PATH=C:\Program Files\Git\bin;%PATH%
git status
echo Setting up a Qt environment...
set QTDIR=C:\Qt\4.7.1
echo -- QTDIR set to C:\Qt\4.7.1
set PATH=C:\Qt\4.7.1\bin;%PATH%
echo -- Added C:\Qt\4.7.1\bin to PATH
set QMAKESPEC=win32-msvc2010
echo -- QMAKESPEC set to "win32-msvc2010"
%comspec% /k ""C:\Program Files\Microsoft Visual Studio 10.0\VC\vcvarsall.bat"" x86
