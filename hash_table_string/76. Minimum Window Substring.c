class Solution {
private:
    bool is_window_ok(int map_s[], int map_t[], vector<int> &vec_t) {
        for (int i = 0; i < vec_t.size(); i++) {
            if (map_s[vec_t[i]] < map_t[vec_t[i]]) {
                return false;
            }
        }
        return true;
    }
public:
    string minWindow(string s, string t) {
        int map_t[128] = {0};
        int map_s[128] = {0};
        vector<int> vec_t;
        
        for (int i = 0; i < t.length(); i++) {
            map_t[t[i]]++;
        }
        
        for (int i = 0; i < 128; i++) {
            if (map_t[i] > 0) {
                vec_t.push_back(i);
            }
        }
        
        int window_begin = 0;
        string result;
        
        for (int i = 0; i < s.length(); i++) {
            map_s[s[i]]++;
            while(window_begin < i) {
                char begin_ch = s[window_begin];
                if (map_t[begin_ch] == 0) {
                    window_begin++;
                }
                else if (map_s[begin_ch] > map_t[begin_ch]) {
                    map_s[begin_ch]--;
                    window_begin++;
                }
                else {
                    break;
                }
            }
            
            if (is_window_ok(map_s, map_t, vec_t)) {
                int new_window_len = i - window_begin + 1;
                if (result.length() > new_window_len || result == "") {
                    result = s.substr(window_begin, new_window_len);
                }
            }
        }
        
        return result;
    }
};