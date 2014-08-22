#ifndef ROOM_H
#define ROOM_H

typedef struct RoomStruct Room;

struct RoomStruct {
    char name[80];
    char description[2048];
    void (*gather_options)();
};

Room load_room(char *filename);

#endif
