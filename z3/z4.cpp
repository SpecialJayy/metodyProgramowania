#include <algorithm>
#include <iostream>
#include <vector>
#include <fstream>
#include "../libraries/libArray.h"
#include "../libraries/libFile.h"

int countOccurrences(const std::vector<long long>& arr, long long target) {
    auto range = std::equal_range(arr.begin(), arr.end(), target);
    return std::distance(range.first, range.second);
}

int interpolationSearch(const std::vector<long long>& arr, long long target) {
    int low = 0, high = (int)arr.size() - 1;
    while (low <= high && target >= arr[low] && target <= arr[high]) {
        if (low == high) return (arr[low] == target) ? low : -1;

        long long pos = low + (double)(target - arr[low]) * (high - low) / (arr[high] - arr[low]);

        if (arr[pos] == target) return (int)pos;
        if (arr[pos] < target) low = (int)pos + 1;
        else high = (int)pos - 1;
    }
    return -1;
}

void removeDuplicates(std::vector<long long>& arr) {
    auto it = std::unique(arr.begin(), arr.end());
    arr.erase(it, arr.end());
}

void saveToFile(const std::vector<long long>& arr, std::fstream& file) {
    const int limit = 200;
    int count = 0;

    for (size_t i = 0; i < arr.size() && count < limit; ++i) {
        file << arr[i];
        count++;

        if (count % 50 == 0) {
            file << "\n";
        }
        else if (count < (int)arr.size() && count < limit) {
            file << " ";
        }
    }

    if (count % 50 != 0) {
        file << "\n";
    }
}

int main() {
    std::fstream outPut = createOutputFile("output_program04.txt");
    std::ifstream file("../assets/lab3/in1.txt");
    if (!file) {
        std::cerr << "brak pliku in1.txt" << std::endl;
        return 1;
    }

    int numDatasets;
    file >> numDatasets;

    while (numDatasets--) {
        int n;
        file >> n;
        std::vector<long long> arr(n);
        for (int i = 0; i < n; ++i) file >> arr[i];

        int numQueries;
        file >> numQueries;

        for (int i = 0; i < numQueries; ++i) {
            long long target;
            file >> target;
            int count = countOccurrences(arr, target);
            int idx = (count > 0) ? interpolationSearch(arr, target) : -1;
            outPut << "(" << count << " " << idx << ") ";
        }
        outPut << std::endl;

        removeDuplicates(arr);

        saveToFile(arr,outPut);

        file.close();
    }
    return 0;
}