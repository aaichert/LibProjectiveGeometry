
add_executable(GeometryExamples
	main.cpp
)
target_link_libraries(GeometryExamples LibProjectiveGeometry)
install(TARGETS GeometryExamples RUNTIME DESTINATION bin)
set_property(TARGET GeometryExamples PROPERTY FOLDER "Examples") 
