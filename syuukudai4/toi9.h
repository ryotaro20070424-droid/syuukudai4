#pragma once

class Vendingmachine
{
private:
    int Money = 0;
    int water;
    int Greentea;
    int juice;

public:
    Vendingmachine(int waterprice, int Greenteaprice, int juiceprice);
    void Inmoney();
    void Buy();
};
