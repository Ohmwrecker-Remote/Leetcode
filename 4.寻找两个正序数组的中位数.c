/*
 * @lc app=leetcode.cn id=4 lang=c
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int size = nums1Size + nums2Size;
    int* temp = (int*)malloc(sizeof(int) * size);
    if (temp != NULL) {
        for (int i = 0; i < size; i++) {
            temp[i] = 0;
        }
        int nums1Index = 0, nums2Index = 0, tempIndex = 0;
        double median = 0.0;
        while (nums1Index < nums1Size && nums2Index < nums2Size) {
            if (nums1[nums1Index] <= nums2[nums2Index]) {
                temp[tempIndex] = nums1[nums1Index];
                nums1Index++;
            }else {
                temp[tempIndex] = nums2[nums2Index];
                nums2Index++;
            }
            tempIndex++;
        }
        while (nums1Index < nums1Size) {
            temp[tempIndex] = nums1[nums1Index];
            tempIndex++;
            nums1Index++;
        }
        while (nums2Index < nums2Size) {
            temp[tempIndex] = nums2[nums2Index];
            tempIndex++;
            nums2Index++;
        }
        if (temp != NULL) {
            if (size == 1) {
                median = temp[0];
            }
            else if (size % 2 == 1) {
                median = temp[((size + 1) / 2) - 1];
            }
            else {
                median = (temp[(size / 2) - 1] + temp[size / 2]) / 2.0;
            }
        }
        return median;
    }
    return 0.0;
}
// @lc code=end

