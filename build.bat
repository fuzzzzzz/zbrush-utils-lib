cl /EHsc /c .\src\*.cpp /I .\include /Fo".\obj\\"
::rebuild dynamic library "zbrushlib.dll"
link /DLL /OUT:zbrushlib.dll .\obj\*.obj
xcopy /s /y "zbrushlib.dll" "D:\Imaging\Pixologic\ZBrush 2020\ZStartup\ZPlugs64\debug"
pause