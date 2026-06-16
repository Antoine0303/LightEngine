#include "SampleScene.h"
#include "Utils.h"
#include "DummyEntity.h"
#include "Collector.h"
#include "Debug.h"
#include "Upgrade.h"
#include "GameManager.h"
#include "Data.h"
#include "AutoCollector.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Magnet.h"
void SampleScene::OnInitialize()
{
	Data* data = Data::Get();
	data->money = 0;
	data->capacity = 100;
	data->spawnRate = 1.1;
	data->collectorNumber = 1;
	data->playerSize = 20;
	data->playerSpeed = 100;
	data->luck = 1;
	data->magnetSize = 0;
	data->autoCollectorSpeed = 100;

	m_rectangle = { GetWindowWidth()- GetWindowHeight() ,10,GetWindowHeight() -10,GetWindowHeight() - 20};

	m_collector = CreateEntity<Collector>(Data::Get()->playerSize, sf::Color::Red);
	m_collector->SetPosition(m_rectangle.x + m_rectangle.width /2, m_rectangle.y + m_rectangle.height / 2);
	//m_collector->GoToDirection(1, 1, Data::Get()->collectorSpeed);

	m_upgrades.push_back(CreateEntity<Upgrade>(20, sf::Color::Black));
	InitUpgrade(m_upgrades.size() - 1, 1, "upgrade Player Speed", 10, 10, 1, 100);

	
	m_upgrades.push_back(CreateEntity<Upgrade>(20, sf::Color::Black));
	InitUpgrade(m_upgrades.size() - 1, 2, "upgrade Player Size", 5, 50, 2, 1.2);

	m_upgrades.push_back(CreateEntity<Upgrade>(20, sf::Color::Black));
	InitUpgrade(m_upgrades.size() - 1, 3, "Upgrade Spawn Rate ", 6, 10, 4, 0.2);

	m_upgrades.push_back(CreateEntity<Upgrade>(20, sf::Color::Black));
	InitUpgrade(m_upgrades.size() - 1, 4, "Upgrade Capacity ", 10, 10, 5, 1.2);

	m_upgrades.push_back(CreateEntity<Upgrade>(20, sf::Color::Black));
	InitUpgrade(m_upgrades.size() - 1, 5, "Upgrade Luck ", 10, 10, 6,2);

	m_upgrades.push_back(CreateEntity<Upgrade>(20, sf::Color::Black));
	InitUpgrade(m_upgrades.size() - 1, 6, "Unlock Magnet ", 10, 10, 7, 2);

	m_upgrades.push_back(CreateEntity<Upgrade>(20, sf::Color::Black));
	InitUpgrade(m_upgrades.size() - 1, 7, "Add Autocollector ", 10, 10, 8, 1);

	m_upgrades.push_back(CreateEntity<Upgrade>(20, sf::Color::Black));
	InitUpgrade(m_upgrades.size() - 1, 8, "Upgrade Autocollector Speed ", 10, 10, 9, 50);

	//exit
	m_upgrades.push_back(CreateEntity<Upgrade>(20, sf::Color::Black));
	InitUpgrade(m_upgrades.size() - 1, 9, "Quit Game", 10, 0, 99, 67);

	m_magnet = CreateEntity<Magnet>(100, sf::Color::Transparent);
}
void SampleScene::InitUpgrade(int index, int lane, std::string text, int maxLevel, int price, int type, float value, bool locked)
{
	m_upgrades[index]->SetLane(lane);
	m_upgrades[index]->SetText(text);
	m_upgrades[index]->SetPrice(price);
	m_upgrades[index]->SetType(type);
	m_upgrades[index]->SetValue(value);
	m_upgrades[index]->SetMaxLevel(maxLevel);
	m_upgrades[index]->SetLocked(locked);


}
void SampleScene::AddAutoCollector()
{
	AutoCollector* autoCollector = CreateEntity<AutoCollector>(Data::Get()->playerSize, sf::Color::Green);
	autoCollector->SetPosition(m_rectangle.x + m_rectangle.width / 2, m_rectangle.y + m_rectangle.height / 2);
	autoCollector->GoToDirection(1, 1, Data::Get()->autoCollectorSpeed);
	m_autoCollectors.push_back(autoCollector);
}
void SampleScene::OnEvent(const sf::Event& event)
{

	if (event.mouseButton.button == sf::Mouse::Button::Left && event.type == sf::Event::EventType::MouseButtonPressed)
	{
		if (m_collector->IsInside(event.mouseButton.x, event.mouseButton.y) == true)
		{
			m_collector->OnClick();
		}
		for (int i = 0; i < m_upgrades.size(); i++)
		{

			if (m_upgrades[i]->IsInside(sf::Mouse::getPosition()))
			{
				m_upgrades[i]->OnClick();
			}

		}
	}
}


void SampleScene::OnUpdate()
{


	m_magnet->SetPosition(m_collector->GetPosition().x, m_collector->GetPosition().y);
	m_collector->SetRadius(Data::Get()->playerSize);
	m_magnet->SetRadius(Data::Get()->magnetSize * Data::Get()->playerSize);
	Debug::DrawText(0, 0, std::to_string(Data::Get()->money), sf::Color::Yellow);
	Debug::DrawText(0, 20, std::to_string(m_collectibles.size()) + "/" + std::to_string(Data::Get()->capacity), sf::Color::White);

	m_timer += GetDeltaTime();
	if (m_timer >= Data::Get()->spawnRate && m_collectibles.size() < Data::Get()->capacity)
	{
		m_collectibles.push_back(CreateEntity<DummyEntity>(5, sf::Color::Green));
		m_collectibles[m_collectibles.size() - 1]->SetPosition(Utils::GenerateRandomNumber(m_rectangle.x+5, m_rectangle.x + m_rectangle.width-5),
			Utils::GenerateRandomNumber(m_rectangle.y+5, m_rectangle.y + m_rectangle.height -5));
		m_timer = 0;
	}

	Debug::DrawRectangle(m_rectangle.x, m_rectangle.y, m_rectangle.width, m_rectangle.height, sf::Color::White);
	for (int i = 0; i < m_upgrades.size(); i++)
	{
		m_upgrades[i]->Draw(sf::Mouse::getPosition());

	}
	for (int i = 0; i < m_collectibles.size(); i++)
	{
		if (m_magnet->IsColliding(m_collectibles[i]))
		{
			m_collectibles[i]->GoToPosition(m_magnet->GetPosition().x, m_magnet->GetPosition().y, Data::Get()->playerSpeed *2);
			
		}
		if (m_collector->IsColliding(m_collectibles[i]))
		{
			m_collectibles[i]->Destroy();
			m_collectibles.erase(m_collectibles.begin() + i);
		}
	}
	for (int i = 0; i < m_collectibles.size(); i++)
	{
		for (AutoCollector* collector : m_autoCollectors) {

			if (collector->IsColliding(m_collectibles[i]))
			{
				m_collectibles[i]->Destroy();
				m_collectibles.erase(m_collectibles.begin() + i);
				return;
			}
		}
	}

}

