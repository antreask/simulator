#ifndef CONSUMER_H
#define CONSUMER_H


class Consumer
{
public:
    Consumer();

    virtual void wakeup()=0;
};

#endif // CONSUMER_H
