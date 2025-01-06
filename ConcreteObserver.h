#ifndef CONCRETE_OBSERVER_H
#define CONCRETE_OBSERVER_H

#include "Observer.h"
#include <iostream>

class ConcreteObserver : public Observer {
private:
    std::string name;

public:
    explicit ConcreteObserver(std::string name) : name(std::move(name)) {}

    void Update(const std::string& message) override {
        std::cout << "Observer " << name << " received message: " << message << "\n";
    }
};

#endif