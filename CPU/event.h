#ifndef EVENT_H
#define EVENT_H

class Event
{
public:
    Event();


    int getClock_cycle() const;
    void setClock_cycle(int value);

    int getWeight() const;
    void setWeight(int value);

private:
    int clock_cycle;
    int weight;
};

#endif // EVENT_H
