#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Color.hpp>
#include <cmath>
#include "Utils.h"

namespace Utils 
{
    bool Normalize(sf::Vector2f& vector)
    {
        float magnitude = std::sqrt(vector.x * vector.x + vector.y * vector.y);

		if (magnitude != 0)
		{
			vector.x /= magnitude;
			vector.y /= magnitude;
		
			return true;
		}

		return false;
    }

	float GetDistance(int x1, int y1, int x2, int y2)
	{
		int x = x2 - x1;
		int y = y2 - y1;

		return std::sqrt(x * x + y * y);
	}

	float GetAngleDegree(const sf::Vector2f& v1, const sf::Vector2f& v2)
	{
		float dot = v1.x * v2.x + v1.y * v2.y;
		float det = v1.x * v2.y - v1.y * v2.x;

		return std::atan2(det, dot) * 180 / 3.14159265;
	}
	int Utils::GenerateRandomNumber(int min, int max)
	{
		
		return rand() % (max - min + 1) + min;
		
	}
	
	sf::Color RandomColor() {
	sf::Color color;

	int number = Utils::GenerateRandomNumber(1, 7);

	switch (number)
	{
	case 1:
		color = sf::Color::Blue;
		break;
	case 2:
		color = sf::Color::Cyan;
		break;
	case 3:
		color = sf::Color::Green;
		break;
	case 4:
		color = sf::Color::Magenta;
		break;
	case 5:
		color = sf::Color::Red;
		break;
	case 6:
		color = sf::Color::White;
		break;
	case 7:
		color = sf::Color::Yellow;
		break;

	default:
		break;
	}

	return color;
}
}

