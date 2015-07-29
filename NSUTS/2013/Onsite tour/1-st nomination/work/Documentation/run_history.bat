@echo off
if [%1]==[] (
    set HISTORYFILE=History.bin
) else (
    set HISTORYFILE=%1
)

SimpleVis\SimpleVis.exe -h %HISTORYFILE%
