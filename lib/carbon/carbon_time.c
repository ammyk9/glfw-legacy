//========================================================================
// GLFW - An OpenGL framework
<<<<<<<< HEAD:lib/cocoa/cocoa_glext.m
// Platform:    Cocoa/NSOpenGL
// API Version: 2.7
// WWW:         http://www.glfw.org/
//------------------------------------------------------------------------
// Copyright (c) 2009-2010 Camilla Berglund <elmindreda@elmindreda.org>
========
// Platform:    Carbon/AGL/CGL
// API Version: 2.7
// WWW:         http://www.glfw.org/
//------------------------------------------------------------------------
// Copyright (c) 2002-2006 Marcus Geelnard
// Copyright (c) 2003      Keith Bauer
// Copyright (c) 2003-2010 Camilla Berglund <elmindreda@elmindreda.org>
>>>>>>>> origin/2.x-lite:lib/carbon/carbon_time.c
//
// This software is provided 'as-is', without any express or implied
// warranty. In no event will the authors be held liable for any damages
// arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented; you must not
//    claim that you wrote the original software. If you use this software
//    in a product, an acknowledgment in the product documentation would
//    be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such, and must not
//    be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source
//    distribution.
//
//========================================================================

#include "internal.h"

//************************************************************************
//****               Platform implementation functions                ****
//************************************************************************

//========================================================================
<<<<<<<< HEAD:lib/cocoa/cocoa_glext.m
// Check if an OpenGL extension is available at runtime
========
// Return timer value in seconds
>>>>>>>> origin/2.x-lite:lib/carbon/carbon_time.c
//========================================================================

double _glfwPlatformGetTime( void )
{
<<<<<<<< HEAD:lib/cocoa/cocoa_glext.m
    // There are no AGL, CGL or NSGL extensions.
    return GL_FALSE;
========
    struct timeval  tv;

    gettimeofday( &tv, NULL );
    return tv.tv_sec + (double) tv.tv_usec / 1000000.0 - _glfwLibrary.Timer.t0;
>>>>>>>> origin/2.x-lite:lib/carbon/carbon_time.c
}


//========================================================================
<<<<<<<< HEAD:lib/cocoa/cocoa_glext.m
// Get the function pointer to an OpenGL function
========
// Set timer value in seconds
>>>>>>>> origin/2.x-lite:lib/carbon/carbon_time.c
//========================================================================

void _glfwPlatformSetTime( double time )
{
<<<<<<<< HEAD:lib/cocoa/cocoa_glext.m
    CFStringRef symbolName = CFStringCreateWithCString( kCFAllocatorDefault,
                                                        procname,
                                                        kCFStringEncodingASCII );

    void *symbol = CFBundleGetFunctionPointerForName( _glfwLibrary.OpenGLFramework,
                                                      symbolName );

    CFRelease( symbolName );

    return symbol;
}

========
    struct timeval  tv;

    gettimeofday( &tv, NULL );
    _glfwLibrary.Timer.t0 = tv.tv_sec + (double) tv.tv_usec / 1000000.0 - time;
}


>>>>>>>> origin/2.x-lite:lib/carbon/carbon_time.c
