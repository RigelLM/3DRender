xcopy .\Temp\Link\x64\Debug\MyProject.exe .\Bin\x64\Debug\ /y
xcopy .\Temp\Link\x64\Release\MyProject.exe .\Bin\x64\Release\ /y
del /f /s /q .\Bin\x64\Debug\Resource\*.*
del /f /s /q .\Bin\x64\Release\Resource\*.*
xcopy .\Resource .\Bin\x64\Debug\Resource /e/y
xcopy .\Resource .\Bin\x64\Release\Resource /e/y