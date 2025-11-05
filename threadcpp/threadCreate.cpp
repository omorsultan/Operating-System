#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

// Thread function
void thread_fun() {
    cout << "Inside thread" << endl;
    for (int j = 0; j < 5; j++) {
        cout << j << endl;
        this_thread::sleep_for(chrono::seconds(1)); // replaces sleep(1)
    }
}

int main() {
    // Create and start thread
    thread thread1(thread_fun);

    // Wait for the thread to finish
    thread1.join();

    cout << "Back to main process" << endl;
    for (int i = 15; i < 20; i++) {
        cout << i << endl;
        this_thread::sleep_for(chrono::seconds(1));
    }

    return 0;
}
