/*************************
* functions for output of
* user-interfaces
*************************/

#ifndef _PHONEBOOK_SHOW_H_

#define _PHONEBOOK_SHOW_H_

#include <stddef.h>

int show_main_menu();

int show_add_menu();

int show_view_menu();

int show_del_menu();

int show_search_menu();

int show_quit_menu();

int show_no_place_message();

int show_no_records_message();

int show_no_found_message();

int show_phone_invoice();

int show_name_invoice();

int show_surname_invoice();

int show_flag_invoice();

int show_name(char *name, size_t length);

int show_surname(char *surname, size_t length);

int show_phone(char *phone, size_t length);

int show_invoice_geting_data_for_search();

int clear_screen();

#endif
