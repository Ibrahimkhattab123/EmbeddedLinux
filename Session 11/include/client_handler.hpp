#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <iostream>
#include <cstring>
#include <algorithm>
#include <unistd.h>
#include <cstdlib>
#include <cstdio>
#include <sys/types.h>
#include <sys/wait.h>


class CommandHandler {
public:
    CommandHandler(std::string clientCommand);
    ~CommandHandler(){}
    void handleCommand();
    

private:
    std::string clientCommand;
    void executeCommand(const std::string& command);

};
#endif //CLIENT_HPP