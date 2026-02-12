cmake_minimum_required (VERSION 4.0)
project (dsa_practice)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
set(CMAKE_CXX_EXTENSIONS OFF)

# option(ERAE_LAB_OSX_BACKWARD_COMPATIBILITY  "Enable OSX backward compatibility" ON)
# if(ERAE_LAB_OSX_BACKWARD_COMPATIBILITY)
#   set(CMAKE_OSX_DEPLOYMENT_TARGET 10.14)
#   set(CMAKE_OSX_ARCHITECTURES "arm64;x86_64")
# endif()

# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)
# set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
# set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
# set(CMAKE_EXPORT_COMPILE_COMMANDS ON )


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-deprecated-declarations -Werror -Wno-unused-private-field")
if(LOCAL_BUILD)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-address-of-packed-member -Werror")
endif()

add_subdirectory(src)
add_subdirectory(test)


