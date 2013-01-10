cmake_minimum_required( VERSION 2.8 )
set( BIN ids_head )
project( ${BIN} )
 
set( SOURCE_ROOT ./ids_head )

file (GLOB HEADERS ${SOURCE_ROOT}/*.hpp)
file (GLOB SOURCES ${SOURCE_ROOT}/*.cpp)
  
set( REQUIRED_LIBRARIES
		mongoclient
		boost_system
		boost_filesystem
		boost_program_options
		boost_thread
		pthread
		config++
		msgpack
		zmq	
)
 
set( CMAKE_CXX_FLAGS "-std=c++11 -Os" ) 
 
add_executable( ${BIN} ${HEADERS} ${SOURCES} )

target_link_libraries( ${BIN} ${REQUIRED_LIBRARIES} )