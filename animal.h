#pragma once
#include "cell.h"
#include <vector>
#include <string>

using namespace std;

class Animal : public Cell
{
private:
    Cell cell;
    friend class Virus;
public:
    Animal(Cell cell);
    Animal();

    Cell getCell();
    double Similarity(Animal &animal2);
    void CellDeath();
    bool operator==(Animal &animal2);
    Animal AsexualReproduction();
    Animal operator+(Animal &animal2);
};