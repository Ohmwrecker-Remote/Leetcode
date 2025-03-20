/*
 * @lc app=leetcode.cn id=8 lang=c
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
// Version_2
int myAtoi(char* s) {
    int sign = 1;
    int signFlag = 0;
    int result = 0;
    int zeroFlag = 0;
    int numberFlag = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == ' '){
            continue;
        }
        if (s[i] == '-') {
            sign = -1;
            signFlag++;
            if ((int)s[i + 1] < 48 || (int)s[i + 1] > 57){
                return 0;
            }
            continue;
        }
        else if (s[i] == '+') {
            sign = 1;
            signFlag++;
            if ((int)s[i + 1] < 48 || (int)s[i + 1] > 57){
                return 0;
            }
            continue;
        }
        if (signFlag > 1) {
            return 0;
        }
        if ((int)s[i] > 48 && (int)s[i] <= 57) {
            numberFlag = 1;
        }
        if (s[i] == '0' && numberFlag == 0 && (int)s[i + 1] >= 48 && (int)s[i + 1] <= 57) {
            continue;
        }else if(s[i] == '0' && numberFlag == 0){
            return  0;
        }
        if ((int)s[i] >= 48 && (int)s[i] <= 57 && numberFlag == 1) {
            if (sign == -1) {
                if ((INT_MIN - result) >= -((int)s[i] - 48)) {
                    return INT_MIN;
                }
                result -= (int)s[i] - 48;
            }
            else {
                if (INT_MAX - result <= (int)s[i] - 48) {
                    return INT_MAX;
                }
                result += (int)s[i] - 48;
            }
        }
        if ((int)s[i + 1] >= 48 && (int)s[i + 1] <= 57 && numberFlag == 1) {
            if ((double)result <= (double)INT_MAX / 10 && (double)result >= (double)INT_MIN / 10) {
                result *= 10;
            }
            else if ((double)result >= (double)INT_MAX / 10) {
                return INT_MAX;
            }
            else if ((double)result <= (double)INT_MIN / 10) {
                return INT_MIN;
            }
        }else {
            break;
        }
    }
    return result;
}
// @lc code=end

