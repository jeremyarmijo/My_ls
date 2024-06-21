/*
** EPITECH PROJECT, 2023
** l s
** File description:
** first version
*/
#include "my.h"

char **list(char **buffer, int nbdir)
{
    struct dirent *file;
    DIR *stream = opendir(".");
    int nbtab = 0;
    int nbchar = 0;

    buffer[nbdir] = 0;
    file = readdir(stream);
    while (file != NULL){
        if (file->d_name[0] == '.'){
            file = readdir(stream);
        } else {
            nbchar = my_strlen(file->d_name);
            buffer[nbtab] = file->d_name;
            buffer[nbtab][nbchar] = '\0';
            file = readdir(stream);
            nbtab++;
            nbchar = 0;
        }
    }
    return buffer;
}
