#ifndef OBSERVER_H
#define OBSERVER_H

#include <string>
#include <vector>
#include <algorithm>

class Observer {
public:
    virtual ~Observer() = default;
    virtual void Update(const std::string& message) = 0;
};

class Subject {
private:
    std::vector<Observer*> observers;

public:
    void Attach(Observer* observer) {
        observers.push_back(observer);
    }

    void Detach(Observer* observer) {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void Notify(const std::string& message) {
        for (auto* observer : observers) {
            observer->Update(message);
        }
    }
};

#endif