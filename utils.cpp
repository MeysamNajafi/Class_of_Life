#include "utils.h"

char GivePair(char Nucleotide)
{
    // output the pair of Nucleotide
    switch (Nucleotide)
    {
    case 'T':
        return 'A';
    case 'A':
        return 'T';
    case 'C':
        return 'G';
    case 'G':
        return 'C';
    }
}