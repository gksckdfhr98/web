class Solution {
public:
    string repeat(int num,string str){
        string res="";
        for(int i=0;i<num;i++){
            res+=str;
        }
        return res;
    }
    
    string decodeString(string s) {
        int i=0;
        while(i<s.size()){
            if(s[i]!=']'){
                i++;
                continue;
            }
            int j=i;
            while(s[j]!='[') j--;
            string repeat_str = s.substr(j+1,i-j-1);
            
            int k=j;
            j--;
            while(j>0 && isdigit(s[j])) j--;
            if(j!=0) j++;
            int repeat_num = stoi(s.substr(j,k-j));
            s.replace(j,i-j+1,repeat(repeat_num,repeat_str));
            i = j + repeat_num*repeat_str.size();
        }
        return s;
        
    }
};
