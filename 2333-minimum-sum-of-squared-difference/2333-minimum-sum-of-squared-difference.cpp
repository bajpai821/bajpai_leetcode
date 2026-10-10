class Solution {
public:
    long long minSumSquareDiff(std::vector<int>& nums1, std::vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        std::vector<int> diff(n);
        long long total_diff_sum = 0;
        int max_diff = 0;
        long long k = (long long)k1 + k2;

        // Calculate absolute differences and track metadata
        for (int i = 0; i < n; ++i) {
            diff[i] = std::abs(nums1[i] - nums2[i]);
            total_diff_sum += diff[i];
            max_diff = std::max(max_diff, diff[i]);
        }

        // If total operations can reduce all differences to 0
        if (total_diff_sum <= k) {
            return 0;
        }

        // Binary search to find the target upper limit for differences
        int left = 0, right = max_diff;
        int target_ceiling = max_diff;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            long long operations_needed = 0;
            
            for (int d : diff) {
                if (d > mid) {
                    operations_needed += (d - mid);
                }
            }

            if (operations_needed <= k) {
                target_ceiling = mid; // mid is achievable, try to go lower
                right = mid - 1;
            } else {
                left = mid + 1; // mid is too low, need a higher ceiling
            }
        }

        // Apply operations to bring down elements above target_ceiling
        for (int i = 0; i < n; ++i) {
            if (diff[i] > target_ceiling) {
                k -= (diff[i] - target_ceiling);
                diff[i] = target_ceiling;
            }
        }

        // Distribute remaining operations among elements at the target_ceiling
        for (int i = 0; i < n && k > 0; ++i) {
            if (diff[i] == target_ceiling) {
                diff[i]--;
                k--;
            }
        }

        // Calculate the final minimum sum of squared differences
        long long min_squared_sum = 0;
        for (int d : diff) {
            min_squared_sum += (long long)d * d;
        }

        return min_squared_sum;
    }
};