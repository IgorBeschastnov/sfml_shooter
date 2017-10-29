#include "Player.h"

static const int FPS_LOCK = 60;
static const int SCREEN_WIDTH = 600;
static const int SCREEN_HEIGHT = 800;

int main()
{
	Texture baseAtlas;
	Texture projAtlas;
	baseAtlas.loadFromFile("base_person.png");
	projAtlas.loadFromFile("base_projectile.png");
	SpriteList baseList = SpriteList(baseAtlas, 32, 32, 4, std::vector<int>{1,4,4,2});
	SpriteList projList = SpriteList(projAtlas,32,32,1,std::vector<int>{1});
	Animation bulletAnim = Animation(&projList, 0, 1);
	Animation idleAnim = Animation(&baseList, 0, 1);
	Animation walkAnim = Animation(&baseList, 1, 8);
	Animation walkShootAnim = Animation(&baseList, 2, 8);
	Animation shootAnim = Animation(&baseList, 3, 2);
	Weapon baseWeapon = Weapon(Projectile(bulletAnim), 5, 1000, 4);
	RenderWindow mainWindow(VideoMode(SCREEN_HEIGHT, SCREEN_WIDTH, 32), "main");
	mainWindow.setFramerateLimit(FPS_LOCK);
	Field mainField(0.01, mainWindow);
	Player player = Player(idleAnim, walkAnim, shootAnim, walkShootAnim, baseWeapon, 3, mainField, Vector2f( 1,1 ));

	while (mainWindow.isOpen())
	{
		mainWindow.clear();
		for (auto proj = enemyProjectiles.begin(); proj != enemyProjectiles.end(); proj++)
		{
			proj->Calculate();
			mainWindow.draw(proj->GetSprite());
		}
		mainField.HandleObjects();
		mainWindow.display();
	}
	return 0;
}