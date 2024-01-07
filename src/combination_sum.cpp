#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> results;
        vector<int> combination;

        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, results, combination);

        return results;
    }

private:
    void dfs(vector<int> &candidates, int target, int start_index, vector<vector<int>> &results, vector<int> &combination)
    {
        if (target == 0)
        {
            results.push_back(combination);
            return;
        }
        else if (target < 0)
        {
            return;
        }

        for (int i = start_index; i < candidates.size(); i++)
        {
            target -= candidates[i];
            combination.push_back(candidates[i]);
            dfs(candidates, target, i, results, combination);
            combination.pop_back();
            target += candidates[i];
        }
    }
};