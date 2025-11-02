#include <bits/stdc++.h>
using namespace std;

mutex mtx1, mtx2;

void taskA() {
    cout << "🧵 Task A: Trying to lock mtx1...\n";
    mtx1.lock();
    cout << "🧵 Task A: Locked mtx1\n";

    this_thread::sleep_for(chrono::milliseconds(200));

    cout << "🧵 Task A: Trying to lock mtx2...\n";
    mtx2.lock();  // waits forever if taskB holds it
    cout << "🧵 Task A: Locked mtx2\n";

    cout << "🧵 Task A: Doing some work...\n";
    this_thread::sleep_for(chrono::milliseconds(300));

    mtx2.unlock();
    mtx1.unlock();
    cout << "🧵 Task A: Finished and released locks\n";
}

void taskB() {
    
    cout << "🔁 Task B: Trying to lock mtx2...\n";
    mtx2.lock();
    cout << "🔁 Task B: Locked mtx2\n";

    this_thread::sleep_for(chrono::milliseconds(200));

    cout << "🔁 Task B: Trying to lock mtx1...\n";
    mtx1.lock();  // waits forever if taskA holds it
    cout << "🔁 Task B: Locked mtx1\n";

    cout << "🔁 Task B: Doing some work...\n";
    this_thread::sleep_for(chrono::milliseconds(300));

    mtx1.unlock();
    mtx2.unlock();
    cout << "🔁 Task B: Finished and released locks\n";
}

int main() {
    thread t1(taskA);
    thread t2(taskB);

    t1.join();
    t2.join();

    cout << "\n✅ Program finished\n";
    return 0;
}
