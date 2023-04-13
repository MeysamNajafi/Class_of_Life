#include "utils.h"

char GivePair(char Nucleotide)
{
    // output the pair of Nucleotide
    switch (Nucleotide)
    {
    case 'T':
        return 'A';
    case 'A':
        return 'T';
    case 'C':
        return 'G';
    case 'G':
        return 'C';
    }
}

bool isPalindrome(string s)
{
    int n = s.length();
    for (int i = 0; i < n / 2; i++)
    {
        if (s[i] != GivePair(s[ n - i -1 ]))
        {
            return false;
        }
    }
    return true;
}

string LCSubstr(string x, string y){
    int m = x.length(), n=y.length();

    int LCSuff[m][n];

    for(int j=0; j<=n; j++)
        LCSuff[0][j] = 0;
    for(int i=0; i<=m; i++)
        LCSuff[i][0] = 0;

    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(x[i-1] == y[j-1])
                LCSuff[i][j] = LCSuff[i-1][j-1] + 1;
            else
                LCSuff[i][j] = 0;
        }
    }

    string longest = "";
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(LCSuff[i][j] > longest.length())
                longest = x.substr((i-LCSuff[i][j]+1) -1, LCSuff[i][j]);
        }
    }
    return longest;
}

bool isUniqueVal(const vector<int> &exclude, int test_val)
{
  for (int i = 0; i < exclude.size(); ++i)
    if (test_val == exclude[i]) 
        return false;
  return true;
}