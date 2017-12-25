#include "Player.h"


Vector2f Player::getMoveDirection()
{
	Vector2f direction = Vector2f(0, 0);
	if (Keyboard::isKeyPressed(Keyboard::Key::W))
		direction.y -= 1;
	if (Keyboard::isKeyPressed(Keyboard::Key::S))
		direction.y += 1;
	if (Keyboard::isKeyPressed(Keyboard::Key::A))
		direction.x -= 1;
	if (Keyboard::isKeyPressed(Keyboard::Key::D))
		direction.x += 1;
	return direction;
}

Vector2f Player::getLookDirection()
{
	float scale = field->GetScale();
	Vector2f direction = (position-field->GetCameraPosition()) / scale;
	Vector2i mousePos = Mouse::getPosition(*window);
	direction.x = mousePos.x - direction.x;
	direction.y = mousePos.y - direction.y;
	return direction;
}

void Player::Calculate()
{
	state = idle;
	Vector2f moveDirection = getMoveDirection();
	if (moveDirection != Vector2f(0, 0))
		Move(moveDirection);
	Vector2f lookDirection = getLookDirection();
	LookAt(lookDirection);
	if (Mouse::isButtonPressed(Mouse::Button::Left))
		Shoot();
	Soldier::Calculate();
}

Player::Player(Animation defaultAnimation, Weapon weapon_, float speed_, Field& field, Vector2f size) : Soldier(defaultAnimation, weapon_, speed_, field, size)
{
	that = this;
	type = player;
	window = field.GetWindow();
}

Player::Player(Animation idle_, Animation walk_, Animation shoot_, Animation walkShoot_, Weapon weapon_, float speed_, Field& field, Vector2f size) : Soldier(idle_, walk_, shoot_, walkShoot_, weapon_, speed_, field, size)
{
	that = this;
	type = player;
	window = field.GetWindow();
}

Player::~Player()
{
}
