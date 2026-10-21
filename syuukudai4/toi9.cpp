#include <iostream>
#include "toi9.h"
using namespace std;
//問９

Vendingmachine::Vendingmachine(int waterprice, int Greenteaprice, int juiceprice)
{
    water = waterprice;
    Greentea = Greenteaprice;
    juice = juiceprice;
}

void Vendingmachine::Inmoney()
{
    cout << "お金を入れてください=>";
    cin >> Money;
}

void Vendingmachine::Buy()
{
    int choice = 0;
    int price = 0;
    cout << "購入する飲み物を選んでください。" << endl
        << "1：水:" << water << "円" << endl
        << "2：お茶:" << Greentea << "円" << endl
        << "3:ジュース:" << juice << "円" << endl;
    cin >> choice;
    switch (choice)
    {
    case 1:
        price = water;
        break;
    case 2:
        price = Greentea;
        break;
    case 3:
        price = juice;
        break;
    default:
        cout << "変なことしないで" << endl;
        return;
    }
    if (price >= Money)
    {
        cout << "お金が足りません(´;ω;｀)" << endl;
    }
    else
    {
        cout << "ｶﾞﾁｬﾝ！ﾋﾟｯﾋﾟｯﾋﾟ！ﾁｬﾘﾝﾁｬﾘﾝ..." << endl
            << "お釣りは" << Money - price << "円です" << endl;
    }
}