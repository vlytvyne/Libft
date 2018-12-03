 #!/bin/bash

#preparations

echo '\e[31;1mType in NAME variable\e[0m'
read name
echo '\e[31;1mWhat will it build?
1. Executable
2. Library
3. Else\e[0m'
read comp_type
exec > Makefile

#create header

echo "# **************************************************************************** #" 
echo "#                                                                              #"
echo "#                                                         :::      ::::::::    #"
echo "#    Makefile                                           :+:      :+:    :+:    #"
echo "#                                                     +:+ +:+         +:+      #"

printf "#    By: "
printf $USER
printf " <"
printf $USER
echo "@student.unit.ua>        +#+  +:+       +#+         #"

echo "#                                                 +#+#+#+#+#+   +#+            #"

printf "#    Created: "
date +"%Y/%m/%d %H:%M:%S" | tr -d '\n'

printf " by "
printf $USER
echo "          #+#    #+#              #"

printf "#    Updated: "
date +"%Y/%m/%d %H:%M:%S" | tr -d '\n'
printf " by "
printf $USER
echo "         ###   ########.fr        #"
echo "#                                                                              #"
echo "# **************************************************************************** #"

#Makefile start

printf "
NAME = "

echo $name

printf "
INCDIR = includes/

SRC = "

#src initialization

ls | find . -name "*.c" | cut -c 3- | tr '\n' ' '

#Makefile pattern

echo "

OBJDIR = objects

OBJ = \$(addprefix \$(OBJDIR)/, \$(SRC:.c=.o))

LIB = libft/libft.a

INCDIR = includes

FLAGS = -Wall -Werror -Wextra

.PHONY: all clean fclean re

all: \$(NAME)

\$(NAME): \$(OBJ)"

case $comp_type in
	1) echo "	gcc \$(FLAGS) \$(OBJ) -o \$(NAME)";;
 	2) echo "	ar -rcs \$(NAME) \$(OBJ)";;
 	*) echo "	!Write your compilation instructions here!";;
esac

echo "
\$(OBJDIR)/%.o: ./%.c \$(INCDIR)/*.h | \$(OBJDIR)
	gcc \$(FLAGS) -o \$@ -c \$< -I \$(INCDIR)

\$(OBJDIR):
	mkdir \$(OBJDIR)

clean:
	rm -Rf \$(OBJDIR)

fclean: clean
	rm -f \$(NAME)

re: fclean all"