#include<bits/stdc++.h>
using namespace std;

int accountA = 500; // Initial balance of account A
int accountB = 0;   // Initial balance of account B
mutex mtx;
void transfer(int amount) {
    // Critical Section (unsafe)
    mtx.lock();
    if (accountA >= amount) {
        this_thread::sleep_for(chrono::seconds(1)); // simulate delay
        accountA -= amount;
        accountB += amount;
    }

    cout << "Transfer " << amount 
         << ": A=" << accountA 
         << ", B=" << accountB 
         << " (Total: " << accountA + accountB << ")\n";
    mtx.unlock();
}

int main() {
    thread t1(transfer, 100);
    thread t2(transfer, 500);

    t1.join();
    t2.join();

    cout << "Final balances: A=" << accountA 
         << ", B=" << accountB 
         << " (Total: " << accountA + accountB << ")\n";

    return 0;
}
