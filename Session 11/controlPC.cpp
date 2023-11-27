#include "include/client_handler.hpp"
#include "include/server.hpp"



int main(int argc, const char **argv){
    Server server(8083);
    server.start();
    return 0;
}