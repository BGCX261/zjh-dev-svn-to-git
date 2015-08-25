@ECHO OFF
SET SRC_PATH=..\GreenTea.Engine.Managed\GreenTea.Engine
SET SRC_ALL=%SRC_PATH%\GTDebug.cs

DEL GreenTeaEngine.dll
DEL GreenTeaEngine.dll.mdb

@ECHO ON

%MONO_BIN%\mcs.bat -target:library %SRC_ALL% -out:GreenTeaEngine.dll -debug

PAUSE
