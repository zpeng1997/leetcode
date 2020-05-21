/*
 * @lc app=leetcode.cn id=1371 lang=cpp
 *
 * [1371] 每个元音包含偶数次的最长子字符串
 *
 * https://leetcode-cn.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/description/
 *
 * algorithms
 * Medium (43.49%)
 * Likes:    227
 * Dislikes: 0
 * Total Accepted:    13.9K
 * Total Submissions: 23.5K
 * Testcase Example:  '"eleetminicoworoep"'
 *
 * 给你一个字符串 s ，请你返回满足以下条件的最长子字符串的长度：每个元音字母，即 'a'，'e'，'i'，'o'，'u'
 * ，在子字符串中都恰好出现了偶数次。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "eleetminicoworoep"
 * 输出：13
 * 解释：最长子字符串是 "leetminicowor" ，它包含 e，i，o 各 2 个，以及 0 个 a，u 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "leetcodeisgreat"
 * 输出：5
 * 解释：最长子字符串是 "leetc" ，其中包含 2 个 e 。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：s = "bcbcbc"
 * 输出：6
 * 解释：这个示例中，字符串 "bcbcbc" 本身就是最长的，因为所有的元音 a，e，i，o，u 都出现了 0 次。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 5 x 10^5
 * s 只包含小写英文字母。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n = s.length();
        vector<int> hash(32, n + 1);
        hash[0] = -1;
        char a[] = {'a','e','i','o','u'};

        int check = 0;
        int res = 0;
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < 5; j ++)
                if(s[i] == a[j])    
                    check ^= 1 << j;
            res = max(res, i - hash[check]);
            hash[check] = min(hash[check], i);
        }
        return res;
    }
};
// @lc code=end

