#include "Header.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
using namespace std;

void SetColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}
void ResetColor() {
    SetColor(15);  // Default gray
}

bool famine = false;
int faisal_vote = 0;
int Ehtasham_vote = 0;
bool election = true;
int row = 15;
int column = 35;
int randomPolitician = 0;
int politician = 2;
int randomPeople = 1;
KingdomEngine::KingdomEngine() {
    ptr = new char* [row];
    for (int i = 0; i < row; i++) {
        ptr[i] = new char[column];
        for (int j = 0; j < column; j++) {
            ptr[i][j] = ' ';
        }
    }
}
KingdomEngine::~KingdomEngine() {
    for (int i = 0; i < row; i++) {
        delete[] ptr[i];
    }
    delete[] ptr;
}

void KingdomEngine::setVal() {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (i == 0 || i == row - 1) {
                ptr[i][j] = '+';
            }
            else if (j == 0 || j == column - 1) {
                ptr[i][j] = '+';
            }
            else {
                ptr[i][j] = ' ';
            }
        }
    }
}

void KingdomEngine::storeSpace() {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            cout << ptr[i][j] << " ";
        }
        cout << endl;
    }
}

void population::initializePeople() {
    PointerToShowPeople = new char* [1];
    PointerToShowPeople[0] = new char[people];
    for (int j = 0; j < people; j++) {
        PointerToShowPeople[0][j] = 'L';
    }
}

void population::setPopulation() {
    int r, c;
    srand(time(0));
    int j = 0;
    if (people < 0)
    {
        people = 0;
    }
    while (j < people) {
        r = rand() % 15;
        c = rand() % 35;
        if (ptr[r][c] == ' ') {
            ptr[r][c] = PointerToShowPeople[0][j];
            j++;
        }
    }
}

void army::setArmy() {
    int armyGenerator = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (i == 2 && j > 2 && j <= 6) {
                if (armyGenerator == 0) { ptr[i][j] = 'A'; }
                if (armyGenerator == 1) { ptr[i][j] = 'R'; }
                if (armyGenerator == 2) { ptr[i][j] = 'M'; }
                if (armyGenerator == 3) { ptr[i][j] = 'Y'; }
                armyGenerator++;
            }
        }
    }
}

void politics::setPolitics() {
    int politicsGenerator = 0;
    while (randomPolitician < politician) {
        int r, c;
        r = rand() % 15;
        c = rand() % 32;
        if (ptr[r][c] == ' ') {
            if (politicsGenerator == 0)
                ptr[r][c] = '1';
            else
                ptr[r][c] = '2';
            politicsGenerator++;
            randomPolitician++;
        }
    }
}

void resourceSystems::setResource() {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (i == 1 && j == 17) { ptr[i][j] = 'S'; }
            else if (i == 1 && j == 18) { ptr[i][j] = 'H'; }
            else if (i == 2 && j == 17) { ptr[i][j] = 'O'; }
            else if (i == 2 && j == 18) { ptr[i][j] = 'P'; }
            else if (i == 1 && j == 14) { ptr[i][j] = 'F'; }
            else if ((i == 1 && j == 15) || (i == 2 && j == 14)) { ptr[i][j] = 'O'; }
            else if (i == 2 && j == 15) { ptr[i][j] = 'D'; }
        }
    }
}

void bank::setBank() {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (i == 12 && j == 1) { ptr[i][j] = 'B'; }
            else if (i == 12 && j == 2) { ptr[i][j] = 'A'; }
            else if (i == 13 && j == 1) { ptr[i][j] = 'N'; }
            else if (i == 13 && j == 2) { ptr[i][j] = 'K'; }
        }
    }
}

void KingdomEngine::information() {
    cout << endl << "Bounded area by + is our region:";
    cout << endl << "P is showing population in the region:";
    cout << endl << "SH\nOP: is showing the shop";
    cout << endl << "FO\nOD: is showing the food that will be consumed by army and public:";
    cout << endl << "ARMY it is showing to army:";
    cout << endl << "BA\nNK: it is showing the bank in the region:";
}

void population::populationDetail() {
    cout << "The total number of people are: " << people << endl;
    system("pause");
}

