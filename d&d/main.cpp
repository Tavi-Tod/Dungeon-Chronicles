#include <emscripten/bind.h>
#include "game_engine.h"

using namespace emscripten;

// Aici expunem clasa GameEngine către Web
EMSCRIPTEN_BINDINGS(my_game) {
    class_<GameEngine>("GameEngine")
        .constructor<>()
        .function("startJoc", &GameEngine::startJoc)
        .function("actiuneJucator", &GameEngine::actiuneJucator)
        .function("urmatoareaLupta", &GameEngine::urmatoareaLupta)
        .function("cumparaPotiuneShop", &GameEngine::cumparaPotiuneShop)
        .function("getLog", &GameEngine::getLog)
        .function("getJucatorHP", &GameEngine::getJucatorHP)
        .function("getJucatorMaxHP", &GameEngine::getJucatorMaxHP)
        .function("getJucatorMP", &GameEngine::getJucatorMP)
        .function("getJucatorAur", &GameEngine::getJucatorAur)
        .function("getJucatorPotiuni", &GameEngine::getJucatorPotiuni)
        .function("getJucatorNivel", &GameEngine::getJucatorNivel)
        .function("getInamicNume", &GameEngine::getInamicNume)
        .function("getInamicHP", &GameEngine::getInamicHP)
        .function("getInamicMaxHP", &GameEngine::getInamicMaxHP)
        .function("getStareInterfata", &GameEngine::getStareInterfata);
}