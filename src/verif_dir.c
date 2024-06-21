/*
** EPITECH PROJECT, 2023
** l s
** File description:
** first version
*/
#include "my.h"

DIR *directory_or_not(char **av)
{
    int i = 0;
    DIR *stream;

    while (av[i] != NULL)
        i++;
    if (i == 3) {
        stream = opendir(av[2]);
        if (stream == NULL) {
            my_printf("ls: cannot access '%s': ", av[2]);
            my_printf("No such file or directory\n");
        }
    }
    if (i == 2)
        stream = opendir(".");
    return stream;
}

DIR *present_dir(char **av)
{
    int i = 0;
    DIR *stream;

    while (av[i] != NULL)
        i++;
    if (i == 3 && opendir(av[2]) == NULL) {
            my_printf("ls: cannot access '%s': ", av[2]);
            my_printf("No such file or directory\n");
            return NULL;
    }
    stream = opendir(av[2] ? av[2] : ".");
    return stream;
}

struct dirent *next_file(struct dirent *file, DIR *stream, char *str)
{
    my_printf("%s %s\n", str, file->d_name);
    file = readdir(stream);
    return file;
}
