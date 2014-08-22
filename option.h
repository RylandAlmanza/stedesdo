#ifndef OPTION_H
#define OPTION_H

typedef struct OptionStruct Option;

struct OptionStruct {
    char text[76];
    void (*callback)();
};

#endif
