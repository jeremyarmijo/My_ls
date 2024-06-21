##
## EPITECH PROJECT, 2023
## makefile
## File description:
## pour my_printf
##

CC	=	gcc

SRC	=	src/my_putchar.c					\
		src/my_put_nbr.c					\
		src/my_putstr.c						\
		src/findflagnb.c					\
		src/my_put_exa.c					\
		src/my_put_oct.c					\
		src/my_put_examaj.c					\
		src/percent_s.c						\
		src/percent_di.c					\
		src/percent_c.c						\
		src/percent_percent.c				\
		src/percent_exa.c					\
		src/percent_examaj.c				\
		src/percent_oct.c					\
		src/my_printf.c						\
		src/writeelse.c						\
		src/if.c							\
		src/percent_f.c						\
		src/my_put_float.c					\
		src/my_put_scientific_notation.c	\
		src/percent_e.c						\
		src/display_output.c				\
		src/my_put_long_int.c				\
		src/percent_u.c						\
		src/my_put_u.c						\
		src/my_lstest.c						\
		src/openfile_dir.c					\
		src/my_strlen.c						\
		src/allfiles.c						\
		src/lsclassic.c						\
		src/onefiledot.c					\
		src/file_exist.c					\
		src/my_strcmp.c						\
		src/list.c							\
		src/complement_ls.c					\
		src/file_noexist.c					\
		src/return_nbtabdir.c				\
		src/statfiles.c						\
		src/verif_dir.c

OBJ	=	$(SRC:.c=.o)

NAME	= my_ls

CFLAGS	= -Wall -Wextra -iquote include

all: $(NAME)

$(NAME):	$(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)
	rm -f *#
	rm -f *~

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
