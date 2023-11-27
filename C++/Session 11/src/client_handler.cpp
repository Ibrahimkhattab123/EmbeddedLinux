#include "include/client_handler.hpp"


CommandHandler::CommandHandler(std::string _clientCommand) : clientCommand(_clientCommand) {}

void CommandHandler::handleCommand() {
        std::cout << "Received command: " << clientCommand << std::endl;
        executeCommand(clientCommand);
    }

void CommandHandler::executeCommand(const std::string& command) {
   
    std::system(command.c_str());

}

