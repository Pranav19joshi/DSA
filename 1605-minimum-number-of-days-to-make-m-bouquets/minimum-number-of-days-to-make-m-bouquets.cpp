class Solution {
public:
    bool canMake(const vector<int>& bloomDay, int m, int k, int day) {
        int bouquets = 0;
        int flowers = 0;
        for (int bloom : bloomDay) {
            if (bloom <= day) flowers++;
            else flowers = 0;
            if (flowers == k) { bouquets++; flowers = 0; }
        }
        return bouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long n = bloomDay.size();
        if ((long long)m * k > n) return -1;

        int low = INT_MAX, high = INT_MIN;
        for (int bloom : bloomDay) {
            low = min(low, bloom);
            high = max(high, bloom);
        }

        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canMake(bloomDay, m, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};