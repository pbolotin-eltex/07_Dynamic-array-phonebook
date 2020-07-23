/******************************************
*
*  SHOW must Go On!
*  And functions here for this!
*
*******************************************
*  Interface part of program here.
******************************************/
#include <stdio.h>

int clear_screen() {
    printf("%s", "\e[1;1H\e[2J");
    return 0;
}

int show_main_menu() {
    clear_screen();
    printf(" * Phonebook Menu\n\n\
Type number and press [enter]:\n\
 * 1. Add new record into phonebook\n\
 * 2. View records\n\
 * 3. Delete record\n\
 * 4. Search abonent\n\
 * 5. Quit\n\n\
Number:");
    return 0;
}

int show_add_menu() {
    clear_screen();
    printf(" * Add new record\n\
Enter name, surname, phone of person\n\n");
    return 0;
}

int show_view_menu() {
    printf("\n * 1. To view next record in phonebook (cyclical)\n\
 * Some different number to return to main menu.\n\
Number:");
    return 0;
}

int show_del_menu() {
    printf("\n * 1. To view next record in phonebook (cyclical)\n\
 * 2. To delete this record (you can see that above)\n\
 * Some different number to return to main menu.\n\
Number:");
    return 0;
}

int show_invoice_geting_data_for_search() {
    clear_screen();
    printf(" * Search record menu\n\n\
 * Enter name, surname, phone of person\n\
 * Enter type of search [and] [or]\n\
 * After searching you can view what was found (if any)\n\n");
    return 0;
}

int show_search_menu() {
    printf("\n * 1. To view next record what was found in phonebook (cyclical)\n\
 * Some different number to return to main menu.\n\
Number:");
    return 0;
}

int show_quit_menu() {
    printf(" * Are you sure you want to quit?\n\
 * 1. No, I want to stay here and return to main menu.\n\
 * 2. Yes, I really need to go away...\n\n");
    return 0;
}

int show_no_place_message() {
    printf("Sorry. No place in your phonebook\n\
for information about your new friend\n\
You can spend your money for our new phonebook\n\
that can keep information about all your contacts! No more limits!\n");
    return 0;
}

int show_no_records_message() {
    printf("Great. No any records in your phonebook yet.\n\
So you can add new record into it.\n\
Or maybe you just like when there is nobody.\n\
It's your right!");
    return 0;
}

int show_no_found_message() {
    printf("No records was found...\n");
}

int show_phone_invoice() {
    printf("phone:");
    return 0;
}

int show_name_invoice() {
    printf("name:");
    return 0;
}

int show_surname_invoice() {
    printf("surname:");
    return 0;
}

int show_flag_invoice() {
    printf(" 0. Or-search\n\
 1. And-search\n\
:");
    return 0;
}

int show_name(char *name, size_t length) {
    printf("    Name of person:");
    /*For safety, temporary change last char to zero*/
    char temp = name[length-1];
    name[length-1] = 0;
    
    fputs(name, stdout);
    
    name[length-1] = temp;
    return 0;
}

int show_surname(char *surname, size_t length) {
    printf("    Surname of person:");
    /*For safety, temporary change last char to zero*/
    char temp = surname[length-1];
    surname[length-1] = 0;
    
    fputs(surname, stdout);
    
    surname[length-1] = temp;
    return 0;
}

int show_phone(char *phone, size_t length) {
    printf("    Phone of person:");
    /*For safety, temporary change last char to zero*/
    char temp = phone[length-1];
    phone[length-1] = 0;
    
    fputs(phone, stdout);
    
    phone[length-1] = temp;
    return 0;
}
