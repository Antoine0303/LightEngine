#pragma once
#include "Entity.h"
class Collector : public Entity
{


public:
	void OnUpdate() override;

	void OnCollision(Entity* other) override;

	void OnClick();
};

