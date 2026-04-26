#ifndef LINKEDLIST_H
#define LINKEDLIST_H

/*
 * Struktura reprezentująca pojedynczy węzeł na liście
 * @tparam T - dowolny typ danych przechowywany w węźle
 */
template <typename T>
struct Element {
    T head;
    Element<T>* next;

    Element(T x, Element<T>* next = nullptr) {
        this->head = x;
        this->next = next;
    }
};

/*
 * Klasa implementująca dynamiczny stos oparty na liście jednokierunkowej (szablon)
 * @tparam T - dowolny typ danych, który będzie lądował na stosie
 */
template <typename T>
class LinkedList {
private:
    Element<T>* topElement;
    int currentSize;

public:
    /*
     * Konstruktor domyślny - inicjalizuje pusty stos
     */
    LinkedList() {
        this->topElement = nullptr;
        this->currentSize = 0;
    }

    /*
     * Destruktor -czyści pamięć
     */
    ~LinkedList() {
        while (!this->empty()) {
            this->pop();
        }
    }

    /*
     * Funkcja sprawdzająca, czy stos jest pusty
     * @return zwraca true jeśli pusty, false jeśli ma elementy
     */
    bool empty() {
        return this->topElement == nullptr;
    }

    /*
     * Funkcja zwracająca obecny rozmiar stosu
     * @return całkowita liczba elementów na stosie
     */
    int size() {
        return this->currentSize;
    }

    /*
     * Funkcja dorzucająca element na sam szczyt stosu
     * @param x - element typu T do wrzucenia
     */
    void push(T x) {
        this->topElement = new Element<T>(x, this->topElement);
        this->currentSize++;
    }

    /*
     * Funkcja zdejmująca i usuwająca z pamięci element ze szczytu stosu
     */
    void pop() {
        if (!this->empty()) {
            Element<T>* temp = this->topElement;
            this->topElement = this->topElement->next;
            delete temp;
            this->currentSize--;
        }
    }

    /*
     * Funkcja podglądająca element na szczycie stosu (bez usuwania go)
     * @return zwraca wartość elementu z samej góry
     */
    T top() {
        return this->topElement->head;
    }
};

#endif //LINKEDLIST_H