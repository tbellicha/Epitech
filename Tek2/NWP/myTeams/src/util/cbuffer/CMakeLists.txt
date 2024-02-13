set(INCROOT ${PROJECT_SOURCE_DIR}/src/util)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/util/cbuffer)

set(SRC
    ${SRC}
    ${INCROOT}/cbuffer.h
    ${SRCROOT}/internal.h
    ${SRCROOT}/my_cbuffer_get_parts.c
    ${SRCROOT}/my_cbuffer_init.c
    ${SRCROOT}/my_cbuffer_pop_to.c
    ${SRCROOT}/my_cbuffer_pop.c
    ${SRCROOT}/my_cbuffer_push.c
    ${SRCROOT}/my_cbuffer_read.c
    ${SRCROOT}/my_cbuffer_read_to.c
    ${SRCROOT}/my_cbuffer_rotate.c
    ${SRCROOT}/my_cbuffer_write.c
    PARENT_SCOPE
)

set(INCDIRS
    ${INCDIRS}
    ${INCROOT}
    PARENT_SCOPE
)
