class Solution {
public:
    string reorganizeString(string str) {
          unordered_map<char,int>mp;
        for(auto i: str)mp[i]++;
        priority_queue<pair<int,char>>pq;
        for(auto it : mp){
            pq.push({it.second,it.first});
        }
        string res="";
        pair<int,char>prev={-1,'#'};
       while(!pq.empty()){
            auto k = pq.top();
            pq.pop();
            res = res + k.second;
            if (prev.first > 0)
                pq.push(prev);
            k.first--;
            prev = k;
            
        }
        cout<<res<<endl;
         if (str.length() != res.length())
            return "";
        else
            return res;
        
    }
};