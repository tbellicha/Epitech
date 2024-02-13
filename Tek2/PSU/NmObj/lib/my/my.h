/*
** EPITECH PROJECT, 2022
** B-PSU-400-NAN-4-1-nmobjdump-tanguy.bellicha
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

    #include <elf.h>
    #include <fcntl.h>
    #include <stdio.h>
    #include <sys/mman.h>
    #include <sys/stat.h>
    #include <stdbool.h>
    #include <string.h>
    #include <unistd.h>

    #if defined(__LP64__)
        #define Elf(type) Elf64_ ## type
    #else
        #define Elf(type) Elf32_ ## type
    #endif

typedef struct s_elf {
    char* filename;
    unsigned int flags;
    Elf(Ehdr)* ehdr;
    Elf(Shdr)* shdr;
} t_elf;

bool check_if_elf_file(Elf(Ehdr)* ehdr);
Elf(Ehdr)* read_elf_file(char* filename);
char* get_nb_bit(void);

#endif /* !MY_H_ */
