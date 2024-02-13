/*
** EPITECH PROJECT, 2022
** Projects
** File description:
** main
*/

#include "ftp.h"

void execute_command(ftp_t *server, client_t *client, char **params, int i)
{
    void (*func[COMMANDS_NB])(client_t * client, char **params) = {
        &exec_user, &exec_pass, &exec_cwd, &exec_cdup, &exec_quit, &exec_dele,
        &exec_pwd, &exec_pasv, &exec_port, &exec_help, &exec_noop, &exec_retr,
        &exec_stor, &exec_port};
    (*func[i])(client, params);
}

bool handle_command(ftp_t *server, client_t *client, char **input)
{
    const char *cmds[COMMANDS_NB] = {"USER", "PASS", "CWD", "CDUP", "QUIT",
                                     "DELE", "PWD", "PASV", "PORT", "HELP", "NOOP",
                                     "RETR", "STOR", "PORT"};

    if (input == NULL || input[0] == NULL)
    {
        dprintf(client->fd, "500 Unknown command.\n");
        return false;
    }
    for (int i = 0; i < COMMANDS_NB; i++)
    {
        if (!strcmp(input[0], cmds[i]))
        {
            execute_command(server, client, &input[1], i);
            return true;
        }
    }
    dprintf(client->fd, "500 Unknown command.\n");
    return false;
}

int loop(ftp_t *server)
{
    struct sockaddr_in cli;
    client_t *client = malloc(sizeof(client_t));

    while (true)
    {
        client->fd = accept(server->server_fd,
                            (struct sockaddr *)&cli, (socklen_t *)&server->sock_size);
        if (client->fd != -1)
        {
            printf("ACCEPTED CLIENT");
            if (fork() == 0)
            {
                client = init_client(client, server->path, cli);
                run_client(server, client);
            }
            else
                close(client->fd);
        }
    }
    return 0;
}

int main(int argc, char **argv)
{
    ftp_t *server = malloc(sizeof(ftp_t));

    if (server == NULL || (argc != 2 && argc != 3))
        return RETURN_FAILURE;
    if (argc == 2)
        return (print_helper(argv[1]));
    server = init_server(argv[1], argv[2]);
    if (!server || !start_server(server))
    {
        free(server);
        return RETURN_FAILURE;
    }
    loop(server);
}
