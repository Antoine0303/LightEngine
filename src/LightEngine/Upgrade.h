#pragma once
#include "Entity.h"

class Upgrade : public Entity {

    int m_price;
    int m_type;
    int m_value;
    int m_lane;
    std::string m_text;
    int m_MaxLevel;
    int m_level = 1;
    bool m_locked = false;
public:
    void OnClick();
    bool IsInside(sf::Vector2i mousePos);


    void SetPrice(int value) { m_price = value; };
    void SetType(int value) { m_type = value; };
    void SetValue(int value) { m_value = value; };
    void SetLane(int value);
    void SetText(std::string value) { m_text = value; };
    void SetMaxLevel(int value) { m_MaxLevel = value; };
    void SetLevel(int value) { m_level = value; };

    void Draw(sf::Vector2i mousePos);

};