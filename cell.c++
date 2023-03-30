#include "cell.h"
#include <iostream>

void Cell::setChromosome(int chromosomes)
{
    vector<Genome>Chromosomes{vector<Genome>(chromosomes)};
}

Genome Cell::getChromosome(int n)
{
    return Chromosomes[n];
}

bool Cell::CellDeath()
{
    for (Genome chromosome : Chromosomes)
    {
        int n;
        int AT, CG = 0;
        string DNAFirstStr = chromosome.getDNAFirst();
        string DNASecondStr = chromosome.getDNASeconds();

        for (int i=0; i<DNAFirstStr.size();i++)
        {
            if (DNASecondStr[i] != GivePair(DNAFirstStr[i]))
            {
                n++;
            }
        }

        for (int i=0; i<DNAFirstStr.size();i++)
        {
            if (DNASecondStr[i] == 'A' && DNASecondStr[i] == 'T')
            {
                AT++;
            }
            else if (DNASecondStr[i] == 'T' && DNASecondStr[i] == 'A')
            {
                AT++;
            }
            else if (DNASecondStr[i] == 'C' && DNASecondStr[i] == 'G')
            {
                CG++;
            }
            else if (DNASecondStr[i] == 'G' && DNASecondStr[i] == 'C')
            {
                CG++;
            }
        }

        if ((AT > CG * 3) || (n > 5))
        {
            return true;
        }
        else
        {
            return false;
        }

    }
}