void KingdomEngine::displayKingdom() {
   /* for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            cout << ptr[i][j];
        }
        cout << endl;
    }*/
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            // Add colors based on content
            if (ptr[i][j] == 'L') SetColor(8);
            else if (ptr[i][j] == '1') SetColor(2);
            else if (ptr[i][j] == '2') SetColor(2);
            else if (ptr[i][j] == '+' || ptr[i][j] == 'A' || ptr[i][j] == 'R' ||
                ptr[i][j] == 'M' || ptr[i][j] == 'Y') SetColor(48);
            else if (ptr[i][j] == 'S' || ptr[i][j] == 'H' || ptr[i][j] == 'O' ||
                ptr[i][j] == 'P') SetColor(15); // Cyan for shop
            else if (ptr[i][j] == 'F' || ptr[i][j] == 'O' || ptr[i][j] == 'D') SetColor(15);
            else if (ptr[i][j] == 'B' || ptr[i][j] == 'A' || ptr[i][j] == 'N' ||
                ptr[i][j] == 'K') SetColor(14);
            else {
                SetColor(4);
            }
            cout << ptr[i][j];
            ResetColor();
        }
        cout << endl;
    }
}

void economy::showEconomy() {
    cout << "Economy of our region is now: " << money;
    system("pause");
}

int politics::Election() {
    cout << "\n=============================================" << endl;
    cout << "             Election Day: Vote Now!         " << endl;
    cout << "=============================================" << endl << endl;
    cout << "Press 1 to vote for Politician 1." << endl;
    cout << "Press 2 to vote for Politician 2." << endl;
    cout << "Enter your choice (1 or 2): ";
    int choice;
    cout << "If you want to vote for Politician 1 press 1:\nIf you want to vote for Politician 2 press 2: ";
    fstream file("Election.txt", ios::app);
    for (int i = 1; i <= people; i++) {
        cout << endl << "Enter vote (" << i << ") person: ";
        cin >> choice;
        if (choice == 1 || choice == 2) {
            if (choice == 1) {
                faisal_vote++;
            }
            if (choice == 2) {
                Ehtasham_vote++;
            }
        }
        else {
            cout << "Invalid input!";
            return 0;
        }
    }
    if (faisal_vote == Ehtasham_vote) {
        cout << "Tie! Enter the final vote (1 or 2): ";
        cin >> choice;
        if (choice == 1 || choice == 2) {
            if (choice == 1) {
                faisal_vote++;
            }
            if (choice == 2) {
                Ehtasham_vote++;
            }
        }
        else {
            cout << "Invalid input!";
            return 0;
        }
    }
    file << "Politician 1:" << faisal_vote << "\t\t Politician 2:" << Ehtasham_vote;
    if (faisal_vote > Ehtasham_vote) {
        system("cls");
        cout << "Winner is Politician 1\n His votes are :" << faisal_vote << endl;
        return system("pause");

    }
    else if (faisal_vote < Ehtasham_vote) {
        system("cls");
        cout << "Winner is Politician 2\n His votes are :" << Ehtasham_vote << endl;
        return system("pause");
    }
    else
    {
        system("cls");
        cout << "No one is winner!\n its votes are : " << faisal_vote << ":" << Ehtasham_vote << endl;
        return system("pause");
    }
    return 0;
}

void politics::coruption(int x) {
    if (x == 1) {

        faisal_money = 2000;
        money -= 1000;
        revolt();
    }
    else {
        cout << "there is no revolt:";
    }
    system("pause");
}
void politics::revolt() {
    if (faisal_vote > Ehtasham_vote) {
        cout << "There is corruption by Politician 1\n";
        cout << "Revolt started!\n";
        cout << "Elections will be held again!\n";

        Election();
    }
    else if (faisal_vote < Ehtasham_vote) {
        cout << "There is corruption by Politician 2\n";
        cout << "Revolt started!\n";
        Election();

    }
    else
    {
        cout << "There is corruption by these both:";
        cout << "Revolt started!\n";
        Election();
    }
    system("pause");
}

void population::disease() {
    srand(time(0));
    int num = rand() % 80 + 60;

    if (num <= 120 && num >= 80) {
        cout << "People are healthy" << endl;
    }
    else if (num <= 70 || num >= 130) {
        if (people > 0) {
            people--;
            cout << "Remaining people are: " << people << endl;
        }
    }
    else {
        cout << endl << "Person is ill!";
    }
    system("pause");
}

void KingdomEngine::femine() {
    srand(time(0));
    int food = rand() % 100;
    if (food < 40 && food > 30) {
        SetColor(4);
        cout << "Famine occurred!\n";
        people -= 4;
        cout << "Remaining people are: " << people << endl;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                if ((i == 1 && j == 14) || (i == 1 && j == 15)) {
                    ptr[i][j] = ' ';
                }
            }
        }
        famine = true;
        money -= 400;
        amount -= 400;
        cout << "Cause: Food storage destroyed and money lost due to famine!\n";
        displayKingdom();
    }
    else {
        cout << "Famine does not occure:\n";
    }
    system("pause");
}

