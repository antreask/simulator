#ifndef GLOBAL_INFO_H
#define GLOBAL_INFO_H

#include <deque>
#include <CPU/event.h>

using namespace std;

class global_info
{
public:
    global_info();

    int clock_cycle=0;
    int pc_value=0;
    deque<Event*> queue;
    void sort_queue(deque<Event *> &queue);
    void sort_queue();
};

#endif // GLOBAL_INFO_H
