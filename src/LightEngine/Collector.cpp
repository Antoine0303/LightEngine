#include "Collector.h"
#include "SampleScene.h"
#include "Utils.h"
#include "Data.h"
void Collector::OnUpdate()
{
	Rectangle rect = GetScene<SampleScene>()->GetRect();

	if (GetPosition(0, 0).x <= rect.x|| GetPosition(1, 1).x >= rect.x+ rect.width)
	{
		SetDirection(-mDirection.x, mDirection.y, Data::Get()->collectorSpeed);
	}
	if (GetPosition(0, 0).y <= rect.y || GetPosition(1, 1).y >= rect.y + rect.height)
	{
		SetDirection(mDirection.x, -mDirection.y, Data::Get()->collectorSpeed);
	}
}

void Collector::OnCollision(Entity* other)
{

	other->Destroy();

	Data::Get()->money += 1;
}

void Collector::OnClick()
{
	GoToDirection(Utils::GenerateRandomNumber(0, GetScene()->GetWindowWidth()), Utils::GenerateRandomNumber(0, GetScene()->GetWindowHeight()), Data::Get()->collectorSpeed);

}