#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>  

using namespace std;

class Prezzo {
  public:
    int price;
    int ordine;
    int nr_pezzi;
    int tempoconsegna;

    Prezzo() : price(0), ordine(0), nr_pezzi(0), tempoconsegna(0) {}
};

class Operazioni {
  private:
    Prezzo u;

  public:
    void Input() {
        cout << "Gentile Cliente," << endl;
        cout << "Inserisca il numero (intero) di pezzi che intende acquistare: ";
        cin >> u.nr_pezzi;

        if (u.nr_pezzi <= 0) {
            cerr << "Errore: il numero di pezzi deve essere maggiore di 0!" << endl;
            return;
        }

        u.price = u.nr_pezzi * 12;
        srand(time(0)); 
        u.ordine = rand() % 1000000 + 1; 
        u.tempoconsegna = rand() % 48 + 1; 

        cout << "Il suo numero ordine è: " << u.ordine << endl;
    }

    void StampaPreventivo() {
        ofstream file("out.txt");
        if (!file.is_open()) {
            cerr << "Errore: impossibile aprire il file 'out.txt'." << endl;
            return;
        }

        file << "Gentile Cliente," << endl;
        file << "Abbiamo ottenuto la sua richiesta di preventivo." << endl;
        file << "Numero d'ordine: " << u.ordine << endl;
        file << "Hai ordinato " << u.nr_pezzi << " pezzi, per un totale di: " << u.price << " euro." << endl;
        file << "Il suo ordine nr. " << u.ordine << " verrà spedito entro " << u.tempoconsegna << " ore." << endl;
        file << "Grazie per averci scelto. Buona giornata!" << endl;

        file.close();
        cout << "Preventivo stampato nel file 'out.txt'." << endl;
    }
};

int main() {
    Operazioni O;
    O.Input();
    O.StampaPreventivo();
    return 0;
}
