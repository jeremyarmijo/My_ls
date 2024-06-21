/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** write int in oct
*/
#include "my.h"

int my_put_oct(int n)
{
    if (n >= 0 && n < 8) {
        my_putchar(n + 48);
    } else {
        my_put_oct(n / 8);
        my_putchar(n % 8 + 48);
    }
    return 1;
}
