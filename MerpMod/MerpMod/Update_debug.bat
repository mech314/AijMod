@echo on
set TARGETROM=A8DK100I
set BUILDCONFIG=Switch_Testing
set PROJNAME=MerpMod

if not exist ".\%TARGETROM%\%BUILDCONFIG%" mkdir ".\%TARGETROM%\%BUILDCONFIG%"

for %%P in (".\*.patch") do del %%P
copy "C:\dev\MerpMod\MerpMod\build\%TARGETROM%\%PROJNAME%.mot" ".\%TARGETROM%\%BUILDCONFIG%\partial-patch.mot"
Copy "..\..\..\SubaruRoms\OEM\%TARGETROM%.bin" ".\%TARGETROM%\%BUILDCONFIG%\patched.bin"
C:\dev\MerpMod\SharpTune.exe rommod hewbuild "C:\dev\MerpMod\MerpMod\TestRom\A8DK100I\Switch_Testing\partial-patch.mot" "C:\dev\MerpMod\MerpMod\TestRom\A8DK100I\Switch_Testing\oem.bin" Switch_Testing

move oem.bin .\%TARGETROM%\%BUILDCONFIG%\
move reverted.bin .\%TARGETROM%\%BUILDCONFIG%\
move *.patch .\%TARGETROM%\%BUILDCONFIG%\
rmdir /s /q %BUILDCONFIG%
