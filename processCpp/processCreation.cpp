#include <iostream>
#include <unistd.h>   // for fork(), getpid()
#include <sys/wait.h> // for wait()
using namespace std;

int main() {
    cout << "Before fork: PID = " << getpid() << endl;

    pid_t pid = fork(); // create new process

    if (pid < 0) {
        cerr << "Fork failed!" << endl;
        return 1;
    }
    else if (pid == 0) {
        // Child process
        cout << "Child Process: PID = " << getpid() 
             << ", Parent PID = " << getppid() << endl;

        for (int i = 0; i < 5; i++) {
            cout << "Child counting: " << i << endl;
            sleep(1);
        }
    }
    else {
        // Parent process
        cout << "Parent Process: PID = " << getpid() 
             << ", Child PID = " << pid << endl;

        // wait for child to complete
        wait(NULL);
        cout << "Child finished. Parent continuing..." << endl;
    }

    cout << "Process (PID " << getpid() << ") exiting." << endl;
    return 0;
}
