set(INCROOT ${PROJECT_SOURCE_DIR}/src/server/items/)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/server/items/)


set(SRC
    ${SRC}
    ${INCROOT}/channel.h
    ${INCROOT}/comment.h
    ${INCROOT}/item.h
    ${INCROOT}/message.h
    ${INCROOT}/team.h
    ${INCROOT}/thread.h
    ${INCROOT}/user.h
    PARENT_SCOPE
)
