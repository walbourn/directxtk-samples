@echo off
setlocal
set NUGET=c:\util\nuget.exe
if NOT exist %NUGET% goto error
echo Updates all projects to latest NuGet version
echo .
pause
for /D %%1 in (*) do (pushd %%1
%NUGET% restore "DirectXTKSimpleSample.sln"
%NUGET% update "DirectXTKSimpleSample.sln"
popd)
popd
goto :eof
:error
echo ERROR cannot find %NUGET%
