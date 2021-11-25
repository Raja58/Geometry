// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        25 Nov 2021
//  @Detail  :        Max Points on a Line (LeetCode)
//  ============================
//  -->

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        map<vector<int>, int> cache;
        int result = 1, n = points.size();
        for(int i = 0; i < n - 1; i++)
        {
            int maxi = 0, same = 1;
            for(int j = i + 1; j < n; j++)
            {
                int y = points[j][1] - points[i][1], x = points[j][0] - points[i][0];
                if(x == 0 && y == 0)
                {
                    same++;
                    continue;
                }
                
                int gcd = __gcd(x, y);
                int a = x / gcd, b = y / gcd;
                if(x < 0)
                {
                    x *= -1;
                    y *= -1;
                }
                
                cache[{a, b}]++;
                if(maxi < cache[{a, b}])
                    maxi = cache[{a, b}];
            }
            maxi += same;
            if(result < maxi)
                result = maxi;
            if(result > n / 2)
                return result;
            cache.clear();
        }
        return result;
    }
};
