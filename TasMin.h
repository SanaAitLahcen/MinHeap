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

    // Fonction pour maintenir la propri�t� du tas en remontant
    void RemonterDansLeTas(int index);

    void DescendreDansLeTas(int index);


    std::vector<int> TrierHeap(); 


    // Ins�re une valeur dans le tas
    void InsertHeapMin(int value);

    // Affiche les �l�ments du tas
    void AfficherHeap() const;

    void SupprimerParIndex(int index);

};




