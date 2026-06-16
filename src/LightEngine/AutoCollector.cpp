#include "AutoCollector.h"
#include "SampleScene.h"
#include "Utils.h"
#include "Data.h"
#include "DummyEntity.h"
void AutoCollector::OnUpdate()
{
	

	Rectangle rect = GetScene<SampleScene>()->GetRect();
	if (GetPosition(0, 0).x <= rect.x || GetPosition(1, 1).x >= rect.x + rect.width)
	{
		SetDirection(-mDirection.x, mDirection.y, Data::Get()->autoCollectorSpeed);

	}
	if (GetPosition(0, 0).y <= rect.y || GetPosition(1, 1).y >= rect.y + rect.height)
	{
		SetDirection(mDirection.x, -mDirection.y, Data::Get()->autoCollectorSpeed);
	}
}

void AutoCollector::OnCollision(Entity* other)
{

	if(other->IsTag(1))
	{
		Data::Get()->money += dynamic_cast<DummyEntity*>(other)->GetValue();
	}
}

void AutoCollector::OnClick()
{
	GoToDirection(Utils::GenerateRandomNumber(0, GetScene()->GetWindowWidth()), Utils::GenerateRandomNumber(0, GetScene()->GetWindowHeight()), Data::Get()->playerSpeed);
}