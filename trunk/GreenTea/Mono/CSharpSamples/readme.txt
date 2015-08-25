*Compile CS file as exe
 Mono-3.2.3\bin\mcs SampleFile.cs

*Compile CS file as dll
 Sample 1: Mono-3.2.3\bin\mcs -target:library SampleFile.cs
 Sample 2: Mono-3.2.3\bin\mcs -r:UnityEngine.dll -target:library SampleFile.cs

*Run
 Mono-3.2.3\bin\mono SampleFile.exe
