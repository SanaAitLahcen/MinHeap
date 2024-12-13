#include "TasMin.h"

void TasMin::DescendreDansLeTas(int index)
{

    int taille = heap.size();
    int minIndex = index;

    int gauche = 2 * index + 1;
    int droite = 2 * index + 2;

    if (gauche < taille && heap[gauche] < heap[minIndex])
        minIndex = gauche;

    if (droite < taille && heap[droite] < heap[minIndex])
        minIndex = droite;

    if (minIndex != index)
    {
        std::swap(heap[index], heap[minIndex]);
        DescendreDansLeTas(minIndex);
    }


}
int TasMin::ExtraireMin()
{
    if (heap.empty())
        throw std::runtime_error("Tas vide !");

    int minValue = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    DescendreDansLeTas(0);
    return minValue;
}

void TasMin::RemonterDansLeTas(int index)
{
    while (index != 0 && heap[(index - 1) / 2] > heap[index])
    {
        std::swap(heap[index], heap[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}



std::vector<int> TasMin::TrierHeap()
{
    std::vector<int> sortedElements;
    while (!heap.empty())
    {
        sortedElements.push_back(ExtraireMin());
    }
    return sortedElements;
}

void TasMin::AfficherHeap() const
{
    for (int value : heap)
    {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}


void TasMin::InsertHeapMin(int value)
{
    heap.push_back(value);    // Ajoute la valeur à la fin
    RemonterDansLeTas(heap.size() - 1); // Réajuste

    std::cout << "Apres insertion de " << value << " : ";
    AfficherHeap();
}





void TasMin::SupprimerParIndex(int index)
{
    // Vérifie si l'index est valide
    if (index < 0 || index >= heap.size())
    {
        throw std::out_of_range("Index invalide !");
    }

    // Remplace l'élément à supprimer par le dernier élément
    heap[index] = heap.back();
    heap.pop_back(); // Supprime le dernier élément

    // Si le tas n'est pas vide, réajuste les éléments
    if (!heap.empty())
    {
        // Vérifie si l'élément doit remonter ou descendre
        if (index > 0 && heap[index] < heap[(index - 1) / 2])
        {
            RemonterDansLeTas(index);
        }
        else
        {
            DescendreDansLeTas(index);
        }
    }

    std::cout << "Tas apres suppression : ";
    AfficherHeap();
}


