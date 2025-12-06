#pragma once // Previne includerea dublă
#include <string>
#include <iostream>

using namespace std;

enum TipClasa { CAVALER, ARCAS, MAGICIAN };
enum StareJoc { MENIU, LUPTA, MAGAZIN, VICTORIE, INFRANGERE };

class Entitate {
protected:
    string nume;
    int nivel;
    int viataMax, viataCurenta;
    int manaMax, manaCurenta;
    int putere, agilitate, inteligenta, armura;

public:
    Entitate(string n, int hp, int mp, int str, int agi, int intel, int arm);
    virtual ~Entitate(); // Destructor virtual

    bool esteMort() const;
    string getNume() const;
    int getHP() const;
    int getMaxHP() const;
    int getMP() const;
    int getMaxMP() const;
    int getNivel() const;

    void modificaHP(int valoare);
    void modificaMP(int valoare);
    
    string primesteLovitura(int damageBrut, bool esteMagic);

    // Getters pentru atribute
    int getStr() const;
    int getInt() const;
    int getAgi() const;
};