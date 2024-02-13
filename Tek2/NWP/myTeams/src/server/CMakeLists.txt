set(INCROOT ${PROJECT_SOURCE_DIR}/src/server)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/server)

set(SRC
    ${SRCROOT}/cycle.c
    ${SRCROOT}/destroy_teams.c
    ${SRCROOT}/destroy.c
    ${SRCROOT}/find_channel.c
    ${SRCROOT}/find_messages_list.c
    ${SRCROOT}/find_team.c
    ${SRCROOT}/find_thread_by_title.c
    ${SRCROOT}/find_thread.c
    ${SRCROOT}/find_user.c
    ${SRCROOT}/find_peer.c
    ${SRCROOT}/get_context.c
    ${SRCROOT}/messages_map.c
    ${SRCROOT}/init.c
    ${SRCROOT}/poll.c
    ${INCROOT}/peer.h
    ${INCROOT}/server.h
    ${SRCROOT}/socket.c
    ${SRCROOT}/start.c
)

set(INCDIRS ${INCROOT})

add_subdirectory(items)
add_subdirectory(peer)
add_subdirectory(packet_handlers)
add_subdirectory(packet_reply)

source_group("server" FILES ${SRC})

set(LIB_NAME libmyteams_server)
set(TARGET_NAME myteams_server)

add_library(${LIB_NAME} ${SRC})

target_include_directories(${LIB_NAME} PRIVATE ${INCDIRS})
target_include_directories(${LIB_NAME} PUBLIC ${INCROOT})

target_link_libraries(${LIB_NAME} PUBLIC myteams_logging myteams_util myteams_common uuid)

add_executable(${TARGET_NAME} ${SRCROOT}/main.c)
target_link_libraries(${TARGET_NAME} PRIVATE ${LIB_NAME})

add_custom_command(TARGET ${TARGET_NAME}
	POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${TARGET_NAME}> ${PROJECT_SOURCE_DIR})
