class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string> > anagram;
        vector<vector<string> > result;
        for (int i = 0; i < strs.size(); i++) {
            string str = strs[i];
            sort(str.begin(), str.end());
            if (anagram.find(str) == anagram.end()) {
                vector<string> item;
                anagram[str] = item;
            }
            anagram[str].push_back(strs[i]);
        }
        
        map<string, vector<string> >::iterator it;
        for (it = anagram.begin(); it != anagram.end(); it++) {
            result.push_back((*it).second);
        }
        return result;
    }
};