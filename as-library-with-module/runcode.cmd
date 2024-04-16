@echo off

@set PROJECT_PATH=%~dp0
@set ROOT_PATH=%~dp0..
call "%ROOT_PATH%\helpers\env_vc.cmd" 17
set PATH=%LLVM%\bin;%PATH%

code "%PROJECT_PATH%" | exit /b
