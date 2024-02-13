set(INCROOT ${PROJECT_SOURCE_DIR}/src/client/packet_handlers)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/client/packet_handlers)

set(SRC
    ${SRC}
    ${SRCROOT}/channel_created.c
    ${SRCROOT}/channel_list.c
    ${SRCROOT}/comment_created.c
    ${SRCROOT}/context_update.c
    ${SRCROOT}/generic.c
    ${SRCROOT}/handle_server_packet.c
    ${SRCROOT}/login.c
    ${SRCROOT}/logout.c
    ${SRCROOT}/message_list.c
    ${SRCROOT}/message_created.c
    ${INCROOT}/server_packet_handlers.h
    ${SRCROOT}/server_handlers.c
    ${SRCROOT}/team_list.c
    ${SRCROOT}/thread_list.c
    ${SRCROOT}/subscribed.c
    ${SRCROOT}/team_created.c
    ${SRCROOT}/unknown_item.c
    ${SRCROOT}/team_info.c
    ${SRCROOT}/user_list.c
    ${SRCROOT}/user_info.c
    ${SRCROOT}/thread_created.c
    ${SRCROOT}/unsubscribed.c
    PARENT_SCOPE
)

set(INCDIRS ${INCROOT})
