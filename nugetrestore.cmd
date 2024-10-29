@echo off
setlocal
set NUGET=c:\util\nuget.exe
if NOT exist %NUGET% goto error
echo .
for /D %%1 in (Simple*) do (pushd %%1
%NUGET% restore "DirectXTKSimpleSample.sln"
popd)
popd
goto :eof
:error
echo ERROR cannot find %NUGET%
