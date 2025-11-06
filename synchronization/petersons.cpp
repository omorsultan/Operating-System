#include<bits/stdc++.h>
using namespace std;

atomic<bool> flag[2];  // indicates if process wants to enter critical section
atomic<int> turn;      // whose turn it is

void process(int id) {
    int other = 1 - id;
    for (int i = 0; i < 5; i++) {
        // Entry section
        flag[id] = true;
        turn = other;
        while (flag[other] && turn == other)
            ; // busy waiting

        // Critical section
        cout << "Process " << id << " is in critical section.\n";
        this_thread::sleep_for(chrono::milliseconds(200));

        // Exit section
        flag[id] = false;

        // Remainder section
        cout << "Process " << id << " is in remainder section.\n";
        this_thread::sleep_for(chrono::milliseconds(200));
    }
}

int main() {
    flag[0] = false;
    flag[1] = false;
    turn = 0;

    thread t1(process, 0);
    thread t2(process, 1);

    t1.join();
    t2.join();

    return 0;
}
