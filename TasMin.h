#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

class TasMin 
{
private:
    std::vector<int> heap;

  

public:
    int ExtraireMin(); 

    // Fonction pour maintenir la propriété du tas en remontant
    void RemonterDansLeTas(int index);

    void DescendreDansLeTas(int index);


    std::vector<int> TrierHeap(); 


    // Insère une valeur dans le tas
    void InsertHeapMin(int value);

    // Affiche les éléments du tas
    void AfficherHeap() const;

    void SupprimerParIndex(int index);

};




