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





void MainWindow::sim_Run()
{
    qDebug() << GI->queue.size();
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

    GI->queue.push_front(new Event(GI->clock_cycle,fetch));
    GI->queue.push_front(new Event(GI->clock_cycle,decode));
    GI->queue.push_front(new Event(GI->clock_cycle,execute));
    GI->queue.push_front(new Event(GI->clock_cycle,memory));
    GI->queue.push_front(new Event(GI->clock_cycle,write_back));
    GI->sort_queue();
    qDebug() << GI->queue.size();
    for (int i=0; i<5; i++)
    {

        Event *e=GI->queue.front();
        GI->queue.pop_front();
        qDebug() << (e->getCons())->getName();
    }


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
