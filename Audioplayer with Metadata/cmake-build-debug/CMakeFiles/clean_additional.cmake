# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\audioplayer_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\audioplayer_autogen.dir\\ParseCache.txt"
  "audioplayer_autogen"
  )
endif()
