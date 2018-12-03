 #!/bin/bash

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
NAME = 

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

\$(NAME): \$(OBJ)
	gcc \$(FLAGS) \$(OBJ) -o \$(NAME)

\$(OBJDIR)/%.o: ./%.c \$(INCDIR)/*.h | \$(OBJDIR)
	gcc \$(FLAGS) -o \$@ -c \$< -I \$(INCDIR)

\$(OBJDIR):
	mkdir \$(OBJDIR)

clean:
	rm -Rf \$(OBJDIR)

fclean: clean
	rm -f \$(NAME)

re: fclean all"