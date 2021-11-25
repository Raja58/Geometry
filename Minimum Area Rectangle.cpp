// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        25 Nov 2021
//  @Detail  :        Minimum Area Rectangle (LeetCode)
//  ============================
//  -->

class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map<int, unordered_set<int>> cache;
        for(vector<int> &x : points)
            cache[x[0]].insert(x[1]);
        int n = points.size(), result = INT_MAX;
        for(int i = 0; i < n - 1; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                if(points[i][0] == points[j][0] || points[i][1] == points[j][1])
                    continue;
                int area = abs((points[i][0] - points[j][0])) * abs((points[i][1] - points[j][1]));
                if(result <= area)
                    continue;
                vector<int> a{points[i][0], points[j][1]}, b{points[j][0], points[i][1]};
                if(cache[a[0]].find(a[1]) == cache[a[0]].end() || cache[b[0]].find(b[1]) == cache[b[0]].end())
                    continue;
                result = area;
            }
        }
        return result != INT_MAX ? result : 0;
    }
};
