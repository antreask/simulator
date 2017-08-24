#include "global_info.h"




global_info::global_info()
{

}


struct Comp
{
    bool operator()(const Event* s1, const Event* s2)
    {

        if (s1->getClock_cycle() == s2->getClock_cycle())
            return (s1->getWeight() > s2->getWeight());
        else
            return (s1->getClock_cycle() > s2->getClock_cycle());


    }
};

void global_info::sort_queue(deque<Event*> &queue)
{
    //deque<Event> b(que); // copy of init
    make_heap( queue.begin(), queue.end(),Comp() ); // create heap from array queue
    sort_heap( queue.begin(), queue.end(),Comp() ); // sort elements with sort_heap

}

void global_info::sort_queue()
{
    make_heap( this->queue.begin(), this->queue.end(),Comp() ); // create heap from array queue
    sort_heap( this->queue.begin(), this->queue.end(),Comp() ); // sort elements with sort_heap
}
