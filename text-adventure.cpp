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

    std::cout << "well, lets start then...\n";
    {
        std::string dummy;
        std::getline(std::cin, dummy);
    }

    while (true) {
        std::cout << "first of all i would ask you who you wanna be today. are you a man or a woman? type your answer. \n";

        std::string response;
        std::getline(std::cin, response);

        if (response == "man") {
            std::cout << "good job! let's continue.\n";
            break;
        }
        else if (response == "woman") {
            std::cout << "good job! let's continue.\n";
            break;
        }
        else {
            std::cout << "hmm.. I'm not sure if you typed man or woman. try again.\n";
        }
    }

    return 0;
}
