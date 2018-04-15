project(engine)

cmake_minimum_required(VERSION 2.6)

add_executable(engine main.cpp point2f.cpp color4.cpp rectf.cpp image.cpp render.cpp scene.cpp animation.cpp engine.cpp SceneLoader.cpp)

install(TARGETS engine RUNTIME DESTINATION bin)
set_property(TARGET engine PROPERTY CXX_STANDARD 14)
target_link_libraries(engine PUBLIC pthread glut GL GLU SDL SDL_image config++)
