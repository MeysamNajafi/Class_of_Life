#include "animal.h"
#include <iostream>
#include "utils.h"
#include <algorithm>

int needleman_wunsch(string s1, string s2, int match_score, int mismatch_penalty, int gap_penalty)
{
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1));

    // Initialize first row and column
    for (int i = 0; i <= n; i++)
        dp[i][0] = i * gap_penalty;
    for (int j = 0; j <= m; j++)
        dp[0][j] = j * gap_penalty;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + match_score;
            }
            else
            {
                dp[i][j] = max({dp[i - 1][j - 1] + mismatch_penalty,
                                dp[i - 1][j] + gap_penalty,
                                dp[i][j - 1] + gap_penalty});
            }
        }
    }

    // Return the similarity score
    return dp[n][m];
}

// This function uses Needleman-Wunsch algorithm to find the similarity between two strings.
// Also there was another option called LCS but we preferred this algorithm
// becuase it is more accurate and is used in genetic concepts like DNA, RNA, etc 
double similarityPercentage(string s1, string s2)
{
    int match_score = 2;
    int mismatch_penalty = -1;
    int gap_penalty = -1;

    int similarity = needleman_wunsch(s1, s2, match_score, mismatch_penalty, gap_penalty);
    double similarity_percent = 0.0;
    if (similarity >= 0)
    {
        similarity_percent = (double)similarity / (double)max(s1.size(), s2.size()) * 100.0;
    }
    return similarity_percent;
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

    for(Genome ch : Chromosomes) 
    { // loop over each chromosome of first animal and find the most similar chromosome with the second animal
            double highestPerc=0;

            // search in the first part of DNA
            for (Genome ch2 : Chromosomes2)
            {
                double perc = similarityPercentage(ch.getDNAFirst(), ch2.getDNAFirst());
                if(perc > highestPerc) highestPerc = perc;
            }
            // search in the second part of DNA
            for (Genome ch2 : Chromosomes2)
            {
                double perc = similarityPercentage(ch.getDNASecond(), ch2.getDNASecond());
                if (perc > highestPerc)
                    highestPerc = perc;
            }
        
            percentages.push_back(highestPerc);
            highestPerc = 0;
    }
        double average =0;
        for (double a: percentages) {
            average +=a;
        }
        similarity = average / percentages.size();

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

Animal Animal::Asexual_reproduction()
{
    int n = getAllChromosomes().size();

}
