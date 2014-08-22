#include "room.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Room load_room(char *filename) {
    Room room;
    char unused_underline[80];
    char line[80];
    FILE *file = fopen(filename, "r");
    fgets(room.name, 80, file);
    fgets(unused_underline, 80, file);
    while (fgets(line, 80, file) != NULL) {
        strcat(room.description, line);
    }
    fclose(file);
    return room;
}
