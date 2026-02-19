@echo off
setlocal EnableExtensions EnableDelayedExpansion

cd /d "%~dp0"

set EXE=game.exe
set SRC=*.cpp
set INC=include
set LIB=lib

echo ==========================
echo Build: %SRC% -> %EXE%
echo Dir  : %CD%
echo ==========================

if not exist "%SRC%" (
  echo ERROR: "%SRC%" not found
  pause
  exit /b 1
)

if not exist "%INC%\raylib.h" (
  echo ERROR: "%INC%\raylib.h" not found
  pause
  exit /b 1
)

if not exist "%LIB%\libraylib.a" (
  echo ERROR: "%LIB%\libraylib.a" not found
  pause
  exit /b 1
)

g++ "%SRC%" -o "%EXE%" -I "%INC%" -L "%LIB%" -lraylib -lopengl32 -lgdi32 -lwinmm
if errorlevel 1 (
  echo.
  echo Build FAILED.
  pause
  exit /b 1
)

echo.
echo Build OK. Running...
echo.

REM Run directly so errors show here
"%CD%\%EXE%"

echo.
echo Program exited with code %errorlevel%.
pause

endlocal
