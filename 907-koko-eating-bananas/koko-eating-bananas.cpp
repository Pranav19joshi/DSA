class Solution {
public:
    int findMax(const vector<int>& piles) {
        int maxVal = piles[0];
        for (int num : piles) {
            if (num > maxVal) maxVal = num;
        }
        return maxVal;
    }

    long long eat(const vector<int>& piles, long long k) {
        long long hours = 0;
        for (long long bananas : piles) {
            hours += (bananas + k - 1) / k;
        }
        return hours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long low = 1;                    
        long long high = findMax(piles);       
        long long ans = high;                 

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long hours = eat(piles, mid);

            if (hours <= h) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return (int)ans;
    }
};