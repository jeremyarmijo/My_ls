/*
** EPITECH PROJECT, 2023
** l s
** File description:
** first version
*/
#include "my.h"

void onefiledot(char **str)
{
    DIR *stream;
    int i = 0;

    while (str[i] != NULL)
        i++;
    if (i == 3) {
        stream = opendir(str[2]);
        if (stream != NULL)
            my_printf("%s\n", str[2]);
        if (stream == NULL) {
            my_printf("ls: cannot access '%s': ", str[2]);
            my_printf("No such file or directory\n");
        }
    }
    if (i == 2)
        my_printf(".\n");
}
