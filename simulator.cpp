#include "mainwindow.h"

#include <QDebug>
#include "CPU/event.h"
#include "CPU/consumer.h"
#include "CPU/ife.h"
#include "CPU/ide.h"
#include "CPU/exe.h"
#include "CPU/mem.h"
#include "CPU/wb.h"
#include <iostream>
#include <algorithm>
#include <deque>
#include <iterator>

using namespace std;

struct Comp
{
    bool operator()(const Event& s1, const Event& s2)
    {

        if (s1.getClock_cycle() == s2.getClock_cycle())
            return (s1.getWeight() > s2.getWeight());
        else
            return (s1.getClock_cycle() > s2.getClock_cycle());


    }
};


void MainWindow::sort_queue(deque<Event> &queue)
{
    //deque<Event> b(que); // copy of init
    make_heap( queue.begin(), queue.end(),Comp() ); // create heap from array queue
    sort_heap( queue.begin(), queue.end(),Comp() ); // sort elements with sort_heap

}




void MainWindow::sim_Run()
{

    for (int i=0; i<3; i++)
    {
        Event event;
        IFE *fetch=new IFE();
        fetch->init(IM);
        //fetch->printIM();
        event.setClock_cycle(i);
        event.setWeight(3-i);
        event.setCons(fetch);
        que.push_front(event);
    }



    for (int i=0; i<3; i++)
    {

        que.pop_back();
        Event c=b.back();
        qDebug()<< c.getClock_cycle();
        qDebug()<< c.getWeight();
        b.pop_back();

    }

    qDebug()<< que.size()<<b.size();


}



void MainWindow::sim_ReinitializeSimulator()
{

}


void MainWindow::sim_Pause()
{

}


void MainWindow::sim_Stop()
{

}


void MainWindow::sim_SingleStep()
{

}
