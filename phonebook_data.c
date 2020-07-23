/***************************************************
* Data manipulation part, all about work with
* PHONEBOOK BASE DATA, get metrics and analysys...
***************************************************/
#include <stdio.h>
#include <string.h>
#include "phonebook_data.h"

/* Just about number of records in phonebook */
int how_many_records(phonebook* phone_book) {
    if(NULL == phone_book) return -1;

    int counter = 0;
    for(int i = 0; i < PHONEBOOK_MAX_REC; i++) {
        if(0 != phone_book->abonents[i].name[0] ||
           0 != phone_book->abonents[i].surname[0] ||
           0 != phone_book->abonents[i].phone[0]) counter++;
    }
    return counter;
}

/* Maybe our phonebook don't have enough place for new records?  */
int is_place_for_new_record(phonebook* phone_book) {
    return how_many_records(phone_book) - PHONEBOOK_MAX_REC;
}

/* Maybe our phonebook don't have any records at all?  */
int are_records_in_phonebook(phonebook* phone_book) {
    return how_many_records(phone_book);
}

/* Where we will place new record? 
   This function gives us an index of this place in array */
int index_of_first_empty_place_in_phonebook(phonebook* phone_book) {
    for(int i = 0; i < PHONEBOOK_MAX_REC; i++) {
        if(0 == phone_book->abonents[i].name[0] ||
           0 == phone_book->abonents[i].surname[0] ||
           0 == phone_book->abonents[i].phone[0]) return i;
    }
    return -1;
}

/* search for next existing record in array,
   because of empty places cans be there! */
int get_index_of_next_existing_record(phonebook* phone_book, \
                                      int current_index) {
    if(current_index < 0) {
        current_index = -1;
    }
    for(int i = 0; i < PHONEBOOK_MAX_REC; i++) {
        int index = (i + current_index + 1)%PHONEBOOK_MAX_REC;
        if(0 != phone_book->abonents[index].name[0] ||
           0 != phone_book->abonents[index].surname[0] ||
           0 != phone_book->abonents[index].phone[0]) {
            return index;
        }
    }
    return -1;
}

/* This function do as its name says about */
int delete_record_from_phonebook_by_index(phonebook* phone_book, \
                                          int delete_index) {
    phone_book->abonents[delete_index].name[0] = 0;
    phone_book->abonents[delete_index].surname[0] = 0;
    phone_book->abonents[delete_index].phone[0] = 0;
    return 0;
}

/* Search for abonent in phonebook.
   [And], [or] modes of search... 
   Will return next index, if it's exist.*/
int search_index_of_abonent_from_current(phonebook* phone_book, \
                                         abonent_record* to_search, \
                                         int current_index, \
                                         int and_search_flag) {
    if(current_index < 0) {
        current_index = -1;
    }
    for(int i = 0; i < PHONEBOOK_MAX_REC; i++) {
        int index = (i + current_index + 1)%PHONEBOOK_MAX_REC;
        if(and_search_flag) {
            if(strcmp(phone_book->abonents[index].name, to_search->name) == 0 &&
               strcmp(phone_book->abonents[index].surname, to_search->surname) == 0 &&
               strcmp(phone_book->abonents[index].phone, to_search->phone) == 0) 
               return index;
        } else {
            if(strcmp(phone_book->abonents[index].name, to_search->name) == 0 ||
               strcmp(phone_book->abonents[index].surname, to_search->surname) == 0 ||
               strcmp(phone_book->abonents[index].phone, to_search->phone) == 0)
               return index;
        }
    }
    return -1;
}
