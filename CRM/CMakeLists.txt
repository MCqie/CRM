cmake_minimum_required(VERSION 3.17)
project(CRM)

set(CMAKE_CXX_STANDARD 14)

add_executable(CRM main.cpp DataSaver.h Goods.h Util.h Menu.h FuncImpl.h)