// @lc code=start
class Solution {
public: 
    // Solution 1: O(n^3)
    // int countTriplets(vector<int>& arr) {
    //     if(arr.empty()) return 0;
        
    //     vector<int> sum(arr.size() + 1, 0);
    //     for(int i = 0; i < arr.size(); i ++)
    //     {
    //        sum[i + 1] = sum[i] ^ arr[i];
    //     }
        
    //     int res;
    //     for(int k = 2; k <= arr.size(); k ++)
    //         for(int l = 1; l + k - 1 <= arr.size(); l ++)
    //         {
    //             int r = l + k - 1;
    //             for(int m = l + 1; m <= r; m ++)
    //             {
    //                if(sum[m - 1] ^ sum[l - 1] == sum[r] ^ sum[m - 1]){
    //                     res ++;
    //                 }
    //             }    
    //         }
        
    //     return res;
    // }

    // Solution 2: O(n^2) 哈希 + 前缀和
    // int countTriplets(vector<int>& arr){
    //     int n = arr.size();
    //     vector<int> s(n + 1)        ;
    //     s[0] = 0;

    //     for(int i = 1; i <= n; i ++)
    //         s[i] = s[i - 1] ^ arr[i - 1];

    //     vector<unordered_map<int,int>> hash(n + 1);

    //     for(int j = 1; j <= n; j ++)
    //         for(int i = 1; i <= j; j ++)
    //             hash[j][s[j] ^ s[i - 1]] ++;
        
    //     int res = 0;
    //     for(int k = 1; k <= n; k ++)
    //         for(int j = 1; j <= k; j ++)
    //             res += hash[j - 1][s[j - 1] ^ s[k]];

    //     return res;
    // }

    //Solution 3: 
    int countTriplets(vector<int>& arr){
        
        
        return res;
    }

    //Solution 4: 
    int countTriplets(vector<int>& arr){
        
        
        return res;
    }
};
// @lc code=end