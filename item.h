#ifndef ITEM_H
#define ITEM_H

typedef struct ItemStruct Item;

struct ItemStruct {
    char name[256];
    char description[2048];
    Room *location;
};

#endif
