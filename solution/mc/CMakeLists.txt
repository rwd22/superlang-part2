
set(CMAKE_CXX_FLAGS "-std=c++1z")

add_executable(mcc
  main.cpp
  printer.cpp
  name.cpp
  type.cpp
  expr.cpp
  stmt.cpp
  decl.cpp
#  sexpr.cpp
#  value.cpp
)