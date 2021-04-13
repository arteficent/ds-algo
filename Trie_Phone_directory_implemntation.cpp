// Problem Statement https://practice.geeksforgeeks.org/problems/phone-directory4628/1



#include <bits/stdc++.h>
using namespace std;

class trie //create trie
{
public:
    char c = '*';
    bool last = false;
    map<char, trie *> m;
};
trie *head = new trie;
void insert(string s)
{
    trie *temp = head;
    for (int i = 0; i < s.length(); i++)
    {
        if (!temp->m.count(s[i]))
        {
            trie *temp2 = new trie;
            temp2->c = s[i];
            temp->m[s[i]] = temp2;
            temp->last = false;
            temp2->last = false;
            temp = temp2;
        }
        else
        {
            temp->last = false;
            temp = temp->m[s[i]];
        }
    }
    temp->last = true;
}
void print(trie *temp, string local)
{
    if (temp->last == true)
    {
        cout << local << " ";
        return;
    }
    for (auto it : temp->m)
    {
        local.push_back(it.first);
        print(it.second, local);
    }
    return;
}
void check(string local)
{
    trie *temp = head;
    if (!temp->m.count(local[0]))
    {
        cout << 0;
        return;
    }
    else
    {
        int i = 0;
        while (i < local.length() && temp->last == false)
        {
            if (!temp->m.count(local[i]) || temp->last)
            {
                cout << 0;
                return;
            }
            else
            {
                temp = temp->m[local[i]];
                i++;
            }
        }
        print(temp, local);
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << "enter the number of the contact list =" << endl;
    int n;
    cin >> n;
    cout << "enter the contact list = " << endl;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        insert(s);
    }
    string s, local;
    cout << "enter the query string = " << endl;
    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        local.push_back(s[i]);
        check(local);
        cout << endl;
    }
    return 0;
}
