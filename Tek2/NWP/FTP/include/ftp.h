/*
** EPITECH PROJECT, 2022
** Projects
** File description:
** ftp
*/

#ifndef FTP_H_
    #define FTP_H_

    #include <unistd.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <stdbool.h>

    #define HELPER_CMD "-help"

    #define RETURN_SUCCESS 0
    #define RETURN_FAILURE 84
    #define RETURN_HELPER 0

    #define CLIENT_MAX_NB 8
    #define BUFFER_SIZE 256
    #define COMMANDS_NB 14

typedef enum login_status_e {
    LOGIN_NONE,
    LOGIN_USER,
    LOGIN_CNCT,
    LOGIN_DISC
} login_status;

typedef struct ftp_s {
    int port;
    char *path;
    struct sockaddr_in sock;
    int sock_size;
    int server_fd;
} ftp_t;

typedef struct client_s {
    int fd;
    char *username;
    char *password;
    char *path;
    login_status login;;
    char *ip;
    bool is_pasv_open;
    int pasv_fd;
    int pasv_port;
    int pasv_sock_size;
    struct sockaddr_in pasv_sock;
} client_t;

/*--------------------[SERVER]--------------------*/
ftp_t *init_sock(ftp_t *ftp);
ftp_t* init_server(char *port, char *path);
bool start_server(ftp_t* server);

/*--------------------[HELPER]--------------------*/
int print_helper(const char *arg);

/*--------------------[COMMAND]--------------------*/
void exec_user(client_t *client, char **params);
void exec_pass(client_t *client, char **params);

void exec_cwd(client_t *client, char **params);
void exec_cdup(client_t *client, char **params);

void exec_quit(client_t *client, char **params);

void exec_dele(client_t *client, char **params);

void exec_pwd(client_t *client, char **params);

void exec_pasv(client_t *client, char **params);

void exec_help(client_t *client, char **params);

void exec_noop(client_t *client, char **params);

void exec_retr(client_t *client, char **params);
void exec_stor(client_t *client, char **params);
void exec_list(client_t *client, char **params);

/*--------------------[ARRAY]--------------------*/
char **str_to_word_array(char *str, char *sep);
void free_array(char **array);
int get_array_size(const char **array);

/*--------------------[PORT]--------------------*/
void exec_port(client_t *client, char **params);
bool check_port(const char* port);

/*--------------------[MAIN]--------------------*/
bool handle_command(ftp_t* server, client_t *client, char **input);

/*--------------------[CLIENT]--------------------*/
client_t* init_client(client_t* client, char *path,
struct sockaddr_in cli);
void run_client(ftp_t *server, client_t *client);

#endif/* !FTP_H_ */
