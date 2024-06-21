/*
** EPITECH PROJECT, 2023
** ls
** File description:
** first version
*/
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdint.h>
#include "my.h"

int ls_l(char **av)
{
    if (av[1][1] == 'l' && av[1][2] == '\0')
        statfiles(av);
    else
        return 0;
    return 1;
}

int ls_a(char **av)
{
    if (av[1][1] == 'a' && av[1][2] == '\0')
        allfiles(av);
    else
        return 0;
    return 1;
}

int ls_d(char **av)
{
    if (av[1][1] == 'd' && av[1][2] == '\0')
        onefiledot(av);
    else
        return 0;
    return 1;
}

static void print_error(char **av)
{
    my_printf("ls: cannot access '%s'", av[1]);
    my_printf(": No such file or directory\n");
}

int main(int ac, char **av)
{
    int nbdir = return_nbtabdir();
    char **listdir = malloc(nbdir * (sizeof(char *)) + 1);
    int error = 0;
    int nbflags = 0;

    listdir = list(listdir, nbdir);
    if (ac >= 2 && av[1][0] == '-'){
        nbflags = ls_a(av);
        nbflags = nbflags + ls_d(av);
        nbflags = nbflags + ls_l(av);
        if (nbflags == 0) {
            print_error(av);
            return 84;
        }
    } else if (ac >= 2)
        error = complement_ls(av, listdir, nbdir);
    if (ac == 1)
        lsclassic();
    return error;
}
