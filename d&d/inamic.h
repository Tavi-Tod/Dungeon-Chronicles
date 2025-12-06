#pragma once
#include "entitate.h"

class Inamic : public Entitate {
public:
    int xpReward;
    int goldReward;

    Inamic(int idDificultate);
    int ataca();
};