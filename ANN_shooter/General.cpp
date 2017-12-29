#include "General.h"
std::vector<std::list<Projectile*>> globalProjectiles = std::vector<std::list<Projectile*>>(SoldierType::typesNumber);
const int FPS_LOCK = 60;
const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 800;