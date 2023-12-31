cmake_minimum_required(VERSION 3.0.0)
project(Myproject VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)
include(CTest)
enable_testing()

find_package(OpenGL REQUIRED)

set( DEPENDENCY_DIR 
${CMAKE_CURRENT_SOURCE_DIR}/dep)

set( SRC_DIR 
${CMAKE_CURRENT_SOURCE_DIR}/src)

file(GLOB_RECURSE SOURCES ${SRC_DIR}/**/*.cpp "main.cpp" ${DEPENDENCY_DIR}/include/glad/glad/glad.c )
file(GLOB_RECURSE HEADERS ${SRC_DIR}/**/*.h  ${SRC_DIR}**/*.hpp)
file(GLOB SHADERS "*.vert" "*.frag" "*.vs" "*.fs" )

include_directories( 
    ${DEPENDENCY_DIR}/include/glad/ 
    ${DEPENDENCY_DIR}/include/glfw/
    ${DEPENDENCY_DIR}/include/freeimage/
    ${DEPENDENCY_DIR}/include/glew
    ${DEPENDENCY_DIR}/include/glm
    ${DEPENDENCY_DIR}/include/freeglut
)

message( "\nBuild mode test is: ${CMAKE_BUILD_TYPE} ****************" )
message("\nArchivos fuente incluidos en el proyecto:")
foreach(source_file ${SOURCES})
    message("   ${source_file}")
endforeach()
message("\nArchivos HEADERS incluidos en el proyecto:")
foreach(header_file ${HEADERS})
    message("   ${header_file}")
endforeach()


if ( CMAKE_BUILD_TYPE STREQUAL "Debug")
    message("\nOpenGL_GLUT_GLFW_Program -- Debug mode ****************")
	link_directories(
	${DEPENDENCY_DIR}/lib/glad/Debug/
	${DEPENDENCY_DIR}/lib/glfw/Debug/
	${DEPENDENCY_DIR}/lib/freeglut/Debug/
	${DEPENDENCY_DIR}/lib/freeimage/Debug/
	${DEPENDENCY_DIR}/lib/glew/Debug/
	${DEPENDENCY_DIR}/lib/glm/Debug/
	)
else()
    message("\nOpenGL_GLUT_GLFW_Program -- Release mode ****************")
	link_directories(
	${DEPENDENCY_DIR}/lib/glad/Release/
	${DEPENDENCY_DIR}/lib/glfw/Release/
	${DEPENDENCY_DIR}/lib/freeglut/Release/
	${DEPENDENCY_DIR}/lib/freeimage/Release/
	${DEPENDENCY_DIR}/lib/glew/Release/
	${DEPENDENCY_DIR}/lib/glm/Release/
	)
endif ()

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES} ${SHADERS} )

target_include_directories(${PROJECT_NAME}
    PRIVATE src
)

if ( CMAKE_BUILD_TYPE STREQUAL "Debug")
	if ( WIN32 )
	    message("\nOpenGL_GLUT_GLFW_Program -- Debug mode Windows ****************")
		target_link_libraries( ${PROJECT_NAME} 
						   opengl32
						   freeglut_staticd.lib
						   glad.lib
	                       glfw3.lib
						   glew32d.lib
						   FreeImaged.lib
						   glm_static.lib
						   
						    )
	else()
		message("\nOpenGL_GLUT_GLFW_Program -- Debug mode Linux ****************")
		target_link_libraries( ${PROJECT_NAME} 
						   ${OPENGL_LIBRARY}
							-lm
							-lGL
							-lGLU
							-lX11
							-lXi
							-lXxf86vm 
							-lXrandr 
							-pthread 
							-ldl
							-lm
						   libglad.a
	                       libglfw3.a
						   libGLEWd.a
						   libglut.a
						   libfreeimage.a
						   libglm_static.a
						    )

	endif()					    	
else()
	if ( WIN32 )
		message("\nOpenGL_GLUT_GLFW_Program -- Release mode Windows ****************")
		target_link_libraries( ${PROJECT_NAME} 
						   opengl32
						   freeglut_static.lib
						   glad.lib
	                       glfw3.lib
						   glew32.lib
						   FreeImage.lib
						   glm_static.lib
						    )
	else()
		message("\nOpenGL_GLUT_GLFW_Program -- Release mode Linux ****************")
		target_link_libraries( ${PROJECT_NAME} 
						  ${OPENGL_LIBRARY}
												    
							-lm
							-lGL
							-lGLU
							-lX11
							-lXi
							-lXxf86vm 
							-lXrandr 
							-pthread 
							-ldl
							-lm
						   libglad.a
	                       libglfw3.a
						   libGLEW.a
						   libglut.a
						   libfreeimage.a
						   libglm_static.a
							)

	endif()	
endif ()                      
