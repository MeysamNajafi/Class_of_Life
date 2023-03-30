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

void Cell::SmallMutationRNA(char ch1, char ch2, int n, int m)
{
    Chromosomes[n].SmallMutationRNA(ch1, ch2, n);
}

void Cell::BigMutationRNA(string str1, int n, string str2, int m)
{
    Chromosomes[n].BigMutationRNA(str1, str2);
    Chromosomes[m].BigMutationRNA(str2, str1);
}

void Cell::SmallMutationDNA(char ch1, char ch2, int n, int m)
{
    Chromosomes[m].SmallMutationDNA(ch1, ch2, n);
}

void Cell::BigMutationDNA(string str1, int n, string str2, int m)
{
    Chromosomes[n].BigMutationDNA(str1, str2);
    Chromosomes[m].BigMutationDNA(str2, str1);
}

void Cell::ReverseMutationRNA(string str1, int n)
{
    Chromosomes[n].ReverseMutationRNA(str1);
}

void Cell::ReverseMutationDNA(string str1, int n)
{
    Chromosomes[n].ReverseMutationDNA(str1);
}