@echo off
set FSL_GLES_EMULATOR_PATH=%FSL_GRAPHICS_SDK%\ThirdParty\Precompiled\openvg1.1-ri
set FSL_GLES_INCLUDE_PATH=%FSL_GLES_EMULATOR_PATH%\include
set FSL_GLES_LIB_PATH=%FSL_GLES_EMULATOR_PATH%\lib
set FSL_GLES_LIB_EGL=libEGL.lib
set FSL_GLES_LIB_GLES=libOpenVG.lib
set FSL_GLES_NAME=Reference
set path=%FSL_GLES_EMULATOR_PATH%;%path%