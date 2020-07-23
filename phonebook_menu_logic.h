#include "phonebook_data.h"

#ifndef _PHONEBOOK_MENU_LOGIC_H_

#define _PHONEBOOK_MENU_LOGIC_H_

/* High level menu */
int main_menu(phonebook* phone_book);

/* submenu for add record */
int add_menu(phonebook* phone_book);

int add_dialog(phonebook* phone_book);

/* submenu for view records */
int view_menu(phonebook* phone_book, int view_index);

/* submenu for delete records */
int del_menu(phonebook* phone_book, int view_index);

/* submenu for search for records */
int search_menu(phonebook* phone_book, int view_index);

int get_data_for_search(abonent_record* phone_book, int *and_search_flag);

int get_data_for_search_dialog(abonent_record* what_to_search,
                               int *and_search_flag);

/* submenu for quit */
int quit_menu(phonebook* phone_book);

#endif
