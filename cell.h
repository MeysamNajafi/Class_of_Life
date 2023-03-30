#pragma once
#include "genome.cpp"
#include <vector>


using namespace std;

class Cell
{
    private:
        vector<Genome> Chromosomes;
    public:
        void setChromosome(int chromosomes);
        Genome getChromosome(int n);

        bool CellDeath();
};