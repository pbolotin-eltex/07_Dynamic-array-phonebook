# Make C-Array-phonebook

.PHONY = clean
CC := gcc

phonebook : phonebook.o \
            phonebook_data.o \
            phonebook_interactions.o \
            phonebook_menu_logic.o \
            phonebook_show.o

phonebook.o : phonebook.c

phonebook_data.o : phonebook_data.c
phonebook_data.o : phonebook_data.h

phonebook_interactios.o : phonebook_interactions.c
phonebook_interactios.o : phonebook_interactions.h

phonebook_menu_logic.o : phonebook_menu_logic.c
phonebook_menu_logic.o : phonebook_menu_logic.h

phonebook_show.o : phonebook_show.c
phonebook_show.o : phonebook_show.h

clean :
	rm -f *.o phonebook
