set(INCROOT ${PROJECT_SOURCE_DIR}/src/common)

set(SRC
    ${INCROOT}/protocol.h
)

set(INCDIRS ${INCROOT})

source_group("common definitions" FILES ${SRC})

set(LIB_NAME myteams_common)

add_library(${LIB_NAME} INTERFACE)
target_include_directories(${LIB_NAME} INTERFACE ${INCDIRS})
