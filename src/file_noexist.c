/*
** EPITECH PROJECT, 2023
** l s
** File description:
** first version
*/
#include "my.h"

int file_noexist(char *av, char **listdir, int nbdir)
{
    int cpt = 0;
    int y = 0;

    while (listdir[cpt] != NULL){
        y = my_strcmp(av, listdir[cpt]);
            if (y == 42){
            cpt++;
            } else {
                break;
            }
    }
    if (cpt == nbdir && av[0] != '-'){
        my_printf("ls: cannot access '%s'", av);
        my_printf(": No such file or directory\n");
        return 84;
    }
    return 0;
}
