#include <iostream>
#include <map>
#include <thread>
#include <future>

using namespace std;


class Singleton {
    static Singleton * instance;
    Singleton() {}
    string name;
    static mutex m_;

public:
     static Singleton * getInstance() {
        if(instance == nullptr) {
//            lock_guard<mutex> lock(m_); // thread safe this will apply mutex implicitly
            m_.lock();
            if(instance == nullptr) {
                cout<<"instance created";
                instance = new Singleton();
            }
            m_.unlock();
        }
        return instance;
    }
    static map<int,int> mp;

    void setName(string name) {
        this->name = name;
    }
    string getName() {
        return this->name;
    }
};

Singleton * Singleton::instance = nullptr;
map<int,int> Singleton::mp;
mutex Singleton::m_;

void func1() {
    Singleton * s = Singleton::getInstance();
    s->setName("thread1");
    cout<<s->getName()<<endl;
}

void func2() {
    Singleton * s = Singleton::getInstance();
    s->setName("thread2");
    cout<<s->getName()<<endl;
}

int main() {

//    Singleton * s = Singleton::getInstance();
//    s->setName("ankush");

//    thread t1(func1);
//    thread t2(func2);

//    t1.join();
//    t2.join();

    async(launch::async, func1);
    cout<<"ok";

    async(launch::async, func2);




    return 0;
}

