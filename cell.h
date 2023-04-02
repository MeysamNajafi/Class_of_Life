#pragma once
#include "genome.h"
#include <vector>

using namespace std;

class Cell : public Genome
{
private:
    vector<Genome> Chromosomes;

public:
    void addChromosome(Genome genome);
    Genome getChromosome(int n);

    void CellDeath();

    void SmallMutationRNA(char ch1, char ch2, int n, int m);
    void BigMutationRNA(string str1, int n, string str2, int m);

    void SmallMutationDNA(char ch1, char ch2, int n, int m);
    void BigMutationDNA(string str1, int n, string str2, int m);

    void ReverseMutationRNA(string str1, int n);
    void ReverseMutationDNA(string str1, int n);

    
};