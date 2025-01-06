#ifndef SINGLETON_H
#define SINGLETON_H

#include <iostream>

class Singleton {
private:
    static Singleton* instance;

    // Private constructor to prevent instantiation
    Singleton() = default;

public:
    // Delete copy constructor and assignment operator
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    static Singleton* GetInstance() {
        if (instance == nullptr) {
            instance = new Singleton();
        }
        return instance;
    }

    static void ShowMessage() {
        std::cout << "Singleton instance is working.\n";
    }
};

#endif