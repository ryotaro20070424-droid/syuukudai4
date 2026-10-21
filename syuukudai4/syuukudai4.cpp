#include <iostream>
#include "calc.h"
#include "toi9.h"
#include "toi10.h"
using namespace std;

static void initRand()
{
    srand((unsigned int)time(nullptr));
}

//問１
const char* str_match(const char* s1, const char* s2)
{
    for (int i = 0; s1[i] != '\0'; i++)
    {
        int j = 0;

        while (s2[j] != '\0' && s1[i + j] == s2[j])
        {
            j++;
        }

        if (s2[j] == '\0')
        {
            return &s1[i];
        }
    }

    return nullptr;
}
//問３
void static mult()
{
    int num, num2;
    cout << "   掛け算したい値を入れて" << endl;
    cin >> num >> num2;
    cout << "かけた結果は" << num * num2 << endl;
}
//問１０



int main()
{
    cout << "問1" << endl;
    const char* s1 = "abcabcdef";
    const char* s2 = "abcd";

    const char* p = str_match(s1, s2);

    if (p != nullptr)
    {
        cout << p << endl;
    }
    else
    {
        cout << "見つかりませんでした" << endl;
    }
    cout << "問２" << endl;
    sum();
    cout << "問３" << endl;
    mult();
    cout << "問９" << endl;
    Vendingmachine  a(110, 160, 230);
    a.Inmoney();
    a.Buy();
    cout << "問１０" << endl;
    initRand();
    Janken game;
    game.Play();
}
