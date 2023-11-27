#include "include/server.hpp"
#include "include/client_handler.hpp"
#include <cstring>

Server::Server(int _port) : port(_port) {
     initializeStateMachine();
}

void Server::start() {

        createSocket();
        bindSocket();
        listenForConnections();

        while (currentState != State::EXIT) {
            stateMachine[currentState]();
        }

        closeConnection();
    }

void Server::initializeStateMachine() {
        stateMachine[State::WAITING] = [this] {
            std::cout << "Waiting for a connection...\n";
            acceptConnection();
        };

        stateMachine[State::CONNECTED] = [this] {
            std::cout << "Connection accepted\n";
            currentState = State::RECEIVE_DATA;
        };

        stateMachine[State::RECEIVE_DATA] = [this] {
            char buffer[1024] = {0};
            ssize_t bytesRead = read(clientSocket, buffer, sizeof(buffer));
            command = buffer;
             if (bytesRead > 0) {
                currentState = State::PROCESS_DATA;
            } else if (bytesRead == 0) {
                std::cout << "Client disconnected\n";
                currentState = State::WAITING;
            } else {
                perror("Read error");
                currentState = State::WAITING;
            }
            currentState = State::PROCESS_DATA;
        };

        stateMachine[State::PROCESS_DATA] = [this] {
            // process data 
            CommandHandler handler(command);
            handler.handleCommand();
            currentState = State::RECEIVE_DATA;
        };

        stateMachine[State::EXIT] = [this] {
            
            closeConnection();
            currentState = State::EXIT;
        };
    }

void Server::createSocket() {
        serverSocket = socket(AF_INET, SOCK_STREAM, 0);
        if (serverSocket == -1) {
            perror("Error creating socket");
            exit(EXIT_FAILURE);
        }
    }

void Server::bindSocket() {
        serverAddr.sin_family = AF_INET;
        serverAddr.sin_addr.s_addr = INADDR_ANY;
        serverAddr.sin_port = htons(port);

        if (bind(serverSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
            perror("Bind failed");
            exit(EXIT_FAILURE);
        }
    }

void Server::listenForConnections() {
        if (listen(serverSocket, 5) < 0) {
            perror("Listen failed");
            exit(EXIT_FAILURE);
        }
        currentState = State::WAITING;
        while (currentState == State::WAITING) {
            stateMachine[currentState]();
        }
    }

void Server::acceptConnection() {
    clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddr, &addrLen);
    if (clientSocket < 0) {
    perror("Accept failed");
    currentState = State::WAITING;
    } else {
        currentState = State::CONNECTED;
    }
    }

void Server::closeConnection() {
        close(clientSocket);
        close(serverSocket);
    }