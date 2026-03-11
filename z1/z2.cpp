#include <iostream>
#include <limits>
#include <algorithm>
#include "../libraries/libFile.h"

using namespace std;

//klasa robiąca i zarządzająca dynamiczną tablicą 1-wymiarową
class dynamicArray {
public:
    int size;
    int* data = nullptr;

    dynamicArray(int size) : size(size) {
        try {
            //wczesna inicjalizacja zerami
            this->data = new int[size]{};
        } catch ( const std::bad_alloc& ) {
            std::cout << "Out of memory" << std::endl;
        }
    }

    //przeciążenie operatora [] dla lepszej czytelności
    int& operator[](int index) {
        return this->data[index];
    }

    ~dynamicArray() {
        delete[] this->data;
    }
};

int kadane(dynamicArray& arr) {
    //algorytm kadane tak jak w zadaniu 1
    int biggestSum = 0;
    int temp = 0;

    for (int k = 0; k < arr.size; k++) {
        if (arr[k] > temp + arr[k]) {
            temp = arr[k];
        } else {
            temp += arr[k];
        }

        if (temp > biggestSum) {
            biggestSum = temp;
        }
    }

    return biggestSum;
}

//klasa robiąca i zarządzająca dynamiczną tablicą 2-wymiarową
class dynamic2DArray {
public:
    int rows;
    int cols;
    dynamicArray** data = nullptr;

    dynamic2DArray(int rows, int cols) : rows(rows), cols(cols) {
        try {
            this->data = new dynamicArray*[this->rows];
            for (int i = 0 ; i < this->rows ; i++) {
                this->data[i] = new dynamicArray(this->cols);
            }
        } catch (const std::bad_alloc&) {
            std::cout << "Out of memory" << std::endl;
        }
    }

    void inputData() {
        for (int j = 0; j < this->rows; j++) {
            for (int k = 0; k < this->cols; k++) {
                (*this)[j][k] = inputInteger();
            }
        }
    }

    int findBestArea() {
        int biggestSum = 0;

        // poruszamy sie dwoma krawędziami kolumn od lewej do prawej
        for (int leftCol = 0; leftCol < this->cols; leftCol++) {
            dynamicArray projectedRow(this->rows);

            for (int rightCol = leftCol; rightCol < this->cols; rightCol++) {
                //robimy rzut na tablice 1-wymiarową
                for (int row = 0; row < this->rows; row++) {
                    projectedRow[row] += (*this)[row][rightCol];
                }

                //używamy algorytmu kadanea na wcześniej zrobionym rzucie
                int currentSum = kadane(projectedRow);

                if (currentSum > biggestSum) {
                    biggestSum = currentSum;
                }
            }
        }

        return biggestSum;
    }

    //przeciążenie operatora dla czytelności
    dynamicArray& operator[](int index) {
        return *(this->data[index]);
    }

    ~dynamic2DArray() {
        for (int i = 0 ; i < this->rows ; i++) {
            delete this->data[i];
        }
        delete[] this->data;
    }
};

int main0() {
    int sets = inputPositiveInteger();

    dynamicArray answers(sets);

    for (int i = 0; i < sets; i++) {
        int rows = inputWithinRange(1, 100);
        int cols = inputWithinRange(1, 100);

        dynamic2DArray arr(rows, cols);
        arr.inputData();
        answers[i] = arr.findBestArea();
    }

    for (int i = 0; i < sets; i++) {
        cout << answers[i] << endl;
    }

    return 0;
}