#include "CPU/consumer.h"
#include <QDebug>


Consumer::Consumer()
{
    //qDebug()<< "Consumer's constructor";

}

void Consumer::wakeup()
{
    //qDebug()<< "Consumer's wakeup called";
}

QString Consumer::getName() const
{
    return name;
}

void Consumer::setName(const QString &value)
{
    name = value;
}

/*global_info *Consumer::getInfo() const
{
    return info;
}

void Consumer::setInfo(global_info *value)
{
    info = value;
}*/
