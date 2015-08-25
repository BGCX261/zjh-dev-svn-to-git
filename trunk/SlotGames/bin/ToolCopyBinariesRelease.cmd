SET COCOS2D_NAME="cocos2d-x"
SET DEST_PATH="..\TankBattle\third_party\%COCOS2D_NAME%\Release.win32"

CALL ToolCleanup.cmd
COPY/Y %DEST_PATH%\*.dll
