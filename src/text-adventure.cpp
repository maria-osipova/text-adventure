// first, undefine any suspicious macros that might clash
#ifdef replace
#undef replace
#endif

#ifdef append
#undef append
#endif

#ifdef operator=
#undef operator=
#endif

#ifdef operator+
#undef operator+
#endif

#ifdef min
#undef min
#endif

#ifdef max
#undef max
#endif

#ifdef string
#undef string
#endif

#ifdef std
#undef std
#endif

#include <iostream>
#include <fstream>
#include <string>

// now include the json header (or any other headers)
#include </Users/maria/Downloads/text-adventure-starting/vcpkg/installed/arm64-osx/include/json/json.h>

// this function copies 'src' onto the end of 'dest' character by character
// instead of using operator=, operator+=, append, etc.
static void safeStringAppend(std::string& dest, const std::string& src) {
    for (char c : src) {
        dest.push_back(c);
    }
}

// this function loads the json file
static void loadJson(const std::string& filePath, Json::Value& dialogues) {
    std::ifstream file(filePath, std::ifstream::binary);
    if (!file.is_open()) {
        std::cerr << "warning: could not open file " << filePath << "\n";
        return;
    }
    file >> dialogues;
    file.close();
}

// this function returns a dialogue string by key
static std::string getDialogue(const Json::Value& dialogues, const std::string& key) {
    if (dialogues.isMember(key)) {
        return dialogues[key].asString();
    }
    return "";
}

// this function manually replaces all occurrences of 'placeholder' with 'value'
// but builds a result string purely with our safe append function
static std::string replacePlaceholders(
    const std::string& original,
    const std::string& placeholder,
    const std::string& value
) {
    if (placeholder.empty()) {
        return original;
    }
    std::string result;
    // reserve enough space to hopefully avoid too many allocations
    result.reserve(original.size() + value.size() * 4);

    size_t startIndex = 0;
    while (true) {
        size_t foundPos = original.find(placeholder, startIndex);
        if (foundPos == std::string::npos) {
            // append everything from startIndex to the end
            safeStringAppend(result, original.substr(startIndex));
            break;
        }
        // append everything before the placeholder
        safeStringAppend(result, original.substr(startIndex, foundPos - startIndex));
        // append the replacement
        safeStringAppend(result, value);

        // move start index
        startIndex = foundPos + placeholder.size();
    }
    return result;
}

// this function checks yes/no input
static std::string getYesNoInput(const Json::Value& dialogues, const std::string& retryKey) {
    while (true) {
        std::string response;
        std::getline(std::cin, response);
        if (response == "yes" || response == "no") {
            return response;
        }
        std::cout << getDialogue(dialogues, retryKey) << "\n";
    }
}

// forward declarations
static void storyAdventure(const Json::Value& dialogues, int& courage, int& generosity, int& trust);
static void storyContinuation(const Json::Value& dialogues, int& courage, int& generosity, int& trust);

int main() {
    Json::Value dialogues;
    loadJson("/Users/maria/Downloads/text-adventure-starting/src/dialogues.json", dialogues);

    // greeting
    std::cout << getDialogue(dialogues, "start_greeting") << "\n";
    {
        std::string dummy;
        std::getline(std::cin, dummy);
    }

    // big adventure
    std::cout << getDialogue(dialogues, "big_adventure") << "\n";
    {
        std::string dummy;
        std::getline(std::cin, dummy);
    }

    // check readiness
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

    // gender selection
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

    // name selection
    std::cout << getDialogue(dialogues, "name_prompt") << "\n";
    std::string name;
    while (true) {
        std::getline(std::cin, name);
        if (!name.empty() && name.find_first_not_of(" \t") != std::string::npos) {
            // do manual replacement for {gender} then {name}
            std::string temp = replacePlaceholders(getDialogue(dialogues, "name_valid"), "{gender}", gender);
            temp = replacePlaceholders(temp, "{name}", name);

            std::cout << temp << "\n";
            {
                std::string dummy;
                std::getline(std::cin, dummy);
            }
            break;
        } else {
            std::cout << getDialogue(dialogues, "name_retry") << "\n";
        }
    }

    // bar intro
    std::cout << getDialogue(dialogues, "bar_intro") << "\n";
    {
        std::string dummy;
        std::getline(std::cin, dummy);
    }

    // bar choice
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

    // stats
    int courage = 0;
    int generosity = 0;
    int trust = 0;

    // start the sea adventure
    storyAdventure(dialogues, courage, generosity, trust);
    return 0;
}

