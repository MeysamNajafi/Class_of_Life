#include "cell.h"
#include <iostream>
#include "utils.h"

void Cell::addChromosome(Genome genome)
{
    Chromosomes.push_back(genome);
}

Genome Cell::getChromosome(int index)
{
    if (index + 1 <= Chromosomes.size())
        return Chromosomes[index];
}

void Cell::CellDeath()
{
    for (Genome chromosome : Chromosomes)
    {
        int n;
        int AT, CG = 0;
        string DNAFirstStr = chromosome.getDNAFirst();
        string DNASecondStr = chromosome.getDNASecond();

        for (int i = 0; i < DNAFirstStr.size(); i++)
        {
            if (DNASecondStr[i] != GivePair(DNAFirstStr[i]))
            {
                n++;
            }
        }

        for (int i = 0; i < DNAFirstStr.size(); i++)
        {
            if (DNASecondStr[i] == 'A' && DNAFirstStr[i] == 'T')
            {
                AT++;
            }
            else if (DNASecondStr[i] == 'T' && DNAFirstStr[i] == 'A')
            {
                AT++;
            }
            else if (DNASecondStr[i] == 'C' && DNAFirstStr[i] == 'G')
            {
                CG++;
            }
            else if (DNASecondStr[i] == 'G' && DNAFirstStr[i] == 'C')
            {
                CG++;
            }
        }

        if ((AT > CG * 3) || (n > 5))
        {
            delete this;
            break;
        }
    }
}