
class Solution {
public:
    std::vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> result(k, 0);
        vector<long long> previousRemainderCount(k, 0);

        for (int num : nums) {
            vector<long long> currentRemainderCount(k, 0);

            // Note: If nums can contain negative values, use: (num % k + k) % k
            int numRemainder = num % k;
            currentRemainderCount[numRemainder]++;

            for (int oldRemainder = 0; oldRemainder < k; oldRemainder++) {
                int newRemainder = (oldRemainder * numRemainder) % k;
                currentRemainderCount[newRemainder] += previousRemainderCount[oldRemainder];
            }

            previousRemainderCount = currentRemainderCount;

            for (int remainder = 0; remainder < k; remainder++) {
                result[remainder] += previousRemainderCount[remainder];
            }
        }

        return result;
    }
};