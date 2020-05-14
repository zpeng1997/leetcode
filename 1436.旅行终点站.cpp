/*
 * @lc app=leetcode.cn id=1436 lang=cpp
 *
 * [1436] 旅行终点站
 *
 * https://leetcode-cn.com/problems/destination-city/description/
 *
 * algorithms
 * Easy (81.18%)
 * Likes:    2
 * Dislikes: 0
 * Total Accepted:    3.9K
 * Total Submissions: 4.7K
 * Testcase Example:  '[["London","New York"],["New York","Lima"],["Lima","Sao Paulo"]]'
 *
 * 给你一份旅游线路图，该线路图中的旅行线路用数组 paths 表示，其中 paths[i] = [cityAi, cityBi] 表示该线路将会从
 * cityAi 直接前往 cityBi 。请你找出这次旅行的终点站，即没有任何可以通往其他城市的线路的城市。
 * 
 * 题目数据保证线路图会形成一条不存在循环的线路，因此只会有一个旅行终点站。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：paths = [["London","New York"],["New York","Lima"],["Lima","Sao Paulo"]]
 * 输出："Sao Paulo" 
 * 解释：从 "London" 出发，最后抵达终点站 "Sao Paulo" 。本次旅行的路线是 "London" -> "New York" ->
 * "Lima" -> "Sao Paulo" 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：paths = [["B","C"],["D","B"],["C","A"]]
 * 输出："A"
 * 解释：所有可能的线路是：
 * "D" -> "B" -> "C" -> "A". 
 * "B" -> "C" -> "A". 
 * "C" -> "A". 
 * "A". 
 * 显然，旅行终点站是 "A" 。
 * 
 * 
 * 示例 3：
 * 
 * 输入：paths = [["A","Z"]]
 * 输出："Z"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= paths.length <= 100
 * paths[i].length == 2
 * 1 <= cityAi.length, cityBi.length <= 10
 * cityAi != cityBi
 * 所有字符串均由大小写英文字母和空格字符组成。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        // 拓扑排序
        map<string, int> hash;
        map<string, string> ha;
        for(auto path : paths){
            hash[path[0]] = 0;
            
            if(hash.find(path[1]) != hash.end()){
                hash[path[1]] += 1;
            }
            
            ha[path[0]] = path[1];
        }
        
        string res;
        for(auto it = hash.begin(); it != hash.end(); it ++){
            if(it->second == 0){
                res = it->first;
                break;
            }
        }
        
        
        while(ha.find(res) != ha.end()){
            
            res = ha.find(res)->second;
        
        }
        
        return res;
    }
};
// @lc code=end

