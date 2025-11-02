#include<bits/stdc++.h>
using namespace std;

mutex mtx;
int shared = 4;
void process(int id) {
    for (int i = 0; i < 5; i++) {
        mtx.lock();   // wait()
        printf("Thread %d: Entering critical section\n",id);
        int temp = shared;
        this_thread::sleep_for(chrono::milliseconds(200));// Simulate some work in the critical section
        shared = temp + 1;
        printf("Thread %d: Exiting critical section, shared = %d\n", id,shared);
        this_thread::sleep_for(chrono::milliseconds(200));

        mtx.unlock(); // signal()
        this_thread::sleep_for(chrono::milliseconds(200));
    }
}

int main() {
    thread t1(process, 0);
    thread t2(process, 1);

    t1.join();
    t2.join();

    return 0;
}
