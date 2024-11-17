# CMakeList.txt: 6 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)
find_package(Python3 COMPONENTS Interpreter Development REQUIRED)
include_directories(${Python3_INCLUDE_DIRS})
target_link_libraries(6 ${Python3_LIBRARIES})



# 如果支持，请为 MSVC 编译器启用热重载。
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project(6 LANGUAGES CXX)
# require C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# we default to Release build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
endif()

# for testing we will need the python interpreter
find_package(PythonInterp REQUIRED)
# we require python development headers
find_package(PythonLibs ${PYTHON_VERSION_MAJOR}.${PYTHON_VERSION_MINOR} EXACT REQUIRED)
# now search for the boost component
# depending on the boost version it is called either python,
# python2, python27, python3, python36, python37, ...
list(
  APPEND _components
    python${PYTHON_VERSION_MAJOR}${PYTHON_VERSION_MINOR}
    python${PYTHON_VERSION_MAJOR}
    python
  )
set(_boost_component_found "")
foreach(_component IN ITEMS ${_components})
  find_package(Boost COMPONENTS ${_component})
  if(Boost_FOUND)
      set(_boost_component_found ${_component})
      break()
  endif()
endforeach()
if(_boost_component_found STREQUAL "")
    message(FATAL_ERROR "No matching Boost.Python component found")
endif()
# 将源代码添加到此项目的可执行文件。
add_executable (6 "6.cpp" "6.h" "cli.py")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 6 PROPERTY CXX_STANDARD 20)
endif()

find_package(Boost REQUIRED COMPONENTS system)
target_link_libraries(6.cpp cli.py Boost::system)

# TODO: 如有需要，请添加测试并安装目标。
