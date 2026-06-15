#pragma once
#include "Entity.h"

class DummyEntity : public Entity
{

	std::string m_rarity;
	int value;
public:
	void OnInitialize() override;

	void OnCollision(Entity* other) override;

	std::string GetRarity() { return m_rarity; };

	int GetValue() { return value; };

	void OnUpdate() override;
};

