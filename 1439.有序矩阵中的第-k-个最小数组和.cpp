/*
 * @lc app=leetcode.cn id=1439 lang=cpp
 *
 * [1439] 有序矩阵中的第 k 个最小数组和
 *
 * https://leetcode-cn.com/problems/find-the-kth-smallest-sum-of-a-matrix-with-sorted-rows/description/
 *
 * algorithms
 * Hard (50.88%)
 * Likes:    10
 * Dislikes: 0
 * Total Accepted:    1.4K
 * Total Submissions: 2.8K
 * Testcase Example:  '[[1,3,11],[2,4,6]]\n5'
 *
 * 给你一个 m * n 的矩阵 mat，以及一个整数 k ，矩阵中的每一行都以非递减的顺序排列。
 * 
 * 你可以从每一行中选出 1 个元素形成一个数组。返回所有可能数组中的第 k 个 最小 数组和。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：mat = [[1,3,11],[2,4,6]], k = 5
 * 输出：7
 * 解释：从每一行中选出一个元素，前 k 个和最小的数组分别是：
 * [1,2], [1,4], [3,2], [3,4], [1,6]。其中第 5 个的和是 7 。  
 * 
 * 示例 2：
 * 
 * 输入：mat = [[1,3,11],[2,4,6]], k = 9
 * 输出：17
 * 
 * 
 * 示例 3：
 * 
 * 输入：mat = [[1,10,10],[1,4,5],[2,3,6]], k = 7
 * 输出：9
 * 解释：从每一行中选出一个元素，前 k 个和最小的数组分别是：
 * [1,1,2], [1,1,3], [1,4,2], [1,4,3], [1,1,6], [1,5,2], [1,5,3]。其中第 7 个的和是 9
 * 。 
 * 
 * 
 * 示例 4：
 * 
 * 输入：mat = [[1,1,10],[2,2,9]], k = 7
 * 输出：12
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == mat.length
 * 
 * n == mat.length[i]
 * 1 <= m, n <= 40
 * 1 <= k <= min(200, n ^ m)
 * 1 <= mat[i][j] <= 5000
 * mat[i] 是一个非递减数组
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    // 想到了dfs, 没想到堆
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();

        typedef pair<int, vector<int>> PIV;
        // 存储sum值 和 这时的选择方案.
        priority_queue<PIV, vector<PIV>, greater<PIV>> heap;
        set<vector<int> > st;

        vector<int> idx(m, 0);
        int sum = 0;

        // 最小的一个数 sum
        for(int i = 0; i < m; i ++)
            sum += mat[i][0];
        heap.push({sum, idx}); // 最小值的大小 和 每行选择的编号

        while(-- k){
            // 取出当前最小值
            sum = heap.top().first;
            idx = heap.top().second;
            heap.pop();

            // 根据当前最小值遍历, 并放入min heap
            for(int i = 0; i < m; i ++){
                int j = idx[i];
                // 不能超过vector大小
                if(j + 1 < n){
                    idx[i] ++;
                    if(st.find(idx) == st.end()){
                        st.insert(idx);
                        heap.push(make_pair(sum - mat[i][j] + mat[i][j + 1], idx));
                    }
                    idx[i]--;
                }
            }
        }
        // 此时最小值即为第k小
        return heap.top().first;
    }
};
// @lc code=end

