# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Tours_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Tours_autogen.dir\\ParseCache.txt"
  "Tours_autogen"
  )
endif()
