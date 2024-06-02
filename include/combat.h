#pragma once

#include "../include/piece.h"
#include "../include/Game.h"
#include <iostream>

class Combat {
private:
    Piece* attacker;
    Piece* defender;
    Display* display;
    Game* game;

    bool attemptAttack(Piece* attacker, Piece* defender) {
        int hitChance = rand() % 100;
        if (hitChance < attacker->getAcc()) {
            defender->takeDamage(attacker->getAtk());
            return true;
        }
        return false;
    }

    // print both player's (currHP/maxHP) (atk) (acc)
    void printStats(Piece* attacker, Piece* defender){}

public:
    Combat(Piece* attacker, Piece* defender, Display* display, Game* game) 
        : attacker(attacker), defender(defender), display(display), game(game) {}

    void startCombat() {
        std::cout << "------------------------------------------------------\n";
        std::cout << "Combat initiated between " << colorToString(attacker->getColor()) << " " << pieceToString(attacker->getType()) << 
            " and " << colorToString(defender->getColor()) << " " << pieceToString(defender->getType()) << "!\n";
        std::cout << "------------------------------------------------------\n";
        
        std::cin.ignore();
        // combat loop
        while (attacker->getHp() > 0 && defender->getHp() > 0) {
            std::cout << colorToString(attacker->getColor()) << pieceToString(attacker->getType()) << "'s turn! Press Enter to attack...";
            std::cin.ignore();

            if (attemptAttack(attacker, defender)) {
                std::cout << " > " << colorToString(attacker->getColor()) << " " << pieceToString(attacker->getType()) << "'s attack hits!\n";
                std::cout << " > " << "Defender's HP: " << defender->getHp() << "\n";
            } else {
                std::cout << " > " << colorToString(attacker->getColor()) << " " << pieceToString(attacker->getType()) << " swings and misses!\n";
            }

            std::cout << "\n";

            if (defender->getHp() <= 0) break;

            std::swap(attacker, defender); // swap roles for next round
        }

        // end combat loop, display results
        if (attacker->getHp() <= 0) {
            std::cout << pieceToString(attacker->getType()) << " has been defeated!\n";
        } else {
            std::cout << pieceToString(defender->getType()) << " has been defeated!\n";
        }

        // check if king died, if yes then flag
        game->whiteWin();
        game->blackWin();
    }
};
