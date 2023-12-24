//
// Created by erick on 12/23/2023.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    ifstream input("input.txt");

    string line;
    string game;
    string round;
    string dice;
    string val;

    int redLim = 12;
    int greenLim = 13;
    int blueLim = 14;

    vector<string> container;

    int sum = 0;
    int id = 1;
    int valid = 1;

    while (getline(input, line)) {
        stringstream gamestream(line);

        getline(gamestream, game, ':');

        while (getline(gamestream, round, ';')) {
            stringstream roundstream(round);

            while (getline(roundstream, dice, ',')) {
                stringstream dicestream(dice);

                container.clear();

                while (getline(dicestream, val, ' ')) {
                    container.push_back(val);
                }

                if (container.at(2) == "red") {
                    if (stoi(container.at(1)) > redLim) {
                        valid = 0;
                        break;
                    }
                }
                else if (container.at(2) == "green") {
                    if (stoi(container.at(1)) > greenLim) {
                        valid = 0;
                        break;
                    }
                }
                else {
                    if (stoi(container.at(1)) > blueLim) {
                        valid = 0;
                        break;
                    }
                }
            }

            if (!valid) {
                break;
            }
        }

        if (valid) {
            sum += id;
        }

        valid = 1;
        id++;
    }

    input.close();

    cout << sum << endl;

    return 0;
}