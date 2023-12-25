//
// Created by erick on 12/24/2023.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    ifstream input("input.txt");

    string line;

    int schematicWidth = 140;
    int schematicHeight = 140;

    int left;
    int right;
    int length = 0;

    char schematic[schematicHeight][schematicWidth];
    vector<int*> numRanges;

    int sum = 0;
    int accum = 0;
    int gearAccum = 1;
    int count = 0;

    for (int i = 0; i < schematicHeight; i++) {
        getline(input, line);

        for (int j = 0; j < schematicWidth; j++) {
            schematic[i][j] = line[j];
        }
    }

    input.close();

    for (int i = 0; i < schematicHeight; i++) {
        for (int j = 0; j < schematicWidth; j++) {
            if (isdigit(schematic[i][j])) {
                while (j < schematicWidth - 1 && isdigit(schematic[i][j + 1])) {
                    length++;
                    j++;
                }

                for (int k = length; k >= 0; k--) {
                    accum += (schematic[i][j - k] - '0') * (int) pow(10, k);
                }

                int *numData = new int[4];

                numData[0] = accum;
                numData[1] = i;
                numData[2] = j - length;
                numData[3] = j;

                numRanges.push_back(numData);

                accum = 0;
                length = 0;
            }
        }
    }

    for (int i = 0; i < schematicHeight; i++) {
        for (int j = 0; j < schematicWidth; j++) {
            if (schematic[i][j] == '*') {
                left = j ? j - 1 : j;
                right = j < schematicWidth - 1 ? j + 1 : j;

                for (int* v : numRanges) {
                    if (abs(i - v[1]) <= 1 && !((v[2] < left && v[3] < left) || (v[2] > right && v[3] > right))) {
                        gearAccum *= v[0];
                        count++;
                    }
                }

                if (count == 2) {
                    sum += gearAccum;
                }

                gearAccum = 1;
                count = 0;
            }
        }
    }

    cout << sum << endl;

    return 0;
}