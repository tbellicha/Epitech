/*
** EPITECH PROJECT, 2022
** B-PSU-400-NAN-4-1-nmobjdump-tanguy.bellicha
** File description:
** obj
*/

#ifndef OBJ_H_
#define OBJ_H_

    #include "my.h"
    #include <stdlib.h>
    #include "flags.h"

bool compute_obj(char* filenm);
char* get_nb_bit(void);
char* get_elf_format(t_elf data);
char* get_elf_arch(t_elf data);
void print_header(t_elf data);
void get_flags(t_elf data);
Elf(Shdr)* fill_section(t_elf data);

#endif /* !OBJ_H_ */
