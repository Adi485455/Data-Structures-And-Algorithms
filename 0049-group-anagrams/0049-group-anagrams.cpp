class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        int n = strs.size();
       
        for(int i =0;i<n;i++){
            vector<int>freq(26,0);
            for(char c :strs[i]){
                freq[c-'a']++;
            }
            // Converting the frequency vector into the key

            // First we define the string key

            string key = "";

            // Now iterate throgh the vector and convert the element of the frequency vector into the string and add it to the string key with the addition of the '#'

            // So key be like '1#0#0#1#0#.....'

            for(int j =0;j<26;j++){
                key+=to_string(freq[j])+'#';
            }

            // then in the map we gonna push the that strings 
            // Imp point here if the both strings have the same key they strings gonna push at that same position so we gonna have the strings with the same keys at the same position

            mp[key].push_back(strs[i]);
            }
             vector<vector<string>>ans;

            // iterating the map and priting all the strings grp wise 
            // As the map gonna store it as the grp wise 

            for(auto &it :mp){
                ans.push_back(it.second);
        }
         return ans;
        
    }
};