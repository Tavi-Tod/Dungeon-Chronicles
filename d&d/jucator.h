#pragma once
#include "entitate.h"
#include <utility> // Pentru std::pair

class Jucator : public Entitate {
private:
    TipClasa clasa;
    int experienta;
    int experientaNecesar;
    int aur;
    int potiuni;

public:
    Jucator(string nume, TipClasa tip);

    int calculeazaDamageBaza();
    std::pair<int, int> folosesteAbilitate(); // Returnează {Damage, Cost}

    void adaugaXP(int xp);
    void adaugaAur(int cantitate);
    bool cumparaPotiune();
    bool beaPotiune();

    int getAur() const;
    int getPotiuni() const;
    int getXP() const;
    int getXPNecesar() const;
};