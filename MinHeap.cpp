// MinHeap.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include"TasMin.h"

int main()
{
   
        TasMin minHeap;
        std::vector<int> randomNumbers;

        // Générer des nombres aléatoires
        std::srand(std::time(0));
        for (int i = 0; i < 10; ++i) 
        {
            randomNumbers.push_back(std::rand() % 1000);
        }

        // Insérer les nombres aléatoires dans le tas
        for (int value : randomNumbers) 
        {
            minHeap.InsertHeapMin(value);
        }

        std::cout << std::endl;
        // Afficher les résultats
        std::cout << "Nombres generes aleatoirement : ";
        for (int value : randomNumbers) 
        {
            std::cout << value << " ";
        }
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "Tas min : ";
        minHeap.AfficherHeap();

        std::cout << "\nSuppression de l'element a l'index 3." << std::endl;
        minHeap.SupprimerParIndex(3);

        std::cout << "\nTri des elements dans le tas : ";
        std::vector<int> sortedElements = minHeap.TrierHeap();
        for (int value : sortedElements)
        {
            std::cout << value << " ";
        }
        std::cout << std::endl;

        

        return 0;
    
}


