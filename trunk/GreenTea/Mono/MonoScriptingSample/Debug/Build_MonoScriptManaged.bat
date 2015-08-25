@ECHO OFF
SET SRC_PATH=..\MonoScriptManaged
SET SRC_ALL=%SRC_PATH%\TestPrint.cs %SRC_PATH%\Mathf.cs %SRC_PATH%\GTVector2.cs %SRC_PATH%\GTVector3.cs %SRC_PATH%\GTGameObject.cs %SRC_PATH%\GTBehaviour.cs %SRC_PATH%\GTInternalCall.cs

DEL MonoScriptManaged.Mono.dll
DEL MonoScriptManaged.Mono.dll.mdb

@ECHO ON

%MONO_BIN%\mcs.bat -target:library %SRC_ALL% -out:MonoScriptManaged.Mono.dll -debug

PAUSE
