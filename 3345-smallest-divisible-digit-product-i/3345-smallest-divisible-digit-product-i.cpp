class Solution {
public:
    int smallestNumber(int n, int t) {
        while (true) {
            int x = n;
            int prod = 1;

            while (x > 0) {
                int digit = x % 10;

                if (digit == 0) {
                    prod = 0;
                    break;
                }

                prod *= digit;
                x /= 10;
            }

            if (prod % t == 0)
                return n;

            n++;
        }
    }
};