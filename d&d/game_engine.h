#pragma once
#include "jucator.h"
#include "inamic.h"
#include <string>

class GameEngine {
private:
    Jucator* jucator;
    Inamic* inamic;
    StareJoc stare;
    string ultimulLog;
    int inamiciInvinsi;

    void genereazaInamic();

public:
    GameEngine();
    ~GameEngine(); // Important pentru a curata memoria

    void startJoc(string nume, int clasaID);
    void actiuneJucator(int actiuneID);
    void urmatoareaLupta();
    void cumparaPotiuneShop();

    // Getters pentru interfata
    string getLog();
    int getJucatorHP();
    int getJucatorMaxHP();
    int getJucatorMP();
    int getJucatorAur();
    int getJucatorPotiuni();
    int getJucatorNivel();
    string getInamicNume();
    int getInamicHP();
    int getInamicMaxHP();
    int getStareInterfata();
};