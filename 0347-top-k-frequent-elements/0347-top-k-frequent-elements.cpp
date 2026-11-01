
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        // -------- brute force -----------

        // count frequency of each element
        unordered_map<int, int> freq;

        for(int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }

        // store elements and their frequencies
        vector<pair<int, int>> arr;

        for(auto it : freq) {
            arr.push_back({it.first, it.second});
        }

        // sort according to frequency in descending order
        sort(arr.begin(), arr.end(), [](auto &a, auto &b) {
            return a.second > b.second;
        });

        // store the top k frequent elements
        vector<int> ans;

        for(int i = 0; i < k; i++) {
            ans.push_back(arr[i].first);
        }

        return ans;
    }
};
