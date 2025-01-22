#include <iostream>
#include <fstream>
#include <string>
#include </Users/maria/Downloads/text-adventure-starting/vcpkg/installed/arm64-osx/include/json/json.h>

// function for loading json
void loadJson(const std::string& filePath, Json::Value& dialogues);

// function for retrieving a dialogue
std::string getDialogue(const Json::Value& dialogues, const std::string& key);

// function for replacing substrings
std::string replacePlaceholders(const std::string& text, const std::string& placeholder, const std::string& value);

// function for checking yes/no questions
std::string getYesNoInput(const Json::Value& dialogues, const std::string& retryKey) {
    while (true) {
        std::string response;
        std::getline(std::cin, response);

        if (response == "yes" || response == "no") {
            return response;
        }

        std::cout << getDialogue(dialogues, retryKey) << "\n";
    }
}

// function to handle the sea adventure storyline
void storyAdventure(const Json::Value& dialogues);

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
            {
                std::string dummy;
                std::getline(std::cin, dummy);
            }
            break;
        } else if (choice == "woman") {
            std::cout << getDialogue(dialogues, "bar_woman") << "\n";
            {
                std::string dummy;
                std::getline(std::cin, dummy);
            }
            break;
        } else {
            std::cout << getDialogue(dialogues, "bar_invalid") << "\n";
        }
    }

    // launch the sea adventure storyline
    storyAdventure(dialogues);

    return 0;
}

// function for loading json
void loadJson(const std::string& filePath, Json::Value& dialogues) {
    std::ifstream file(filePath, std::ifstream::binary);
    if (!file.is_open()) {
        std::cerr << "warning: could not open file " << filePath << ".\n";
        return;
    }
    file >> dialogues;
    file.close();
}

// function for retrieving a dialogue
std::string getDialogue(const Json::Value& dialogues, const std::string& key) {
    if (dialogues.isMember(key)) {
        return dialogues[key].asString();
    }
    return ""; // return an empty string if the key is missing
}

// function for replacing substrings
std::string replacePlaceholders(const std::string& text, const std::string& placeholder, const std::string& value) {
    std::string result = text;
    size_t pos = 0;
    while ((pos = result.find(placeholder, pos)) != std::string::npos) {
        result.replace(pos, placeholder.length(), value);
        pos += value.length();
    }
    return result;
}

// function to handle the sea adventure storyline
void storyAdventure(const Json::Value& dialogues) {

    std::string response;

    // start the story
    std::cout << getDialogue(dialogues, "story_intro") << "\n";
    {
        std::string dummy;
        std::getline(std::cin, dummy);
    }
    std::cout << getDialogue(dialogues, "story_no_choice") << "\n";
    {
        std::string dummy;
        std::getline(std::cin, dummy);
    }
    std::cout << getDialogue(dialogues, "storm_start") << "\n";
    {
        std::string dummy;
        std::getline(std::cin, dummy);
    }

    // first question: would you jump to save someone overboard?
    std::cout << getDialogue(dialogues, "storm_question") << " type yes or no\n";
    response = getYesNoInput(dialogues, "ready_retry");
    if (response == "yes") {
        std::cout << getDialogue(dialogues, "storm_answer_yes") << "\n";
        {
            std::string dummy;
            std::getline(std::cin, dummy);
        }
    } else {
        std::cout << getDialogue(dialogues, "storm_answer_no") << "\n";
        {
            std::string dummy;
            std::getline(std::cin, dummy);
        }
    }

    // continue the story
    std::cout << getDialogue(dialogues, "storm_aftermath") << "\n";
    {
        std::string dummy;
        std::getline(std::cin, dummy);
    }

    // second question: would you share your food supplies?
    std::cout << getDialogue(dialogues, "storm_aftermath3") << " type yes or no\n";
    response = getYesNoInput(dialogues, "ready_retry");
    if (response == "yes") {
        std::cout << getDialogue(dialogues, "share_food_yes") << "\n";
        {
            std::string dummy;
            std::getline(std::cin, dummy);
        }
    } else {
        std::cout << getDialogue(dialogues, "share_food_no") << "\n";
        {
            std::string dummy;
            std::getline(std::cin, dummy);
        }
    }

    // third story + question: would you check the faint light on the horizon?
    std::cout << getDialogue(dialogues, "light_on_horizon2") << " type yes or no\n";
    response = getYesNoInput(dialogues, "ready_retry");
    if (response == "yes") {
        std::cout << getDialogue(dialogues, "light_answer_yes1") << "\n";
        {
            std::string dummy;
            std::getline(std::cin, dummy);
        }
    } else {
        std::cout << getDialogue(dialogues, "light_answer_no") << "\n";
        {
            std::string dummy;
            std::getline(std::cin, dummy);
        }
    }

    // conclude the story
    std::cout << getDialogue(dialogues, "story_ending") << "\n";

    // final choice: go with the companion or stay
    std::cout << getDialogue(dialogues, "final_choice") << " type yes or no\n";
    response = getYesNoInput(dialogues, "ready_retry");
    if (response == "yes") {
        std::cout << "you chose to go with them. your adventure continues...\n";
    } else {
        std::cout << getDialogue(dialogues, "stay_choice") << "\n";
    }
}
