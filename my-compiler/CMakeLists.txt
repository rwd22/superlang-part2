
set(CMAKE_CXX_FLAGS "-std=c++1z")

add_executable(cvc
  main.cpp
  printer.cpp
  expr.cpp
  sexpr.cpp
  value.cpp
)