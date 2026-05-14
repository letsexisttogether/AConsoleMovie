@echo off
setlocal

set BUILD_DIR=Build
set GENERATOR=Ninja
set CONFIG=%1

if "%CONFIG%"=="" set CONFIG=Debug

cmake -S . -B %BUILD_DIR% ^
  -G %GENERATOR% ^
  -DCMAKE_BUILD_TYPE=%CONFIG% ^
  -DCMAKE_EXPORT_COMPILE_COMMANDS=ON

if errorlevel 1 exit /b %errorlevel%

echo.
echo Configured %CONFIG% successfully.
