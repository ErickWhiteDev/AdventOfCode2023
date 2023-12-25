//
// Created by erick on 12/24/2023.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include "node.h"

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

    vector<int> characteristics;

    int count = 0;

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

        characteristics.push_back(count);

        count = 0;
        cardWinners.clear();
        cardHeld.clear();
    }
    
    for (int i = 1; i <= characteristics.size(); i++) {
        Node* root = getNewNode(i, characteristics, nullptr);
        generateTree(root);
        sum += countNodes(root);
        deleteTree(root);
    }

    input.close();

    cout << sum << endl;

    return 0;
}