#include "animal.h"
#include <iostream>
#include "utils.h"
#include <algorithm>
#include <unordered_set>
#include <time.h>
#include <cstdlib>
#include <cmath>

// EDIT INDEX ALGORITHM
double similarityPercentage(const string &str1, const string &str2)
{
    const int len1 = str1.length();
    const int len2 = str2.length();
    const int max_len = std::max(len1, len2);
    int dp[len1 + 1][len2 + 1];
    for (int i = 0; i <= len1; ++i)
    {
        for (int j = 0; j <= len2; ++j)
        {
            if (i == 0)
            {
                dp[i][j] = j;
            }
            else if (j == 0)
            {
                dp[i][j] = i;
            }
            else if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = 1 + std::min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]});
            }
        }
    }
    const int edit_dist = dp[len1][len2];
    return (1.0 - static_cast<double>(edit_dist) / max_len) * 100.0;
}

Animal::Animal(Cell cell)
{
    this->cell = cell;
}
Animal::Animal()
{
}

Cell Animal::getCell()
{
    return this->cell;
}

double Animal::Similarity(Animal &animal2)
{
    double similarity;
    vector<Genome> Chromosomes = this->cell.getAllChromosomes();
    vector<Genome> Chromosomes2 = animal2.cell.getAllChromosomes();
    vector<double> percentages;

    for (Genome ch : Chromosomes) // loop over each chromosome of first animal and find the most similar chromosome with the second animal
    {
        double highestPerc = 0;

        // search in the first part of DNA
        for (Genome ch2 : Chromosomes2)
        {
            double perc = similarityPercentage(ch.getDNAFirst(), ch2.getDNAFirst());    // search in the first part
            double perc2 = similarityPercentage(ch.getDNASecond(), ch2.getDNASecond()); // search in the second part
            if (perc > highestPerc)
                highestPerc = perc;
            if (perc2 > highestPerc)
                highestPerc = perc2;
        }
        percentages.push_back(highestPerc);
        highestPerc = 0;
    }

    double total = 0;
    for (double a : percentages)
    {
        total += a;
    }

    similarity = total / percentages.size();
    return similarity;
}

bool Animal::operator==(Animal &animal2)
{
    int n = this->cell.getAllChromosomes().size();
    int m = animal2.cell.getAllChromosomes().size();

    if ((Similarity(animal2) >= 70) && n == m)
    {
        return true;
    }
    return false;
}

Animal Animal::operator+(Animal &animal2)
{
    srand(time(0));

    int n = cell.getAllChromosomes().size();
    int m = animal2.cell.getAllChromosomes().size();

    if (n % 2 != 0 || m % 2 != 0)
    {
        throw "error!!!";
    }

    Animal obj1 = AsexualReproduction();
    Animal obj2 = animal2.AsexualReproduction();
    Cell newCell;

    for (int i = 0; i < n / 2; i++)
    {
        int randNumber = rand() % n;
        Genome newGenome;
        newGenome.setDNA(obj1.getCell().getAllChromosomes()[randNumber].getDNAFirst());
        newCell.addChromosome(newGenome);
    }
    for (int i = 0; i < m / 2; i++)
    {
        int randNumber = rand() % n;
        Genome newGenome;
        newGenome.setDNA(obj2.getCell().getAllChromosomes()[randNumber].getDNAFirst());
        newCell.addChromosome(newGenome);
    }
    Animal newAnimal(newCell);
    return newCell;
}

void Animal::CellDeath()
{
    for (int i = 0; i < cell.getAllChromosomes().size(); i++)
    {
        Genome chromosome = cell.getAllChromosomes()[i];
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
            cell.getAllChromosomes().erase(cell.getAllChromosomes().begin() + i);
        }
    }
    
}

Animal Animal::AsexualReproduction()
{
    srand(time(0));
    int n = cell.getAllChromosomes().size();
    vector<string> twoNChromosomes;
    double similarity = 0;
    int counter = 0;
    Cell newCell;
    int firstLoopCount = round(n * 0.7);

    // create a vector from mother's DNAs (2n)
    for (auto ch : cell.getAllChromosomes())
    {
        twoNChromosomes.push_back(ch.getDNAFirst());
        twoNChromosomes.push_back(ch.getDNAFirst());
    }

    // choose 70% of chromosomes from the chromosomes of mother (n)
    for (int i = 0; i < firstLoopCount; i++)
    {
        bool wasAdded = true;
        string dna;

        // find a dna which is not duplicate
        while (wasAdded)
        {
            int randNumber = rand() % n;
            dna = cell.getAllChromosomes()[randNumber].getDNAFirst();

            // check if the dna was added to the new cell or no
            for (auto ch : newCell.getAllChromosomes())
                if (ch.getDNAFirst() == dna)
                    continue;

            wasAdded = false;
        }

        // delete the selected dna from thw 2n chromosomes vector
        for (int i = 0; i < twoNChromosomes.size(); i++)
        {
            if (twoNChromosomes[i] == dna)
                twoNChromosomes.erase(twoNChromosomes.begin() + i);
        }

        Genome newGenome;
        newGenome.setDNA(dna);
        newCell.addChromosome(newGenome);
    }

    // randomely select the other part
    for (int i = 0; i < n - firstLoopCount; i++)
    {
        int randNumber = rand() % twoNChromosomes.size();
        string dna = twoNChromosomes[randNumber];
        Genome newGenome;
        newGenome.setDNA(dna);
        newCell.addChromosome(newGenome);
    }

    Animal newAnimal(newCell);


    return newAnimal;
}