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

    double Similarity(Animal &animal2);
    Animal AsexualReproduction();
    bool operator==(Animal &animal2);
};