#include <iostream>
#include "Listapuntatori.cpp"  

int main() {
    // Dichiarazione della lista di interi
    ListaPuntatori<int> lista;
    int numero, val_Ele, posizione;

    // Caricamento degli elementi
    std::cout << "Dimmi il numero degli elementi che vuoi inserire all'interno della lista' ";
    std::cin >> numero;

    for (int i = 0; i < numero; ++i) {
        std::cout << "Inserisci l'elemento " << i+1 << ": ";
        std::cin >> val_Ele;
        lista.inslista(val_Ele, i + 1);
    }

    // Visualizzazione della lista
    std::cout << "Elementi della lista: ";
    for (int i = 1; i <= lista.lunghezza(); ++i) {
        std::cout << lista.leggilista(i) << " ";
    }
    std::cout << std::endl;


    // Ricerca di un elemento nella lista
    std::cout << "Inserisci un elemento da cercare: ";
    std::cin >> val_Ele;
    if (lista.contiene(val_Ele)) {
        int occorrenze = lista.contaOccorrenze(val_Ele);
        std::cout << "L'elemento " << val_Ele << " è presente nella lista." << std::endl;
    } else {
        std::cout << "L'elemento " << val_Ele << " non è presente nella lista." << std::endl;
    }

    // Calcolo massimo, minimo e somma
    int minimo=lista.minimo();
    int massimo=lista.massimo();
    int somma=lista.somma();

    std::cout << "elemento massimo: " << massimo<< std::endl;
    std::cout << "elemento minimo: " << minimo << std::endl;
    std::cout << "Somma degli elementi: " << somma << std::endl;

    // Modifica di un elemento
    std::cout << "\nInserisci la posizione dell'elemento da aggiornare: ";
    std::cin >> posizione;
    if (posizione >= 1 && posizione <= lista.lunghezza()) {
        std::cout << "Inserisci il nuovo val_Ele: ";
        std::cin >> val_Ele;
        lista.scrivilista(val_Ele, posizione);
        std::cout << "Elemento aggiornato con successo." << std::endl;
    } else {
        std::cout << "posizione non trovata." << std::endl;
    }

    // Rimozione di un elemento per posizione
    std::cout << "\nInserisci la posizione dell'elemento da rimuovere (per posizione): ";
    std::cin >> posizione;
    if (posizione >= 1 && posizione <= lista.lunghezza()) {
        lista.canclista(posizione);
        std::cout << "Elemento rimosso con successo." << std::endl;
    } else {
        std::cout << "posizione non val_Eleida." << std::endl;
    }

    // Rimozione di un elemento 
    std::cout << "\nInserisci il val_Ele dell'elemento da rimuovere: ";
    std::cin >> val_Ele;
    if (lista.contiene(val_Ele)) {
        // Rimuoviamo tutti gli elementi 
        while (lista.contiene(val_Ele)) {
            // Troviamo la posizione dell'elemento
            for (int i = 1; i <= lista.lunghezza(); ++i) {
                if (lista.leggilista(i) == val_Ele) {
                    lista.canclista(i);
                    break;
                }
            }
        }
        std::cout << "Tutti gli elementi con il val_Ele " << val_Ele << " sono stati rimossi." << std::endl;
    } else {
        std::cout << "L'elemento " << val_Ele << " non è presente nella lista." << std::endl;
    }

    // Visualizzazione finale della lista
    std::cout << "\nElementi finali della lista: ";
    for (int i = 1; i <= lista.lunghezza(); ++i) {
        std::cout << lista.leggilista(i) << " ";
    }
    std::cout << std::endl;

    return 0;
}
