class Solution
{
public:
    vector<string> restoreIpAddresses(string s)
    {
        if (s.size() < 4)
        {
            return vector<string>();
        }
        vector<string> result;
        for (size_t i = 1; i <= 3 && i < s.size() - 2; ++i)
        {
            string ip1 = s.substr(0, i);
            if (!__isValid(ip1))
            {
                break;
            }
            for (size_t j = i + 1; j - i <= 3 && j < s.size() - 1; ++j)
            {
                string ip2 = s.substr(i, j - i);
                if (!__isValid(ip2))
                {
                    break;
                }
                for (size_t k = j + 1; k - j <= 3 && k < s.size(); ++k)
                {
                    if (s.size() - k > 3)
                    {
                        continue;
                    }
                    string ip3 = s.substr(j, k - j);
                    string ip4 = s.substr(k);
                    if (!__isValid(ip3))
                    {
                        break;
                    }
                    if (!__isValid(ip4))
                    {
                        continue;
                    }
                    result.push_back(ip1 + "." + ip2 + "." + ip3 + "." + ip4);
                }
            }
        }
        return result;
    }

private:
    bool __isValid(const string &s)
    {
        return !(s.size() > 1 && '0' == s[0] || stoi(s) > 255);
    }
};
