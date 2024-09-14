#include <iostream>
#include <stack>

using namespace std;

bool checkParenthesis(string input)
{
    stack<char> s;
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] == ' ')
        {
            i++;
        }
        else if (input[i] == '(' || input[i] == '[' || input[i] == '{')
            s.push(input[i]);
        else if (input[i] == ')' || input[i] == ']' || input[i] == '}')
        {
            if (s.empty())
                return false;
            else if (input[i] == ')' && s.top() != '(')
                return false;
            else if (input[i] == ']' && s.top() != '[')
                return false;
            else if (input[i] == '}' && s.top() != '{')
                return false;
            else
                s.pop();
        }
    }
    if (s.empty())
        return true;
    else
        return false;
}

int main()
{
    int testCases;
    cin >> testCases;

    for (int i = 0; i < testCases; i++)
    {
        string input;
        cin >> input;
        if (checkParenthesis(input))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}
