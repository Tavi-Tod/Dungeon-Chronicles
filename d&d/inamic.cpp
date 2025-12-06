#include "inamic.h"
#include <cstdlib>

Inamic::Inamic(int idDificultate) : Entitate("Monstru", 1, 1, 1, 1, 1, 0) {
    string numeInamici[] = {"Sobolan", "Goblin", "Lup", "Bandit", "Schelet", "Orc", "Troll", "Gargui", "Vrajitor Negru", "DRAGON"};
    
    // Asiguram ca ID-ul nu depaseste array-ul
    if(idDificultate > 9) idDificultate = 9;

    nume = numeInamici[idDificultate];
    nivel = idDificultate + 1;
    
    viataMax = 30 + (idDificultate * 25);
    viataCurenta = viataMax;
    putere = 5 + (idDificultate * 3);
    agilitate = 2 + (idDificultate * 2);
    armura = idDificultate;

    xpReward = 20 + (idDificultate * 15);
    goldReward = 10 + (idDificultate * 10);
}

int Inamic::ataca() {
    return putere + (rand() % 5);
}