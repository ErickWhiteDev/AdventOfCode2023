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

    int minRed = 0;
    int minGreen = 0;
    int minBlue = 0;

    vector<string> container;

    int sum = 0;

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
                    minRed = max(stoi(container.at(1)), minRed);
                }
                else if (container.at(2) == "green") {
                    minGreen = max(stoi(container.at(1)), minGreen);
                }
                else {
                    minBlue = max(stoi(container.at(1)), minBlue);
                }
            }
        }

        sum += minRed * minGreen * minBlue;

        minRed = 0;
        minGreen = 0;
        minBlue = 0;
    }

    input.close();

    cout << sum << endl;

    return 0;
}