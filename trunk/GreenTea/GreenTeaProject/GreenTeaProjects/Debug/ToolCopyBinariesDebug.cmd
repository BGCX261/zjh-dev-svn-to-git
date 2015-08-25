SET DEST_PATH="..\..\cocos2dx\Debug.win32"

CALL ToolCleanup.cmd
COPY/Y %DEST_PATH%\*.dll
COPY/Y %DEST_PATH%\*.pdb
