
# YACSGL library
file (GLOB YACSGL_SOURCE_FILES "src/*.c")
add_library(yacsgl STATIC 
    ${YACSGL_SOURCE_FILES}
)
target_include_directories(yacsgl PUBLIC ${CMAKE_CURRENT_LIST_DIR}/inc)
