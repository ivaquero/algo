/*
 * @lc app=leetcode.cn id=70 lang=cpp
 * @lcpr version=30204
 *
 * [70] 爬楼梯
 */

// @lcpr-template-start
#include <vector>
using namespace std;

// @lcpr-template-end
// @lc code=start
class Solution {
public:
  auto climbStairs(int n) -> int {
    // base case
    if (n == 1 || n == 2)
      return n;
    // recursion
    vector<int> dps(n + 1);
    dps[1] = 1;
    dps[2] = 2;
    for (int i = 3; i <= n; i++) {
      dps[i] = dps[i - 1] + dps[i - 2];
    }
    return dps[n];
  }
};
// @lc code=end

/*
// @lcpr case=start
// 2\n
// @lcpr case=end

// @lcpr case=start
// 3\n
// @lcpr case=end

 */
