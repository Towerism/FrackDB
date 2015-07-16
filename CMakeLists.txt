ADD_BII_TARGETS()

include(biicode/boost/setup)
set(Boost_USE_STATIC_LIBS OFF)

bii_find_boost(REQUIRED)
target_include_directories(${BII_BLOCK_TARGET} INTERFACE ${Boost_INCLUDE_DIRS})
target_link_libraries(${BII_BLOCK_TARGET} INTERFACE ${Boost_LIBRARIES})

# enable c++14
SET(CMAKE_CXX_FLAGS "-std=c++14" ${CMAKE_CXX_FLAGS})