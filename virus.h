#pragma once
#include "Animal.h"
#include <vector>
#include <string>

class Virus : public Genome
{
    private:
        vector<char> RNA;
        friend class Animal;
        
    public:
        void setRNA(string rna);
        string getRNA();
        void Sickness(Animal animal);
};