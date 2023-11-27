#ifndef SERVER_HPP
#define SERVER_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <functional>
#include <map>
#include "include/client_handler.hpp"

class Server {
public:
    Server(int port);
    void start();
    ~Server(){}

private:
    int serverSocket, clientSocket;
    int port;
    struct sockaddr_in serverAddr, clientAddr;
    socklen_t addrLen = sizeof(clientAddr);
    std::string command;

    enum class State {
        WAITING,
        CONNECTED,
        RECEIVE_DATA,
        PROCESS_DATA,
        EXIT
    };

    State currentState;
    std::map<State, std::function<void()>> stateMachine;

    void initializeStateMachine();
    void createSocket();
    void bindSocket();
    void listenForConnections();
    void acceptConnection();
    void closeConnection();

}; // Class Server

#endif //SERVER_HPP