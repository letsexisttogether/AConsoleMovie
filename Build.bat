@echo off
setlocal

set BUILD_DIR=Build

cmake --build %BUILD_DIR%

if errorlevel 1 exit /b %errorlevel%

echo.
echo Build completed successfully.
