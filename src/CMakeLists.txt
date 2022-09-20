cmake_minimum_required(VERSION 3.19)

set(CMAKE_OSX_ARCHITECTURES "arm64;x86_64" CACHE STRING "" FORCE)

project("4nxci" C)

set(ENABLE_PROGRAMS OFF CACHE BOOL "" FORCE)
set(ENABLE_TESTING OFF CACHE BOOL "" FORCE)
set(ENABLE_ZLIB_SUPPORT OFF CACHE BOOL "" FORCE)
set(INSTALL_MBEDTLS_HEADERS OFF CACHE BOOL "" FORCE)
set(LINK_WITH_PTHREAD OFF CACHE BOOL "" FORCE)
set(UNSAFE_BUILD OFF CACHE BOOL "" FORCE)
set(USE_PKCS11_HELPER_LIBRARY OFF CACHE BOOL "" FORCE)
set(USE_SHARED_MBEDTLS_LIBRARY OFF CACHE BOOL "" FORCE)
set(USE_STATIC_MBEDTLS_LIBRARY ON CACHE BOOL "" FORCE)
add_subdirectory(mbedtls)

add_executable(${CMAKE_PROJECT_NAME}
    aes.c
    ConvertUTF.c
    cnmt.c
    extkeys.c
    filepath.c
    hfs0.c
    main.c
    nca.c
    nsp.c
    pki.c
    rsa.c
    romfs.c
    sha.c
    utils.c
    xci.c
)

target_include_directories(${CMAKE_PROJECT_NAME}
    PRIVATE
        mbedtls/include
)

if(MSVC)
    target_include_directories(${CMAKE_PROJECT_NAME}
    PRIVATE
        msvc_compat
    )
endif()

target_link_libraries(${CMAKE_PROJECT_NAME} "mbedtls")