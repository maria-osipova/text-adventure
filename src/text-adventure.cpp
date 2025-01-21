#include <iostream>
#include <fstream>
#include <string>
#include </Users/maria/Downloads/text-adventure-starting/vcpkg/installed/arm64-osx/include/json/json.h>

// Функция для загрузки JSON
void loadJson(const std::string& filePath, Json::Value& dialogues) {
    std::ifstream file(filePath, std::ifstream::binary);
    if (!file.is_open()) {
        std::cerr << "warning: could not open file " << filePath << ".\n";
        return;
    }
    file >> dialogues;
    file.close();
}

// Функция для получения диалога
std::string getDialogue(const Json::Value& dialogues, const std::string& key) {
    if (dialogues.isMember(key)) {
        return dialogues[key].asString();
    }
    return ""; // Возвращаем пустую строку, если ключ отсутствует
}

// Функция для замены подстрок
std::string replacePlaceholders(const std::string& text, const std::string& placeholder, const std::string& value) {
    std::string result = text;
    size_t pos = 0;
    while ((pos = result.find(placeholder, pos)) != std::string::npos) {
        result.replace(pos, placeholder.length(), value);
        pos += value.length();
    }
    return result;
}

int main() {
    Json::Value dialogues;
    loadJson("/Users/maria/Downloads/text-adventure-starting/src/dialogues.json", dialogues);

    std::cout << getDialogue(dialogues, "start_greeting") << "\n";
    {
        std::string dummy;
        std::getline(std::cin, dummy);
    }

    std::cout << getDialogue(dialogues, "big_adventure") << "\n";
    {
        std::string dummy;
        std::getline(std::cin, dummy);
    }

    while (true) {
        std::cout << getDialogue(dialogues, "ready_prompt") << "\n";

        std::string response;
        std::getline(std::cin, response);

        if (response == "yes") {
            std::cout << getDialogue(dialogues, "ready_yes") << "\n";
            break;
        } else if (response == "no") {
            std::cout << getDialogue(dialogues, "ready_no") << "\n";
            return 0;
        } else {
            std::cout << getDialogue(dialogues, "ready_retry") << "\n";
        }
    }

    std::cout << getDialogue(dialogues, "start_continue") << "\n";
    {
        std::string dummy;
        std::getline(std::cin, dummy);
    }

    std::string gender;

    while (true) {
        std::cout << getDialogue(dialogues, "gender_prompt") << "\n";

        std::getline(std::cin, gender);

        if (gender == "man" || gender == "woman") {
            std::cout << getDialogue(dialogues, "gender_valid") << "\n";
            break;
        } else {
            std::cout << getDialogue(dialogues, "gender_retry") << "\n";
        }
    }

    std::cout << getDialogue(dialogues, "name_prompt") << "\n";
    std::string name;

    while (true) {
        std::getline(std::cin, name);

        if (!name.empty() && name.find_first_not_of(" \t") != std::string::npos) {
            std::cout << replacePlaceholders(
                replacePlaceholders(
                    getDialogue(dialogues, "name_valid"),
                    "{gender}", gender),
                "{name}", name) << "\n";
            std::string dummy;
            std::getline(std::cin, dummy);
            break;
        } else {
            std::cout << getDialogue(dialogues, "name_retry") << "\n";
        }
    }

    std::string country_first, country_second;
    bool first_country_valid = false;

    while (true) {
        if (!first_country_valid) {
            std::cout << getDialogue(dialogues, "country_prompt") << "\n";
            std::getline(std::cin, country_first);

            if (country_first.empty() || country_first.find_first_not_of(" \t") == std::string::npos) {
                std::cout << getDialogue(dialogues, "country_retry") << "\n";
                continue;
            }

            first_country_valid = true;
        }

        std::cout << getDialogue(dialogues, "country_wish_prompt") << "\n";
        std::getline(std::cin, country_second);

        if (country_second.empty() || country_second.find_first_not_of(" \t") == std::string::npos) {
            std::cout << getDialogue(dialogues, "country_wish_retry_empty") << "\n";
            continue;
        }

        if (country_first == country_second) {
            std::cout << getDialogue(dialogues, "country_wish_retry_same") << "\n";
            continue;
        }

        std::cout << getDialogue(dialogues, "country_valid") << "\n";
        std::cin.get();
        break;
    }

    std::cout << getDialogue(dialogues, "bar_intro") << "\n";
    {
        std::string dummy;
        std::getline(std::cin, dummy);
    }

    while (true) {
        std::cout << getDialogue(dialogues, "bar_entrance") << "\n";
        std::string choice;
        std::getline(std::cin, choice);

        if (choice == "man") {
            std::cout << getDialogue(dialogues, "bar_man") << "\n";
            break;
        } else if (choice == "woman") {
            std::cout << getDialogue(dialogues, "bar_woman") << "\n";
            break;
        } else {
            std::cout << getDialogue(dialogues, "bar_invalid") << "\n";
        }
    }

    std::cout << getDialogue(dialogues, "conversation_continue") << "\n";

    return 0;
}
