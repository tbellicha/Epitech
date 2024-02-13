/*
** EPITECH PROJECT, 2022
** B-PSU-400-NAN-4-1-nmobjdump-tanguy.bellicha
** File description:
** read_header
*/

#include "my.h"

bool check_if_elf_file(Elf(Ehdr)* ehdr)
{
    if (memcmp(ehdr->e_ident, ELFMAG, SELFMAG) == 0)
        return (true);
    return (false);
}

Elf(Ehdr)* read_elf_file(char* filename)
{
    int fd = 0;
    void* buffer = NULL;
    struct stat stat;
    Elf(Ehdr)* elf;

    if ((fd = open(filename, O_RDONLY)) != -1) {
        fstat(fd, &stat);
        buffer = mmap(NULL, stat.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
        close(fd);
        if (buffer != (void *) -1) {
            elf = buffer;
            return (elf);
        }
    }
    return (NULL);
}

char* get_nb_bit(void)
{
    if (__LP64__)
        return ("64");
    return ("32");
}
