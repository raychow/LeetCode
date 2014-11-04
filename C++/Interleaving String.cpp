class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        if (s1.size() + s2.size() != s3.size())
        {
            return false;
        }
        vector<vector<bool>> matrix(s2.size() + 1, vector<bool>(s1.size() + 1));
        matrix[0][0] = true;
        for (int i = 1; i <= s1.size(); ++i)
        {
            matrix[0][i] = matrix[0][i - 1] && s1[i - 1] == s3[i - 1];
        }
        for (int i = 1; i <= s2.size(); ++i)
        {
            matrix[i][0] = matrix[i - 1][0] && s2[i - 1] == s3[i - 1];
        }
        for (int i = 1; i <= s2.size(); ++i)
        {
            for (int j = 1; j <= s1.size(); ++j)
            {
                if (matrix[i - 1][j])
                {
                    matrix[i][j] = s2[i - 1] == s3[i + j - 1];
                }
                else if (matrix[i][j - 1])
                {
                    matrix[i][j] = s1[j - 1] == s3[i + j - 1];
                }
            }
        }
        return matrix[s2.size()][s1.size()];
    }
};
