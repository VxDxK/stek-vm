cmake_minimum_required(VERSION 3.23)
project(c_course C)

set(CMAKE_C_STANDARD 17)
#add_compile_options(-fsanitize=address,undefined,leak)
#add_link_options(-fsanitize=address,undefined,leak)
add_executable(c_course main.c array_int.c maybe_int64.c util.c stack.c stack.h interpret.c interpret.h stek_vm.c)
