class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        
        unordered_map<char, vector<char>> adj;
        unordered_map<char, int> indeg;
        for (auto &word : words)
            for (char c : word)
                indeg[c] = 0;

        for(int i = 0; i < words.size() - 1; i++) {
            string first_word = words[i];
            string second_word = words[i+1];

            int x = 0;
            bool flag = false;

            while(x < first_word.size() && x < second_word.size()) {
                if(first_word[x] != second_word[x]){
                    adj[first_word[x]].push_back(second_word[x]);
                    indeg[second_word[x]]++;
                    flag = true;
                    break;
                }

                x++;
            }

            if(!flag && first_word.size() > second_word.size()) return "";
        }

        queue<char> q;
        for (auto& [c, d] : indeg)
            if (d == 0) q.push(c);

        string order = "";
        while(!q.empty()) {
            auto v = q.front(); q.pop();
            order += v;
            for(auto &u : adj[v]) {
                if(--indeg[u] == 0) {
                    q.push(u);
                }
            }
        }

        return (order.size() == adj.size()) ? order : "";
    }
};
