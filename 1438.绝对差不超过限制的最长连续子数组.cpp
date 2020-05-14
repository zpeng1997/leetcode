/*
 * @lc app=leetcode.cn id=1438 lang=cpp
 *
 * [1438] 绝对差不超过限制的最长连续子数组
 *
 * https://leetcode-cn.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/description/
 *
 * algorithms
 * Medium (35.68%)
 * Likes:    19
 * Dislikes: 0
 * Total Accepted:    3K
 * Total Submissions: 8.2K
 * Testcase Example:  '[8,2,4,7]\n4'
 *
 * 给你一个整数数组 nums ，和一个表示限制的整数 limit，请你返回最长连续子数组的长度，该子数组中的任意两个元素之间的绝对差必须小于或者等于
 * limit 。
 * 
 * 如果不存在满足条件的子数组，则返回 0 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [8,2,4,7], limit = 4
 * 输出：2 
 * 解释：所有子数组如下：
 * [8] 最大绝对差 |8-8| = 0 <= 4.
 * [8,2] 最大绝对差 |8-2| = 6 > 4. 
 * [8,2,4] 最大绝对差 |8-2| = 6 > 4.
 * [8,2,4,7] 最大绝对差 |8-2| = 6 > 4.
 * [2] 最大绝对差 |2-2| = 0 <= 4.
 * [2,4] 最大绝对差 |2-4| = 2 <= 4.
 * [2,4,7] 最大绝对差 |2-7| = 5 > 4.
 * [4] 最大绝对差 |4-4| = 0 <= 4.
 * [4,7] 最大绝对差 |4-7| = 3 <= 4.
 * [7] 最大绝对差 |7-7| = 0 <= 4. 
 * 因此，满足题意的最长子数组的长度为 2 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [10,1,2,4,7,2], limit = 5
 * 输出：4 
 * 解释：满足题意的最长子数组是 [2,4,7,2]，其最大绝对差 |2-7| = 5 <= 5 。
 * 
 * 
 * 示例 3：
 * 
 * 输入：nums = [4,2,2,2,4,4,2,2], limit = 0
 * 输出：3
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^9
 * 0 <= limit <= 10^9
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    // Solution 1: Monotonic Queue
    int longestSubarray(vector<int>& nums, int limit) {
        // 找区间的最大值和最小值, 若区间 |最大值 - 最小值| <= limit, 找出一个最长的区间
        // 单调队列, 写得少, 有点慌
        int size = nums.size();
        deque<int> left, right;

        int ans = 0;
        for(int i = 0, j = 0; i < size; i ++){
            // 找到最大值
            while(!left.empty() && nums[i] >= nums[left.back()])
                left.pop_back();
            left.push_back(i);

            while(!right.empty() && nums[i] <= nums[right.back()])
                right.pop_back();
            right.push_back(i);

            while(!left.empty() && !right.empty() && nums[left.front()] - nums[right.front()] > limit){
                j ++;
                while(!left.empty() && left.front() < j)
                    left.pop_front();
                while(!right.empty() && right.front() < j)
                    right.pop_front();
            }

            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};
// @lc code=end

