// Błahut Paweł
#include <cmath>
#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include "../libraries/libInput.h"
#include "../libraries/libArray.h"

using namespace std;

//struct do testCase, żeby po wpisaniu zapisać tutaj tablice i oczekiwany wynik
struct TestCase {
    int rows;
    int cols;
    vector<vector<int>> matrix;
    int target;
};

void printResult(const string& funcName, int target, pair<int, int> result) {
    if (result.first != -1) {
        cout << funcName << ": " << target << " w (" << result.first << "," << result.second << ")\n";
    } else {
        cout << funcName << ": nie ma " << target << "\n";
    }
}

int main() {
    int sets = inputPositiveInteger();
    vector<TestCase> allTests;

    for (int i = 0; i < sets; ++i) {
        TestCase testCase;

        testCase.rows = inputWithinRange(1, 100);
        testCase.cols = inputWithinRange(1,100);

        testCase.matrix.resize(testCase.rows, vector<int>(testCase.cols));

        for (int r = 0; r < testCase.rows; ++r) {
            for (int c = 0; c < testCase.cols; ++c) {
                testCase.matrix[r][c] = inputWithinRange(-pow(2,15),pow(2,15));
            }
        }
        testCase.target = inputInteger();
        allTests.push_back(testCase);
    }

    for (const auto& testCase : allTests) {
        printResult("RekPier", testCase.target, saddleBackRec(testCase.matrix, testCase.target, true));
        printResult("RekOst",  testCase.target, saddleBackRec(testCase.matrix, testCase.target, false));
        printResult("IterPier", testCase.target, saddleBackIter(testCase.matrix, testCase.target, true));
        printResult("IterOst",  testCase.target, saddleBackIter(testCase.matrix, testCase.target, false));
        cout << "---\n";
    }

    return 0;
}