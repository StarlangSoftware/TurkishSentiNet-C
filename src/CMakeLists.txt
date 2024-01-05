cmake_minimum_required(VERSION 3.23)
project(SentiNet)
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_FLAGS "-O3")

find_package(xml_parser_c REQUIRED)
find_package(util_c REQUIRED)

add_library(SentiNet PolarityType.h PolarityType.c SentiLiteral.c SentiLiteral.h SentiSynSet.c SentiSynSet.h SentiLiteralNet.c SentiLiteralNet.h SentiNet.c SentiNet.h)
target_link_libraries(SentiNet xml_parser_c::xml_parser_c util_c::util_c)
