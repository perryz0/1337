class Solution {
public:
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        unordered_map<string,int> mp;
        string whole;
        for(const string& c : chunks) whole+=c;

        // cout << whole << endl;

        string cur;
        bool prevSeen=false;
        for(const char& c : whole){
            if(cur.empty() && c=='-')continue;
            
            //commit to a word if we see these
            if(c == ' ' || (prevSeen && c == '-')){
                //commit
                // cout << "cur char: " << c << ", committed: " << cur << ", prevSeen: " << prevSeen << endl;
                if(prevSeen)cur.pop_back();
                prevSeen=false;//reset
                mp[cur]++;
                cur.clear();
            } 
            else if(c == '-'){
                // cout << "cur char: " << c << ", prevSeen is set!" << endl;
                prevSeen=true;
                cur+='-';
            }
            else{
                // if(prevSeen){
                //     cur.pop_back();
                //     prevSeen=false;
                // }
                prevSeen=false;
                // prevSeen=false;
                cur += c;// add this char to the curr substring
            }
        }

        if(!cur.empty()) {
            if(prevSeen) cur.pop_back();
            mp[cur]++;//last word not added
        }

        vector<int> ans;
        for(const string& q : queries) {
            ans.push_back(mp[q]);
        }
        return ans;
    }
};