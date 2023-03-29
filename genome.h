#pragma once
#include <vector>
#include <string>

using namespace std;

class Genome
{
private:
    vector<char> RNA;
    pair<vector<char>, vector<char> > DNA;

public:
    void setRNA(string rna);
    void setDNA(string dna);
    void MakeDNABasedOnRNA();

    void SmallMutationRNA(char ch1, char ch2, int n);
    void BigMutationRNA(string str1, string str2);

    void SmallMutationDNA(char ch1, char ch2, int n);
    void BigMutationDNA(string str1, string str2);
    void ReverseMutationRNA(string str1);
    void ReverseMutationDNA(string str1);

};
