#include "CPU/consumer.h"
#include <QDebug>


Consumer::Consumer()
{
    qDebug()<< "Consumer's constructor";

}

void Consumer::wakeup()
{
    qDebug()<< "Consumer's wakeup called";
}
