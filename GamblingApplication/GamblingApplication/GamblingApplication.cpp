#include <iostream>
#include <windows.h>
#include <string>

class player {
public:
    int money;
    int name;
    int guess;
    int bet;
    int win;
    int loss;
};

class house {
public:
    int randomNumber = rand() % 10;
    void regenNumber() {
        randomNumber = rand() % 10;
    }
};

int main()
{
    srand(time(0));
    player player;
    house house;
    std::cout << "---------------------------------------------------------------------\n";
    std::cout << "                    Welcome to the Casino!\n";
    std::cout << "---------------------------------------------------------------------\n";
    std::cout << "                      Here are the rules!" << std::endl;
    Sleep(1000);
    std::cout << "1) Choose any number between 1 and 10!" << std::endl;
    Sleep(1000);
    std::cout << "2) If you win and guess the number, you get 10x your money!" << std::endl;
    Sleep(1000);
    std::cout << "3) If you bet the wrong number, you lose your betting amount." << std::endl;
    Sleep(1000);

    std::cout << "\nHow much money do you want to play with?" << std::endl;
    std::cin >> player.money;

restart:
    house.regenNumber();
    std::cout << "You have " << player.money << std::endl;
    std::cout << "How much do you want to gamble with this round?" << std::endl;
    std::cin >> player.bet;
    Sleep(1000);

    std::cout << "Guess a random number between 1 and 10" << std::endl;
    std::cin >> player.guess;
    Sleep(1000);

    if (player.guess > 10) {
        std::cout << "Please select a number between 1 and 10" << std::endl;
        Sleep(1000);
        system("cls");
        goto restart;
    }

    std::cout << "You have guessed " << player.guess << std::endl;

    if (player.guess == house.randomNumber) {
        player.win = player.bet * 10;
        player.money = player.money + player.win;
        std::cout << "You won! You now have " + std::to_string(player.money);
    }
    else {
        player.money = player.money - player.bet;
        std::cout << "You have lost! You now have " + std::to_string(player.money) << std::endl;
        std::cout << "The correect answer was " << house.randomNumber << std::endl;

    }

    if (player.money <= 0) {
        std::cout << "You are broke! Go home loser!";
    }
    else {
        Sleep(1000);
        system("cls");
        goto restart;
    }
}