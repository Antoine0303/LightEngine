#pragma once
#include "Entity.h"

class DummyEntity : public Entity
{

	std::string m_rarity;

public:
	void OnInitialize() override;

	void OnCollision(Entity* other) override;
};

