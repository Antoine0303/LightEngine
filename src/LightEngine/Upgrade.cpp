#include "Upgrade.h"
#include "Data.h"
#include "SampleScene.h"
#include "Debug.h"
void Upgrade::OnClick() {

    Data* data = Data::Get();

    if (m_level >= m_MaxLevel || Data::Get()->money < m_price || m_locked) {
        return;
    }

    Data::Get()->money -= m_price;
    m_level++;
    
    switch (m_type)
    {
    case 1:
        data->playerSpeed += m_value;
        m_price *= 3;
        break;
    case 2:
        data->playerSize *= m_value;
        m_price *= 5;
        break;

    case 3: 
        data->collectorNumber + m_value;
        m_price *= 5;
        break;

    case 4:
        data->spawnRate *= m_value;
        m_price *= 3;
        break;

    case 5:
        data->capacity *= m_value;
        m_price *= 3;
        break;
    case 6:
        data->luck *= m_value;
        m_price *= 2.5;
        break;
    case 7:
        if(m_level == 2)
        {
            m_price *= 0.5;
            data->magnetSize += 2;
            m_text = "upgrade magnet size";
        }
        else
        {
            data->magnetSize += m_value;
            
            m_price *= 3;
        }

        break;

    case 8:
       
        data->collectorNumber += m_value;

        GetScene<SampleScene>()->AddAutoCollector();
        m_price *= 10;
        GetScene<SampleScene>()->UnlockUpgrade(6);

        break;

    case 9:
        data->autoCollectorSpeed += m_value;
        m_price *= 10;
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
    Debug::DrawRectangle(10, pos.y, 350, 30, col);
    
    if (m_type == 99)
        return;

    Debug::DrawText(350, pos.y - 30, "level " + std::to_string(m_level) + "/" + std::to_string(m_MaxLevel), 1, 0, sf::Color::White, 20);
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
    if (mousePos.x >= 10 && mousePos.x <= 360 && mousePos.y >= pos.y && mousePos.y <= pos.y + 30)
        return true;
    else
        return false;
}