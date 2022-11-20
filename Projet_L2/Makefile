CC= gcc        # compilateur
CFLAGS= -Wall -Werror -Wextra -g -std=c99 # options de compilation pour les sources C
SRC=main.c Creation_arbres/*.c Fonctionnalites/*.c Lecture_fichier/*.c Free_Fonction/*.c
OBJ=$(SRC:.c=.o)
EXEC=main

all: $(EXEC)

main: $(OBJ)
	$(CC) $(CFLAGS) $(SRC) -o $(EXEC)

clean:
	rm -rf main *.o Creation_arbres/*.o Fonctionnalites/*.o Lecture_fichier/*.o Free_Fonction/*.o
