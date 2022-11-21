// Copyright (c) 2022 Immaculata HS All rights reserved.
//
// Created by: Joseph Kwon
// Created on: November 15 2022
// This program generates two random values for Dice 1 and Dice 2.
// It continues generating random numbers until Dice 1 and Dice 2 match.

#include <iostream>
#include <random>

int counter1 = 0;

// function definition for a looped loading
int loadbar() {
    // initialize the counter
    int counter1 = 0;

    // Loading bar using a while loop
    while (counter1 != 40) {
        std::cout << "⚅ ";
        // incrementing counter1
        counter1++;
    }

    std::cout << "Loading.";
    std::cout << ".";
    std::cout << ".\n";
}

int calculations() {
    // Declaring variables
    int counter = 0;

    // Assigning a random integer from 0-9 to secretNumber:
    std::random_device rseed;
    std::mt19937 rgen(rseed());
    std::uniform_int_distribution<int> idist(0, 6);
    const int SECRET_NUMBER{idist(rgen)};

    // Assigning a random integer from 0-9 to secretNumber (changed to 2)
    std::random_device rseed2;
    std::mt19937 rgen2(rseed2());
    std::uniform_int_distribution<int> idist2(0, 6);
    const int SECRET_NUMBER2{idist2(rgen2)};

    // A do while loop to print the random numbers until they match
    do {
        const int SECRET_NUMBER{idist(rgen)};
        const int SECRET_NUMBER2{idist2(rgen2)};
        // Gets the user's guess
        std::cout << "Dice ⚀ = " << SECRET_NUMBER << " & ";
        std::cout << "Dice ⚁ = " << SECRET_NUMBER2 << ".\n ";

        counter++;

        // Breaks the loop if the two random numbers match
        if (SECRET_NUMBER == SECRET_NUMBER2) {
            break;
        }
        // Performing this Do While loop while this boolean expression is true
    } while (SECRET_NUMBER != SECRET_NUMBER2);

    // If the first random number is equal to the
    // second random number then display counter to the user
    if (SECRET_NUMBER == SECRET_NUMBER2) {
        std::cout << "The dice matched at " << counter << " rolls.\n";
    }

    // 1 set as "1.0000" because c++ kept rounding my answer
    float percentage = 1.0000 / counter;
    float finalPercentage = percentage * 100;

    std::cout << "The chance of this was " << finalPercentage << " %\n";
}

int main() {
    // call the function definition for loop and calculations above
    loadbar();
    calculations();

    // Declaring variables
    std::string userAnswer;

    // users a while loop to give the user the option
    // to continue or not after the user finishes
    std::cout << "Would you like to try again? (y/n)\n";
    std::cout << ">> ";
    std::cin >> userAnswer;
    std::cout << "\n";
    while (userAnswer == "y") {
        return main();

        // Else if the user answer is n, thank them for playing
    }
    if (userAnswer == "n") {
        std::cout << "Thanks for playing.";
        // else if none of the options above
        // were inputted, display default message
    } else {
        std::cout << "program has ended.";
    }
}
