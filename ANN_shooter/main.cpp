#include "Player.h"

static const int FPS_LOCK = 60;
static const int SCREEN_WIDTH = 600;
static const int SCREEN_HEIGHT = 800;

int main()
{
	Texture baseAtlas;
	Texture projAtlas;
	baseAtlas.loadFromFile("pers_walk.png");
	projAtlas.loadFromFile("base_projectile.png");
	SpriteList baseList = SpriteList(baseAtlas, 60, 63, 1, std::vector<int>{6});
	SpriteList projList = SpriteList(projAtlas,32,32,1,std::vector<int>{1});
	Animation bulletAnim = Animation(&projList, 0, 1);
	Animation baseAnim = Animation(&baseList, 0, 12);
	Weapon baseWeapon = Weapon(Projectile(bulletAnim), 5, 1000, 4);
	RenderWindow mainWindow(VideoMode(SCREEN_HEIGHT, SCREEN_WIDTH, 32), "main");
	mainWindow.setFramerateLimit(FPS_LOCK);
	Player player = Player(baseAnim, baseWeapon, 250, mainWindow);
	while (mainWindow.isOpen())
	{
		mainWindow.clear();
		for (auto proj = enemyProjectiles.begin(); proj != enemyProjectiles.end(); proj++)
		{
			proj->Calculate();
			mainWindow.draw(proj->GetSprite());
		}
		mainWindow.draw(player.GetSprite());
		if (Mouse::isButtonPressed(Mouse::Button::Left))
			player.Shoot();
		player.Calculate();
		mainWindow.display();
	}
	return 0;
}