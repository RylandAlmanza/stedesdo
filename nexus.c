#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "nexus.h"
#include "world.h"

bool nexus_switch_on = false;

void flip_switch() {
    char new_state[4];
    nexus_switch_on = nexus_switch_on ? false : true;
    strcpy(new_state, nexus_switch_on ? "on" : "off");
    printf("You flip the switch %s.\n\n", new_state);
}

void nexus_gather_options() {
    char switch_state[4];
    strcpy(switch_state, nexus_switch_on ? "off" : "on");
    sprintf(options[0].text, "Flip switch %s.", switch_state);
    options[0].callback = &flip_switch;
    option_count = 1;
}

Room load_nexus() {
    Room nexus = load_room("nexus.txt");
    nexus.gather_options = &nexus_gather_options;
    return nexus;
}
