#include "Player.h"
#include "Perceptor.h"
int main()
{
	srand(time(NULL));
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
	Field mainField(0.02, mainWindow, Vector2f(0,0), false);
	Weapon annWeapon = Weapon(Projectile(bulletAnim, Vector2f(0.25,0.25)), 5, 10, 4);
	Weapon playerWeapon = Weapon(Projectile(bulletAnim, Vector2f(0.25, 0.25)), 5, 10, 6);
	Perceptor ann = Perceptor(idleAnim, walkAnim, shootAnim, walkShootAnim, annWeapon, 3, mainField, Vector2f( 1,1 ));
	Player player = Player(idleAnim, walkAnim, shootAnim, walkShootAnim, playerWeapon, 5, mainField, Vector2f(1, 1));
	while (mainWindow.isOpen())
	{
		/*  —ÃŒ“–»
		        —“–≈Àﬂ…  */
		ann.LookAt(player.GetPosition());
		//ann.Shoot();
		if (globalProjectiles[0].size() != 0)
		{
			/*  ƒ”ÃŒ…
			        ”¡≈√¿…  */
			auto dir = ann.Process();
			//std::cout << dir.x << " " << dir.y << std::endl;
			ann.Move(dir);
			ann.Calculate();
		}
		//std::cout <<  ann.GetPosition().x << " " << ann.GetPosition().y << std::endl;
		mainWindow.clear();
		mainField.HandleObjects();
		mainWindow.display();
	}
	return 0;
}