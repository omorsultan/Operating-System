#include <iostream>
#include <thread>
#include <vector>

using namespace std;

// Function to calculate partial sum
void partial_sum(int* array, int start, int end, int& result) {
    int sum = 0;
    for (int i = start; i < end; i++) {
        sum += array[i];
    }
    result = sum;
}

int main() {
    int array[100];
    for (int i = 0; i < 100; i++) {
        array[i] = i + 1;
    }

    int size = sizeof(array) / sizeof(array[0]);
    int mid = size / 2;

    int sum_first_half = 0;
    int sum_second_half = 0;

    // Create threads
    thread t1(partial_sum, array, 0, mid, ref(sum_first_half));
    thread t2(partial_sum, array, mid, size, ref(sum_second_half));

    // Wait for threads to finish
    t1.join();
    t2.join();

    cout << "Sum of first half: " << sum_first_half << endl;
    cout << "Sum of second half: " << sum_second_half << endl;
    cout << "Total sum: " << sum_first_half + sum_second_half << endl;

    return 0;
}
