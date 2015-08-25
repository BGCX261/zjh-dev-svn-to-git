@ECHO OFF

SET SRC_PATH=..\GreenTea.Engine.Managed.Test
SET SRC_ALL=%SRC_PATH%\StartPointClass.cs

DEL GreenTeaEngineTest.dll
DEL GreenTeaEngineTest.dll.mdb

@ECHO ON

%MONO_BIN%\mcs.bat -r:GreenTeaEngine.dll -target:library %SRC_ALL% -out:GreenTeaEngineTest.dll -debug

PAUSE
