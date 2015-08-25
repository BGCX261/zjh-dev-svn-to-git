@ECHO OFF
SET SRC_PATH=..\MonoScriptManaged.Test
SET SRC_ALL=%SRC_PATH%\TC_TestPrint.cs %SRC_PATH%\BehaviourTest.cs

DEL MonoScriptManaged.Test.Mono.dll
DEL MonoScriptManaged.Test.Mono.dll.mdb

@ECHO ON

%MONO_BIN%\mcs.bat -r:MonoScriptManaged.Mono.dll -target:library %SRC_ALL% -out:MonoScriptManaged.Test.Mono.dll -debug

PAUSE
