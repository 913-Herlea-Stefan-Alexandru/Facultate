//
// Created by User on 21/06/2021.
//

#ifndef STAR_CATALOGUE_OBSERVER_H
#define STAR_CATALOGUE_OBSERVER_H

#include <vector>
#include <algorithm>
class Observer
{
public:
    virtual void update() = 0;
    virtual ~Observer() {}
};

class Observable
{
private:

    std::vector<Observer*> observers;
public:
    virtual ~Observable() {}

    void add_observer(Observer *obs)
    {
        observers.push_back(obs);
    }

    void remove_observer(Observer *obs)
    {
        auto it = std::find(observers.begin(), observers.end(), obs);
        if (it != observers.end())
            observers.erase(it);
    }

    void notify()
    {
        for (auto observer: observers)
        {
            observer->update();
        }
    }
};

#endif //STAR_CATALOGUE_OBSERVER_H