// this function contains the main sea adventure storyline
static void storyAdventure(const Json::Value& dialogues, int& courage, int& generosity, int& trust) {
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

    // storm question
    std::cout << getDialogue(dialogues, "storm_question") << " type yes or no\n";
    std::string response = getYesNoInput(dialogues, "ready_retry");
    if (response == "yes") {
        std::cout << getDialogue(dialogues, "storm_answer_yes") << "\n";
        courage += 1;
        {
            std::string dummy;
            std::getline(std::cin, dummy);
        }
    } else {
        courage -= 1;
        std::cout << getDialogue(dialogues, "storm_answer_no") << "\n";
        {
            std::string dummy;
            std::getline(std::cin, dummy);
        }
    }

    std::cout << getDialogue(dialogues, "storm_aftermath") << "\n";
    {
        std::string dummy;
        std::getline(std::cin, dummy);
    }

    // share food question
    std::cout << getDialogue(dialogues, "storm_aftermath3") << " type yes or no\n";
    response = getYesNoInput(dialogues, "ready_retry");
    if (response == "yes") {
        std::cout << getDialogue(dialogues, "share_food_yes") << "\n";
        generosity += 1;
        {
            std::string dummy;
            std::getline(std::cin, dummy);
        }
    } else {
        generosity -= 1;
        std::cout << getDialogue(dialogues, "share_food_no") << "\n";
        {
            std::string dummy;
            std::getline(std::cin, dummy);
        }
    }

    // faint light question
    std::cout << getDialogue(dialogues, "light_on_horizon2") << " type yes or no\n";
    response = getYesNoInput(dialogues, "ready_retry");
    if (response == "yes") {
        trust += 1;
        std::cout << getDialogue(dialogues, "light_answer_yes1") << "\n";
        {
            std::string dummy;
            std::getline(std::cin, dummy);
        }
    } else {
        trust -= 1;
        std::cout << getDialogue(dialogues, "light_answer_no") << "\n";
        {
            std::string dummy;
            std::getline(std::cin, dummy);
        }
    }

    std::cout << getDialogue(dialogues, "story_ending") << "\n";

    // final choice
    std::cout << getDialogue(dialogues, "final_choice") << " type yes or no\n";
    response = getYesNoInput(dialogues, "ready_retry");
    if (response == "yes") {
        storyContinuation(dialogues, courage, generosity, trust);
    } else {
        std::cout << getDialogue(dialogues, "stay_choice") << "\n";
    }
}

