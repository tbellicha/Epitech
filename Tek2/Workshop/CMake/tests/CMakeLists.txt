set(SRCROOT ${PROJECT_SOURCE_DIR}/tests)

set(SRC
    ${SRCROOT}/tests_ikea.c
)

set(TARGET_NAME unit_test)

add_executable(${TARGET_NAME} ${SRC})

set_target_properties(${TARGET_NAME} PROPERTIES FOLDER "tests")

if (CMAKE_COMPILER_IS_GNUCC)
    target_compile_options(${TARGET_NAME} PRIVATE -Wall -Wextra)
endif()

target_link_libraries(${TARGET_NAME} PRIVATE libikea ${CRITERION_LIBRARIES})

add_test(NAME ${TARGET_NAME} COMMAND ${TARGET_NAME})