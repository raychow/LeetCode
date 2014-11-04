class Solution
{
public:
    string simplifyPath(string path)
    {
        vector<string> pathPart;
        size_t partStart = 0;
        size_t partEnd = 0;
        do
        {
            partEnd = path.find('/', partStart);
            if (partStart != partEnd)
            {
                string part = path.substr(partStart,
                    string::npos == partEnd ? partEnd : partEnd - partStart);
                if (part.empty() || "." == part)
                {
                    // Nothing.
                }
                else if (".." == part)
                {
                    if (!pathPart.empty())
                    {
                        pathPart.pop_back();
                    }
                }
                else
                {
                    pathPart.push_back(part);
                }
            }
            partStart = partEnd + 1;
        } while (string::npos != partEnd);
        if (pathPart.empty())
        {
            return "/";
        }
        stringstream ss;
        for (const string &s : pathPart)
        {
            ss << '/' << s;
        }
        return ss.str();
    }
};
