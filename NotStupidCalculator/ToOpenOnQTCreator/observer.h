#ifndef OBSERVER_H
#define OBSERVER_H
#include <QVector>

class Observer
{
public:
     virtual void update() = 0;
     virtual ~Observer() {};
};

class Observable
{
private:
    QVector<Observer* > observers_;
public:
    void addObserver(Observer* observer);
    void removeObserver(Observer* observer);
    void notifyUpdate() const;
    virtual ~Observable() {};
};

#endif // OBSERVER_H
