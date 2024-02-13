set(INCROOT ${PROJECT_SOURCE_DIR}/src/util)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/util/endian)

set(SRC
    ${SRC}
    ${INCROOT}/endian.h
    ${SRCROOT}/big_endian_to_be.h
    ${SRCROOT}/big_endian_to_le.h
    ${SRCROOT}/little_endian_to_be.h
    ${SRCROOT}/little_endian_to_le.h
    PARENT_SCOPE
)
