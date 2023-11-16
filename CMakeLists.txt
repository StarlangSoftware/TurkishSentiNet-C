cmake_minimum_required(VERSION 3.23)
project(SentiNet C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_FLAGS "-O3")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_library(SentiNet src/PolarityType.h src/SentiLiteral.c src/SentiLiteral.h src/SentiSynSet.c src/SentiSynSet.h src/SentiLiteralNet.c src/SentiLiteralNet.h src/SentiNet.c src/SentiNet.h src/PolarityType.c)
target_link_libraries(SentiNet ${CONAN_LIBS})
add_executable(SentiNetTest src/PolarityType.h src/SentiLiteral.c src/SentiLiteral.h src/SentiSynSet.c src/SentiSynSet.h src/SentiLiteralNet.c src/SentiLiteralNet.h src/SentiNet.c src/SentiNet.h Test/SentiNetTest.c)
target_link_libraries(SentiNetTest ${CONAN_LIBS})
add_executable(SentiLiteralNetTest src/PolarityType.h src/SentiLiteral.c src/SentiLiteral.h src/SentiSynSet.c src/SentiSynSet.h src/SentiLiteralNet.c src/SentiLiteralNet.h src/SentiNet.c src/SentiNet.h Test/SentiLiteralNetTest.c)
target_link_libraries(SentiLiteralNetTest ${CONAN_LIBS})
