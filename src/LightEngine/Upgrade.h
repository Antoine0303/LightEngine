#pragma once
#include "Entity.h"

class Upgrade : public Entity {

    int m_price;
    int m_type;
    float m_value;
    int m_lane;
    std::string m_text;
    int m_MaxLevel;
    int m_level = 1;
    bool m_locked;
public:
    void OnClick();
    bool IsInside(sf::Vector2i mousePos);


    void SetPrice(int value) { m_price = value; };
    void SetType(int value) { m_type = value; };
    void SetValue(float value) { m_value = value; };
    void SetLane(int value);
    void SetText(std::string value) { m_text = value; };
    void SetMaxLevel(int value) { m_MaxLevel = value; };
    void SetLevel(int value) { m_level = value; };
    void SetLocked(bool isLocked) { m_locked = isLocked; }

    void Draw(sf::Vector2i mousePos);

};