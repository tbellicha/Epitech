set(INCROOT ${PROJECT_SOURCE_DIR}/src/util)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/util/leb128)

set(SRC
    ${SRC}
    ${SRCROOT}/decode.c
    ${SRCROOT}/encode.c
    ${SRCROOT}/size.c
    ${INCROOT}/leb128.h
    PARENT_SCOPE
)

set(INCDIRS
    ${INCDIRS}
    ${INCROOT}
    PARENT_SCOPE
)
