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
};