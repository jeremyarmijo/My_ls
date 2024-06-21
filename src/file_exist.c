/*
** EPITECH PROJECT, 2023
** l s
** File description:
** first version
*/
#include "my.h"

int nb_dir(char **str)
{
    int i = 0;

    while (str[i] != 0) {
        i++;
    }
    return i;
}

void file_exist(char *av, char **filedir, int nbdir, int error)
{
    int cpt2 = 0;
    int p = 0;

    if (error == 84)
        return;
    while (filedir[cpt2] != NULL){
        p = my_strcmp(av, filedir[cpt2]);
            if (p == 1){
                break;
            }
            cpt2++;
    }
    if (cpt2 != nbdir) {
        my_printf("%s  ", filedir[cpt2]);
    }
}
