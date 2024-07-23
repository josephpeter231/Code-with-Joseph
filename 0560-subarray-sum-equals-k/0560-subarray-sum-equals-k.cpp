#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSumCount;
        prefixSumCount[0] = 1; 
        int cnt = 0, sum = 0;
        for (int num : nums) {
            sum += num;
            if (prefixSumCount.find(sum - k) != prefixSumCount.end()) {
                cnt += prefixSumCount[sum - k];
            }
            prefixSumCount[sum]++;
        }
        return cnt;
    }
};