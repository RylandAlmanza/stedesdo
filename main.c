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
        
        if (scanf("%d", &choice) > -1) {
            if (choice == 0) {
                break;
            }
            if (choice > option_count) {
                printf("That's not an option.\n\n");
                continue;
            }
            options[choice - 1].callback();
        } else {
            printf("Seriously? I gave you a list of numbers you can choose. "
                   "How do you screw that up? This isn't some text adventure "
                   "where you have to guess cryptic commands at random. Just "
                   "pick a number.\n\n");
            getchar();
        }
    }
}
