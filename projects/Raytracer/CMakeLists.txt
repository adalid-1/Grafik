#--------------------------------------------------------------------------
# Raytracer project
#--------------------------------------------------------------------------

PROJECT(Raytracer)
FILE(GLOB Raytracer_headers code/*.h)
FILE(GLOB Raytracer_sources code/*.cc  code/*.cpp)


SET(files_Raytracer ${Raytracer_headers} ${Raytracer_sources} ../Raytracer/code/main.cpp code/Ray.cpp code/Ray.h code/Sphere.cpp code/Sphere.h code/ShapeList.h code/Camera.h)
SOURCE_GROUP("Raytracer" FILES ${files_Raytracer})


ADD_EXECUTABLE(Raytracer ${files_Raytracer})
TARGET_LINK_LIBRARIES(Raytracer core render)
ADD_DEPENDENCIES(Raytracer core render)



