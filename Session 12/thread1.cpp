#include <iostream>
#include <thread>

void thread_fun(char A){
    for (int i = 0; i < 999; i++) {
        std::cout << A << std::endl;
    }
    std::cout << "End of thread" << std::endl;
}

int main() {
    std::thread th(thread_fun, 'A');

    std::cout << "Begin of thread" << std::endl;

    // The detached child thread is now free, and runs on its own. It becomes a daemon process. 
    // Once detached, the thread should live that way forever.
    // one of the characteristics of multithreaded programming: we cannot be sure which thread runs first
    th.detach();

    // Once a thread detached, we cannot force it to join with the main thread again
    //if (th.joinable()){
    //    th.join();
    //}

    return 0;


}