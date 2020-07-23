/***************************************************
* Data manipulation part, all about work with
* PHONEBOOK BASE DATA, get metrics and analysys...
***************************************************/
#include <stdio.h>
#include <string.h>
#include "phonebook_data.h"

/* Just about number of records in phonebook */
int how_many_records(abonent_record* phonebook) {
    if(NULL == phonebook) return -1;

    int counter = 0;
    for(int i = 0; i < PHONEBOOK_MAX_REC; i++) {
        if(0 != phonebook[i].name[0] ||
           0 != phonebook[i].surname[0] ||
           0 != phonebook[i].phone[0]) counter++;
    }
    return counter;
}

/* Maybe our phonebook don't have enough place for new records?  */
int is_place_for_new_record(abonent_record* phonebook) {
    return how_many_records(phonebook) - PHONEBOOK_MAX_REC;
}

/* Maybe our phonebook don't have any records at all?  */
int are_records_in_phonebook(abonent_record* phonebook) {
    return how_many_records(phonebook);
}

/* Where we will place new record? 
   This function gives us an index of this place in array */
int index_of_first_empty_place_in_phonebook(abonent_record* phonebook) {
    for(int i = 0; i < PHONEBOOK_MAX_REC; i++) {
        if(0 == phonebook[i].name[0] ||
           0 == phonebook[i].surname[0] ||
           0 == phonebook[i].phone[0]) return i;
    }
    return -1;
}

/* search for next existing record in array,
   because of empty places cans be there! */
int get_index_of_next_existing_record(abonent_record* phonebook, \
                                      int current_index) {
    if(current_index < 0) {
        current_index = -1;
    }
    for(int i = 0; i < PHONEBOOK_MAX_REC; i++) {
        int index = (i + current_index + 1)%PHONEBOOK_MAX_REC;
        if(0 != phonebook[index].name[0] ||
           0 != phonebook[index].surname[0] ||
           0 != phonebook[index].phone[0]) {
            return index;
        }
    }
    return -1;
}

/* This function do as its name says about */
int delete_record_from_phonebook_by_index(abonent_record* phonebook, \
                                          int delete_index) {
    phonebook[delete_index].name[0] = 0;
    phonebook[delete_index].surname[0] = 0;
    phonebook[delete_index].phone[0] = 0;
    return 0;
}

/* Search for abonent in phonebook.
   [And], [or] modes of search... 
   Will return next index, if it's exist.*/
int search_index_of_abonent_from_current(abonent_record* phonebook, \
                                         abonent_record* to_search, \
                                         int current_index, \
                                         int and_search_flag) {
    if(current_index < 0) {
        current_index = -1;
    }
    for(int i = 0; i < PHONEBOOK_MAX_REC; i++) {
        int index = (i + current_index + 1)%PHONEBOOK_MAX_REC;
        if(and_search_flag) {
            if(strcmp(phonebook[index].name, to_search->name) == 0 &&
               strcmp(phonebook[index].surname, to_search->surname) == 0 &&
               strcmp(phonebook[index].phone, to_search->phone) == 0) 
               return index;
        } else {
            if(strcmp(phonebook[index].name, to_search->name) == 0 ||
               strcmp(phonebook[index].surname, to_search->surname) == 0 ||
               strcmp(phonebook[index].phone, to_search->phone) == 0)
               return index;
        }
    }
    return -1;
}
