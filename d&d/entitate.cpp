#include "entitate.h"
#include <cstdlib> // pentru rand()

Entitate::Entitate(string n, int hp, int mp, int str, int agi, int intel, int arm) 
    : nume(n), viataMax(hp), viataCurenta(hp), manaMax(mp), manaCurenta(mp),
      putere(str), agilitate(agi), inteligenta(intel), armura(arm) {
    nivel = 1;
}

Entitate::~Entitate() {}

bool Entitate::esteMort() const { return viataCurenta <= 0; }
string Entitate::getNume() const { return nume; }
int Entitate::getHP() const { return viataCurenta; }
int Entitate::getMaxHP() const { return viataMax; }
int Entitate::getMP() const { return manaCurenta; }
int Entitate::getMaxMP() const { return manaMax; }
int Entitate::getNivel() const { return nivel; }

int Entitate::getStr() const { return putere; }
int Entitate::getInt() const { return inteligenta; }
int Entitate::getAgi() const { return agilitate; }

void Entitate::modificaHP(int valoare) {
    viataCurenta += valoare;
    if (viataCurenta > viataMax) viataCurenta = viataMax;
    if (viataCurenta < 0) viataCurenta = 0;
}

void Entitate::modificaMP(int valoare) {
    manaCurenta += valoare;
    if (manaCurenta > manaMax) manaCurenta = manaMax;
    if (manaCurenta < 0) manaCurenta = 0;
}

string Entitate::primesteLovitura(int damageBrut, bool esteMagic) {
    // Calcul eschiva
    int sansaEschiva = agilitate * 2;
    if (rand() % 100 < sansaEschiva) {
        return nume + " a eschivat atacul!";
    }

    int damageFinal = damageBrut;
    if (!esteMagic) {
        damageFinal -= armura;
        if (damageFinal < 1) damageFinal = 1;
    }

    modificaHP(-damageFinal);
    return nume + " a primit " + to_string(damageFinal) + " daune.";
}