void KingdomEngine::weather() {
    srand(time(0));
    int condition = rand() % 50;
    system("cls");
    if (condition == 22) {
        SetColor(9);
        cout << endl << "It is raining in our kingdom!\n" ;
      
    }
    else if (condition > 15 && condition < 30) {
        SetColor(8);
        cout << "The weather condition is normal!\n";
      
    }
    else if (condition < 15) {
        SetColor(144);
        cout << "The weather condition is partially cloudy!\n";
        
    }
    else {
        SetColor(6);
        cout << "The weather is too hot!\n";
       
    }
    system("pause");
    displayKingdom();
    return;
}

int politics::war() {
    cout << "\n======================================" << endl;
    cout << "         War Mode: Player vs AI       " << endl;
    cout << "======================================" << endl;
    srand(time(0));
    int posibility = rand() % 50;
    system("cls");
    if (posibility == 25) {
        cout << "No one won the war!\n";
        cout << "War was tied!\n";
    }
    else if (posibility < 25 && posibility >= 0) {
        cout << "You lost the war!\n";
        cout << "There will be a large loss in kingdom economy\n";
        money -= 1000;
        people -= 4;
        destroyArmy();
    }
    else if (posibility > 25) {
        cout << "You won the war!\n";
        cout << "There will be a large advantage in everything!\n";
        money += 1000;
        people += 4;
    }
    system("pause");
    return 0;
}

void politics::politicsDetail() {
    cout << endl << "There are two politicians:\n";
    cout << "1) Politician 1\n";
    cout << "2) Politician 2\n";
}
void bank::showBankDetails() {
    cout << endl << "In this bank the money is: " << amount;
}
void army::destroyArmy() {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (i == 2 && (j == 5 || j == 6)) {
                ptr[i][j] = ' ';
            }
        }
    }
}

int politics::moneyUpdate(int x) {
    money += x;
    return 0;
}
void bank::updateAmount(int x) {
    amount += x;
}

