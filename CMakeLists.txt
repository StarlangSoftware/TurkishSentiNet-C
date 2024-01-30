cmake_minimum_required(VERSION 3.23)
project(SentiNet)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-O3")

find_package(xml_parser_c REQUIRED)
find_package(util_c REQUIRED)

add_library(SentiNet src/PolarityType.h src/PolarityType.c src/SentiLiteral.c src/SentiLiteral.h src/SentiSynSet.c src/SentiSynSet.h src/SentiLiteralNet.c src/SentiLiteralNet.h src/SentiNet.c src/SentiNet.h)
target_link_libraries(SentiNet xml_parser_c::xml_parser_c util_c::util_c)
add_executable(SentiNetTest src/PolarityType.h src/PolarityType.c src/SentiLiteral.c src/SentiLiteral.h src/SentiSynSet.c src/SentiSynSet.h src/SentiLiteralNet.c src/SentiLiteralNet.h src/SentiNet.c src/SentiNet.h Test/SentiNetTest.c)
target_link_libraries(SentiNetTest xml_parser_c::xml_parser_c util_c::util_c)
add_executable(SentiLiteralNetTest src/PolarityType.h src/PolarityType.c src/SentiLiteral.c src/SentiLiteral.h src/SentiSynSet.c src/SentiSynSet.h src/SentiLiteralNet.c src/SentiLiteralNet.h src/SentiNet.c src/SentiNet.h Test/SentiLiteralNetTest.c)
target_link_libraries(SentiLiteralNetTest xml_parser_c::xml_parser_c util_c::util_c)
