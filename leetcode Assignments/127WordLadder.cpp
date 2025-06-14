class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> wordS(wordList.begin(), wordList.end());
        if(wordS.find(endWord) == wordS.end()) return 0;
        int l = 1;
        queue<string> q;
        q.push(beginWord);
        while(!q.empty()){
            int s = q.size();
            int i = 0;
            while(i < s){
                string w = q.front();
                q.pop();
                if(w ==  endWord) return l;
                
                for(int k = 0; k <w.length(); k++){
                    char ch = w[k];
                    for( int l = 0; l < 26; l++){
                        w[k] = 'a' + l;
                        if(wordS.find(w) != wordS.end()){
                            q.push(w);
                            wordS.erase(w);
                        } 
                    }
                    w[k] = ch;
                }


               
                i++;
            }
            l++;
        }
        return 0;
    }
};