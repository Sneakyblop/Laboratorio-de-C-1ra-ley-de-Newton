@echo off
chcp 65001 >nul
gcc -std=c99 -Wall -Wextra -pedantic main.c validaciones.c simulador.c -lm -o artemis.exe
if errorlevel 1 (
    echo No se pudo compilar el simulador.
    exit /b 1
)
echo Compilacion terminada. Ejecuta artemis.exe para iniciar el simulador.
