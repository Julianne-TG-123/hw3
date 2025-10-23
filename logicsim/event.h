#ifndef EVENT_H
#define EVENT_H
#include "wire.h"

struct Event
{
    uint64_t time;
    Wire* wire;
    char state;
};

typedef struct EventLess {
        //write the operator() required to make this a functor that compares Events by time
        bool operator()(Event* a, Event* b) const{
            if(a->time < b->time){
                //true if a occurs earlier
                //min-heap
                return true;
            } else {
                return false;
            }
        }
} EventLess;
	
#endif
