
configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/libglfw.pc.cmake 
    ${CMAKE_CURRENT_BINARY_DIR}/libglfw.pc @ONLY)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR} 
    ${CMAKE_SOURCE_DIR}/lib 
    ${GLFW_INCLUDE_DIR})

set(libglfw_SOURCES
    ${common_SOURCES}
    carbon_enable.c
    carbon_fullscreen.c
    carbon_glext.c
    carbon_init.c
    carbon_joystick.c
    carbon_time.c
    carbon_window.c)

add_library(libglfwStatic STATIC ${libglfw_SOURCES})
add_library(libglfwShared SHARED ${libglfw_SOURCES}) 
target_link_libraries(libglfwShared  ${GLFW_LIBRARIES})
set_target_properties(libglfwStatic libglfwShared PROPERTIES 
    CLEAN_DIRECT_OUTPUT 1
    OUTPUT_NAME glfw
)

# Append -fno-common to the compile flags to work around a bug in the Apple GCC
get_target_property(CFLAGS libglfwShared COMPILE_FLAGS)
if(NOT CFLAGS)
  set(CFLAGS "")
endif(NOT CFLAGS)
set_target_properties(libglfwShared PROPERTIES COMPILE_FLAGS "${CFLAGS} -fno-common")

install(TARGETS libglfwStatic libglfwShared DESTINATION lib)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/libglfw.pc DESTINATION lib/pkgconfig)

