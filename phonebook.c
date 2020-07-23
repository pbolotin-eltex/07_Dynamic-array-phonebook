/**********************************
* PHONEBOOK on C-Array [10 records]
* Super Static Project!
* Add, View, Delete, Search, Quit!
**********************************/
#include "phonebook_menu_logic.h"

abonent_record phonebook[PHONEBOOK_MAX_REC];

int main() {
    main_menu(phonebook);
    return 0;
}
