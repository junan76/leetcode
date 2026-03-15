#include <string>
#include <list>

using std::list;
using std::string;

class Solution
{
public:
    bool isValid(string s)
    {
        list<char> stack;

        for (int i = 0; i < s.size(); i++)
        {
            switch (s[i])
            {
            case '(':
            case '[':
            case '{':
                stack.push_back(s[i]);
                break;
            case ')':
            case ']':
            case '}':
                if (i == 0)
                    return false;
                else if (stack.back() == left_of(s[i]))
                    stack.pop_back();
                else
                    stack.push_back(s[i]);
                break;
            default:
                return false;
            }
        }

        return stack.size() == 0;
    }

private:
    char left_of(const char right)
    {
        switch (right)
        {
        case ')':
            return '(';
        case ']':
            return '[';
        case '}':
            return '{';
        default:
            return 0;
        }
    }
};