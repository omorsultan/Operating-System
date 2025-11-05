#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

// Thread function
void thread_fun(int* array, int size, int& result) {
    cout << "Inside thread" << endl;
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
        cout << "Element " << i << " has been summed. Current sum: " << sum << endl;
        this_thread::sleep_for(chrono::seconds(1)); // sleep(1)
    }
    result = sum;
}

int main() {
    int ara[5] = {1, 2, 3, 4, 5};
    int sum = 0;

    // Create thread
    thread t1(thread_fun, ara, 5, ref(sum));

    // Wait for thread to finish
    t1.join();

    cout << "\nBack to main process" << endl;
    cout << "Sum of elements: " << sum << endl;

    return 0;
}
