#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    stack<char> stack;
    string input;

    cin >> noskipws >> input;

    int n = 0;

    for (char &c : input)
    {
        // Do nothing if no character to delete
        if (c == '<' && n > 0)
        {
            stack.pop();
            n--;
        }
        else
        {
            stack.push(c);
            n++;
        }
    }

    char *res = (char *)malloc(n + 1);

    if (n > 0)
    {
        res[n] = '\n'; // alternatively << endl

        while (!stack.empty())
        {
            res[--n] = stack.top();
            stack.pop();
        }

        cout << res;
    }

    free(res);

    return 0;
}