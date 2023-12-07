//
// Created by erick on 12/5/2023.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <cctype>

using namespace std;

int main() {

    ifstream input("input.txt");

    string line;

    int sum = 0;

    vector<int> calibration_values;

    while (getline(input, line)) {
        for (char c : line) {
            if (isdigit(c)) {
                calibration_values.push_back((int) c - (int) '0');
            }
        }

        sum += 10 * calibration_values.at(0) + calibration_values.back();

        calibration_values.clear();
    }

    input.close();

    cout << sum << endl;

    return 0;
}