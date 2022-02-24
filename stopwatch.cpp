#include <iostream>
#include <map>
#include <future>
#include <unistd.h>
using namespace std;

class StopWatch {

public:
    int start;
    atomic<bool> shouldRun;
    future<void> f;
    StopWatch() {
        start = 0;
        shouldRun=true;
    }
    void startWatch() {
        cout<<"in start";
        while(1) {
            if(shouldRun) {
                start++;
                cout << start<<endl;
            } else {
                break;
            }
        }
    }

    void stopWat() {
        cout<<"in stop";
        shouldRun= false;
        cout<<start;
        cout<<"stopped";
    }

    void pauseWatch() {

    }

    void startIt() {
        f=  async(launch::async, &StopWatch::startWatch, this);
    }
};

int main() {

    StopWatch stopWatch;
    stopWatch.startIt();
    usleep(100);
    cout<<"**";
    stopWatch.stopWat();
    return 0;
}