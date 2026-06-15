#include "DummyEntity.h"
#include "Utils.h"
#include <iostream>

void DummyEntity::OnInitialize()
{

	int random = Utils::GenerateRandomNumber(1, 1000);

	//if(random <= )
}

void DummyEntity::OnCollision(Entity* other)
{
	std::cout << "DummyEntity::OnCollision" << std::endl;
}