    class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            unordered_map<string,vector<string>>mp;
            int n = strs.size();
            vector<vector<string>>ans;
           

            for(int i=0;i<n;i++){
                vector<int>freq(26,0);
                 string key = "";

                // Calculating the freq of each str
                for(char c : strs[i]){
                    freq[c-'a']++;
                }
                // As we can't directly store the vector array as the key in the map 
                // so need to convert the vector freq into the string then stored in the hashmap as key
                // freq = [1,0,0,0,1,0,...,1]  ->  key = "1#0#0#0#1#0#0#...#1#"
                for (int a:freq){
                    key+=to_string(a)+"#";
                }
                mp[key].push_back(strs[i]);
            }

            for(auto it :mp){
                ans.push_back(it.second);
            }

            return ans;

        }
    };