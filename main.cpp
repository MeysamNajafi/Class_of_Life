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
    gen3.setDNA("CGCTTTGCA");
    gen4.setDNA("AAACAGCA");

    Cell cell, cell2;
    cell.addChromosome(gen);
    cell.addChromosome(gen2);
    cell.addChromosome(gen3);
    cell2.addChromosome(gen4);

    Animal animal(cell);
    Animal animal2(cell2);
    double similarity =  animal.Similarity(animal2);
    cout << "SIMILARITY SCORE IS: " << similarity << endl;

    Animal newBornAnimal = animal.AsexualReproduction();
    double newBornanimalSimilarity = animal.Similarity(newBornAnimal);
    cout << "SIMILARITY SCORE OF NEW BORN ANIMAL IS: " << newBornanimalSimilarity << endl;
}