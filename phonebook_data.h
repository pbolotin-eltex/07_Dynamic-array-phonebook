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
#define PHONEBOOK_MAX_REC 10

/* Type for abonent records */
typedef struct abonent_record {
    char name[MAX_STR_LEN];
    char surname[MAX_STR_LEN];
    char phone[MAX_STR_LEN];
} abonent_record;

/* Just about number of records in phonebook */
int how_many_records(abonent_record* phonebook);

/* Maybe our phonebook doesn't have enough place for new records?  */
int is_place_for_new_record(abonent_record* phonebook);

/* Maybe our phonebook doesn't have any records at all?  */
int are_records_in_phonebook(abonent_record* phonebook);

/* Where we will place new record? 
   This function gives us an index of this place in array */
int index_of_first_empty_place_in_phonebook(abonent_record* phonebook);

/* search for next existing record in array,
   because of empty places cans be there! */
int get_index_of_next_existing_record(abonent_record* phonebook, \
                                      int current_index);

/* This function do as its name says about */
int delete_record_from_phonebook_by_index(abonent_record* phonebook, \
                                          int delete_index);

/* Search for abonent in phonebook.
   [And], [or] modes of search... 
   Will return next index, if it's exist.*/
int search_index_of_abonent_from_current(abonent_record* phonebook, \
                                         abonent_record* what_to_search, \
                                         int current_index, \
                                         int and_search_flag);

#endif
