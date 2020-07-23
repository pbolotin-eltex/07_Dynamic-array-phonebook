/**********************************
* PHONEBOOK on C-Array [10 records]
* Super Static Project!
* Add, View, Delete, Search, Quit!
**********************************/
#include "phonebook_menu_logic.h"

abonent_record array[PHONEBOOK_MAX_REC];

phonebook phone_book;

int main() {
    phone_book.size = PHONEBOOK_MAX_REC;
    phone_book.abonents = array;
    main_menu(&phone_book);
    return 0;
}
