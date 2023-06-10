#include <iostream>
#include <string>
#include <bits/stdc++.h>
int binarySearch(const std::string& str, char target, int left, int right) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (str[mid] == target)
            return mid;
        else if (str[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1; // Character not found
}

int searchCharacter(const std::string& str, char target) {
    int length = str.length();

    // Convert the string to a sorted array of characters
    std::string sortedStr = str;
    std::sort(sortedStr.begin(), sortedStr.end());

    return binarySearch(sortedStr, target, 0, length - 1);
}

int main() {
    std::string str = "example";
    char target = 'a';

    int index = searchCharacter(str, target);
    if (index != -1)
        std::cout << "Character '" << target << "' found at index " << index << std::endl;
    else
        std::cout << "Character '" << target << "' not found." << std::endl;

    return 0;
}
