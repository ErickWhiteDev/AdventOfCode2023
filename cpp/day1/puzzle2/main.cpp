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

    vector<string> num_words = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    while (getline(input, line)) {
        for (int i = 0; i < line.length(); i++) {
            for (int j = 1; j < num_words.size(); j++) {
                if (line.find(num_words.at(j)) == i) {
                    line.replace(i, num_words.at(j).length() - 1, to_string(j));
                    break;
                }
            }
        }

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