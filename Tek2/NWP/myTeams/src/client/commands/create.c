/*
** EPITECH PROJECT, 2022
** Project
** File description:
** create
*/

#include "cbuffer.h"
#include "client.h"
#include "leb128.h"
#include "protocol.h"

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

static bool create_command_parse_comment_inputs(
    char *params, char **name, char **body)
{
    ssize_t body_len = parse_string(params, "You must enter a message.");

    if (body_len <= 0 || body_len > MAX_BODY_LENGTH) {
        puts("Invalid or too long message parameter");
        return false;
    }
    *name = "";
    *body = params + 1;
    (*body)[body_len] = 0;
    return true;
}

static bool create_command_parse_inputs(
    context_type_t type, char *params, char **name, char **body)
{
    ssize_t name_len;
    ssize_t body_len;

    if (type == CONTEXT_THREAD)
        return create_command_parse_comment_inputs(params, name, body);
    name_len = parse_string(params, "You must enter a name.");
    body_len =
        parse_string(params + name_len + 3, "You must enter a description.");
    if (name_len <= 0 || body_len <= 0 || name_len > MAX_NAME_LENGTH
        || body_len > MAX_DESCRIPTION_LENGTH) {
        puts("Invalid or too long parameters");
        return false;
    }
    *name = params + 1;
    *body = params + name_len + 4;
    (*name)[name_len] = 0;
    (*body)[body_len] = 0;
    return true;
}

static void send_create_item_packet(
    client_t *client, char const *name, char const *body)
{
    size_t name_len = strlen(name);
    size_t body_len = strlen(body);
    size_t offset = sizeof(uuid_t);
    char *buf = client->tmp_buf;

    memcpy(buf, client->context, sizeof(uuid_t));
    offset += uleb128_encode_32(buf + offset, name_len);
    memcpy(buf + offset, name, name_len);
    offset += name_len;
    memcpy(buf + offset, body, body_len);
    offset += body_len;
    my_cbuffer_push_back_uleb128_32(&client->out_buf, C2S_CREATE_ITEM);
    my_cbuffer_push_back_uleb128_32(&client->out_buf, offset);
    my_cbuffer_push_back(&client->out_buf, buf, offset);
}

void command_create(client_t *client, char *params)
{
    context_type_t type = client->context_type;
    char *name;
    char *body;

    if (create_command_parse_inputs(type, params, &name, &body))
        send_create_item_packet(client, name, body);
}

void print_helper_create(void)
{
    puts("When the context is not defined (/use):");
    puts("\t/create \"team_name\" \"team_description\": create a new team");
    puts("When team_uuid is defined (/use \"team_uuid\"):");
    fputs("\t/create \"channel_name\" \"channel_description\" : ", stdout);
    fputs("create a new channel\n", stdout);
    fputs("When team_uuid and channel_uuid are defined ", stdout);
    fputs("(/use \"team_uuid\" \"channel_uuid\"):\n", stdout);
    puts(
        "\t/create \"thread_title\" \"thread_message\": create a new thread");
    fputs(
        "When team_uuid, channel_uuid and thread_uuid are defined ", stdout);
    fputs("(/use \"team_uuid\" \"channel_uuid\" \"thread_uuid\"):\n", stdout);
    puts("\t/create \"comment_body\": create a new reply");
}
