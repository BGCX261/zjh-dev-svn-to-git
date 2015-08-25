SET SRC_PATH=..\CSharpSamples
SET SRC_ALL=%SRC_PATH%\TestCase.cs %SRC_PATH%\TestCaseMath.cs

DEL TestCase.dll
DEL TestCase.dll.mdb

%MONO_BIN%\mcs.bat -target:library %SRC_ALL% -out:TestCase.Mono.dll -debug
