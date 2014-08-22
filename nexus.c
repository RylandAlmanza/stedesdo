#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "nexus.h"
#include "world.h"

bool nexus_switch_on = false;

void examine_door() {
    printf("It's a large, featureless, light-gray door. It has no doorknob.\n"
           "\n");
}

void examine_switch() {
    char door_name[8];
    strcpy(door_name, nexus_switch_on ? "doorway" : "door");
    printf("Beside the %s is a small gray switch. It looks like an ordinary "
           "light switch.\n\n", door_name);
}

void flip_switch() {
    char new_state[4];
    if (nexus_switch_on == false) {
        nexus_switch_on = true;
        printf("You flip the switch, and the door beside it fades away"
               "\n\n");
    } else {
        nexus_switch_on = false;
        printf("You flip the switch, and the door reappears, filling in the "
               "empty space.\n\n");
    }
}

void enter_door() {
    printf("nope.\n\n");
}

void nexus_gather_options() {
    option_count = 0;
    if (!nexus_switch_on) {
        strcpy(options[option_count].text, "Examine door");
        options[option_count].callback = &examine_door;
        option_count++;
    }
    strcpy(options[option_count].text, "Examine switch");
    options[option_count].callback = &examine_switch;
    option_count++;
    strcpy(options[option_count].text, "Flip switch");
    options[option_count].callback = &flip_switch;
    option_count++;
    if (nexus_switch_on) {
        strcpy(options[option_count].text, "Enter (exit?) door");
        options[option_count].callback = &enter_door;
        option_count++;
    }
}

Room load_nexus() {
    Room nexus = load_room("nexus.txt");
    nexus.gather_options = &nexus_gather_options;
    return nexus;
}
