@echo off

rem Set the output executable name
set OUTPUT=main

rem Compile the source files
gcc -o %OUTPUT% src\main.c src\math_functions.c -I include -std=c11

rem Check for compilation errors
if %ERRORLEVEL% neq 0 (
    echo "Error during compilation!"
    exit /b %ERRORLEVEL%
)

echo "Compilation successful!"

rem Run the compiled executable
%OUTPUT%

pause