// this function continues the story if the player chooses "yes"
static void storyContinuation(const Json::Value& dialogues, int& courage, int& generosity, int& trust) {
    std::cout << getDialogue(dialogues, "adventure_continue_intro") << "\n";
    {
        std::string dummy;
        std::getline(std::cin, dummy);
    }
    std::cout << getDialogue(dialogues, "adventure_continue_intro2") << "\n";
    {
        std::string dummy;
        std::getline(std::cin, dummy);
    }
    std::cout << getDialogue(dialogues, "adventure_continue_intro3") << "\n";
    {
        std::string dummy;
        std::getline(std::cin, dummy);
    }

    // help push the boat
    std::cout << getDialogue(dialogues, "adventure_question1") << "\n";
    std::string response = getYesNoInput(dialogues, "ready_retry");
    if (response == "yes") {
        courage += 1;
        std::cout << getDialogue(dialogues, "adventure_answer1_yes") << "\n";
    } else {
        courage -= 1;
        std::cout << getDialogue(dialogues, "adventure_answer1_no") << "\n";
    }
    {
        std::string dummy;
        std::getline(std::cin, dummy);
    }

    // rowing
    std::cout << getDialogue(dialogues, "adventure_continue_row") << "\n";
    {
        std::string dummy;
        std::getline(std::cin, dummy);
    }
    std::cout << getDialogue(dialogues, "adventure_continue_row2") << "\n";
    {
        std::string dummy;
        std::getline(std::cin, dummy);
    }

    // loyalty question
    std::cout << getDialogue(dialogues, "adventure_question2") << "\n";
    response = getYesNoInput(dialogues, "ready_retry");
    if (response == "yes") {
        trust += 1;
        std::cout << getDialogue(dialogues, "adventure_answer2_yes") << "\n";
    } else {
        trust -= 1;
        std::cout << getDialogue(dialogues, "adventure_answer2_no") << "\n";
    }
    {
        std::string dummy;
        std::getline(std::cin, dummy);
    }

    // island approach
    std::cout << getDialogue(dialogues, "adventure_continue_island1") << "\n";
    {
        std::string dummy;
        std::getline(std::cin, dummy);
    }
    std::cout << getDialogue(dialogues, "adventure_continue_island2") << "\n";
    {
        std::string dummy;
        std::getline(std::cin, dummy);
    }

    // ask or silent (with error handling)
    while (true) {
        std::cout << getDialogue(dialogues, "adventure_question3") << "\n";
        {
            std::string dummy;
            std::getline(std::cin, dummy);
        }
        std::string choice;
        std::getline(std::cin, choice);

        if (choice == "ask") {
            trust += 1;
            std::cout << getDialogue(dialogues, "adventure_answer3_ask") << "\n";
            break;
        } else if (choice == "silent") {
            std::cout << getDialogue(dialogues, "adventure_answer3_silent") << "\n";
            break;
        } else {
            std::cout << getDialogue(dialogues, "ready_retry") << "\n";
        }
    }
    {
        std::string dummy;
        std::getline(std::cin, dummy);
    }

    // landing
    std::cout << getDialogue(dialogues, "adventure_landing") << "\n";
    {
        std::string dummy;
        std::getline(std::cin, dummy);
    }
    std::cout << getDialogue(dialogues, "adventure_landing2") << "\n";
    {
        std::string dummy;
        std::getline(std::cin, dummy);
    }

    // final endings based on stats
    if (courage == 0 && generosity == 0 && trust == 0) {
        std::cout << "ending #1: no courage, no generosity, no trust.\n";
        std::cout << "you decide to stay on the shore, unwilling to risk or share.\n";
    }
    else if (courage == 0 && generosity == 0 && trust == 1) {
        std::cout << "ending #2: no courage, no generosity, but some trust.\n";
        std::cout << "you trust others but won't share or take bold steps. you watch from afar.\n";
    }
    else if (courage == 0 && generosity == 1 && trust == 0) {
        std::cout << "ending #3: no courage, generous, no trust.\n";
        std::cout << "you share your resources but refuse to face dangers or rely on anyone else.\n";
    }
    else if (courage == 0 && generosity == 1 && trust == 1) {
        std::cout << "ending #4: no courage, generous, trusting.\n";
        std::cout << "you are kind and believe in others, but fear holds you back from big adventures.\n";
    }
    else if (courage == 1 && generosity == 0 && trust == 0) {
        std::cout << "ending #5: courageous, not generous, no trust.\n";
        std::cout << "you take risks alone, hoarding supplies and ignoring calls for cooperation.\n";
    }
    else if (courage == 1 && generosity == 0 && trust == 1) {
        std::cout << "ending #6: courageous, not generous, but trusting.\n";
        std::cout << "you believe in a companion's support, yet do not share freely.\n";
    }
    else if (courage == 1 && generosity == 1 && trust == 0) {
        std::cout << "ending #7: courageous, generous, but no trust.\n";
        std::cout << "you bravely face threats and share with others, but cannot rely on them.\n";
    }
    else if (courage == 1 && generosity == 1 && trust == 1) {
        std::cout << "ending #8: courageous, generous, trusting.\n";
        std::cout << "you have the qualities of a true hero. your future adventures await!\n";
    }

    // show final stats
    std::cout << "\nyour final stats:\n";
    std::cout << " courage: " << courage << "\n";
    std::cout << " generosity: " << generosity << "\n";
    std::cout << " trust: " << trust << "\n";
    std::cout << "thanks for playing!\n";
}

