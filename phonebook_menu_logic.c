/**********************************
* THIS PART for BEHAVIOR LOGIC of
* this program.
**********************************/
#include "phonebook_menu_logic.h"
#include "phonebook_show.h"
#include "phonebook_interactions.h"

/* High level menu */
int main_menu(abonent_record* phonebook) {
    int quit_choice = 0;

    while(!quit_choice) {
        show_main_menu();
        switch(get_user_choice()) {
        /**** Add case ****/            
        case 1:
            if(is_place_for_new_record(phonebook)) {
                add_menu(phonebook);
            } else {
                show_no_place_message();
                get_user_reaction();
            }
            break;
        /**** View case ****/            
        case 2:
            if(are_records_in_phonebook(phonebook)) {
                int view_index = -1;
                do {
                    view_index = get_index_of_next_existing_record(phonebook, \
                                                                   view_index);
                    view_menu(phonebook, view_index);
                } while(get_user_choice() == 1);
            } else {
                show_no_records_message();
                get_user_reaction();
            }
            break;
        /**** Delete case ****/            
        case 3:
            if(are_records_in_phonebook(phonebook)) {
                int view_index = -1;
                int user_choice = 1;
                do {
                    view_index = get_index_of_next_existing_record(phonebook, \
                                                                   view_index);
                    del_menu(phonebook, view_index);
                    user_choice = get_user_choice();
                    if(user_choice == 2) {
                        delete_record_from_phonebook_by_index(phonebook, \
                                                                   view_index);
                    }
                /* 1 - continue viewing, 2 delete and continue viewing */    
                } while((1 == user_choice || 2 == user_choice) && \
                         are_records_in_phonebook(phonebook));
            } else {
                show_no_records_message();
                get_user_reaction();
            }
            break;
        /**** Search case ****/                        
        case 4:
            if(are_records_in_phonebook(phonebook)) {
                abonent_record to_search;
                int and_mode = 0;
                get_data_for_search(&to_search, &and_mode);
                int current = -1;
                int user_choice = 1;
                int was_found = 0;
                do {
                    current = search_index_of_abonent_from_current(phonebook, \
                                                                   &to_search,\
                                                                   current, \
                                                                   and_mode);
                    if(current == -1) {
                        show_no_found_message();
                        get_user_reaction();
                    } else {
                        was_found = 1;
                        search_menu(phonebook, &to_search, current);
                        user_choice = get_user_choice();
                    }
                } while(1 == user_choice && was_found);
            } else {
                show_no_records_message();
                get_user_reaction();
            }
            break;
        /**** Quit case ****/                        
        case 5:
            quit_choice = quit_menu(phonebook);
            break;
        default:;
        }
    }
    return 0;
}

/* submenu for add record */
int add_menu(abonent_record* phonebook) {
    show_add_menu();
    add_dialog(phonebook);
    return 0;
}

int add_dialog(abonent_record* phonebook) {
    int index = index_of_first_empty_place_in_phonebook(phonebook);
    show_name_invoice();
    get_field_data_from_user(phonebook[index].name, MAX_STR_LEN);
    show_surname_invoice();
    get_field_data_from_user(phonebook[index].surname, MAX_STR_LEN);
    show_phone_invoice();
    get_field_data_from_user(phonebook[index].phone, MAX_STR_LEN);
    return 0;
}

/* submenu for view records */
int view_menu(abonent_record* phonebook, int view_index) {
    clear_screen();
    show_name(phonebook[view_index].name, MAX_STR_LEN);
    show_surname(phonebook[view_index].surname, MAX_STR_LEN);
    show_phone(phonebook[view_index].phone, MAX_STR_LEN);
    show_view_menu();
    return 0;
}

/* submenu for delete records */
int del_menu(abonent_record* phonebook, int view_index) {
    clear_screen();
    show_name(phonebook[view_index].name, MAX_STR_LEN);
    show_surname(phonebook[view_index].surname, MAX_STR_LEN);
    show_phone(phonebook[view_index].phone, MAX_STR_LEN);
    show_del_menu();
    return 0;
}

/* submenu for search for records */
int search_menu(abonent_record* phonebook,
                abonent_record* look_for_abonent,\
                int view_index) {
    clear_screen();
    show_name(phonebook[view_index].name, MAX_STR_LEN);
    show_surname(phonebook[view_index].surname, MAX_STR_LEN);
    show_phone(phonebook[view_index].phone, MAX_STR_LEN);
    show_search_menu();
    return 0;
}

int get_data_for_search(abonent_record* phonebook, int* and_search_flag) {
    clear_screen();
    show_invoice_geting_data_for_search();
    get_data_for_search_dialog(phonebook, and_search_flag);
    return 0;    
}

int get_data_for_search_dialog(abonent_record* to_search, int* and_mode) {
    show_name_invoice();
    get_field_data_from_user(to_search->name, MAX_STR_LEN);
    show_surname_invoice();
    get_field_data_from_user(to_search->surname, MAX_STR_LEN);
    show_phone_invoice();
    get_field_data_from_user(to_search->phone, MAX_STR_LEN);
    show_flag_invoice();
    if(get_user_choice() != 0) *and_mode = 1;
    return 0;
}

/* submenu for quit */
int quit_menu(abonent_record* phonebook) {
    clear_screen();
    show_quit_menu();
    if(get_user_choice() == 2) return 1;
    else return 0;
}
