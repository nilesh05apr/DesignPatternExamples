#ifndef SINGLETON_H
#define SINGLETON_H

class Singleton {
    static Singleton *instance;
    int data;
    Singleton();
    Singleton(const Singleton&);
    Singleton& operator=(const Singleton&);

    public:
        static Singleton *getInstance();
        int getData();
        void setData(int data);
        Singleton(const Singleton&) = delete;
        Singleton& operator=(const Singleton&) = delete;
};

#endif