//========================================================================
// GLFW - An OpenGL framework
<<<<<<<< HEAD:lib/carbon/carbon_enable.c
// Platform:    Carbon/AGL/CGL
// API Version: 2.7
// WWW:         http://www.glfw.org/
//------------------------------------------------------------------------
// Copyright (c) 2002-2006 Marcus Geelnard
// Copyright (c) 2003      Keith Bauer
// Copyright (c) 2003-2010 Camilla Berglund <elmindreda@elmindreda.org>
========
// Platform:    Cocoa/NSOpenGL
// API Version: 2.7
// WWW:         http://www.glfw.org/
//------------------------------------------------------------------------
// Copyright (c) 2009-2010 Camilla Berglund <elmindreda@elmindreda.org>
>>>>>>>> origin/2.x-lite:lib/cocoa/cocoa_time.m
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

<<<<<<<< HEAD:lib/carbon/carbon_enable.c
========
#include "internal.h"

#include <sys/time.h>
>>>>>>>> origin/2.x-lite:lib/cocoa/cocoa_time.m

//************************************************************************
//****               Platform implementation functions                ****
//************************************************************************

//========================================================================
<<<<<<<< HEAD:lib/carbon/carbon_enable.c
// Enable system keys
//========================================================================

void _glfwPlatformEnableSystemKeys( void )
{
    // Nothing to do; event handling code checks the status of
    // _glfwWin.sysKeysDisabled to ensure this behavior.
}

//========================================================================
// Disable system keys
//========================================================================

void _glfwPlatformDisableSystemKeys( void )
{
    // Nothing to do; event handling code checks the status of
    // _glfwWin.sysKeysDisabled to ensure this behavior.
========
// Return timer value in seconds
//========================================================================

double _glfwPlatformGetTime( void )
{
    return [NSDate timeIntervalSinceReferenceDate] - _glfwLibrary.Timer.t0;
}

//========================================================================
// Set timer value in seconds
//========================================================================

void _glfwPlatformSetTime( double time )
{
    _glfwLibrary.Timer.t0 = [NSDate timeIntervalSinceReferenceDate] - time;
>>>>>>>> origin/2.x-lite:lib/cocoa/cocoa_time.m
}

