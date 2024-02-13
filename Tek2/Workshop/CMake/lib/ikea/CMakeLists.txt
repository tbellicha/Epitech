set(INCROOT ${PROJECT_SOURCE_DIR}/include)
set(SRCROOT ${PROJECT_SOURCE_DIR}/lib/ikea)

set(SRC
    ${SRCROOT}/get_furniture.c
    ${INCROOT}/ikea.h
)

set(INCDIRS ${INCROOT})

source_group("" FILES ${SRC})

set(LIB_NAME libikea)

add_library(${LIB_NAME} ${SRC})

target_include_directories(${LIB_NAME} PRIVATE ${INCDIRS})
target_include_directories(${LIB_NAME} PUBLIC ${INCROOT})