#ifndef CONSUMER_H
#define CONSUMER_H

#include <QString>

class Consumer
{
public:
    Consumer();

    virtual void wakeup();

    QString getName() const;
    void setName(const QString &value);

private:
    QString name;
};

#endif // CONSUMER_H
