#include "animal.h"
#include <iostream>
#include "utils.h"
#include <algorithm>
#include <unordered_set>

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


Animal::Animal(Cell cell){
    this->cell = cell;
}

double Animal::Similarity(Animal& animal2)
{
    double similarity;
    vector<Genome> Chromosomes = this->cell.getAllChromosomes();
    vector<Genome> Chromosomes2 = animal2.cell.getAllChromosomes();
    vector<double> percentages;

    for (Genome ch : Chromosomes) // loop over each chromosome of first animal and find the most similar chromosome with the second animal
    {     
            double highestPerc=0;

            // search in the first part of DNA
            for (Genome ch2 : Chromosomes2)
            {
                double perc = similarityPercentage(ch.getDNAFirst(), ch2.getDNAFirst()); // search in the first part
                double perc2 = similarityPercentage(ch.getDNASecond(), ch2.getDNASecond()); // search in the second part
                if(perc > highestPerc) highestPerc = perc;
                if(perc2 > highestPerc) highestPerc = perc2;

                percentages.push_back(highestPerc);
                highestPerc = 0;
            }
    }

    double total = 0;
    for (double a: percentages) {
            total += a;
    }

    similarity = total / percentages.size();
    return similarity;
}

bool Animal::operator==(Animal &animal2){
    int n = this->cell.getAllChromosomes().size();
    int m = animal2.cell.getAllChromosomes().size();

    if ((Similarity(animal2) >= 70) && n == m)
    {
        return true;
    }
    return false;
}

Animal Animal::AsexualReproduction()
{
    srand(time(0));
    int n = cell.getAllChromosomes().size();
    double similarity = 0;
    int counter = 0;

    while (true)
    {
        Cell newCell;
        similarity = 0;

        for (Genome g : cell.getAllChromosomes())
        { 
            Genome newGenome;
            newGenome.setDNA(g.getDNAFirst());
            newCell.addChromosome(newGenome);
        }

        // selecting random chromosome
        for (int i = 0; i < n; i++)
        {
            int dnaLength = rand() % (8 - 4 + 1) + 4; // LENGTH OF THE RANDOM DNA WILL BE BETWEEN 4 and 8
            string dna = ""; 
            for (int i = 0; i < dnaLength; i++) 
            {
                int randNumber = rand() % 4;
                char randChar;
                switch (randNumber)
                {
                    case 0:
                        randChar = 'A';
                        break;
                    case 1:
                        randChar = 'T';
                        break;
                    case 2:
                        randChar = 'C';
                        break;
                    case 3:
                        randChar = 'G';
                        break;
                }
                dna += randChar;
            }
            
            Genome newGenome;
            newGenome.setDNA(dna);
            newCell.addChromosome(newGenome);
        }
        Animal newAnimal(newCell);

        similarity = Similarity(newAnimal);
        if (similarity > 70) return newAnimal;
    }
}