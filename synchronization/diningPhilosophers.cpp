#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std;

const int NUM_PHILOSOPHERS = 5;
mutex chopstick[NUM_PHILOSOPHERS];  // One mutex for each chopstick

void dine(int id) {
    int left = id;
    int right = (id + 1) % NUM_PHILOSOPHERS;

    for (int i = 0; i < 3; ++i) {  // Each philosopher eats 3 times
        cout << "Philosopher " << id << " is thinking.\n";
        this_thread::sleep_for(chrono::milliseconds(1000));

        // To avoid deadlock: odd philosophers pick right first
        if (id % 2 == 0) {
            chopstick[left].lock();
            chopstick[right].lock();
        } else {
            chopstick[right].lock();
            chopstick[left].lock();
        }

        cout << "Philosopher " << id << " is eating.\n";
        this_thread::sleep_for(chrono::milliseconds(1000));

        chopstick[left].unlock();
        chopstick[right].unlock();

        cout << "Philosopher " << id << " finished eating.\n";
    }
}

int main() {
    thread philosophers[NUM_PHILOSOPHERS];

    for (int i = 0; i < NUM_PHILOSOPHERS; i++)
        philosophers[i] = thread(dine, i);

    for (int i = 0; i < NUM_PHILOSOPHERS; i++)
        philosophers[i].join();

    return 0;
}
