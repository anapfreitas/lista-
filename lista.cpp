#include <stdio.h>

struct No {
    int valor;
    No* prox;

    No() {
        valor = 0;
        prox = NULL;
    }

    No(int _valor) {
        valor = _valor;
        prox = NULL;
    }
};

struct Lista {
    No* inicio, * fim;
    int n;

    Lista() {
        inicio = NULL;
        fim = NULL;
        n = 0;
    }

    bool vazia() {
        return inicio == NULL;
    }

    void inserirInicio(int valor) {
        n++;
        No* novo = new No(valor);

        if (vazia()) {
            inicio = novo;
            fim = novo;
            return;
        }

        novo->prox = inicio;
        inicio = novo;
    }

    void inserirFinal(int valor) {
        n++;
        No* novo = new No(valor);

        if (vazia()) {
            inicio = novo;
            fim = novo;
            return;
        }

        fim->prox = novo;
        fim = novo;
    }

    void imprimir() {
        No* aux = inicio;

        while (aux != NULL) {
            printf("%d -> ", aux->valor);
            aux = aux->prox;
        }

        printf("\n");
    }

    int tamanho() {
        return n;
    }

    void removerInicio() {
        if (tamanho() <= 1) {
            delete (inicio);
            inicio = NULL;
            fim = NULL;
            n = 0;
            return;
        }

        No* remover = inicio;
        inicio = inicio->prox;
        delete (remover);
        n--;
    }

    void removerFinal() {
        if (tamanho() <= 1) {
            delete (inicio);
            inicio = NULL;
            fim = NULL;
            n = 0;
            return;
        }

        No* penultimo = inicio;
        while (penultimo->prox != fim) {
            penultimo = penultimo->prox;
        }
        delete (fim);
        penultimo->prox = NULL;
        fim = penultimo;
        n--;
    }

    void inserir(int valor, int pos) {
        if (pos >= tamanho()) {
            inserirFinal(valor);
            return;
        }

        if (pos < 1) {
            inserirInicio(valor);
            return;
        }

        No* aux1 = inicio;
        for (int i = 0; i < pos - 1; i++) {
            aux1 = aux1->prox;
        }
        No* aux2 = aux1->prox;

        No* novo = new No(valor);
        aux1->prox = novo;
        novo->prox = aux2;
        n++;
    }

    void remover(int pos) {
        if (pos <= 1) {
            removerInicio();
            return;
        }

        if (pos >= tamanho()) {
            removerFinal();
            return;
        }

        No* aux1 = inicio;
        for (int i = 0; i < pos - 2; i++) {
            aux1 = aux1->prox;
        }
        No* remover = aux1->prox;
        No* aux2 = remover->prox;
        aux1->prox = aux2;
        delete (remover);
        n--;
    }

    void removerUltimosN(int N) {
        if (N >= tamanho()) {
            esvaziar();
        } else {
            int pos = tamanho() - N;
            while (pos > 0) {
                removerFinal();
                pos--;
            }
        }
    }

    void removerSegundoElemento() {
        if (tamanho() <= 1) {
            return;
        }

        No* remover = inicio->prox;
        inicio->prox = remover->prox;
        delete (remover);
        n--;
    }

    void inserirTamanhoNoFinal() {
        inserirFinal(tamanho());
    }

    void inserirNumerosDe1ateN(int N) {
        for (int i = 1; i <= N; i++) {
            inserirFinal(i);
        }
    }

    void inserirPenultimaPosicao(int valor) {
        if (tamanho() <= 1) {
            return;
        }

        No* aux1 = inicio;
        while (aux1->prox->prox != NULL) {
            aux1 = aux1->prox;
        }

        No* novo = new No(valor);
        novo->prox = aux1->prox;
        aux1->prox = novo;
        n++;
    }
};

int main() {
    Lista l;

    l.inserirInicio(10);
    l.inserirInicio(5);
    l.inserirInicio(8);
    l.inserirFinal(7);
    l.inserirFinal(3);
    l.inserir(13, 2);
    l.inserir(0, 0);
    l.inserir(50, 50);

    l.remover(4);
    l.remover(2);
    l.remover(1);

    l.removerUltimosN(2);
    l.removerSegundoElemento();
    l.inserirTamanhoNoFinal();
    l.inserirNumerosDe1ateN(5);
    l.inserirPenultimaPosicao(99);

    l.imprimir();

    printf("%d\n", l.tamanho());

    return 0;
}
