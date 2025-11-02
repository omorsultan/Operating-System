#include<bits/stdc++.h>
using namespace std;

queue<int> buffer;
const int BUFFER_SIZE = 5;

mutex mtx;
condition_variable not_full, not_empty;

void producer() {
  int item = 0;
    while (item < 10) {
        unique_lock<mutex> lock(mtx);
        not_full.wait(lock, [] { return buffer.size() < BUFFER_SIZE; });

        item++;
        buffer.push(item);
        cout <<"  Producer produced item " << item 
             << " | Buffer size: " << buffer.size() << endl;

        lock.unlock();
        not_empty.notify_one();
        this_thread::sleep_for(chrono::milliseconds(300));
    }
}

void consumer() {
    for (int i = 0; i < 10; i++) {
        unique_lock<mutex> lock(mtx);
        not_empty.wait(lock, [] { return !buffer.empty(); });

        int item = buffer.front();
        buffer.pop();
        cout << "🧑‍💻 Consumer consumed item " << item 
             << " | Buffer size: " << buffer.size() << endl;

        lock.unlock();
        not_full.notify_one();
        this_thread::sleep_for(chrono::milliseconds(500));
    }
}

int main() {
    thread t1(producer);
    thread t2(consumer);


    t1.join();
    t2.join();
 

    cout << "\n✅ All items produced and consumed successfully!\n";
    return 0;
}
