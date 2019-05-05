cmake_minimum_required(VERSION 3.0)
project(parseR)

set(CMAKE_CXX_STANDARD 11)

file(GLOB headers include/*.h)
file(GLOB sources src/*.cpp)

add_executable(
	${PROJECT_NAME}
	${headers}
	${sources}
)

target_link_libraries(
	${PROJECT_NAME}
)