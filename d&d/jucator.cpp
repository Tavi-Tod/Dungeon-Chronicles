#include "jucator.h"
#include <cstdlib>

Jucator::Jucator(string nume, TipClasa tip) : Entitate(nume, 100, 50, 10, 10, 10, 0) {
    clasa = tip;
    experienta = 0;
    experientaNecesar = 100;
    aur = 0;
    potiuni = 3;

    if (clasa == CAVALER) {
        viataMax = 140; viataCurenta = 140;
        manaMax = 50;  manaCurenta = 50;
        putere = 18; agilitate = 8; inteligenta = 5; armura = 5;
    } else if (clasa == ARCAS) {
        viataMax = 100; viataCurenta = 100;
        manaMax = 80;  manaCurenta = 80;
        putere = 12; agilitate = 18; inteligenta = 8; armura = 2;
    } else if (clasa == MAGICIAN) {
        viataMax = 80; viataCurenta = 80;
        manaMax = 150; manaCurenta = 150;
        putere = 5; agilitate = 10; inteligenta = 20; armura = 0;
    }
}

int Jucator::calculeazaDamageBaza() {
    int dmg = (clasa == MAGICIAN) ? inteligenta : putere;
    int variatie = (dmg * 0.2);
    return dmg - variatie + (rand() % (variatie * 2 + 1));
}

std::pair<int, int> Jucator::folosesteAbilitate() {
    if (clasa == CAVALER && manaCurenta >= 20) return { (int)(putere * 2.5), 20 };
    if (clasa == ARCAS && manaCurenta >= 25) return { (int)(agilitate * 2.2), 25 };
    if (clasa == MAGICIAN && manaCurenta >= 40) return { (int)(inteligenta * 3.0), 40 };
    return {0, 0};
}

void Jucator::adaugaXP(int xp) {
    experienta += xp;
    if (experienta >= experientaNecesar) {
        nivel++;
        experienta -= experientaNecesar;
        experientaNecesar = (int)(experientaNecesar * 1.5);
        
        // Level up stats
        viataMax += 20; viataCurenta = viataMax;
        manaMax += 10; manaCurenta = manaMax;
        putere += 2; agilitate += 2; inteligenta += 2;
        
        if (clasa == CAVALER) { putere += 3; armura += 1; }
        if (clasa == ARCAS) agilitate += 3;
        if (clasa == MAGICIAN) { inteligenta += 3; manaMax += 20; }
    }
}

void Jucator::adaugaAur(int cantitate) { aur += cantitate; }

bool Jucator::cumparaPotiune() {
    if (aur >= 50) {
        aur -= 50;
        potiuni++;
        return true;
    }
    return false;
}

bool Jucator::beaPotiune() {
    if (potiuni > 0) {
        modificaHP(50);
        potiuni--;
        return true;
    }
    return false;
}

int Jucator::getAur() const { return aur; }
int Jucator::getPotiuni() const { return potiuni; }
int Jucator::getXP() const { return experienta; }
int Jucator::getXPNecesar() const { return experientaNecesar; }