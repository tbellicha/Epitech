/*
** EPITECH PROJECT, 2022
** B-PSU-400-NAN-4-1-nmobjdump-tanguy.bellicha
** File description:
** main
*/

#include "obj.h"

int main(int argc, char** argv)
{
    bool is_any_error = false;

    if (argc == 1)
        return (!compute_obj("a.out"));
    for (int i = 0; i < (argc - 1); i++)
        if (!compute_obj(argv[i + 1]))
            is_any_error = true;
    return (is_any_error);
}

bool compute_obj(char* filenm)
{
    t_elf data;

    data.ehdr = read_elf_file(filenm);
    if (data.ehdr == NULL) {
        fprintf(stderr, "objdump: '%s': No such file\n", filenm);
        return (false);
    }
    if (data.ehdr->e_ident[EI_CLASS] != 2)
        exit(0);
    if (!check_if_elf_file(data.ehdr)) {
        fprintf(stderr, "objdump: '%s': file format not recognized\n", filenm);
        return (false);
    }
    data.filename = filenm;
    data.shdr = fill_section(data);
    print_header(data);
    return (true);
}

Elf(Shdr)* fill_section(t_elf data)
{
    Elf(Shdr)* section = NULL;

    for (int i = 1; i < (data.ehdr->e_shnum - 1); i++) {
        section = (void*) (&(data.ehdr + data.ehdr->e_shoff)[i]);
    }
    return (section);
}