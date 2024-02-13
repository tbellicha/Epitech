set(INCROOT ${PROJECT_SOURCE_DIR}/src/client/commands)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/client/commands)

set(SRC
    ${SRC}
    ${SRCROOT}/commands_info.c
    ${INCROOT}/commands.h
    ${SRCROOT}/create.c
    ${SRCROOT}/handle_command.c
    ${SRCROOT}/help.c
    ${SRCROOT}/info.c
    ${SRCROOT}/list.c
    ${SRCROOT}/login.c
    ${SRCROOT}/logout.c
    ${SRCROOT}/messages.c
    ${SRCROOT}/send.c
    ${SRCROOT}/subscribe.c
    ${SRCROOT}/subscribed.c
    ${SRCROOT}/unsubscribe.c
    ${SRCROOT}/use.c
    ${SRCROOT}/user.c
    ${SRCROOT}/users.c
    PARENT_SCOPE
)

set(INCDIRS ${INCROOT})
