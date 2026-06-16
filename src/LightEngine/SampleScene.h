#pragma once

#include "Scene.h"
#include <vector>
class DummyEntity;
class Collector;
class Upgrade;
class Magnet;
struct Rectangle
{
	int x;
	int y;
	int width;
	int height;
};


class SampleScene : public Scene
{
private:
	Collector* m_collector;
	
	Rectangle m_rectangle; 
	//rect

	std::vector<DummyEntity*> m_collectibles;
	

	Magnet* m_magnet;
	float m_timer = 0;
	float m_spawnRate = 0.5;



	int m_capacity = 20;
	int m_money = 0;
	std::vector< Upgrade*> m_upgrades;
public:
	void OnInitialize() override;
	void OnEvent(const sf::Event& event) override;
	void OnUpdate() override;
	Rectangle GetRect() { return m_rectangle; };
	int GetMoney() { return m_money; };
	void SetMoney(int value) { m_money = value; };
	void AddMoney(int value) { m_money += value; };
	void InitUpgrade(int index, int lane, std::string text, int maxLevel, int price, int type, float value);
};


