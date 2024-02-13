set(INCROOT ${PROJECT_SOURCE_DIR}/src/util)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/util/hash)

set(SRC
    ${SRC}
    ${INCROOT}/hash.h
    ${SRCROOT}/internal.h
    ${SRCROOT}/my_hasher_finish.c
    ${SRCROOT}/my_hasher_init.c
    ${SRCROOT}/my_hasher_write.c
    ${SRCROOT}/my_hasher_write_fixed_int.c
    ${SRCROOT}/my_hasher_write_int.c
    ${SRCROOT}/my_hash_load_from_mem.c
    ${SRCROOT}/my_siphash13_rounds.c
    PARENT_SCOPE
)

set(INCDIRS
    ${INCDIRS}
    ${INCROOT}
    PARENT_SCOPE
)