void army::restoreArmy() {
    int armyGenerator = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (i == 2 && j > 2 && j <= 6) {
                if (armyGenerator == 0) { ptr[i][j] = 'A'; }
                if (armyGenerator == 1) { ptr[i][j] = 'R'; }
                if (armyGenerator == 2) { ptr[i][j] = 'M'; }
                if (armyGenerator == 3) { ptr[i][j] = 'Y'; }
                armyGenerator++;
            }
        }
    }
}
void population::addPeople() {
    people += 2;
}
void population::restorePeople() {
    people = 10;
}
void population::removePopulatoion()
{
    for (int i = 0;i < row;i++)
    {
        for (int j = 0;j < column;j++)
        {
            if (ptr[i][j] == 'L')
            {
                ptr[i][j] = ' ';
            }
        }
    }
}
void population::cleanPopulation()
{
    delete[] PointerToShowPeople[0];
    delete[]  PointerToShowPeople;
}
void economy::foodComsume()
{
    for (int i = 0;i < row;i++)
    {
        for (int j = 0;j < column;j++)
        {
            if (i == 1 && (j == 14 || j == 15))
            {
                ptr[i][j] = ' ';
            }
        }
    }
    cout << "Half food consumed by the army:" << endl;
    displayKingdom();
    system("pause");
    system("cls");
    for (int i = 0;i < row;i++)
    {
        for (int j = 0;j < column;j++)
        {
            if (i == 2 && (j == 14 || j == 15))
            {
                ptr[i][j] = ' ';
            }
        }
    }
    cout << "Half food consumed by the public:" << endl;
    displayKingdom();
    system("pause");
    system("cls");
}
void economy::restoreFood()
{
    for (int i = 0;i < row;i++)
    {
        for (int j = 0;j < column;j++)
        {
            if (i == 1 && j == 14) { ptr[i][j] = 'F'; }
            else if ((i == 1 && j == 15) || (i == 2 && j == 14)) { ptr[i][j] = 'O'; }
            else if (i == 2 && j == 15) { ptr[i][j] = 'D'; }
        }
    }
    system("pause");
}
void resourceSystems::resourcesOf1()
{
    resource1 = "Gold";
    countOfResource1 = 20;
    resource2 = "Leather";
    countOfResource2 = 25;
    resource3 = "Stone";
    countOfResource3 = 30;
    resource4 = "Wood";
    countOfResource4 = 0;
    resource5 = "Horses";
    countOfResource5 = 0;
    resource6 = "Iron";
    countOfResource6 = 0;
}
void resourceSystems::resourcesOf2()
{
    resource1 = "Gold";
    countOfResource1 = 0;
    resource2 = "Leather";
    countOfResource2 = 0;
    resource3 = "Stone";
    countOfResource3 = 0;
    resource4 = "Wood";
    countOfResource4 = 23;
    resource5 = "Horses";
    countOfResource5 = 18;
    resource6 = "Iron";
    countOfResource6 = 20;
}
void resourceSystems::displayR1()
{
    cout << "\n============================================" << endl;
    cout << "         Resources of Player        " << endl;
    cout << "============================================" << endl;
    cout << endl << resource1 << " amount is at kingdom 1 is =" << countOfResource1;
    cout << endl << resource2 << " amount is at kingdom 1 is =" << countOfResource2;
    cout << endl << resource3 << " amount is at kingdom 1 is =" << countOfResource3;
    cout << endl << resource4 << " amount is at kingdom 1 is =" << countOfResource4;
    cout << endl << resource5 << " amount is at kingdom 1 is =" << countOfResource5;
    cout << endl << resource6 << " amount is at kingdom 1 is =" << countOfResource6;
}
void population::peopleOf1()
{
    people = 10;
}
void population::peopleOf2()
{
    people = 12;
}
void bank::moneyOf1()
{
    amount = 100000;
    money = 100000;
}
void bank::moneyOf2()
{
    amount = 120000;
    money = 120000;
}
int KingdomEngine::getmoney()
{
    return money;
}
int KingdomEngine::getamount()
{
    return amount;
}
void KingdomEngine::setMoneyZero()
{
    money = 0;
}
void KingdomEngine::setAmountZero()
{
    amount = 0;
}
void politics::trading(politics& p1)
{
    if (p1.countOfResource1 >= 5)
    {
        this->countOfResource1 += 5;
        p1.countOfResource1 -= 5;
    }
    else {
        this->countOfResource1 -= 5;
        p1.countOfResource1 += 5;
    }
    if (p1.countOfResource2 >= 5)
    {
        this->countOfResource2 += 5;
        p1.countOfResource2 -= 5;
    }
    else {
        this->countOfResource2 -= 5;
        p1.countOfResource2 += 5;
    }
    if (p1.countOfResource3 >= 5)
    {
        this->countOfResource3 += 5;
        p1.countOfResource3 -= 5;
    }
    else
    {
        this->countOfResource3 -= 5;
        p1.countOfResource3 += 5;
    }
    if (this->countOfResource4 >= 5)
    {
        this->countOfResource4 -= 5;
        p1.countOfResource4 += 5;
    }
    else {
        this->countOfResource4 += 5;
        p1.countOfResource4 -= 5;
    }
    if (this->countOfResource5 >= 5)
    {
        this->countOfResource5 -= 5;
        p1.countOfResource5 += 5;
    }
    else {
        this->countOfResource5 += 5;
        p1.countOfResource5 -= 5;
    }
    if (p1.countOfResource6 >= 5)
    {
        this->countOfResource6 -= 5;
        p1.countOfResource6 += 5;
    }
    else {
        this->countOfResource6 += 5;
        p1.countOfResource6 -= 5;
    }
}
void politics::warWithPlayer(politics& p1)
{
    FullWar();
    cout << "\n its being war:";
    if (p1.amount > this->amount && p1.money > this->money)
    {
        cout << "\nplayer 1 won the war player 2 lose the war:";
        p1.amount += 300;
        p1.money += 250;
        this->amount -= 300;
        this->money -= 250;
    }
    if (p1.amount < this->amount && p1.money < this->money)
    {
        cout << "\nplayer 2 won the war player 1 lose the war:";
        p1.amount -= 300;
        p1.money -= 250;
        this->amount += 300;
        this->money += 250;
    }
    else
    {
        cout << "\n war was draw both players have the same power :";
        p1.amount -= 100;
        p1.money -= 100;
        this->amount -= 100;
        this->money -= 100;
    }
}
void politics::FullWar()
{
    system("cls");
    char array[20][30];
    for (int i = 0;i < 20;i++)
    {
        for (int j = 0;j < 30;j++)
        {
            if (i == 0 || j == 0 || j == 29 || i == 19)
            {
                array[i][j] = '+';
            }
            else if ((i >= 8 && i <= 12) && (j >= 8 && j <= 12))
            {
                array[i][j] = 'A';
            }
            else  if ((i >= 8 && i <= 12) && (j >= 18 && j <= 22))
            {
                array[i][j] = 'F';
            }
            else
            {
                array[i][j] = ' ';
            }
        }
    }
    for (int i = 0;i < 20;i++)
    {
        for (int j = 0;j < 30;j++)
        {
            cout << array[i][j];
        }
        cout << endl;
    }
    cout << endl;
    cout << "A is showing the army of the player 1:"<<endl;
    cout << "F is showing the army of the player 2:" << endl;
    system("pause");
}