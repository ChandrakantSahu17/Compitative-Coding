#include <bits/stdc++.h>
using namespace std;

void nextArr(string needle, int *next)
{
    int j = 0;

    next[0] = 0;

    for (int i = 1; needle[i] != '\0'; i++)
    {
        while (needle[i] != needle[j] && j > 0)
        {
            j = next[j - 1];
        }

        if (needle[i] == needle[j])
        {
            j++;
        }
        next[i] = j;
    }
}

int strStr(string haystack, string needle)
{
    //KMP Algirithm
    if (needle.size() == 0)
        return 0;

    int size = needle.size();
    int next[size];
    nextArr(needle, next);
    int j = 0;

    for (int i = 0; i < haystack.size(); i++)
    {
        while (haystack[i] != needle[j] && j > 0)
        {
            j = next[j - 1];
        }

        if (haystack[i] == needle[j])
        {
            j++;
        }

        if (j == needle.size())
        {
            return i - needle.size() + 1;
        }
    }

    return -1;
}

int main()
{
    string H = "Hello";
    string N = "ll";
    int x = strStr(H, N);
    cout << x;
}