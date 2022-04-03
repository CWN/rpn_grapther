cmake_minimum_required(VERSION 3.21)
project(cproject C)

set(CMAKE_C_STANDARD 99)

add_executable(cproject main.c simple_stack.h simple_stack.c token.h token.c simple_list.h simple_list.c parser.h parser.c rpn_executor.h rpn_executor.c display.h display.c)
