# CMake build file for itl2
# By: Mohamed A.M. Bamakhrama (mohamed@alumni.tum.de)

cmake_minimum_required(VERSION 2.6)
PROJECT(itl)
add_library(itl STATIC hijri/hijri.c prayertime/astro.c prayertime/prayer.c hijri/umm_alqura.c)

include_directories ("${PROJECT_SOURCE_DIR}")

add_executable(demo_hijri EXCLUDE_FROM_ALL examples/demo_hijri.c )
add_executable(demo_prayer EXCLUDE_FROM_ALL  examples/demo_prayer.c)
target_link_libraries(demo_hijri itl -lm)
target_link_libraries(demo_prayer itl -lm)

add_custom_target(samples DEPENDS demo_prayer demo_hijri)