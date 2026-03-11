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
    int* multipliedData = nullptr;

    dynamicArray(int size) : size(size) {
        //bezpieczne tworzenie nowej tablicy dynamicznej
        try {
            this->data = new int[size]{};
            this->multipliedData = new int[size]{};
        } catch ( const std::bad_alloc& ) {
            std::cout << "Out of memory" << std::endl;
        }
    }

    // przeciążenie operatora [] dla lepszej czytelności kodu
    int& operator[](int index) {
        return this->multipliedData[index];
    }

    void showBiggestSum() {
        //uzywamy algorytmu kadanea
        long long biggestSum = 0;
        long long temp = 0;
        int tempStart = 0;
        int start = 0;
        int end = -1;

        for (int k = 0; k < this->size; k++) {
            if (this->multipliedData[k] > temp + this->multipliedData[k]) {
                temp = this->multipliedData[k];
                tempStart = k;
            } else {
                temp = temp + this->multipliedData[k];
            }

            // jeśli mamy nową największą sume to aktualizujemy największą sume globalną
            if (temp > biggestSum) {
                biggestSum = temp;
                start = tempStart;
                end = k;
            }
        }

        cout << start << " " << end << " " << biggestSum << endl;
    }

    ~dynamicArray() {
        delete[] this->data;
        delete[] this->multipliedData;
    }
};

int main1() {
    //bierzemy ilość zestawów
    int sets = inputPositiveInteger();

    for (int i = 0; i < sets; i++) {
        //bierzemy rozmiar tablicy
        int arraySize = inputWithinRange(1, 1000000);
        dynamicArray array(arraySize);

        for (int j = 0; j < arraySize; j++) {
            // wartosci bezwzgledne nie będą przekraczać 2000
            int element = inputWithinRange(-2000, 2000);
            array.data[j] = element;

            //wykonujemy operacje matematycze i zapsujemy do nowej tabeli aby było prosciej
            if (element >= 0) {
                array.multipliedData[j] = 3 * element;
            } else {
                array.multipliedData[j] = 2 * element;
            }
        }

        array.showBiggestSum();
    }

    return 0;
}