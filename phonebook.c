/**********************************
* PHONEBOOK on C-Array [10 records]
* Super Static Project!
* Add, View, Delete, Search, Quit!
**********************************/
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

#include "phonebook_menu_logic.h"

phonebook phone_book;

int main() {
    phone_book.size = 0;
    phone_book.abonents = NULL;

    main_menu(&phone_book);
    
    free(phone_book.abonents);

    return 0;
}
