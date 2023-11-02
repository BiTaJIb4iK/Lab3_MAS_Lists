#include <iostream>
#include <string.h>
#include <vector>
#include <random>
#include <unordered_set>


int main()
{
    std::vector<int> arr = { 17, 18, 5, 4, 6, 1 };

    auto custom_check = [](const int& a, const int& b)->bool {
        if (a % 2 == 0 && b % 2 != 0) {
            return true;
        }
        else if (a % 2 != 0 && b % 2 == 0) {
            return false;
        }
        else {
            return a < b;
        }
        };

    std::sort(arr.begin(), arr.end(), custom_check);


    for (int i = 0; i < /*deleteDublicates(arr)*/ arr.size(); i++)
        std::cout << arr[i] << ' ';

}
