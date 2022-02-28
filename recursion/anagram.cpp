#include <iostream>
#include <vector>
#include <string>

using namespace std;

int minSteps(string s, string t)
{
    vector<int> H(27, 0);
    vector<int> G(27, 0);

    for (int i = 0; i < s.length(); i++)
        H[s[i] - 'a']++;
    for (int i = 0; i < t.length(); i++)
        G[t[i] - 'a']++;
    int count = 0;
    for (int i = 0; i < 27; i++)
    {
        count += abs(H[i] - G[i]);
    }

    return count;
}

int main()
{
    string s, t;
    cin >> s >> t;

    cout << minSteps(s, t);

    return 0;
}