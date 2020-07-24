/***************************************************
* Data manipulation part, all about work with
* PHONEBOOK BASE DATA, get metrics and analysys...
***************************************************/
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "phonebook_data.h"

/* Just about number of records in phonebook */
int how_many_records(phonebook* phone_book) {
    if(NULL == phone_book->abonents) return -1;

    int counter = 0;
    for(int i = 0; i < phone_book->size; i++) {
        if(0 != phone_book->abonents[i].name[0] ||
           0 != phone_book->abonents[i].surname[0] ||
           0 != phone_book->abonents[i].phone[0]) counter++;
    }
    return counter;
}

/* Maybe our phonebook don't have enough place for new records?  */
int is_place_for_new_record(phonebook* phone_book) {
    int h_m_r = how_many_records(phone_book);
    if(-1 != h_m_r && h_m_r < phone_book->size) {
        return 1;
    }
    return 0;
}

/* If it's needed another piece of memory for new records */
int try_to_take_more_memory(phonebook* phone_book) {
    phone_book->size++;
    void* new_ptr = realloc(phone_book->abonents, \
                            sizeof(abonent_record) * phone_book->size);
    if(NULL == new_ptr) {
        perror("Out of memory!\n");
        free(phone_book->abonents);
        exit(EXIT_FAILURE);
        /*  because of exit() this 'return' will not be done */
        return -1;
    }
    phone_book->abonents = (abonent_record*)new_ptr;
    memset(&phone_book->abonents[phone_book->size-1], 0, sizeof(abonent_record));
    return 0;
}

/* Maybe our phonebook don't have any records at all?  */
int are_records_in_phonebook(phonebook* phone_book) {
    if(NULL == phone_book->abonents) return 0;
    if(phone_book->size == 0) return 0;
    return how_many_records(phone_book);
}

/* Where we will place new record? 
   This function gives us an index of this place in array */
int index_of_first_empty_place_in_phonebook(phonebook* phone_book) {
    for(int i = 0; i < phone_book->size; i++) {
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
    for(int i = 0; i < phone_book->size; i++) {
        int index = (i + current_index + 1) % phone_book->size;
        if(0 != phone_book->abonents[index].name[0] ||
           0 != phone_book->abonents[index].surname[0] ||
           0 != phone_book->abonents[index].phone[0]) {
            return index;
        }
    }
    return -1;
}

/* It only set zeroes on the place of "deleted" record
   It don't move other records */
int delete_record_from_phonebook_by_index(phonebook* phone_book, \
                                          int delete_index) {
    phone_book->abonents[delete_index].name[0] = 0;
    phone_book->abonents[delete_index].surname[0] = 0;
    phone_book->abonents[delete_index].phone[0] = 0;
    return 0;
}

/* It really will move other records (if any are)
to fill the place of "deleted" record. It will resize 
allocated memory to actual count of the records. */
int move_other_records_and_change_memory_size(phonebook* phone_book, \
                                              int to_where_move_index) {
    if(to_where_move_index != phone_book->size - 1) {
        /* Move records */
        printf("to_where_move_index: %d", to_where_move_index);
        memmove(&phone_book->abonents[to_where_move_index], \
                &phone_book->abonents[to_where_move_index + 1],\
                sizeof(abonent_record) * \
                    (phone_book->size - 1 - to_where_move_index));
    }

    phone_book->size--;
    /* Change size of the alllocated memory */
    if(0 == phone_book->size) {
        free(phone_book->abonents);
        phone_book->abonents = NULL;
    } else {
        void* new_ptr = realloc(phone_book->abonents, \
                                sizeof(abonent_record) * phone_book->size);
        if(NULL == new_ptr) {
            perror("Out of memory!\n");
            free(phone_book->abonents);
            exit(EXIT_FAILURE);
            /*  because of exit() this 'return' will not be done */
            return -1;
        }
        phone_book->abonents = (abonent_record*)new_ptr;
    }
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
    for(int i = 0; i < phone_book->size; i++) {
        int index = (i + current_index + 1) % phone_book->size;
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
