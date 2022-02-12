#include <iostream>
#include <random> // for random_device, mt19937 seeder, uniform_int_distribution
#include <chrono> // for high precision waiting and time calculation
#include <thread> // for sleeping this thread

/*  turns out the chrono header has a high_resolution_clock::now()
    convinient since chrono was already in use for thread sleeping https://www.pluralsight.com/blog/software-development/how-to-measure-execution-time-intervals-in-c--
*/

std::string input;
bool playAgain = true;

void quickDraw() {
    std::string drew;
    
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> uni(3000, 7000);
    int randomMillis = uni(rng);
    std::this_thread::sleep_for(std::chrono::milliseconds(randomMillis));
    
    puts("DRAW!");
    auto computerDrew = std::chrono::high_resolution_clock::now();
    
    std::getline(std::cin, drew);
    auto userDrew = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> timeTaken = userDrew - computerDrew;
    
    if (timeTaken.count() < 0.1) {
        std::cout << "So sad...you drew before the clock struck noon!" << std::endl;
    } else if (timeTaken.count() > 0.33f) {
        std::cout << "So slow...you died! You took: " << timeTaken.count() << " seconds." << std::endl;
    } else if (timeTaken.count() > 0.1 && timeTaken.count() <= 0.33f) {
        std::cout << "Congratulations! You are the fastest gun in the west! You drew in: " << timeTaken.count() << " seconds." << std::endl;
    }
    
    puts("Enter QUIT to stop playing or anything else to try again...");
    std::string answer;
    std::getline(std::cin, answer);
    if (answer == "QUIT") {
        playAgain = false;
    } else {
        playAgain = true;
    }
}

int main(int argc, const char * argv[]) {
    puts("Welcome to Quick Draw! It's high noon and this town isn't big enough for both of you! Press Enter to begin...");
    puts("");
    std::getline(std::cin, input);
    while (playAgain == true) {
        quickDraw();
    }
    
    puts("Thanks for playing! Have a great day!");
    
    return 0;
}

