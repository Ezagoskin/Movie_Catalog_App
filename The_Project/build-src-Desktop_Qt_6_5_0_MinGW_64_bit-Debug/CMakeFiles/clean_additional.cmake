# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\body_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\body_autogen.dir\\ParseCache.txt"
  "body_autogen"
  )
endif()
