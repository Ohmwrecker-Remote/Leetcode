/*
 * @lc app=leetcode.cn id=5 lang=c
 *
 * [5] 最长回文子串
 */

// @lc code=start

int isPalindrome(char* s, int start, int end);

char* longestPalindrome(char* s) {
       // 优化算法使用从中间往两边扩展的方式
       int size = strlen(s);
       int windowSizeJ = 0;
       int windowSizeO = 0;
       int startJ = 0;
       int startO = 0;
       int start = 0;
       if (size <= 1) {
           return s;
       }
        // 奇数 至少一个输出
        for (int i = 0; i < size; i++) {
            int left = i - 1;
            int right = i + 1;
            while (left >= 0 && right < size && s[left] == s[right]) {
                left--;
                right++;
            }
            if (right - left + 1 > windowSizeJ) {
                windowSizeJ = right - left - 1;
                startJ = left + 1;
            }
        }
        // 偶数
        for (int i = 0; i < size; i++) {
            int left = i;
            int right = i + 1;
            while (left >= 0 && right < size && s[left] == s[right]) {
                left--;
                right++;
            }
            if (right - left + 1 - 2 > windowSizeO) {
                windowSizeO = right - left + 1 - 2;
                // 补偿while中多减的1
                startO = left + 1;
            }
        }
       int maxWindow = 0;
       if (windowSizeJ > windowSizeO) {
           maxWindow = windowSizeJ;
           start = startJ;
       }
       else {
           maxWindow = windowSizeO;
           start = startO;
       }
       char* result = (char*)malloc(maxWindow + 1);
       // 将s[2]中的maxlength个字符存入result
   
       strncpy(result, s + start, maxWindow);
       result[maxWindow] = '\0'; // 手动添加终止符
    //    strncpy_s(result,maxWindow + 1, s + start, maxWindow);
       return result;
}

// int isPalindrome(char* s, int start, int end) {
//     int size = end - start + 1;
//     if (size < 1) {
//         return 0;
//     }
//     if (size == 1) {
//         return 1;
//     }
//     // 偶数
//     if (size % 2 == 0) {
//         for (int i = 0; i <= (size / 2) - 1; i++) {
//             if (s[start + i] != s[end - i]) {
//                 return 0;
//             }
//         }
//         return 1;
//     }
//     // 奇数 
//     if (size % 2 == 1) {
//         for (int i = 0; i <= (size - 1 / 2) - 1; i++) {
//             if (s[start + i] != s[end - i]) {
//                 return 0;
//             }
//         }
//         return 1;
//     }
//     return 0;
// }
// @lc code=end

