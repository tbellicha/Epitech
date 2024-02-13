set(INCROOT ${PROJECT_SOURCE_DIR}/src/server)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/server/packet_handlers)

set(SRC
    ${SRC}
    ${INCROOT}/packet_handlers.h
    ${SRCROOT}/comment_list.c
    ${SRCROOT}/create_item.c
    ${SRCROOT}/get_channels.c
    ${SRCROOT}/get_messages.c
    ${SRCROOT}/get_team_info.c
    ${SRCROOT}/get_subscribed_teams.c
    ${SRCROOT}/get_team_users.c
    ${SRCROOT}/get_teams.c
    ${SRCROOT}/get_user_info.c
    ${SRCROOT}/get_users.c
    ${SRCROOT}/handle_packet.c
    ${SRCROOT}/handlers.c
    ${SRCROOT}/login.c
    ${SRCROOT}/logout.c
    ${SRCROOT}/message.c
    ${SRCROOT}/set_context.c
    ${SRCROOT}/subscribe_team.c
    ${SRCROOT}/thread_list.c
    ${SRCROOT}/unknown.c
    ${SRCROOT}/unsubscribe_team.c
    PARENT_SCOPE
)

set(INCDIRS ${INCDIRS} ${INCROOT} PARENT_SCOPE)
