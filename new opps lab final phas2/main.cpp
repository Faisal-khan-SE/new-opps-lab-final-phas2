#include<iostream>
#include "Header.h"
#include <conio.h>
#include <cstdlib>
#include <limits>
//HELOOO WORLD 
int main()
{
    politics game;// player 1
    game.peopleOf1();
    game.moneyOf1();
    game.resourcesOf1();
    politics game2;//player 2
    game2.peopleOf2();
    game2.moneyOf2();
    game2.resourcesOf2();
    int selectObj;
    cout << "Enter the 1 to select the kingdom of the player 1 \nPress 2 to see the kingdom of the player 2 \nPress 3 to conduct Trade in these both kingdoms \nPress 4 to conduct war between these both two kingdoms:";
    cin >> selectObj;
    if (selectObj >= 1 && selectObj <= 4)
    {
        if (selectObj == 1)
        {
            int choice;
            bool running = true;
            game.setVal();
            game.initializePeople();
            game.setPopulation();
            game.setArmy();
            game.setResource();
            game.setBank();
            game.setPolitics();
            game.resourcesOf1();
            while (running) {
                system("cls");
                game.removePopulatoion();
                game.initializePeople();
                game.setPopulation();
                game.displayKingdom();
                game.information();
                game.showEconomy();
                game.showBankDetails();
                cout << "\n\n=== KINGDOM MANAGEMENT ===";
                cout << "\n1. Check Weather";
                cout << "\n2. Check Population";
                cout << "\n3.Consume Food";
                cout << "\n4. Hold Election";
                cout << "\n5. Check for Corruption";
                cout << "\n6. Check for Disease";
                cout << "\n7. Check for Famine";
                cout << "\n8. Check for War";
                cout << "\n9. Restore Army (Cost: 200)";
                cout << "\n10. Add People (Cost: 100)";
                cout << "\n11. Restore People (Cost: 300)";
                cout << "\n12.Restore Food (Cost:300)";
                cout << "\n13. To show the resources of the kingdom ";
                cout << "\n00. Exit";
                cout << "\nEnter your choice: ";
                cin >> choice;
                cin.ignore(/*numeric_limits<streamsize>::max(), '\n'*/);

                system("cls");
                switch (choice) {
                case 1: {
                    game.weather();
                    game.moneyUpdate(100);
                    game.updateAmount(100);
                    break;

                }
                case 2: {
                    game.populationDetail();
                    game.moneyUpdate(100);
                    game.updateAmount(100);
                    break;
                }
                case 3:
                {
                    game.foodComsume();
                    game.moneyUpdate(100);
                    game.updateAmount(100);
                    break;
                }
                case 4: {
                    game.Election();
                    game.moneyUpdate(100);
                    game.updateAmount(100);
                    break;
                }
                case 5:
                {
                    int corup;
                    cout << "\n If u want corruption then press 1 otherwise press any key:";
                    cin >> corup;
                    game.coruption(corup);
                }
                case 6: {
                    game.disease();
                    game.moneyUpdate(100);
                    game.updateAmount(100);
                    break;
                }

                case 7: {
                    game.femine();
                    game.moneyUpdate(100);
                    game.updateAmount(100);
                    break;
                }

                case 8: {
                    game.war();
                    game.moneyUpdate(100);
                    game.updateAmount(100);
                    break;
                }
                case 9: {
                    if (game.getmoney() >= 200) {
                        game.moneyUpdate(-200);
                        game.updateAmount(-200);
                        game.restoreArmy();
                        cout << "Army restored!";
                    }
                    else {
                        cout << "Not enough money!";
                    }
                    break;
                }
                case 10: {
                    if (game.getmoney() >= 100) {
                        game.moneyUpdate(-100);
                        game.updateAmount(-100);
                        game.addPeople();
                        cout << "People added!";
                    }
                    else {
                        cout << "Not enough money!";
                    }
                    break;
                }
                case 11:
                {
                    if (game.getmoney() >= 300) {
                        game.moneyUpdate(-300);
                        game.updateAmount(-300);
                        cout << "Population restored!";
                        game.restorePeople();
                    }
                    else {
                        cout << "Not enough money!";
                    }
                    break;
                }
                case 12:
                {
                    if (game.getmoney() >= 300 && game.getamount() >= 300)
                    {
                        game.restoreFood();
                        game.moneyUpdate(-300);
                        game.updateAmount(-300);
                    }
                    else {
                        cout << "\n balance shortage:";
                    }
                    break;
                }
                case 13:
                {
                    game.displayR1();
                    game.moneyUpdate(100);
                    game.updateAmount(100);
                    break;
                }
                case 00: running = false; break;
                default: cout << "Invalid choice!";
                }
                game.cleanPopulation();
                if (game.getamount() <= 0) { game.setAmountZero(); }
                if (game.getmoney() <= 0) { game.setMoneyZero(); }
                cout << "\nPress enter to continue...";
                cin.get();
            }
        }
        else if (selectObj == 2)
        {
            int choice;
            bool running = true;
            game2.setVal();
            game2.initializePeople();
            game2.setPopulation();
            game2.setArmy();
            game2.setResource();
            game2.setBank();
            game2.setPolitics();
            game2.resourcesOf2();
            while (running) {
                system("cls");
                game2.removePopulatoion();
                game2.initializePeople();
                game2.setPopulation();
                game2.displayKingdom();
                SetColor(3);
                game2.information();
                game2.showEconomy();
                game2.showBankDetails();
                cout << "\n\n=== KINGDOM MANAGEMENT ===";
                cout << "\n1. Check Weather";
                cout << "\n2. Check Population";
                cout << "\n3.Consume Food";
                cout << "\n4. Hold Election";
                cout << "\n5. Check for Corruption";
                cout << "\n6. Check for Disease";
                cout << "\n7. Check for Famine";
                cout << "\n8. Check for War";
                cout << "\n9. Restore Army (Cost: 200)";
                cout << "\n10. Add People (Cost: 100)";
                cout << "\n11. Restore People (Cost: 300)";
                cout << "\n12.Restore Food (Cost:300)";
                cout << "\n13. To show the resources of the kingdom ";
                cout << "\n00. Exit";
                cout << "\nEnter your choice: ";
                cin >> choice;
                cin.ignore(/*numeric_limits<streamsize>::max(), '\n'*/);
            
                system("cls");
                switch (choice) {
                case 1: {
                    game2.weather();
                    game2.moneyUpdate(100);
                    game2.updateAmount(100);
                    break;

                }
                case 2: {
                    game2.populationDetail();
                    game2.moneyUpdate(100);
                    game2.updateAmount(100);
                    break;
                }
                case 3:
                {
                    game2.foodComsume();
                    game2.moneyUpdate(100);
                    game2.updateAmount(100);
                    break;
                }
                case 4: {
                    game2.Election();
                    game2.moneyUpdate(100);
                    game2.updateAmount(100);
                    break;
                }
                case 5:
                {
                    int corup;
                    cout << "\n If u want corruption then press 1 otherwise press any key:";
                    cin >> corup;
                    game.coruption(corup);
                }
                case 6: {
                    game2.disease();
                    game2.moneyUpdate(100);
                    game2.updateAmount(100);
                    break;
                }

                case 7: {
                    game2.femine();
                    game2.moneyUpdate(100);
                    game2.updateAmount(100);
                    break;
                }

                case 8: {
                    game2.war();
                    game2.moneyUpdate(100);
                    game2.updateAmount(100);
                    break;
                }
                case 9: {
                    if (game2.getmoney() >= 200) {
                        game2.moneyUpdate(-200);
                        game2.updateAmount(-200);
                        game2.restoreArmy();
                        cout << "Army restored!";
                    }
                    else {
                        cout << "Not enough money!";
                    }
                    break;
                }
                case 10: {
                    if (game2.getmoney() >= 100) {
                        game2.moneyUpdate(-100);
                        game2.updateAmount(-100);
                        game2.addPeople();
                        cout << "People added!";
                    }
                    else {
                        cout << "Not enough money!";
                    }
                    break;
                }
                case 11:
                {
                    if (game2.getmoney() >= 300) {
                        game2.moneyUpdate(-300);
                        game2.updateAmount(-300);
                        cout << "Population restored!";
                        game2.restorePeople();
                    }
                    else {
                        cout << "Not enough money!";
                    }
                    break;
                }
                case 12:
                {
                    if (game2.getmoney() >= 300 && game.getamount() >= 300)
                    {
                        game2.restoreFood();
                        game2.moneyUpdate(-300);
                        game2.updateAmount(-300);
                    }
                    else {
                        cout << "\n balance shortage:";
                    }
                    break;
                }
                case 13:
                {
                    game2.displayR1();
                    game2.moneyUpdate(100);
                    game2.updateAmount(100);
                    break;
                }
                case 00: running = false; break;
                default: cout << "Invalid choice!";
                }
                game2.cleanPopulation();
                if (game2.getamount() <= 0) { game2.setAmountZero(); }
                if (game2.getmoney() <= 0) { game2.setMoneyZero(); }
                cout << "\nPress enter to continue...";
                cin.get();
            }
        }
        else if (selectObj == 3)
        {
            system("cls");
            cout << "Its trading time come on lets go \n";
            game2.trading(game);
            cout << "resources of player 1 are: \n";
            game.displayR1();
            cout << "\n\nresources of the player 2 are the :\n";
            game2.displayR1();
        }
        else if (selectObj == 4)
        {
            system("cls");
            cout << "Its war time come on lets go \n";
            game2.war(game);
        }
    }
    return 0;
}