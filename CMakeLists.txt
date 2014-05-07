# CMake build file for itl2
# By: Mohamed A.M. Bamakhrama (mohamed@alumni.tum.de)

cmake_minimum_required(VERSION 2.6)
PROJECT(itl)
add_library(libitl STATIC hijri.c astro.c prayer.c umm_alqura.c)

include_directories ("${PROJECT_SOURCE_DIR}")

add_executable(demo_hijri demo_hijri.c)
add_executable(demo_prayer demo_prayer.c)
target_link_libraries(demo_hijri libitl -lm)
target_link_libraries(demo_prayer libitl -lm)
