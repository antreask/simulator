#ifndef CONSUMER_H
#define CONSUMER_H

#include <QString>
//#include "global_info.h"

class Consumer
{
public:
    Consumer();

    virtual void wakeup();

    QString getName() const;
    void setName(const QString &value);

    //global_info *getInfo() const;
    //void setInfo(global_info *value);

private:
    QString name;
    // global_info *info;
};

#endif // CONSUMER_H
