set(INCROOT ${PROJECT_SOURCE_DIR}/src/util)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/util/uuid)

set(SRC
    ${SRC}
    ${INCROOT}/uuid_util.h
    ${SRCROOT}/pair_cmp.c
    ${SRCROOT}/pair_hash.c
    ${SRCROOT}/pair_init.c
    PARENT_SCOPE
)

set(INCDIRS
    ${INCDIRS}
    ${INCROOT}
    PARENT_SCOPE
)
