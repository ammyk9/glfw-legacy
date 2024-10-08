//========================================================================
// GLFW - An OpenGL framework
// Platform:    X11/GLX
// API version: 2.7
// WWW:         http://www.glfw.org/
//------------------------------------------------------------------------
// Copyright (c) 2002-2006 Marcus Geelnard
// Copyright (c) 2006-2010 Camilla Berglund <elmindreda@elmindreda.org>
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

#include <time.h>


//========================================================================
// Return raw time
//========================================================================

static uint64_t getRawTime(void)
{
#if defined( _POSIX_TIMERS ) && defined( _POSIX_MONOTONIC_CLOCK )
    if( _glfwLibrary.Timer.monotonic )
    {
        struct timespec ts;

        clock_gettime( CLOCK_MONOTONIC, &ts );
        return (uint64_t) ts.tv_sec * (uint64_t) 1000000000 + (uint64_t) ts.tv_nsec;
    }
    else
#endif
    {
        struct timeval tv;

        gettimeofday( &tv, NULL );
        return (uint64_t) tv.tv_sec * (uint64_t) 1000000 + (uint64_t) tv.tv_usec;
    }
}


//========================================================================
// Initialise timer
//========================================================================

void _glfwInitTimer( void )
{
#if defined( _POSIX_TIMERS ) && defined( _POSIX_MONOTONIC_CLOCK )
    struct timespec ts;

    if( clock_gettime( CLOCK_MONOTONIC, &ts ) == 0 )
    {
        _glfwLibrary.Timer.monotonic = GL_TRUE;
        _glfwLibrary.Timer.resolution = 1e-9;
    }
    else
#endif
    {
        _glfwLibrary.Timer.resolution = 1e-6;
    }

    _glfwLibrary.Timer.base = getRawTime();
}


//************************************************************************
//****               Platform implementation functions                ****
//************************************************************************

//========================================================================
// Return timer value in seconds
//========================================================================

double _glfwPlatformGetTime( void )
{
    return (double) (getRawTime() - _glfwLibrary.Timer.base) *
        _glfwLibrary.Timer.resolution;
}


//========================================================================
// Set timer value in seconds
//========================================================================

void _glfwPlatformSetTime( double time )
{
    _glfwLibrary.Timer.base = getRawTime() -
        (uint64_t) (time / _glfwLibrary.Timer.resolution);
}


