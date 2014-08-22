#ifndef WORLD_H
#define WORLD_H

#include "room.h"
#include "item.h"
#include "option.h"

Room rooms[10];
Room *current_room;
Item items[20];
Option options[10];
int option_count;

void present_room(Room *room);
void present_options(Room *room);
#endif
