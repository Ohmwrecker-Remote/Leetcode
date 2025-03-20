/*
 * @lc app=leetcode.cn id=7 lang=c
 *
 * [7] 整数反转
 */

// @lc code=start
int reverse(int x) {
    int digit = 0;
    int result = 0;
    int flag = 0;
    while(x != 0){
        digit = x % 10;
        if(x >= 10 || x <=  -10){
        flag++;
        }
        result += digit;
        x = (x - digit) / 10;
        if (flag > 0){
            if(result > INT_MAX / 10 || result < INT_MIN / 10){
                return 0;
            }
            result *= 10;
            flag--;
        }
    }
    return result;
}
// @lc code=end

