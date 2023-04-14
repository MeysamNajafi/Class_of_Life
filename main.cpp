// #include "/Users/meysam/stdc++.h"
#include "genome.h"
#include "animal.h"
#include "cell.h"
#include <string>
#include <iostream>
using namespace std;
vector<Genome> genomes;
Genome tempGenome;

void menu();

// ====================== GENOME ====================
Genome createGenome(string rna, string dna)
{
    Genome g1;
    g1.setRNA(rna);
    g1.setDNA(dna);
    return g1;
}

void smallMutRNA()
{
    system("clear");
    char toFind, toReplace;
    int n;
    cout << "*** Small Mutation RNA *** \n";
    cout << "Enter charachter to find: \n";
    cin >> toFind;
    cout << "Enter charachter to replace: \n";
    cin >> toReplace;
    cout << "Specify the number of replacements \n";
    cin >> n;

    tempGenome.SmallMutationRNA(toFind, toReplace, n);
}
void smallMutDNA()
{
    system("clear");
    char toFind, toReplace;
    int n;
    cout << "*** Small Mutation DNA *** \n";
    cout << "Enter charachter to find: \n";
    cin >> toFind;
    cout << "Enter charachter to replace: \n";
    cin >> toReplace;
    cout << "Specify the number of replacements \n";
    cin >> n;

    tempGenome.SmallMutationDNA(toFind, toReplace, n);
}

void bigMutRNA()
{
    system("clear");
    string toFind, toReplace;
    cout << "*** Big Mutation RNA *** \n";
    cout << "Enter string to find: \n";
    cin >> toFind;
    cout << "Enter string to replace: \n";
    cin >> toReplace;

    tempGenome.BigMutationRNA(toFind, toReplace);
}

void bigMutDNA()
{
    system("clear");
    string toFind, toReplace;
    cout << "*** Big Mutation DNA *** \n";
    cout << "Enter string to find: \n";
    cin >> toFind;
    cout << "Enter string to replace: \n";
    cin >> toReplace;

    tempGenome.BigMutationRNA(toFind, toReplace);
}

void reverseMutRNA()
{
    system("clear");
    string toReverse;
    cout << "*** Reverse Mutation RNA *** \n";
    cout << "Enter string to reverse: \n";
    cin >> toReverse;

    tempGenome.ReverseMutationRNA(toReverse);
}
void reverseMutDNA()
{
    system("clear");
    string toReverse;
    cout << "*** Reverse Mutation DNA *** \n";
    cout << "Enter string to reverse: \n";
    cin >> toReverse;

    tempGenome.ReverseMutationDNA(toReverse);
}

void showGenomeInfo()
{
    cout << "RNA is: " << tempGenome.getRNA() << endl;
    cout << "DNA (First Part) is: " << tempGenome.getDNAFirst() << endl;
    cout << "DNA (Second Part) is: " << tempGenome.getDNASecond() << endl;
}

void chromosomeMenu(bool isContinue = true)
{
    system("clear");

    if (!isContinue)
    {
        string rna, dna;
        cout << "Here is the menu to manage Genome! \n";
        cout << "Enter the RNA \n";
        cin >> rna;
        cout << "Enter the DNA \n";
        cin >> dna;
        tempGenome = createGenome(rna, dna);
        system("clear");
        cout << "Genome created successfully ;) \n";
        
    }
    else {
        cout << "======================= INFO ====================\n\n";
        showGenomeInfo();
        cout << "\n======================= INFO ====================\n\n";
    }

    cout << "Now, enter a number to continue: \n";
    cout << "0. Back \n";
    cout << "1. Small Mutation RNA \n";
    cout << "2. Small Mutation DNA \n";
    cout << "3. Big Mutation RNA \n";
    cout << "4. Big Mutation DNA \n";
    cout << "5. Reverse Mutation RNA \n";
    cout << "6. Reverse Mutation DNA \n";

    int operand;
    cin >> operand;
    if (operand < 0 || operand > 6)
    {
        cout << "Wrong Number!";
        chromosomeMenu();
    }

    switch (operand)
    {
    case 0:
        menu();
        return;
    case 1:
        smallMutRNA();
        break;
    case 2:
        smallMutDNA();
        break;
    case 3:
        bigMutRNA();
        break;
    case 4:
        bigMutDNA();
        break;
    case 5:
        reverseMutRNA();
        break;
    case 6:
        reverseMutDNA();
        break;
    }
    chromosomeMenu();
}

// ====================== GENOME ====================

void menu()
{

    system("clear");
    cout << "Welcome to The Life Program! \n";
    cout << "Enter a number to continue: \n";
    cout << "1. Genome \n";
    cout << "2. Cell \n";
    cout << "3. Animal \n";
    cout << "4. Virus \n";

    int operand;
    cin >> operand;
    if (operand < 1 || operand > 4)
    {
        cout << "Wrong Number!";
        menu();
    }
    switch (operand)
    {
    case 1:
        chromosomeMenu(false);
        break;
        // case 2:
        //     chromosomeMenu();
        //     break;
        // case 3:
        //     chromosomeMenu();
        //     break;
        // case 4:
        //     chromosomeMenu();
        //     break;
    }
}

int main()
{
    // Genome gen, gen2, gen3, gen4;
    // gen.setDNA("AGTACGCA");
    // gen2.setDNA("TTAGAGCA");
    // gen3.setDNA("CGCTTTGCA");
    // gen4.setDNA("AAACAGCA");

    // Cell cell, cell2;
    // cell.addChromosome(gen);
    // cell.addChromosome(gen2);
    // cell.addChromosome(gen3);
    // cell2.addChromosome(gen4);

    // Animal animal(cell);
    // Animal animal2(cell2);
    // double similarity = animal.Similarity(animal2);
    // cout << "SIMILARITY SCORE IS: " << similarity << endl;

    // Animal newBornAnimal = animal.AsexualReproduction();
    // double newBornanimalSimilarity = animal.Similarity(newBornAnimal);
    // cout << "SIMILARITY SCORE OF NEW BORN ANIMAL IS: " << newBornanimalSimilarity << endl;
    menu();
}