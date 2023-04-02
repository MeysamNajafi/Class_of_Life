// #include "/Users/meysam/stdc++.h"
#include "genome.h"
#include "animal.h"
#include "cell.h"
#include <string>
using namespace std;

int main()
{
    Genome gen, gen2, gen3, gen4;
    gen.setDNA("AATTAAGCTC");
    gen2.setDNA("TTCGAA");
    gen3.setDNA("CCGATGCAC");
    gen4.setDNA("TGCTGA");

    Cell cell, cell2;
    cell.addChromosome(gen);
    cell.addChromosome(gen2);
    cell2.addChromosome(gen3);
    cell2.addChromosome(gen4);

    Animal animal(cell);
    Animal animal2(cell2);
    animal.Similarity(animal2);
}