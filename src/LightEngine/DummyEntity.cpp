#include "DummyEntity.h"
#include "Utils.h"
#include <iostream>
#include "Data.h"

void DummyEntity::OnInitialize()
{
	SetTag(1);
	int random = Utils::GenerateRandomNumber(1, 100000);
	if (random <= 100000 )
	{
		m_rarity = "Common";
		SetColor(sf::Color(120,120,120));
		value = 1;
	}
	if (random <= 10000 * Data::Get()->luck)
	{
		m_rarity = "Rare";
		SetColor(sf::Color::Cyan);
		value = 10;
	}
	if (random <= 1000 * Data::Get()->luck)
	{
		m_rarity = "Epic";
		SetColor(sf::Color::Magenta);
		value = 100;
	}
	if (random <= 100 * Data::Get()->luck)
	{
		m_rarity = "Legendary";
		SetColor(sf::Color::Yellow);
		value = 1000;
	}
	if (random <= 10 * Data::Get()->luck)
	{
		m_rarity = "Mythical";
		SetColor(sf::Color::Red);
		value = 10000;
	}
	if (random <= 1 * Data::Get()->luck)
	{
		m_rarity = "Godly";
		value = 100000;
	}

	
	
	
	
	

	
}

void DummyEntity::OnCollision(Entity* other)
{
	
	std::cout << "DummyEntity::OnCollision" << std::endl;
}
void DummyEntity::OnUpdate()
{
	if (m_rarity == "Godly")
		SetColor(Utils::RandomColor());
}

