#include <iostream>
#include<ctime>
#include<cstdlib>
#include <cstring>
using namespace std;

static void initRand()
{
	srand((unsigned int)time(nullptr));
}

const char* Handname[]
{
	"グー",
	"チョキ",
	"パー",
};

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

int Player::Gethand()
{
    return Hand;
}

Player::Player(const char* name)
{
    strcpy_s(Name, sizeof(Name), name);
    Hand = 0;
}

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

CPUPlayer::CPUPlayer(const char* name)
{
    strcpy_s(CPUName, sizeof(CPUName), name);
    CPUHand = 0;
}

int CPUPlayer::CGethand() 
{
    return CPUHand;
}

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

Janken::Janken()
{
    playerhand = 0;
    cpuhand = 0;
}

void Player::SelectHand()
{
    cout << "====================" << endl;
    cout << "出す手を選んでね" << endl
        << "グー：0 || チョキ：1 || パー：2" << endl
        << "=>";
    cin >> Hand;
    if (Hand < 0 || Hand>2)
    {
        SelectHand();
    }
}

void CPUPlayer::RandHand()
{
    CPUHand = rand() % 3;
}

void Janken::showHand()
{
    cout << "あなたの手は" << Handname[playerhand] << endl
        << "あいての手は" << Handname[cpuhand] << endl;
}

void Janken::Judge(int &winp,int &losep)
{
    cout << "結果は";
    if (playerhand == cpuhand)
    {
        cout << "あいこ" << endl;
    }
    else if 
        ((playerhand == 0 && cpuhand == 1) || 
        (playerhand == 1 && cpuhand == 2) || 
        (playerhand == 2 && cpuhand == 0))
    {
        cout << "あなたの勝ち！" << endl;
        winp++;
    }
    else
    {
        cout << "負けですね" << endl;
        losep++;
    }
}

void FinalJudge(int winp, int losep,char* name,char* cpuName)
{
    cout << "===========================" << endl;
    cout << "リザルトは、勝ちが「" << winp << "」回！" << endl
        << "負けが「" << losep << "」回！" << endl;
    if (winp > losep)
    {
        cout << name << "の勝ちです!!!" << endl
            << cpuName << "の負け" << endl;
    }
    else
    {
        cout << name << "の負けですね　(*´Д｀)ハァ" << endl
            << cpuName << "の勝ち～‼　ィェーィ!!" << endl;
    }
}

void Janken::Play()
{
        char name[30];
        char cpuName[30];
        cout << "君の名は？" << endl << "=>";
        cin >> name;
        cout << "敵の名は？" << endl << "=>";
        cin >> cpuName;
        Player player(name);
        CPUPlayer CPU(cpuName);
    int check = 0;
    int winp = 0;
    int losep = 0;
    while (check == 0)
    {
        int num = 0;
        const char* str[] = { "1発","3回","5回" };
        const int a[] = { 1,3,5 };
        cout << "＝＝＝＝じゃんけんゲーム！＝＝＝＝" << endl
            << "何回勝負でプレイする？" << endl
            << "1発勝負は「0」を3回勝負は「1」を5回勝負は「2」を押してね☆" << endl
            << "(引き分けはなしだよ)" << endl;
        cin >> num;
        if (num < 0 || num>2)
            continue;
        cout << str[num] << "勝負だね♧" << endl;
        num = a[num];
        for (int i = 0; i < num; i++)
        {
            do {
                player.SelectHand();
                CPU.RandHand();
                playerhand = player.Gethand();
                cpuhand = CPU.CGethand();
                showHand();
                Judge(winp, losep);
            } while (playerhand == cpuhand);
        }
        FinalJudge(winp, losep,name, cpuName);
        check++;
    }
}

//元のやつ
//void Initrand()
//{
//	srand((unsigned int)time(NULL));
//}
//
//void Cpu(int& CpuHand)
//{
//	CpuHand = rand() % 3;
//}
//
//bool Judge(int Hand, int CpuHand)
//{
//	cout << "結果は";
//	if ((Hand == 0 && CpuHand == 1) || (Hand == 1 && CpuHand == 2) || (Hand == 2 && CpuHand == 0))
//	{
//		cout << "あなたの勝ち！" << endl;
//		return true;
//	}
//	else
//	{
//		cout << "負けですね" << endl;
//		return false;
//	}
//}
//
//void FinalJudge(int winp, int losep)
//{
//	cout << "===========================" << endl;
//	cout << "リザルトは、勝ちが「" << winp << "」回！" << endl
//		<< "負けが「" << losep << "」回！" << endl;
//	if (winp > losep)
//	{
//		cout << "あなたの勝ちです!!!" << endl;
//	}
//	else
//	{
//		cout << "あなたの負けですね　(*´Д｀)ハァ" << endl;
//	}
//}
//
//void Play(int num)
//{
//	int Hand = 0;
//	int CpuHand = 0;
//	int winp = 0;
//	int losep = 0;
//	const char* str[] = { "グー","チョキ","パー" };
//	for (int i = 0;i < num;i++)
//	{
//		cout << "===================" << endl;
//		cout << i + 1 << "回目！" << endl
//			<< "あなたの手は？グーなら「０」、チョキなら「１」、パーなら「２」を押してね♦＞";
//		cin >> Hand;
//		if (Hand < 0 || Hand>2)
//			continue;
//		Cpu(CpuHand);
//		cout << "あなたの手は" << str[Hand] << "!" << endl
//			<< "相手は" << str[CpuHand] << "!";
//		if (Hand == CpuHand)
//		{
//			cout << "あいこ！" << endl;
//			i--;
//			continue;
//		}
//		Judge(Hand, CpuHand) ? winp++ : losep++;
//	}
//	FinalJudge(winp, losep);
//}
//
//int main()
//{
//	Initrand();
//	int check = 0;
//	while (check == 0)
//	{
//		int num = 0;
//		const char* str[] = { "1発","3回","5回" };
//		const int a[] = { 1,3,5 };
//		cout << "＝＝＝＝じゃんけんゲーム！＝＝＝＝" << endl
//			<< "何回勝負でプレイする？" << endl
//			<< "1発勝負は「0」を3回勝負は「1」を5回勝負は「2」を押してね☆" << endl
//			<< "(引き分けはなしだよ)" << endl;
//		cin >> num;
//		if (num < 0 || num>2)
//			continue;
//		cout << str[num] << "勝負だね♧" << endl;
//		num = a[num];
//		Play(num);
//		check++;
//	}
//}