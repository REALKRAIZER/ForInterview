#include "observer.h"
#include <algorithm>

void Observable::addObserver(Observer *observer)
{
    observers_.push_back(observer);
}
void Observable::removeObserver(Observer *observer)
{
    observers_.erase(std::find(observers_.begin(), observers_.end(), observer));
}
void Observable::notifyUpdate() const
{
    for(auto it : observers_)
        it->update();
}
