#include "Magnet.h"
#include "Debug.h"
void Magnet::OnUpdate()
{

	Debug::DrawCircle(GetPosition().x, GetPosition().y, GetRadius(), sf::Color::White);

}
