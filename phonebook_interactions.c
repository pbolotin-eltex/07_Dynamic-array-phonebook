/***********************************
* Ways to get important informaiton
* from user into the program data.
* Changable, of course.
***********************************/
#include <stdio.h>
#include <stdio_ext.h>
#include "phonebook_interactions.h"

int get_choice_by_scanf() {
    __fpurge(stdin);
    int choice;
    scanf("%d", &choice);
    return choice;
}

int get_user_choice() {
    return get_choice_by_scanf();
}

int get_user_reaction() {
    __fpurge(stdin);
    char c;
    scanf("%c", &c);
    __fpurge(stdin);
    return 0;
}

int get_string_by_fgets(char *place, size_t length) {
    __fpurge(stdin);
    fgets(place, length, stdin);
    __fpurge(stdin);
    return 0;
}

int get_field_data_from_user(char *place, size_t length) {
    return get_string_by_fgets(place, length);
}
