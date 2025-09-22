# Toolchain for clang installed with homebrew on MacOs `brew install llvm@20`

# Set this to force CMake to use this toolchain
set(CMAKE_SYSTEM_NAME Darwin)
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

# Path to Homebrew's LLVM
set(LLVM_DIR "/opt/homebrew/opt/llvm")

# Compiler paths
set(CMAKE_C_COMPILER "${LLVM_DIR}/bin/clang")
set(CMAKE_CXX_COMPILER "${LLVM_DIR}/bin/clang++")

# Set the sysroot and include path
set(CMAKE_SYSROOT "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk")
set(CMAKE_OSX_SYSROOT ${CMAKE_SYSROOT})

# Add LLVM's bin and lib to paths
set(CMAKE_FIND_ROOT_PATH "${LLVM_DIR}")
set(CMAKE_PREFIX_PATH "${LLVM_DIR}")
set(CMAKE_LIBRARY_PATH "${LLVM_DIR}/lib")

set(CMAKE_AR "${LLVM_DIR}/bin/llvm-ar")
set(CMAKE_RANLIB "${LLVM_DIR}/bin/llvm-ranlib")
set(CMAKE_NM "${LLVM_DIR}/bin/llvm-nm")

# Add Clang's includes and libs
set(CMAKE_C_FLAGS "--sysroot=${CMAKE_SYSROOT} -isystem ${LLVM_DIR}/include ${CMAKE_C_FLAGS}")
set(CMAKE_CXX_FLAGS "--sysroot=${CMAKE_SYSROOT} -isystem ${LLVM_DIR}/include ${CMAKE_CXX_FLAGS}")

# Using LLVM libc++ and libunwind
set(CMAKE_EXE_LINKER_FLAGS "-L${LLVM_DIR}/lib/c++ -L${LLVM_DIR}/lib/unwind -lunwind ${CMAKE_EXE_LINKER_FLAGS}")

# Make sure we use these tools for building
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
