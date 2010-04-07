ICU is much simpler to compîle under Visual Studio so we do this
then we use gendef utility from mingw-w64 project to generate .def file
from dll.
And finally we use dlltool to generate an import lib :

gendef icuuc40.dll
dlltool --input-def icuuc40.def  --dllname icuuc40.dll --output-lib libicuuc.a -k
