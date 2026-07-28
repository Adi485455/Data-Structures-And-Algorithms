class Solution {
public:
    string smallestPalindrome(string s) {
       if (s.size()==1) return s;
       vector<int>freq(26,0);

       for(char c :s){
        freq[c-'a']++;
       } 
       string FP = "";
       string MP = "";
    
       for(int i=0;i<26;i++){
        FP += string(freq[i]/2,i+'a');
        if(freq[i]%2 == 1){
            MP+=(i+'a');
        }
       }
       string LP = FP;
       reverse(LP.begin(),LP.end());
       return FP+MP+LP;
    }
};