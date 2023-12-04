#include <iostream>

using namespace std;
string array_string[] = {"Dao", "Mai", "Lan", "Thuy"};
void generateCombinations(int* nums, int n, int* temp, int start, int k, int& count) {
    if (k == 0) {
        for (int i = 0; i < count; ++i) {
            cout << array_string[temp[i] - 1] << " ";
            //cout << temp[i] << " ";
        }
        cout << endl;
        return;
    }
    for (int i = start; i < n; ++i) {
        temp[count++] = nums[i];
        generateCombinations(nums, n, temp, i + 1, k - 1, count);
        count--;
    }
}

int main() {
    int n = 4;
    int k = 3;
    int nums[] = {1, 2, 3, 4};
    int temp[k];
    int count = 0;
    generateCombinations(nums, n, temp, 0, k, count);
    return 0;
}