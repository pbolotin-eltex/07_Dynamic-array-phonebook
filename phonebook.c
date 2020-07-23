/**********************************
* PHONEBOOK on C-Array [10 records]
* Super Static Project!
* Add, View, Delete, Search, Quit!
**********************************/
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

#include "phonebook_menu_logic.h"

abonent_record* array[PHONEBOOK_MAX_REC];

phonebook phone_book;

int main() {
    /* This part of code is needed every time when need a reallocation of memory
    */
    phone_book.size = 0;
    void* new_ptr = realloc(NULL, sizeof(abonent_record) * PHONEBOOK_MAX_REC);
    if(NULL == new_ptr) {
        perror("Out of memory!\n");
        exit(EXIT_FAILURE);
    }
    phone_book.abonents = (abonent_record*)new_ptr;
    memset(phone_book.abonents, 0, sizeof(abonent_record) * PHONEBOOK_MAX_REC);
    /* End of the part of code, that's needed when was used a reallocation. */
    main_menu(&phone_book);
    
    free(phone_book.abonents);

    return 0;
}
