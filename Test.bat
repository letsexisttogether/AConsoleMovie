@echo off
setlocal

set BUILD_DIR=Build
set TEST_EXECUTABLE=AConsoleTests.exe

cmake --build %BUILD_DIR%

if errorlevel 1 exit /b %errorlevel%

echo.
echo Launching tests...
echo.

"%BUILD_DIR%\Test\%CONFIG%\%TEST_EXECUTABLE%" %* --gtest_color=yes

exit /b %errorlevel%
