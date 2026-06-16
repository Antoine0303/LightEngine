#include "Collector.h"
#include "SampleScene.h"
#include "Utils.h"
#include "Data.h"
#include "DummyEntity.h"
void Collector::OnUpdate()
{
	float speed = Data::Get()->playerSpeed;
	Rectangle rect = GetScene<SampleScene>()->GetRect();
	sf::Vector2f pos = GetPosition();

	float directionX = 0;
	float directionY = 0;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
		if (GetPosition(0, 0).y <= rect.y) {
			SetPosition(pos.x, rect.y, 0.5 ,0);
			return;
		}

		directionY -= 1;

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		if (GetPosition(1, 1).y >= rect.y + rect.height) {
			SetPosition(pos.x, rect.y + rect.height, 0.5, 1);
			return;
		}

		directionY += 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
		if (GetPosition(0, 0).x <= rect.x) {
			SetPosition(rect.x, pos.y, 0, 0.5);
			return;
		}

		directionX -= 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		if (GetPosition(1, 1).x >= rect.x + rect.width) {
			SetPosition(rect.x + rect.width, pos.y, 1, 0.5);
			return;
		}

		directionX += 1;
	}

	float move = GetDeltaTime() * speed;

	if (directionX != 0 && directionY != 0) 
	{
		directionX = directionX / std::sqrt(2);
		directionY = directionY / std::sqrt(2);
	}

	SetPosition(pos.x + directionX * move, pos.y + directionY * move);

	/*if (GetPosition(1, 1).y >= rect.y + rect.height) {
		SetPosition(pos.x, pos.y - GetDeltaTime() * speed);

	}
	if (GetPosition(0, 0).y <= rect.y) {
		SetPosition(pos.x, pos.y + GetDeltaTime() * speed);

	}
	if (GetPosition(1, 1).x >= rect.x + rect.width) {
		SetPosition(pos.x - GetDeltaTime() * speed, pos.y);

	}
	if (GetPosition(0, 0).x <= rect.x) {
		SetPosition(pos.x + GetDeltaTime() * speed, pos.y);
	}*/
}

void Collector::OnCollision(Entity* other)
{

	if(other->IsTag(1))
	{
		Data::Get()->money += dynamic_cast<DummyEntity*>(other)->GetValue();
	}
}

void Collector::OnClick()
{
	//GoToDirection(Utils::GenerateRandomNumber(0, GetScene()->GetWindowWidth()), Utils::GenerateRandomNumber(0, GetScene()->GetWindowHeight()), Data::Get()->collectorSpeed);

}