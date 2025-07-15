@echo off
set "FOLDER=%1"

if "%FOLDER%"=="" (
    echo ❌ Error: Please provide a folder name like "012_find-pivot-index"
    exit /b
)

mkdir "%FOLDER%"
cd "%FOLDER%"
type nul > brute.cpp
type nul > optimized.cpp
type nul > notes.txt

:: Open the folder in VSCode (if installed and code command is available)
code .

cd ..
git add "%FOLDER%"
git commit -m "Add %FOLDER% solution"
git push

echo ✅ "%FOLDER%" created and pushed.
