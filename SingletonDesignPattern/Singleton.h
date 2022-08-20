#ifndef SINGLETON_H
#define SINGLETON_H

class Singleton {
    static Singleton *instance;
    int data;
    Singleton(){}
    public:
        static Singleton *getInstance();
        int getData();
        void setData(int data);
};

#endif