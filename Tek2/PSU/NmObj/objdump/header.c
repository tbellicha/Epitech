/*
** EPITECH PROJECT, 2022
** B-PSU-400-NAN-4-1-nmobjdump-tanguy.bellicha
** File description:
** header
*/

#include "obj.h"

char* get_elf_format(t_elf data)
{
    if (data.ehdr->e_ident[EI_DATA] == 2)
        return ("big");
    if (data.ehdr->e_ident[EI_CLASS] == 2 && data.ehdr->e_machine == 0x3e)
        return ("x86-64");
    if (data.ehdr->e_ident[EI_CLASS] == 1 && data.ehdr->e_machine == 0x03)
        return ("i386");
    return ("little");
}

char* get_elf_arch(t_elf data)
{
    if (data.ehdr->e_ident[EI_DATA] == 2)
        return ("UNKNOWN!");
    if (data.ehdr->e_ident[EI_CLASS] == 2 && data.ehdr->e_machine == 0x3e)
        return ("i386:x86-64");
    if (data.ehdr->e_ident[EI_CLASS] == 1 && data.ehdr->e_machine == 0x03)
        return ("i386");
    return ("UNKNOWN!");
}

void get_flags(t_elf data)
{
	unsigned int flags = HAS_RELOC *
		(data.ehdr->e_type == ET_REL && (data.shdr->sh_type == SHT_RELA ||
			data.shdr->sh_type == SHT_REL)) |
		EXEC_P * (data.ehdr->e_type == ET_EXEC) |
		HAS_SYMS * (data.shdr->sh_type == SHT_SYMTAB ||
			data.shdr->sh_type == SHT_DYNSYM) |
		DYNAMIC * (data.ehdr->e_type == ET_DYN) | D_PAGED *
		((data.ehdr->e_type == ET_EXEC || data.ehdr->e_type == ET_DYN));

	if (flags > data.flags)
		data.flags = flags;
}

void print_header(t_elf data)
{
    printf("\n%s     file format elf%s-%s\n", data.filename,
    get_nb_bit(), get_elf_format(data));
    printf("architecture: %s, flags 0x%08x:\n", get_elf_arch(data),
    data.flags);
    printf("\n");
    printf("start adress: 0x%016x\n", (unsigned int) data.ehdr->e_entry);
}
