// #include "/Users/meysam/stdc++.h"
// ******* NOTE ******* use sytem("CLS") instead system("clear") if your OS is windows
#include "genome.h"
#include "animal.h"
#include "cell.h"
#include "virus.h"
#include <string>
#include <iostream>
using namespace std;

vector<Genome> genomes;
Genome tempGenome;
vector<Cell> cells;
Cell tempCell;
vector<Animal> animals;
Animal tempAnimal;

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

    tempGenome.BigMutationDNA(toFind, toReplace);
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
        cout << "Enter the RNA (enter s to skip) \n";
        cin >> rna;
        if (rna == "s")
            rna = "";
        cout << "Enter the DNA \n";
        cin >> dna;
        tempGenome = createGenome(rna, dna);
        system("clear");
        cout << "Genome created successfully ;) \n";
    }
    else
    {
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
        genomes.push_back(tempGenome);
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

// ====================== CELL ====================
void printCellChromosomes()
{
    int counter = 0;
    for (Genome genome : tempCell.getAllChromosomes())
    {
        cout << counter + 1 << ". RNA: " << genome.getRNA() << "  /  DNA (First): " << genome.getDNAFirst() << "  /  DNA (Second): " << genome.getDNASecond() << "\n";
        counter++;
    }
}

void cellSmallMutDNA()
{
    system("clear");
    char toFind, toReplace;
    int n, m;

    cout << "*** Small Mutation DNA in Cell *** \n";
    printCellChromosomes();

    cout << "Enter the chromosome index to edit: \n";
    cin >> m;
    cout << "Enter charachter to find: \n";
    cin >> toFind;
    cout << "Enter charachter to replace: \n";
    cin >> toReplace;
    cout << "Specify the number of replacements \n";
    cin >> n;

    tempCell.SmallMutationDNA(toFind, toReplace, n, m - 1);
}
void cellBigMutDNA()
{
    system("clear");
    string toFind, toReplace;
    int n, m;

    cout << "*** Big Mutation DNA in Cell *** \n";
    printCellChromosomes();

    cout << "Enter the chromosome index you want to find a substring on it: \n";
    cin >> n;
    cout << "Enter the chromosome index  you want to replace a substring on it: \n";
    cin >> m;
    cout << "Enter string to find: \n";
    cin >> toFind;
    cout << "Enter string to replace: \n";
    cin >> toReplace;

    tempCell.BigMutationDNA(toFind, n, toReplace, m - 1);
}
void cellReverseMutDNA()
{
    system("clear");
    string toReverse;
    int n;

    cout << "*** Reverse Mutation DNA in Cell *** \n";
    printCellChromosomes();

    cout << "Enter the chromosome index you want to do reverse on it: \n";
    cin >> n;
    cout << "Enter the substring to reverse: \n";
    cin >> toReverse;

    tempCell.ReverseMutationDNA(toReverse, n - 1);
}
void cellPalindorme()
{
    system("clear");
    int n;

    cout << "*** Find Palindorme in Cell's Chromosome *** \n";
    printCellChromosomes();

    cout << "Enter the chromosome index you want to do reverse on it: \n";
    cin >> n;

    tempCell.Palindorme(n);
}
Cell createCell(){
    Cell newCell;
    int number;
    bool getNumber = true;
    while (getNumber)
    {
        char command;
        cin >> number;
        newCell.addChromosome(genomes[number - 1]);

        cout << "Do you want to add another chromosome? (y/n) \n";
        cin >> command;
        if (command == 'n')
            getNumber = false;
    }
    return newCell;
}

void cellMenu(bool isContinue = true)
{
    system("clear");
    if (!isContinue)
    {
        cout << "Here is the menu to manage Cell! \n";
        cout << "Enter a number to select a choromosome to add it to cell: \n";
        for (int i = 0; i < genomes.size(); i++)
        {
            Genome genome = genomes[i];
            cout << i + 1 << ". RNA: " << genome.getRNA() << "  /  DNA (First): " << genome.getDNAFirst() << "  /  DNA (Second): " << genome.getDNASecond() << "\n";
        }

        tempCell = createCell();

        system("clear");
        cout << "Cell created successfully ;) \n";
    }
    else
    {
        cout << "======================= INFO ====================\n\n";
        printCellChromosomes();
        cout << "\n======================= INFO ====================\n\n";
    }

    cout << "Now, enter a number to continue: \n";
    cout << "0. Back \n";
    cout << "1. Check Cell Death \n";
    cout << "2. Small Mutation DNA \n";
    cout << "3. Big Mutation DNA \n";
    cout << "4. Reverse Mutation DNA \n";
    cout << "5. Palindorme \n";

    int operand;
    cin >> operand;
    if (operand < 0 || operand > 5)
    {
        cout << "Wrong Number!";
        cellMenu();
    }

    switch (operand)
    {
    case 0:
        cells.push_back(tempCell);
        menu();
        return;
    case 1:
        tempCell.CellDeath();
        break;
    case 2:
        cellSmallMutDNA();
        break;
    case 3:
        cellBigMutDNA();
        break;
    case 4:
        cellReverseMutDNA();
        break;
    case 5:
        cellPalindorme();
        break;
    }
    cellMenu();
}
// ====================== CELL ====================

// ====================== ANIMAL ====================
void showAnimalInfo(bool showCells = false)
{
    if (animals.size() == 0 || showCells)
        for (int i = 0; i < cells.size(); i++)
        {
            cout << i + 1 << ". \n";
            Cell cell = cells[i];
            for (int j = 0; j < cell.getAllChromosomes().size(); j++)
            {
                Genome genome = cell.getAllChromosomes()[j];
                cout << "   " << j + 1 << ". RNA: " << genome.getRNA() << "  /  DNA (First): " << genome.getDNAFirst() << "  /  DNA (Second): " << genome.getDNASecond() << "\n";
            }
        }
    else
        for (int i = 0; i < animals.size(); i++)
        {
            cout << i + 1 << ". \n";
            Animal animal = animals[i];
            for (int j = 0; j < animal.getCell().getAllChromosomes().size(); j++)
            {
                Genome genome = animal.getCell().getAllChromosomes()[j];
                cout << "   " << j + 1 << ". RNA: " << genome.getRNA() << "  /  DNA (First): " << genome.getDNAFirst() << "  /  DNA (Second): " << genome.getDNASecond() << "\n";
            }
        }
}
void animalCheckSimilarity()
{
    system("clear");
    int first, second;

    cout
        << "*** Check Similarity between 2 Animals *** \n";
    showAnimalInfo();

    cout << "Enter a number to select the first animal: \n";
    cin >> first;

    cout << "Enter a number to select the second animal: \n";
    cin >> second;

    double result =  animals[first - 1].Similarity(animals[second - 1]);
    system("clear");
    cout << "The similarity is: " << result << endl;
}
void animalAsexual()
{
    system("clear");
    int first, second;

    cout
        << "*** Asexual Reproduction *** \n";
    showAnimalInfo();

    cout << "Enter a number to select the mother animal: \n";
    cin >> first;

    Animal newAnimal = animals[first - 1].AsexualReproduction();
    animals.push_back(newAnimal);
    system("clear");
    cout << "Borned! \n";
}
void animalEquality()
{
    system("clear");
    int first, second;

    cout
        << "*** Check Equailty of two Animal *** \n";
    showAnimalInfo();

    cout << "Enter a number to select the first animal: \n";
    cin >> first;
    cout << "Enter a number to select the second animal: \n";
    cin >> second;

    bool result = animals[first - 1] == animals[second - 1];
    system("clear");
    if (result)
        cout << "Their Similarity is more than 70(%) and they are equal \n";
    else
        cout << "Their Similarity is less than 70(%) and they are not equal \n";
}
void animalSexual()
{
    system("clear");
    int first, second;

    cout
        << "*** Sexual Reproduction between two Animal *** \n";
    showAnimalInfo();

    cout << "Enter a number to select the first animal: \n";
    cin >> first;
    cout << "Enter a number to select the second animal: \n";
    cin >> second;

    if (animals[first - 1] == animals[second - 1] == false){
        cout << "Sexual Reproduction is not possible! \n";
        return;
    }

    Animal newAnimal = animals[first - 1] + animals[second - 1];
    animals.push_back(newAnimal);

    system("clear");
    cout << "Borned! \n";
}
void animalMenu(bool isContinue = true)
{
    if (!isContinue)
    {
        system("clear");
        int num;
        cout << "Here is the menu to manage Animal! \n";
        showAnimalInfo(true);
        cout << "Enter a number to select a cell \n";
        cin >> num;
        tempAnimal = Animal(cells[num - 1]);
        animals.push_back(tempAnimal);

        system("clear");
        cout << "Animal created successfully ;) \n";
    }
    else
    {
        cout << "======================= INFO ====================\n\n";
        showAnimalInfo();
        cout << "\n======================= INFO ====================\n\n";
    }

    cout << "Now, enter a number to continue: \n";
    cout << "0. Back \n";
    cout << "1. Create New Animal \n";
    cout << "2. Check Similarity \n";
    cout << "3. Asexual Reproduction \n";
    cout << "4. Check Equality \n";
    cout << "5. Sexual Reproduction \n";
    cout << "6. Check Cell Death \n";

    int operand;
    cin >> operand;
    if (operand < 0 || operand > 6)
    {
        cout << "Wrong Number!";
        animalMenu();
    }

    switch (operand)
    {
    case 0:
        menu();
        return;
    case 1:
        animalMenu(false);
        break;
    case 2:
        animalCheckSimilarity();
        break;
    case 3:
        animalAsexual();
        break;
    case 4:
        animalEquality();
        break;
    case 5:
        animalSexual();
        break;
    case 6:
        tempAnimal.CellDeath();
        break;
    }
    animalMenu();
}
// ====================== ANIMAL ====================

// ====================== VIRUS ====================
void virusMenu(){
    system("clear");

    string rna;
    int number;
    Virus virus;

    cout << "Enter an RNA to check if this harmful for an animal \n";
    cin >> rna;
    virus.setRNA(rna);

    system("clear");
    showAnimalInfo();
    cout << "Enter a number to select an animal: \n";
    cin >> number;

    system("clear");
    virus.Sickness(animals[number - 1]);
}

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
    case 2:
        cellMenu(false);
        break;
    case 3:
        animalMenu(false);
        break;
    case 4:
        virusMenu();
        break;
    }
}

int main()
{
    // Genome gen, gen2, gen3, gen4, gen5, gen6, gen7;
    // gen.setDNA("CCAA");
    // gen2.setDNA("TTAGAGCA");
    // gen3.setDNA("CGCTTTGCA");
    // gen4.setDNA("AAACAGCA");
    // gen5.setDNA("CTATCG");
    // gen6.setDNA("GGGTAT");
    // gen7.setDNA("ATGTCATG");

    // Cell cell, cell2;
    // cell.addChromosome(gen);
    // cell.addChromosome(gen2);
    // cell.addChromosome(gen3);
    // cell.addChromosome(gen4);
    // cell.addChromosome(gen5);
    // cell.addChromosome(gen6);
    // cell.addChromosome(gen7);

    // Animal animal(cell);
    // Animal animal2(cell2);
    // double similarity = animal.Similarity(animal2);
    // cout << "SIMILARITY SCORE IS: " << similarity << endl;

    // Animal newBornAnimal = animal.AsexualReproduction();
    
    // double newBornanimalSimilarity = animal.Similarity(newBornAnimal);
    // cout << "SIMILARITY SCORE OF NEW BORN ANIMAL IS: " << newBornanimalSimilarity << endl;
    menu();
}