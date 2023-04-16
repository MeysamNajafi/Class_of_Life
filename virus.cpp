#include "virus.h"
#include "utils.h"
#include <iostream>
#include <string>

void Virus::setRNA(string rna)
{
    for (int i = 0; i < rna.size(); i++)
    {
        RNA.push_back(rna[i]);
    }
}

string Virus::getRNA()
{
    string RNAStr(RNA.begin(), RNA.end());
    return RNAStr;
}

void Virus::Sickness(Animal animal)
{
    vector<Genome> Chromosomes = animal.getCell().getAllChromosomes();
    string VirusStr = this->getRNA();

    string longestStr = Chromosomes[0].getRNA();
    for (int i = 1; i < Chromosomes.size(); i++)
    {
        longestStr = LCSubstr(longestStr, Chromosomes[i].getRNA());
    }

    string PairVirusStr;
    for (int i = 0; i < getRNA().size(); i++)
    {
        PairVirusStr = GivePair(VirusStr[i]);
    }

    int firstIndex = VirusStr.find(longestStr);
    int secondIndex = PairVirusStr.find(longestStr);

    if (firstIndex == string::npos && secondIndex == string::npos)
    {
        cout << "It is not harmful \n";
    }
    else
    {
        cout << "It is harmful \n";
    }
}
