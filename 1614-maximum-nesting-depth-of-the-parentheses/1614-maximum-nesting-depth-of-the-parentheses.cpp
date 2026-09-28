class Solution {
public:
    int maxDepth(string s) {
        int depth = 0;
        int res = 0;

        for(char c : s) {
            if(c == '(') {
                depth++;
            }
            else if(c == ')') {
                depth--;
            }

            res = max(res, depth);
        }

        return res;
    }
};