#include "cell.h"
#include <iostream>
#include "utils.h"

// =====================
// HELPER FUNCTIONS
// =====================
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

void Cell::SmallMutationDNA(char ch1, char ch2, int n, int m)
{
    Chromosomes[m].SmallMutationDNA(ch1, ch2, n);
}

void Cell::BigMutationDNA(string str1, int n, string str2, int m)
{
    Chromosomes[n].BigMutationDNA(str1, str2);
    Chromosomes[m].BigMutationDNA(str2, str1);
}

void Cell::ReverseMutationDNA(string str1, int n)
{
    Chromosomes[n].ReverseMutationDNA(str1);
}

void Cell::Palindorme(int n)
{
    if (n >= 0 && n < Chromosomes.size()){
            string s = Chromosomes[n].getDNAFirst();

            int n = s.length();
            for (int i = 0; i < n - 4; i++)
            {
                for (int j = i + 4; j <= n; j++)
                {
                    string substr = s.substr(i, j - i);
                    if (substr.length() % 2 != 0) continue;
                    if (isPalindrome(substr))
                        cout << substr << endl;
                }
            }
    }
}