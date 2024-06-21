/*
** EPITECH PROJECT, 2023
** l s
** File description:
** first version
*/
#include "my.h"

char *cutstr(char *str)
{
    char *tmp = str + 3;

    str = tmp;
    str[12] = '\0';
    return str;
}

void right_dir(struct stat *buf)
{
    my_printf(S_ISDIR(buf->st_mode) ? "d" : "-");
    my_printf(buf->st_mode & S_IRUSR ? "r" : "-");
    my_printf(buf->st_mode & S_IWUSR ? "w" : "-");
    my_printf(buf->st_mode & S_IXUSR ? "x" : "-");
    my_printf(buf->st_mode & S_IRGRP ? "r" : "-");
    my_printf(buf->st_mode & S_IWGRP ? "w" : "-");
    my_printf(buf->st_mode & S_IXGRP ? "x" : "-");
    my_printf(buf->st_mode & S_IROTH ? "r" : "-");
    my_printf(buf->st_mode & S_IWOTH ? "w" : "-");
    my_printf(buf->st_mode & S_IXOTH ? "x. " : "-. ");
}

void total_ls_l(char **av)
{
    struct dirent *filetmp;
    struct stat buftmp;
    DIR *streamtmp = directory_or_not(av);
    int nb = 0;

    if (streamtmp == NULL)
        return;
    filetmp = readdir(streamtmp);
    while (filetmp != NULL){
        if (filetmp->d_name[0] == '.')
            filetmp = readdir(streamtmp);
        else {
            stat(filetmp->d_name, &buftmp);
            nb = (buftmp.st_blocks / 2) + nb;
            filetmp = readdir(streamtmp);
        }
    }
    my_printf("total %d\n", nb);
    closedir(streamtmp);
}

void print_ls_l(INITS_1, struct stat *buf, struct group **grp, char **str)
{
    *id = getpwuid(buf->st_uid);
    *grp = getgrgid(buf->st_gid);
    right_dir(buf);
    my_printf("%d %s ", buf->st_nlink, (*id)->pw_name);
    if (*grp != NULL)
        my_printf("%s  %d", (*grp)->gr_name, buf->st_size);
    *str = (ctime(&buf->st_mtime));
    *str = cutstr(*str);
}

void statfiles(char **av)
{
    struct dirent *file;
    DIR *stream = present_dir(av);
    struct stat buf;
    struct passwd *id;
    struct group *grp;
    char *str;

    if (stream == NULL)
        return;
    total_ls_l(av);
    file = readdir(stream);
    while (file != NULL){
        if (file->d_name[0] == '.')
            file = readdir(stream);
        else {
            stat(file->d_name, &buf);
            print_ls_l(&id, &buf, &grp, &str);
            file = next_file(file, stream, str);
        }
    }
}
