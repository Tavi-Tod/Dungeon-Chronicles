#include "game_engine.h"
#include <ctime>
#include <cstdlib>

GameEngine::GameEngine() {
    srand(time(0));
    stare = MENIU;
    jucator = nullptr;
    inamic = nullptr;
    inamiciInvinsi = 0;
}

GameEngine::~GameEngine() {
    if (jucator) delete jucator;
    if (inamic) delete inamic;
}

void GameEngine::startJoc(string nume, int clasaID) {
    if (jucator) delete jucator;
    jucator = new Jucator(nume, (TipClasa)clasaID);
    stare = LUPTA;
    inamiciInvinsi = 0;
    genereazaInamic();
    ultimulLog = "Jocul a inceput! Ai intalnit un " + inamic->getNume();
}

void GameEngine::genereazaInamic() {
    if (inamic) delete inamic;
    inamic = new Inamic(inamiciInvinsi);
}

void GameEngine::actiuneJucator(int actiuneID) {
    if (stare != LUPTA || !jucator || jucator->esteMort()) return;

    ultimulLog = "";
    bool turaInamicului = true;

    // ... (LOGICA DIN MESAJUL ANTERIOR PENTRU 1, 2, 3) ...
    // Pentru a nu copia tot codul imens iar, aici pui logica din switch-ul de actiune
    // Exemplu scurt:
    if (actiuneID == 1) { 
         int dmg = jucator->calculeazaDamageBaza();
         ultimulLog += inamic->primesteLovitura(dmg, false);
    }
     
    else if (actiuneID == 3) {
        if(!jucator->beaPotiune()) turaInamicului = false;
        else ultimulLog += "Te-ai vindecat.";
    }
     else if (actiuneID == 2) { // Abilitate
        pair<int, int> ab = jucator->folosesteAbilitate();
        // ab.first este DAMAGE-ul
        // ab.second este COSTUL DE MANA

        if (ab.second > 0) { // Verificam daca functia a returnat un cost (adica am avut mana)
            
            // --- GRESEALA PROBABILA 1: Ai scris modificaHP in loc de modificaMP ---
            jucator->modificaMP(-ab.second); // CORECT: Scadem MP (Mana)
            
            // --- GRESEALA PROBABILA 2: Ai scris jucator->primesteLovitura in loc de inamic ---
            string textAtac = inamic->primesteLovitura(ab.first, true); // CORECT: Inamicul ia damage
            
            ultimulLog += "[ABILITATE] " + textAtac;

        } else {
            ultimulLog += "Nu ai destula Mana/Stamina!";
            turaInamicului = false; // Daca nu ai mana, nu pierzi tura
        }
    }
    

    // Verificari Moarte Inamic
    if (inamic->esteMort()) {
        inamiciInvinsi++;
        jucator->adaugaXP(inamic->xpReward);
        jucator->adaugaAur(inamic->goldReward);
        stare = (inamiciInvinsi > 9) ? VICTORIE : MAGAZIN;
        ultimulLog += "<br>Victorie!";
        return;
    }

    // Actiune Inamic
    if (turaInamicului) {
         int dmg = inamic->ataca();
         ultimulLog += "<br>" + jucator->primesteLovitura(dmg, false);
         jucator->modificaMP(5);
    }
    
    if (jucator->esteMort()) stare = INFRANGERE;
}

void GameEngine::urmatoareaLupta() {
    if (stare == MAGAZIN) {
        stare = LUPTA;
        genereazaInamic();
        ultimulLog = "Urmatoarea lupta: " + inamic->getNume();
    }
}

void GameEngine::cumparaPotiuneShop() {
    if (stare == MAGAZIN && jucator->cumparaPotiune()) {
        ultimulLog = "Ai cumparat o potiune.";
    }
}

// Implementarea Getter-ilor simpli
string GameEngine::getLog() { return ultimulLog; }
int GameEngine::getJucatorHP() { return jucator ? jucator->getHP() : 0; }
int GameEngine::getJucatorMaxHP() { return jucator ? jucator->getMaxHP() : 0; }
int GameEngine::getJucatorMP() { return jucator ? jucator->getMP() : 0; }
int GameEngine::getJucatorAur() { return jucator ? jucator->getAur() : 0; }
int GameEngine::getJucatorPotiuni() { return jucator ? jucator->getPotiuni() : 0; }
int GameEngine::getJucatorNivel() { return jucator ? jucator->getNivel() : 0; }
string GameEngine::getInamicNume() { return inamic ? inamic->getNume() : "-"; }
int GameEngine::getInamicHP() { return inamic ? inamic->getHP() : 0; }
int GameEngine::getInamicMaxHP() { return inamic ? inamic->getMaxHP() : 0; }
int GameEngine::getStareInterfata() { return stare; }