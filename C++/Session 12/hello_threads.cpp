#include <iostream>
#include <thread>

void thread_fun(){
    for (int i = 0; i < 9000000; i++) {
        std::cout << "A" << std::endl;
    }
    std::cout << "End of thread" << std::endl;
}

int main() {
    std::thread th(thread_fun);

    std::cout << "Begin of thread" << std::endl;

    if (th.joinable()){
        th.join();
    }

    return 0;


}