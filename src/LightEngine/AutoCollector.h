#pragma once
#include "Entity.h"
class AutoCollector : public Entity
{


public:
	void OnUpdate() override;

	void OnCollision(Entity* other) override;

	void OnClick();

	void OnInitialize() override;
};

