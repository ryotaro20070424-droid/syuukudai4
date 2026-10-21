#pragma once
extern const char* Handname[];

const char* Handname[];

class Player
{
private:
    char Name[30];
    int Hand;
public:
    Player(const char* name);
    void SelectHand();
    int Gethand();
};

class CPUPlayer
{
private:
    char CPUName[30];
    int CPUHand;
public:
    CPUPlayer(const char* name);
    void RandHand();
    int CGethand();
};

class Janken
{
private:
    int playerhand;
    int cpuhand;
public:
    Janken();
    void showHand();
    void Judge(int& winp, int& losep);
    void Play();
};

void FinalJudge(int winp, int losep);