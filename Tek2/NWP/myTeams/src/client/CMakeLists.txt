set(INCROOT ${PROJECT_SOURCE_DIR}/src/client)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/client)

set(SRC
    ${SRCROOT}/args.c
    ${SRCROOT}/client.c
    ${INCROOT}/client.h
    ${INCROOT}/client_struct.h
    ${SRCROOT}/check_uuid.c
    ${INCROOT}/error_messages.h
    ${SRCROOT}/handle_client_select.c
    ${SRCROOT}/handle_server_select.c
    ${SRCROOT}/helper.c
    ${SRCROOT}/parse_string.c
    ${SRCROOT}/run.c
    ${SRCROOT}/send_packet.c
    ${INCROOT}/write_u32.c
)

set(INCDIRS ${INCROOT})

add_subdirectory(commands)
add_subdirectory(packet_handlers)

source_group("client" FILES ${SRC})

set(LIB_NAME libmyteams_cli)
set(TARGET_NAME myteams_cli)

add_library(${LIB_NAME} ${SRC})

target_include_directories(${LIB_NAME} PRIVATE ${INCDIRS})
target_include_directories(${LIB_NAME} PUBLIC ${INCROOT})

target_link_libraries(${LIB_NAME} PUBLIC myteams_logging myteams_util myteams_common uuid)

add_executable(${TARGET_NAME} ${SRCROOT}/main.c)
target_link_libraries(${TARGET_NAME} PRIVATE ${LIB_NAME})

add_custom_command(TARGET ${TARGET_NAME}
	POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${TARGET_NAME}> ${PROJECT_SOURCE_DIR})
