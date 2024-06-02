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



public:
    Combat(Piece* attacker, Piece* defender, Display* display, Game* game) 
        : attacker(attacker), defender(defender), display(display), game(game) {}

    void startCombat() {
        std::cout << "Combat initiated between " << pieceToString(attacker->getType()) << " and " << pieceToString(defender->getType()) << "!\n";
        
        // combat loop
        while (attacker->getHp() > 0 && defender->getHp() > 0) {
            std::cout << colorToString(attacker->getColor()) << pieceToString(attacker->getType()) << "'s turn! Press Enter to attack...";
            std::cin.ignore();

            if (attemptAttack(attacker, defender)) {
                std::cout << colorToString(attacker->getColor()) << pieceToString(attacker->getType()) << "'s attack hits!\nDefender's HP: " << defender->getHp() << "\n";
            } else {
                std::cout << colorToString(attacker->getColor()) << pieceToString(attacker->getType()) << "swings and misses!\n";
            }

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
