class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(), wordList.end());
        if (s.find(endWord) == s.end()) return 0;

        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        s.erase(beginWord);

        while (!q.empty()) {
            string w = q.front().first;
            int l = q.front().second;
            q.pop();

            for (int i = 0; i < w.length(); i++) {
                char original = w[i];
                for (char j = 'a'; j <= 'z'; j++) {
                    if (j == original) continue;

                    w[i] = j;
                    if (w == endWord) return l + 1;

                    if (s.find(w) != s.end()) {
                        q.push({w, l + 1});
                        s.erase(w);
                    }
                }
                w[i] = original; 
            }
        }

        return 0;  
    }
};
