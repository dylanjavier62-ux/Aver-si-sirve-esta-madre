cmake_minimum_required(VERSION 3.21)
project(MobileFPSBypass)

include($ENV{GEODE_SDK}/cmake/Geode.cmake)

add_geode_mod(MobileFPSBypass
    MAIN main.cpp
)
