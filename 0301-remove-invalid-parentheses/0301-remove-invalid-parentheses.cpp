class Solution {
public:

    bool isValid(string s) {
        int count = 0;

        for (char ch : s) {
            if (ch == '(') {
                count++;
            }
            else if (ch == ')') {
                count--;

                if (count < 0)
                    return false;
            }
        }

        return count == 0;
    }

    vector<string> removeInvalidParentheses(string s) {

        vector<string> vec;
        queue<string> q;
        set<string> visited;

        q.push(s);
        visited.insert(s);

        bool found = false;

        while (!q.empty()) {

            int size = q.size();

            for (int i = 0; i < size; i++) {

                string current = q.front();
                q.pop();

                if (isValid(current)) {
                    vec.push_back(current);
                    found = true;
                }

                if (found)
                    continue;

                for (int j = 0; j < current.length(); j++) {

                    char ch = current[j];

                    if (ch != '(' && ch != ')')
                        continue;

                    string next =
                        current.substr(0, j) +
                        current.substr(j + 1);

                    if (visited.find(next) == visited.end()) {
                        visited.insert(next);
                        q.push(next);
                    }
                }
            }

            if (found)
                break;
        }

        return vec;
    }
};