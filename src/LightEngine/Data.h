#pragma once

class Data {


private:


public:
    static Data* Get();
    int money;
    int playerSpeed;
    float playerSize;
    int collectorNumber;
    float spawnRate;
    int capacity;
    float luck;
    float magnetSize;
    float autoCollectorSpeed;
    int ballsCollected;
    bool stats;

};