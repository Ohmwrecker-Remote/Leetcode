/*
 * @lc app=leetcode.cn id=3 lang=c
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
int lengthOfLongestSubstring(const char* s) {
    int n = strlen(s);
    int maxLength = 0, start = 0;
    int charIndex[128]; // 用于存储字符上次出现的位置
    memset(charIndex, -1, sizeof(charIndex)); // 初始化为-1，表示字符还未出现过

    for (int end = 0; end < n; end++) {
        char currentChar = s[end];
        // 如果当前字符在窗口内已经出现过，则更新窗口的起始位置
        if (charIndex[currentChar] >= start) {
            start = charIndex[currentChar] + 1; // 更新窗口位置
        }
        charIndex[currentChar] = end; // 记录当前字符的位置
        // end - start + 1表示当前窗口的长度，更新最大长度
        maxLength = (end - start + 1) > maxLength ? (end - start + 1) : maxLength; // 更新最大长度
    }

    return maxLength;
}

// @lc code=end

