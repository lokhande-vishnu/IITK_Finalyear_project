@echo off
set MATLAB=C:\PROGRA~1\MATLAB\MATLAB~1\R2015a
set MATLAB_ARCH=win64
set MATLAB_BIN="C:\Program Files\MATLAB\MATLAB Production Server\R2015a\bin"
set ENTRYPOINT=mexFunction
set OUTDIR=.\
set LIB_NAME=sigm_mex
set MEX_NAME=sigm_mex
set MEX_EXT=.mexw64
call "C:\PROGRA~1\MATLAB\MATLAB~1\R2015a\sys\lcc64\lcc64\mex\lcc64opts.bat"
echo # Make settings for sigm > sigm_mex.mki
echo COMPILER=%COMPILER%>> sigm_mex.mki
echo COMPFLAGS=%COMPFLAGS%>> sigm_mex.mki
echo OPTIMFLAGS=%OPTIMFLAGS%>> sigm_mex.mki
echo DEBUGFLAGS=%DEBUGFLAGS%>> sigm_mex.mki
echo LINKER=%LINKER%>> sigm_mex.mki
echo LINKFLAGS=%LINKFLAGS%>> sigm_mex.mki
echo LINKOPTIMFLAGS=%LINKOPTIMFLAGS%>> sigm_mex.mki
echo LINKDEBUGFLAGS=%LINKDEBUGFLAGS%>> sigm_mex.mki
echo MATLAB_ARCH=%MATLAB_ARCH%>> sigm_mex.mki
echo BORLAND=%BORLAND%>> sigm_mex.mki
echo OMPFLAGS= >> sigm_mex.mki
echo OMPLINKFLAGS= >> sigm_mex.mki
echo EMC_COMPILER=lcc64>> sigm_mex.mki
echo EMC_CONFIG=optim>> sigm_mex.mki
"C:\Program Files\MATLAB\MATLAB Production Server\R2015a\bin\win64\gmake" -B -f sigm_mex.mk
