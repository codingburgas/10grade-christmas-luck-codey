# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "codeyapp/CMakeFiles/codeyapp_autogen.dir/AutogenUsed.txt"
  "codeyapp/CMakeFiles/codeyapp_autogen.dir/ParseCache.txt"
  "codeyapp/codeyapp_autogen"
  )
endif()
