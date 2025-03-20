/*
 * @lc app=leetcode.cn id=6 lang=c
 *
 * [6] Z 字形变换
 */

// @lc code=start
char* convert(char* s, int numRows) {

    int length = strlen(s);
    char* output = (char*)malloc(sizeof(char) * (length + 1));
    for (int i = 0; i < length + 1; i++) {
        output[i] = '\0';
    }
    int flag = 0;
    int pointer = 0;
    int isFirst = 1;
    for (int i = 0; i < numRows; i++) {
        if (numRows == 1) {
            return s;
        }
        // 第一行或者最后一行
        if (i == 0 || i == numRows - 1) {
            pointer = i;
            while (pointer < length) {
                output[flag] = s[pointer];
                flag++;
                pointer += numRows * 2 - 2;
            }
        }
        else if (i != 0 && i != numRows - 1) {
            // 中间行
            pointer = i;
            isFirst = 1;
            while (pointer < length) {
                if (isFirst == 1) {
                    if (pointer < length) {
                        output[flag] = s[pointer];
                        flag++;
                        isFirst = 0;
                    }
                }
                else if (isFirst == 0)
                {
                    pointer += (numRows - (i + 1)) * 2;
                    if (pointer < length) {
                        output[flag] = s[pointer];
                        flag++;
                        isFirst = 1;
                        pointer += i * 2;
                    }
                }
            }
        }
        
    }
    return output;
    free(output);
}
// @lc code=end

