class Solution {
public:
    string minWindow(string s, string t) {
        if(s.length()<t.length()) return "";
        
        map<char,int> counter;
        for(auto str : t){
            counter[str]++;
        }
        int min_len = 9876543;
        int min_idx=0;
        int cnt=t.length();
        int left(0),right(0);
        
        while(right<=s.length()){
            if(counter[s[right]]>0) cnt--;
            counter[s[right]]--;
            right++;
            
            while(cnt==0){
                if(min_len > right-left){
                    min_idx = left;
                    min_len = right-left;
                }
                if(counter[s[left]]>=0) cnt++;
                counter[s[left]]++;
                left++;
            }
        }
        
        return min_len < 9876543 ? s.substr(min_idx,min_len) : "";
    }
};
