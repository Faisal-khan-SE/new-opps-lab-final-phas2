#pragma once
#include<iostream>
#include<windows.h>
using namespace std;
// Color helper functions
void SetColor(int color);

void ResetColor();
//static int amount = 1000;
//static int money = 1000;
class KingdomEngine {
protected:
    char** ptr;
    int amount;
    int money;
    int people;
    string resource1, resource2, resource3;//for object 1
    string resource4, resource5, resource6;//for object 2
public:
    int countOfResource1, countOfResource2, countOfResource3;
    int countOfResource4, countOfResource5, countOfResource6;
    KingdomEngine();
    virtual ~KingdomEngine();  // Added destructor
    void information();
    void displayKingdom();
    void setVal();
    void storeSpace();
    void femine();
    void weather();
    int getmoney();//to check money at condition
    int getamount();//to check th amount at the amount conmditions
    void setMoneyZero();
    void setAmountZero();
};

class population : public KingdomEngine {
public:
    char** PointerToShowPeople;
    void peopleOf1();
    void peopleOf2();
    population() {};
    void cleanPopulation();
    void initializePeople();
    void setPopulation();
    void removePopulatoion();
    void populationDetail();
    void disease();
    void addPeople();
    void restorePeople();
};

class economy : public population {
public:
    economy() {}
    void showEconomy();
    void foodComsume();
    void restoreFood();
};

class army : public economy {
public:
    army() {}
    void setArmy();
    void destroyArmy();
    void restoreArmy();
};

class resourceSystems : public army {
public:
    void setResource();
    void resourcesOf1();
    void resourcesOf2();
    void displayR1();
    void displayR2();
};

class bank : public resourceSystems {

public:

    bank() {
        amount = 0;
        money = 0;
    }
    void moneyOf1();
    void moneyOf2();
    void updateAmount(int);
    void setBank();
    void showBankDetails();
};

class politics : public bank {
public:
    void FullWar();
    int faisal_money = 1000;
    int ehtasham_money = 1000;
    void setPolitics();
    void politicsDetail();
    int Election();
    void coruption(int);
    void revolt();
    int war();
    int moneyUpdate(int);
    void trading(politics& p1);
    void war(politics& p1);
};