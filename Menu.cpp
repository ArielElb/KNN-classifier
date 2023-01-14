//
// Created by Erel Arnold on 1/11/23.
//

#include <iostream>
#include "Menu.h"


void Menu::showMenu(std::vector<Command *> commands) {
    int choice;
    do {
        std::cout << "Welcome to the Anomaly Detection Server" << std::endl;
        std::cout << "Please choose an option:" << std::endl;
        std::cout << "1. upload a time series csv file" << std::endl;
        std::cout << "2. algorithm settings" << std::endl;
        std::cout << "3. detect anomalies" << std::endl;
        std::cout << "4. display results" << std::endl;
        std::cout << "5. upload anomalies and analyze results" << std::endl;
        std::cout << "6. exit" << std::endl;
        std::cin >> choice;
        switch (choice) {
            case 1:
                commands[0]->execute();
                break;
            case 2:
                commands[1]->execute();
                break;
            case 3:
                commands[2]->execute();
                break;
            case 4:
                commands[3]->execute();
                break;
            case 5:
                commands[4]->execute();
                break;
            case 8:
                break;
            default:
                std::cout << "Invalid input" << std::endl;
                break;
        }
    } while (choice != 8);


}
