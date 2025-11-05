#include <bits/stdc++.h>
using namespace std;

mutex mtx;               // For synchronizing access
condition_variable cv;   // For waiting and signaling
int readerCount = 0;     // Number of active readers
bool writerActive = false; // True if a writer is writing

void reader(int id) {
    for (int i = 0; i < 3; i++) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [] { return !writerActive; });  // wait until no writer
        readerCount++;
        lock.unlock();

        // ---- Reading section ----
        cout << "📖 Reader " << id << " is reading.\n";
        this_thread::sleep_for(chrono::milliseconds(400));

        lock.lock();
        readerCount--;
        if (readerCount == 0)
            cv.notify_all();  // if last reader, notify waiting writers
        lock.unlock();

        this_thread::sleep_for(chrono::milliseconds(200));
    }
}

void writer(int id) {
    for (int i = 0; i < 3; i++) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [] { return !writerActive && readerCount == 0; }); // wait until no readers/writers
        writerActive = true;
        lock.unlock();

        // ---- Writing section ----
        cout << "✍️ Writer " << id << " is writing.\n";
        this_thread::sleep_for(chrono::milliseconds(700));

        lock.lock();
        writerActive = false;
        cv.notify_all(); // wake up readers/writers
        lock.unlock();

        this_thread::sleep_for(chrono::milliseconds(300));
    }
}

int main() {
    thread readers[3], writers[2];

    for (int i = 0; i < 3; i++)
        readers[i] = thread(reader, i + 1);
    for (int i = 0; i < 2; i++)
        writers[i] = thread(writer, i + 1);

    for (int i = 0; i < 3; i++)
        readers[i].join();
    for (int i = 0; i < 2; i++)
        writers[i].join();

    cout << "\n✅ All reading and writing completed successfully!\n";
    return 0;
}
