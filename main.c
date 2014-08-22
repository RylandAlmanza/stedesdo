#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "world.h"
#include "nexus.h"

int main() {
    char input[80];
    int choice;
    bool game_done = false;
    rooms[0] = load_nexus();
    current_room = &rooms[0];
    present_room(current_room);
    while (game_done == false) {
        present_options(current_room);
        scanf("%d", &choice);
        if (choice != 0) {
            options[choice - 1].callback();
        } else {
            game_done = true;
        }
    }
}
