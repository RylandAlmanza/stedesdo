#include <stdio.h>
#include <string.h>
#include "world.h"

void present_room(Room *room) {
    char underline[80] = "====================================================="
                         "===========================";
    underline[strlen(room->name)] = NULL;
    printf("%s%s\n%s\n", room->name, underline,
           room->description);
}

void present_options(Room *room) {
    char options_string[2048];
    char index_string[2];
    int i;
    room->gather_options();
    strcpy(options_string, "");
    for (i = 0; i < option_count; i++) {
        strcat(options_string, "[");
        sprintf(index_string, "%d", i + 1);
        strcat(options_string, index_string);
        strcat(options_string, "] ");
        strcat(options_string, options[i].text);
        strcat(options_string, "\n");
    }
    printf("%s\n> ", options_string);
}
