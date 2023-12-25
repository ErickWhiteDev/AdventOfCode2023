//
// Created by erick on 12/24/2023.
//

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main() {
    ifstream input("input.txt");

    string line;

    int schematicWidth = 140;
    int schematicHeight = 140;

    int left;
    int right;
    int top;
    int bottom;
    int length = 0;
    int found = 0;

    char schematic[schematicHeight][schematicWidth];

    int sum = 0;

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
                top = i ? i - 1 : i;
                bottom = i < schematicHeight - 1 ? i + 1 : i;

                left = j ? j - 1 : j;
                right = j < schematicWidth - 1 ? j + 1 : j;

                while (j < schematicWidth - 1 && isdigit(schematic[i][j + 1])) {
                    length++;
                    right++;
                    j++;
                }

                for (int m = top; m <= bottom; m++) {
                    for (int n = left; n <= right; n++) {
                        if (schematic[m][n] != '.' && !isdigit(schematic[m][n])) {
                            for (int k = length; k >= 0; k--) {
                                sum += (schematic[i][j - k] - '0') * (int) pow(10, k);
                            }

                            found = 1;
                             break;
                        }
                    }

                    if (found) {
                        break;
                    }
                }

                length = 0;
                found = 0;
            }
        }
    }

    cout << sum << endl;

    return 0;
}