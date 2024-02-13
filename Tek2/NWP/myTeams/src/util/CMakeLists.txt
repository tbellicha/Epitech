set(INCROOT ${PROJECT_SOURCE_DIR}/src/util)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/util)

set(SRC
    ${SRCROOT}/my_memrev.c
    ${SRCROOT}/my_memswap.c
    ${INCROOT}/util.h
)

set(INCDIRS ${INCROOT})

add_subdirectory(cbuffer)
add_subdirectory(endian)
add_subdirectory(hash)
add_subdirectory(hash_map)
add_subdirectory(leb128)
add_subdirectory(uuid)
add_subdirectory(vec)

source_group("utilities" FILES ${SRC})

set(LIB_NAME myteams_util)

add_library(${LIB_NAME} ${SRC})
target_include_directories(${LIB_NAME} PUBLIC ${INCDIRS})
target_link_libraries(${LIB_NAME} PUBLIC uuid)
