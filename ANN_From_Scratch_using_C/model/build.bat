@echo off
cd src
gcc main.c -o main -std=c11
if %errorlevel% neq 0 (
    echo "Compilation failed!"
    pause
    exit /b
)
echo "Running the program..."
main.exe

pause


