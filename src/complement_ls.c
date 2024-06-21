/*
** EPITECH PROJECT, 2023
** l s
** File description:
** first version
*/
#include "my.h"

int complement_ls(char **av, char **listdir, int nbdir)
{
    int error = 0;
    int x = 1;
    int y = 0;

    while (av[x] != NULL)
        x++;
    for (int i = 1; av[i] != 0; i++) {
        if (opendir(av[i]) != NULL) {
                openfile_dir(av);
            } else {
                error = file_noexist(av[i], listdir, nbdir);
                file_exist(av[i], listdir, nbdir, error);
                y++;
        }
    }
    x = x - 1;
    if (x == y && error != 84)
        my_printf("\n");
    return error;
}
