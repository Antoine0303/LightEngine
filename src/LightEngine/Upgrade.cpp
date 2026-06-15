#include "Upgrade.h"
#include "Data.h"
#include "SampleScene.h"
#include "Debug.h"
void Upgrade::OnClick() {

    Data* data = Data::Get();

    if (m_level >= m_MaxLevel || Data::Get()->money < m_price) {
        return;
    }

    Data::Get()->money -= m_price;
    m_level++;
    m_price *= 2.5;

    int collectorSpeed;
    int collectorSize;
    int collectorNumber;
    int spawnRate;
    int capacity;
    switch (m_type)
    {
    case 1:
        data->collectorSpeed += m_value;
        break;
    case 2:
        data->collectorSize *= m_value;
        break;

    case 3:
        data->collectorNumber + m_value;
        break;

    case 4:
        data->spawnRate + m_value;
        break;

    case 5:
        data->capacity + m_value;
        break;
    case 99:
        exit(0);
        break;
    default:
        break;
    }

}
void Upgrade::Draw(sf::Vector2i mousePos)
{
    sf::Vector2f pos = this->GetPosition();
    sf::Color col;
    if (IsInside(mousePos) && Data::Get()->money < m_price)
    {
        col = sf::Color::Red;
        //ShowTips();
    }
    else if (IsInside(mousePos) && Data::Get()->money >= m_price)
    {
        col = sf::Color::Green;
        //ShowTips();
    }
    else
        col = sf::Color::White;

    if (m_locked == true)
        col = sf::Color::Color(255, 255, 255, 100);

    Debug::DrawText(pos.x, pos.y, m_text, col);
    Debug::DrawRectangle(10, pos.y, 300, 30, col);
    
    if (m_type == 99)
        return;

    Debug::DrawText(300, pos.y - 30, "level " + std::to_string(m_level) + "/" + std::to_string(m_MaxLevel), 1, 0, sf::Color::White, 20);
    if (m_level >= m_MaxLevel)
    {
        Debug::DrawText(10, pos.y - 30, "max", sf::Color::Red);
        m_locked = true;
        return;
    }
    if (m_locked == true)
        return;
    if (Data::Get()->money < m_price)
    {
        Debug::DrawText(10, pos.y - 30, std::to_string(m_price), sf::Color::Red);
    }
    else
        Debug::DrawText(10, pos.y - 30, std::to_string(m_price), sf::Color::Yellow);

    
}
void Upgrade::SetLane(int lane)
{
    m_lane = lane;

    SetPosition(20, (GetScene()->GetWindowHeight() / 10) * lane);
}

bool Upgrade::IsInside(sf::Vector2i mousePos)
{
    sf::Vector2f pos = this->GetPosition();
    if (mousePos.x >= 10 && mousePos.x <= 310 && mousePos.y >= pos.y && mousePos.y <= pos.y + 30)
        return true;
    else
        return false;
}