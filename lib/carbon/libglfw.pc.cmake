prefix=@PREFIX@
exec_prefix=@PREFIX@
libdir=@PREFIX@/lib
includedir=@PREFIX@/include

Name: GLFW
Description: A portable framework for OpenGL development
Version: 2.7
<<<<<<<< HEAD:lib/carbon/libglfw.pc.in
URL: http://www.glfw.org/
========
URL: http://glfw.sourceforge.net/
>>>>>>>> origin/2.x-lite:lib/carbon/libglfw.pc.cmake
Libs: -L${libdir} -lglfw -framework AGL -framework OpenGL -framework Carbon
Cflags: -I${includedir}
