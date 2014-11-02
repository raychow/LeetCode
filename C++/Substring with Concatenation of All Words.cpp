class Solution
{
public:
    vector<int> findSubstring(string S, vector<string> &L)
    {
        map<string, int> expectedWords;
        for (auto &str : L)
        {
            ++expectedWords[str];
        }
        size_t wordSize = L.front().size();
        size_t wordsSize = L.size() * wordSize;
        size_t iEnd = S.size() - wordsSize;
        vector<int> result;
        for (size_t i = 0; i < wordSize; ++i)
        {
            map<string, int> currentWords;
            int currentWordCount = 0;
            int start = i;
            for (size_t j = i; j < S.size(); j += wordSize)
            {
                auto word = S.substr(j, wordSize);
                if (!expectedWords.count(word) || !expectedWords[word])
                {
                    currentWords.clear();
                    currentWordCount = 0;
                    start = j + wordSize;
                    continue;
                }
                if (currentWords[word] >= expectedWords[word])
                {
                    auto prevWord = S.substr(start, wordSize);
                    while (prevWord != word)
                    {
                        --currentWords[prevWord];
                        --currentWordCount;
                        start += wordSize;
                        prevWord = S.substr(start, wordSize);
                    }
                    start += wordSize;
                }
                else
                {
                    ++currentWords[word];
                    ++currentWordCount;
                }
                if (currentWordCount == L.size())
                {
                    result.push_back(start);
                    auto firstWord = S.substr(start, wordSize);
                    --currentWords[firstWord];
                    --currentWordCount;
                    start += wordSize;
                }
            }
        }
        return result;
    }
};
