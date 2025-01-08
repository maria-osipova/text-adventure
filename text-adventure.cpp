#include <iostream>
#include <string>

int main() {
    std::cout << "hello, stranger! press enter to start.\n";
    {
        std::string dummy;
        std::getline(std::cin, dummy);
    }

    std::cout << "you are here for a big adventure.\n";
    {
        std::string dummy;
        std::getline(std::cin, dummy);
    }

    while (true) {
        std::cout << "are you ready? type yes or no \n";

        std::string response;
        std::getline(std::cin, response);

        if (response == "yes") {
            std::cout << "good job! you are here for a big adventure.\n";
            break;
        }
        else if (response == "no") {
            std::cout << "hmm.. goodbye then! see you next time when you will be ready for a big adventure.\n";
            break;
        }
        else {
            std::cout << "hmm.. I'm not sure if you typed yes or no. try again.\n";
        }
    }

    return 0;
}
