/*
** EPITECH PROJECT, 2023
** l s
** File description:
** first version
*/
#include "my.h"

void allfiles(char **av)
{
    DIR *stream = directory_or_not(av);
    struct dirent *file;

    if (stream == NULL)
        return;
    file = readdir(stream);
    while (file != 0) {
        my_printf("%s  ", file->d_name);
        file = readdir(stream);
    }
    my_printf("\n");
    closedir(stream);
}
