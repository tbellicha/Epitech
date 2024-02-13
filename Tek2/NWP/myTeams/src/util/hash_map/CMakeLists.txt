set(INCROOT ${PROJECT_SOURCE_DIR}/src/util)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/util/hash_map)

set(SRC
    ${SRC}
    ${INCROOT}/hash_map.h
    ${SRCROOT}/internal.h
    ${SRCROOT}/my_calloc.c
    ${SRCROOT}/my_hash_map_contains.c
    ${SRCROOT}/my_hash_map_cstr_key.c
    ${SRCROOT}/my_hash_map_drop.c
    ${SRCROOT}/my_hash_map_get.c
    ${SRCROOT}/my_hash_map_hash_key.c
    ${SRCROOT}/my_hash_map_init.c
    ${SRCROOT}/my_hash_map_insert_entry.c
    ${SRCROOT}/my_hash_map_insert.c
    ${SRCROOT}/my_hash_map_iter.c
    ${SRCROOT}/my_hash_map_remove.c
    PARENT_SCOPE
)

set(INCDIRS
    ${INCDIRS}
    ${INCROOT}
    PARENT_SCOPE
)
