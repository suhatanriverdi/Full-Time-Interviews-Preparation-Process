// QUESTION LINK ---> https://leetcode.com/problems/can-place-flowers/

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();
        if (size == 1) {
            if (flowerbed[0] == 0) {
                return n <= 1;
            } else {
                return n <= 0;
            }
        }
        if (size == 2) {
            if (flowerbed[0] == 0 && flowerbed[1] == 0) {
                return n <= 1;
            } else {
                return n <= 0;
            }
        }
        // size >= 3
        if (flowerbed[0] == 0 && flowerbed[1] == 0) {
            flowerbed[0] = 1;
            n--;
        }
        if (flowerbed[size - 1] == 0 && flowerbed[size - 2] == 0) {
            flowerbed[size - 1] = 1;
            n--;
        }
        for (int i = 1; i < size; i++) {
            if (flowerbed[i - 1] == 0 && flowerbed[i] == 0 && flowerbed[i + 1] == 0) {
                flowerbed[i] = 1;
                n--;
            }
        }
        return n <= 0;
    }
};