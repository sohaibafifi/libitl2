# CMake build file for itl2
# By: Mohamed A.M. Bamakhrama (mohamed@alumni.tum.de)

cmake_minimum_required(VERSION 2.6)
PROJECT(itl)

message("Installation target directory is: " ${CMAKE_INSTALL_PREFIX} )
message("To override this value, use 'cmake -DCMAKE_INSTALL_PREFIX:PATH=$DIR'" )

set( COMPILE_FLAGS "-ansi -pedantic -Wall -O2" )
set( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${COMPILE_FLAGS}" )

# Specify header files
set(HEADER_FILES
        hijri/hijri.h
        prayertime/prayer.h
        prayertime/astro.h
        )

# Specify sources
set(SOURCE_FILES
        hijri/hijri.c
        prayertime/astro.c
        prayertime/prayer.c
        hijri/umm_alqura.c
        )

add_library(itl SHARED ${HEADER_FILES} ${SOURCE_FILES})

install(FILES ${HEADER_FILES} DESTINATION "include/itl/")
install(TARGETS itl DESTINATION "lib/")
install(FILES pkgconfig/itl.pc DESTINATION "lib/")

add_executable(demo_hijri EXCLUDE_FROM_ALL examples/demo_hijri.c )
add_executable(demo_prayer EXCLUDE_FROM_ALL  examples/demo_prayer.c)

target_link_libraries(demo_hijri itl -lm)
target_link_libraries(demo_prayer itl -lm)

add_custom_target(samples DEPENDS demo_prayer demo_hijri)