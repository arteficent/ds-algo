//Problem https://www.geeksforgeeks.org/trie-insert-and-search/

#include <bits/stdc++.h>
using namespace std;

class trie          //create trie
{
public:
    char c = '*';
    bool last = false;
    map<char, trie *> m;
};

trie *head = new trie;      //initial pointer

void insert(string s)           //To insert string in trie
{
    trie *temp = head;

    for (int i = 0; i < s.length(); i++)
    {
        if (!temp->m.count(s[i]))
        {
            trie *temp2 = new trie;
            temp2->c = s[i];
            temp->last = false;
            temp2->last = false;
            temp->m[s[i]] = temp2;
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

bool check(string s)            //To check string in the trie
{
    trie *temp = head;
    int i = 0;
    while (i < s.length() && temp->last == false)
    {
        cout << i << temp->c << endl;
        if (!temp->m.count(s[i]) || temp->last)
        {
            return false;
        }
        else
        {
            temp = temp->m[s[i]];
            i++;
        }
    }
    cout << i << temp->c << endl;
    return true;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n; //Number of words to insert in trie
    for (int i = 0; i < n; i++)
    {
        string local;
        cin >> local;
        insert(local);
    }
    string s;
    cin >> s; //The string you want to check
    cout << check(s);
    return 0;
}
