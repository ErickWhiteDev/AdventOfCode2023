//
// Created by erick on 12/24/2023.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    ifstream input("input.txt");

    string line;
    string card;
    string winning;
    string winNums;
    string heldNums;

    vector<int> cardWinners;
    vector<int> cardHeld;

    int count = -1;

    int sum = 0;

    while (getline(input, line)) {
        stringstream cardstream(line);

        getline(cardstream, card, ':');

        getline(cardstream, winning, '|');

        stringstream winningstream(winning);

        while (getline(winningstream, winNums, ' ')) {
            if (winNums.length() > 0) {
                cardWinners.push_back(stoi(winNums));
            }
        }

        while (getline(cardstream, heldNums, ' ')) {
            if (heldNums.length() > 0) {
                cardHeld.push_back(stoi(heldNums));
            }
        }

        for (int i : cardHeld) {
            if (find(cardWinners.begin(), cardWinners.end(), i) != cardWinners.end()) {
                count++;
            }
        }

        if (count >= 0) {
            sum += (int) pow(2, count);
        }

        count = -1;
        cardWinners.clear();
        cardHeld.clear();
    }

    input.close();

    cout << sum << endl;

    return 0;
}