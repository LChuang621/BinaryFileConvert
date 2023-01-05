
if(Test-Path '.\build')
{
	Remove-Item -Path '.\build' -Recurse -Force
}

New-Item -ItemType Directory -Path '.\build'

cd build
cmake ..
cd ..