/***************************************
* This is important header file. 
*
* Type for abonent record defined here.
*
* Main limits of program as
* defines describes.
****************************************/

#ifndef _PHONEBOOK_DATA_H_

#define _PHONEBOOK_DATA_H_


/* Limits */
#define MAX_STR_LEN 32
/*#define PHONEBOOK_MAX_REC 2*/

/* Type for abonent records */
typedef struct abonent_record {
    char name[MAX_STR_LEN];
    char surname[MAX_STR_LEN];
    char phone[MAX_STR_LEN];
} abonent_record;

/* Type for unsigned int */
typedef unsigned int uint;

/* Type for phonebook on dynamic array */
typedef struct phonebook {
    abonent_record* abonents;
    uint size;
} phonebook;

/* Just about number of records in phonebook */
int how_many_records(phonebook* phone_book);

/* Maybe our phonebook doesn't have enough place for new records?  */
int is_place_for_new_record(phonebook* phone_book);

/* If it's needed another piece of memory for new records */
int try_to_take_more_memory(phonebook* phone_book);

/* Maybe our phonebook doesn't have any records at all?  */
int are_records_in_phonebook(phonebook* phone_book);

/* Where we will place new record? 
   This function gives us an index of this place in array */
int index_of_first_empty_place_in_phonebook(phonebook* phone_book);

/* search for next existing record in array,
   because of empty places cans be there! */
int get_index_of_next_existing_record(phonebook* phone_book, \
                                      int current_index);

/* This function do as its name says about */
int delete_record_from_phonebook_by_index(phonebook* phone_book, \
                                          int delete_index);

/* Search for abonent in phonebook.
   [And], [or] modes of search... 
   Will return next index, if it's exist.*/
int search_index_of_abonent_from_current(phonebook* phone_book, \
                                         abonent_record* what_to_search, \
                                         int current_index, \
                                         int and_search_flag);

#endif
