#include <iostream>

std::string input;

void spongeText(std::string s) {
    std::string str;
    bool flipCase = true;
    std::string uppedChar;
    std::string lowerChar;
    int randomInt;

    for (int i = 0; i <= s.length(); i++) {
        if (flipCase) {
            uppedChar = toupper(s[i]);
            str.append(uppedChar);
        } else {
            lowerChar = tolower(s[i]);
            str.append(lowerChar);
        }
        randomInt = rand() % 100;
        if (randomInt <= 50) {
            flipCase = false;
        } else {
            flipCase = true;
        }
    }
    std::cout << str << std::endl;
}

int main() {
    puts("Enter text to spongecase for QuIcK aNd WiTtY rEsPoNsEs...");
    std::getline(std::cin, input);
    spongeText(input);

    return 0;
}
