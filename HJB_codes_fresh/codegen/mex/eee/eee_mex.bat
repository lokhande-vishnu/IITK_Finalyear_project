@echo off
set MATLAB=C:\PROGRA~1\MATLAB\MATLAB~1\R2015a
set MATLAB_ARCH=win64
set MATLAB_BIN="C:\Program Files\MATLAB\MATLAB Production Server\R2015a\bin"
set ENTRYPOINT=mexFunction
set OUTDIR=.\
set LIB_NAME=eee_mex
set MEX_NAME=eee_mex
set MEX_EXT=.mexw64
call "C:\PROGRA~1\MATLAB\MATLAB~1\R2015a\sys\lcc64\lcc64\mex\lcc64opts.bat"
echo # Make settings for eee > eee_mex.mki
echo COMPILER=%COMPILER%>> eee_mex.mki
echo COMPFLAGS=%COMPFLAGS%>> eee_mex.mki
echo OPTIMFLAGS=%OPTIMFLAGS%>> eee_mex.mki
echo DEBUGFLAGS=%DEBUGFLAGS%>> eee_mex.mki
echo LINKER=%LINKER%>> eee_mex.mki
echo LINKFLAGS=%LINKFLAGS%>> eee_mex.mki
echo LINKOPTIMFLAGS=%LINKOPTIMFLAGS%>> eee_mex.mki
echo LINKDEBUGFLAGS=%LINKDEBUGFLAGS%>> eee_mex.mki
echo MATLAB_ARCH=%MATLAB_ARCH%>> eee_mex.mki
echo BORLAND=%BORLAND%>> eee_mex.mki
echo OMPFLAGS= >> eee_mex.mki
echo OMPLINKFLAGS= >> eee_mex.mki
echo EMC_COMPILER=lcc64>> eee_mex.mki
echo EMC_CONFIG=optim>> eee_mex.mki
"C:\Program Files\MATLAB\MATLAB Production Server\R2015a\bin\win64\gmake" -B -f eee_mex.mk
