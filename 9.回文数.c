/*
 * @lc app=leetcode.cn id=9 lang=c
 *
 * [9] 回文数
 */

#include <stdbool.h>

// @lc code=start
bool isPalindrome(int x) {
    int compare[10] = {0};
    int flag = 0;
    if(x < 0){
        return false;
    }
    if ( x == 0){
        return true;
    }
    if (x < 10){
        return true;
    }
    while (x > 9){
        compare[flag] = x % 10;
        x = x - x % 10;
        x /= 10;
        flag++;
    }
    if (x!= 0){
        compare[flag] = x;
        flag++;
    }
    for (int i = 0; i < flag / 2; i++){
        if(compare[i] != compare[flag - 1 - i]){
            return false;
        }
    }
    return true;
}
// @lc code=end

