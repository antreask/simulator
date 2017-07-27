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
    bool operator()(const Event* s1, const Event* s2)
    {

        if (s1->getClock_cycle() == s2->getClock_cycle())
            return (s1->getWeight() > s2->getWeight());
        else
            return (s1->getClock_cycle() > s2->getClock_cycle());


    }
};


void MainWindow::sort_queue(deque<Event*> &queue)
{
    //deque<Event> b(que); // copy of init
    make_heap( queue.begin(), queue.end(),Comp() ); // create heap from array queue
    sort_heap( queue.begin(), queue.end(),Comp() ); // sort elements with sort_heap

}




void MainWindow::sim_Run()
{

    if (syntaxpass)
    {
        // --------------->>>>>>>>>>put the code below in here
    }
    else
    {
        console->append("<html>"
                        "<b>Check source first!! (F4)</b>"
                        "</html>");
        // ---------------> Uncomment this     ----->>>>>>>>>return;
    }

    IFE *fetch= new IFE();
    IDE *decode=new IDE();
    EXE *execute=new EXE();
    MEM *memory = new MEM();
    WB *write_back = new WB();

    fetch->init(IM,decode);
    decode->init(execute);
    memory->init(write_back);


    // queue.push_front(new Event(fetch));


    /*   if (Spinbox->value()==0)
           console->append( QString::number(Spinbox->value()));
       else
           console->append( QString::number(Spinbox->value()));*/


    /*  for (int i=0; i<3; i++)
      {
          Event *event=new Event();
          IFE *fetch=new IFE();
          event->setClock_cycle(i);
          event->setWeight(3-i);
          event->setCons(fetch);
          que.push_front(event);
      }


      for (int i=0; i<3; i++)
      {
          Event *event=new Event();
          IFE *fetch=new IFE();
          event->setClock_cycle(i);
          event->setWeight(3-i);
          event->setCons(fetch);
          que.push_front(event);
      }

      qDebug() << "que size "<< que.size();
      sort_queue(que);
      for (int i=0; i<6; i++)
      {


          Event *c=que.back();
          qDebug()<< c->getClock_cycle()<< " "<<c->getWeight();
          que.pop_back();

      }*/


}


void MainWindow::sim_SingleStep()
{

}
