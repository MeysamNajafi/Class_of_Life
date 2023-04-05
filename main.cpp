// #include "/Users/meysam/stdc++.h"
#include "genome.h"
#include "animal.h"
#include "cell.h"
#include <string>
#include <iostream>
using namespace std;

int main()
{
    Genome gen, gen2, gen3, gen4;
    gen.setDNA("AGTACGCA");
    gen2.setDNA("TTAGAGCA");
    gen3.setDNA("AGTACGCA");
    gen4.setDNA("TTGCAGCA");

    Cell cell, cell2;
    cell.addChromosome(gen);
    cell.addChromosome(gen2);
    cell2.addChromosome(gen3);
    cell2.addChromosome(gen4);

    Animal animal(cell);
    Animal animal2(cell2);
    double similarity =  animal.Similarity(animal2);
    cout << "SIMILARITY SCORE IS: " << similarity << endl;
    bool res = animal == animal2;
    if(res)
        cout << "YES";
    else 
        cout << "NO";
}