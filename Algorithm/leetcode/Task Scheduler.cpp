struct cmp{
  bool operator()(pair<int,int> p1, pair<int,int> p2){
      if(p1.first!=p2.first){
          return p1.first > p2.first;
      }
      else return p1.second < p2.second;
  }  
};

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char,int> m;
        for(auto c : tasks){
            m[c]++;
        }
        priority_queue< pair<int,int>, vector< pair<int,int> >, cmp> pq;
        for(auto it=m.begin();it!=m.end();it++){
            pq.push({0,it->second});
        }
        int ans=0;
        while(!pq.empty()){
            pair<int,int> cur = pq.top();
            pq.pop();
            if(cur.first>ans){
                ans = cur.first;    
            }
            cur.first += (n+1);
            cur.second--;
            if(cur.second){
                pq.push(cur);
            }
            ans++;
        }
        return ans;
    }
};
