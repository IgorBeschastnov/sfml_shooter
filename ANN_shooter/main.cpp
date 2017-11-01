#include "Player.h"

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
	RenderWindow mainWindow(VideoMode(SCREEN_HEIGHT, SCREEN_WIDTH, 32), "main");
	mainWindow.setFramerateLimit(FPS_LOCK);
	Field mainField(0.01, mainWindow, Vector2f(0,0),true);
	Weapon baseWeapon = Weapon(Projectile(bulletAnim, Vector2f(0.25,0.25)), 5, 10, 4);
	Player player = Player(idleAnim, walkAnim, shootAnim, walkShootAnim, baseWeapon, 3, mainField, Vector2f( 1,1 ));
	Soldier sold = Soldier(idleAnim, walkAnim, shootAnim, walkShootAnim, baseWeapon, 3, mainField, Vector2f(1, 1));
	while (mainWindow.isOpen())
	{
		mainWindow.clear();
		sold.Move(Vector2f(1, 0));
		mainField.HandleObjects();
		mainWindow.display();
	}
	return 0;
}