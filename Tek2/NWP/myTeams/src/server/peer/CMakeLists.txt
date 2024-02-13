set(INCROOT ${PROJECT_SOURCE_DIR}/src/server)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/server/peer)

set(SRC
    ${SRC}
    ${INCROOT}/peer.h
    ${SRCROOT}/check_logged_in.c
    ${SRCROOT}/create_channel.c
    ${SRCROOT}/create_comment.c
    ${SRCROOT}/create_team.c
    ${SRCROOT}/create_thread.c
    ${SRCROOT}/create.c
    ${SRCROOT}/destroy.c
    ${SRCROOT}/init_item_header.c
    ${SRCROOT}/is_subscribed.c
    ${SRCROOT}/item_creators.c
    ${SRCROOT}/item_exists.c
    ${SRCROOT}/log.c
    ${SRCROOT}/read_input.c
    ${SRCROOT}/set_user.c
    ${SRCROOT}/unset_user.c
    ${SRCROOT}/write_output.c
    PARENT_SCOPE
)

set(INCDIRS ${INCDIRS} ${INCROOT} PARENT_SCOPE)
