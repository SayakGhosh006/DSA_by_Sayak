class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> pos;
        
        ListNode* prev = head;
        ListNode* curr = head->next;
        
        int index = 1;
        
        while(curr->next != nullptr) {
            ListNode* next = curr->next;
            
            if((prev->val < curr->val && curr->val > next->val) ||
               (prev->val > curr->val && curr->val < next->val)) {
                pos.push_back(index);
            }
            
            prev = curr;
            curr = next;
            index++;
        }
        
        if(pos.size() < 2)
            return {-1, -1};
        
        int mini = INT_MAX;
        
        for(int i = 1; i < pos.size(); i++) {
            mini = min(mini, pos[i] - pos[i-1]);
        }
        
        int maxi = pos.back() - pos.front();
        
        return {mini, maxi};
    }
};