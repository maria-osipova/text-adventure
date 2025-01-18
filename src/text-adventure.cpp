#include <iostream>
#include <string>
#include </Users/maria/Downloads/text-adventure-starting/vcpkg/installed/arm64-osx/include/json/json.h>
#include <fstream>


void loadJson(const std::string& filePath, Json::Value& dialogues) {
    std::ifstream file(filePath, std::ifstream::binary);
    if (!file.is_open()) {
        std::cerr << "Warning: Could not open file " << filePath << ". Using default dialogues.\n";
        return;
    }
    file >> dialogues;
    file.close();
}

// Функция для получения диалога
std::string getDialogue(const Json::Value& dialogues, const std::string& key, const std::string& defaultText) {
    if (dialogues.isMember(key)) {
        return dialogues[key].asString();
    }
    return defaultText;
}

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

    std::cout << "well, lets start then... press enter to continue.\n";
    {
        std::string dummy;
        std::getline(std::cin, dummy);
    }

    std::string gender;

    while (true) {
        std::cout << "first of all i would like to ask you: who do you wanna be today? are you a man or a woman? type man or woman. \n";

        std::getline(std::cin, gender);

        if (gender == "man") {
            std::cout << "good job! let's continue.\n";
            break;
        } else if (gender == "woman") {
            std::cout << "good job! let's continue.\n";
            break;
        } else {
            std::cout << "hmm.. I'm not sure if you typed man or woman. try again.\n";
        }
    }

    std::cout << "enter your name.\n";
    std::string name;

    while (true) {

        std::getline(std::cin, name);

        if (!name.empty() && name.find_first_not_of(" \t") != std::string::npos) {

            std::cout << "so. the story begins. you are a " << gender << ", named " << name << ". press enter to continue.\n";
            std::string dummy;
            std::getline(std::cin, dummy);
            break;
        }
        else {
            std::cout << "hmm.. I'm not sure if you typed your name. try again.\n";
        }
    }

    std::string country_first, country_second;
    bool first_country_valid = false;

    while (true) {
        if (!first_country_valid) {
            std::cout << "now please enter the country you live in.\n";
            std::getline(std::cin, country_first);

            if (country_first.empty() || country_first.find_first_not_of(" \t") == std::string::npos) {
                std::cout << "hmm.. i'm not sure if you typed the country you live in. try again.\n";
                continue;
            }

            first_country_valid = true;
        }

        std::cout << "now please enter the country you would like to live in.\n";
        std::getline(std::cin, country_second);

        if (country_second.empty() || country_second.find_first_not_of(" \t") == std::string::npos) {
            std::cout << "hmm.. i'm not sure if you typed the country you would like to live in. try again.\n";
            continue;
        }

        if (country_first == country_second) {
            std::cout << "your countries should be two different ones. try again.\n";
            continue;
        }

        std::cout << "good job! press enter to continue.\n";
        std::cin.get();
        break;
    }

    return 0;
}



