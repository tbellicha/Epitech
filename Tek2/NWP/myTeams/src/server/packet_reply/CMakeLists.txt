set(INCROOT ${PROJECT_SOURCE_DIR}/src/server)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/server/packet_reply)

set(SRC
    ${SRC}
    ${INCROOT}/packet_reply.h
    ${SRCROOT}/channel_created.c
    ${SRCROOT}/channel_list.c
    ${SRCROOT}/comment_created.c
    ${SRCROOT}/comment_list.c
    ${SRCROOT}/context_update.c
    ${SRCROOT}/error.c
    ${SRCROOT}/generic.c
    ${SRCROOT}/login.c
    ${SRCROOT}/logout.c
    ${SRCROOT}/message.c
    ${SRCROOT}/messages_list.c
    ${SRCROOT}/subscribed.c
    ${SRCROOT}/team_created.c
    ${SRCROOT}/team_info.c
    ${SRCROOT}/team_list.c
    ${SRCROOT}/team_users_list.c
    ${SRCROOT}/thread_created.c
    ${SRCROOT}/thread_list.c
    ${SRCROOT}/unknown_item.c
    ${SRCROOT}/unsubscribed.c
    ${SRCROOT}/user_info.c
    ${SRCROOT}/user_list.c
    PARENT_SCOPE
)

set(INCDIRS ${INCDIRS} ${INCROOT} PARENT_SCOPE)
