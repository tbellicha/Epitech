/*
** EPITECH PROJECT, 2022
** Project
** File description:
** thread_list
*/

#include "client.h"
#include "protocol.h"
#include "logging_client.h"
#include "server_packet_handlers.h"

#include <string.h>

static void send_first_part(
    client_t *client, uuid_t author_id, uint32_t *title_length, char *title)
{
    my_cbuffer_pop_front(&client->in_buf, author_id, sizeof(uuid_t));
    my_cbuffer_pop_front_uleb128_32(&client->in_buf, title_length);
    my_cbuffer_pop_front(&client->in_buf, title, *title_length);
}

static void send_second_part(
    client_t *client, uint32_t *body_length, char *body)
{
    my_cbuffer_pop_front_uleb128_32(&client->in_buf, body_length);
    my_cbuffer_pop_front(&client->in_buf, body, *body_length);
}

static void init_memory_for_thread_list(
    char *title, char *body, char *thread_id_str, char *author_id_str)
{
    memset(title, 0, MAX_NAME_LENGTH + 1);
    memset(body, 0, MAX_BODY_LENGTH + 1);
    memset(thread_id_str, 0, UUID_STR_LEN);
    memset(author_id_str, 0, UUID_STR_LEN);
}

static void run_thread_list(client_t *client)
{
    uuid_t thread_id;
    uuid_t author_id;
    uint64_t timestamp;
    char title[MAX_NAME_LENGTH + 1] = {0};
    uint32_t title_length;
    char body[MAX_BODY_LENGTH + 1] = {0};
    uint32_t body_length;
    char thread_str[37] = {0};
    char author_str[37] = {0};

    init_memory_for_thread_list(title, body, thread_str, author_str);
    my_cbuffer_pop_front(&client->in_buf, thread_id, sizeof(uuid_t));
    my_cbuffer_pop_front_uleb128_64(&client->in_buf, &timestamp);
    send_first_part(client, author_id, &title_length, title);
    send_second_part(client, &body_length, body);
    uuid_unparse(thread_id, thread_str);
    uuid_unparse(author_id, author_str);
    client_channel_print_threads(
        thread_str, author_str, timestamp, title, body);
}

server_packet_result_t s2c_handle_thread_list_packet(
    client_t *client, uint32_t len)
{
    uint32_t count;

    my_cbuffer_pop_front_uleb128_32(&client->in_buf, &count);
    for (size_t i = 0; i < count + len * 0; i++)
        run_thread_list(client);
    return PRESULT_OK;
}
