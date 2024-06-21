/*
** EPITECH PROJECT, 2023
** headers
** File description:
** function for my_printf
*/
#include <stdarg.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

#ifndef MY
    #define MY
    #define INITS_1 struct passwd **id

struct dirent *next_file(struct dirent *file, DIR *stream, char *str);
DIR *present_dir(char **av);
DIR *directory_or_not(char **av);
void statfiles(char **av);
int return_nbtabdir(void);
int file_noexist(char *av, char **listdir, int nbdir);
int complement_ls(char **av, char **listdir, int nbdir);
int my_strcmp(char *str, char *list);
char **list(char **buffer, int nbdir);
void file_exist(char *av, char **filedir, int nbdir, int error);
int return_nbtabdir(void);
void onefiledot(char **str);
void lsclassic(void);
void allfiles(char **av);
int my_strlen(char *str);
void openfile_dir(char **av);
void display_output(int nb, int nbf, int count);
int percent_e(va_list args, const char *format, int *z);
void my_put_scientific_notation(double nb);
int percent_u(va_list args, const char *format, int *z);
int my_put_long_int(unsigned int n);
int my_put_u(long nb);
int percent_f(va_list agrs, const char *format, int *z);
int my_put_float(double nb);
void dif_de_percent(va_list args, const char *format, int *z);
int writeelse(const char *format, int *z);
int percent_s(va_list agrs, const char *format, int *z);
int percent_di(va_list args, const char *format, int *z);
int percent_c(va_list args, const char *format, int *z);
int percent_percent(const char *format, int *z);
int percent_exa(va_list args, const char *format, int *z);
int percent_examaj(va_list args, const char *format, int *z);
int percent_oct(va_list args, const char *format, int *z);
int my_printf(const char *format, ...);
int my_put_exa(int n);
int my_put_examaj(int n);
int my_put_oct(int i);
void my_putchar(char c);
int my_putstr(const char *str);
int my_put_nbr(int n);
int findflagnb(const char *str, char c);
#endif
