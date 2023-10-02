#include <stdio.h>
#include <stdlib.h>

typedef struct stNodoDoble
{
    int num;
    struct stNodoDoble* anterior;
    struct stNodoDoble* siguiente;

} stNodoDoble;

void mostrarListaDoble(stNodoDoble* lista);
stNodoDoble* inicLista();
stNodoDoble* cargaNodoDoble (int num);
stNodoDoble* agregarPpio(stNodoDoble* lista, stNodoDoble* nuevoNodo);
stNodoDoble* cargarLista(stNodoDoble* lista);
stNodoDoble* borrarPrimero(stNodoDoble* lista);
int capicuaCheck(stNodoDoble* lista);
stNodoDoble* borrarMedio (stNodoDoble* lista);

int main()
{
    int flag;

    stNodoDoble* lista = inicLista();
    lista = cargarLista(lista);
    mostrarListaDoble(lista);

    flag = capicuaCheck(lista);
    printf("\n\n%i", flag);

    lista = borrarMedio(lista);
    printf("\n\n");
    mostrarListaDoble(lista);
    return 0;
}

stNodoDoble* inicLista()
{
    return NULL;
}

stNodoDoble* cargaNodoDoble (int num)
{
    stNodoDoble* aux = (stNodoDoble*)malloc(sizeof (stNodoDoble));
    aux->num = num;
    aux->anterior = NULL;
    aux->siguiente = NULL;


    return aux;
}

stNodoDoble* agregarPpio(stNodoDoble* lista, stNodoDoble* nuevoNodo)
{
    if(!lista)
    {
        lista = nuevoNodo;
    }
    else
    {
        lista->anterior = nuevoNodo;
        nuevoNodo->siguiente = lista;
        lista = nuevoNodo;
    }
    return lista;
}

stNodoDoble* cargarLista(stNodoDoble* lista)
{
    stNodoDoble* nuevo;
    nuevo = cargaNodoDoble(1);
    lista = agregarPpio(lista, nuevo);

    nuevo = cargaNodoDoble(7);
    lista = agregarPpio(lista, nuevo);

    nuevo = cargaNodoDoble(6);
    lista = agregarPpio(lista, nuevo);

    nuevo = cargaNodoDoble(8);
    lista = agregarPpio(lista, nuevo);

    nuevo = cargaNodoDoble(1);
    lista = agregarPpio(lista, nuevo);
    return lista;
}

void mostrarListaDoble(stNodoDoble* lista)
{
    stNodoDoble* aux = lista;
    while (aux != NULL)
    {
        printf(" | %i | ", aux->num);
        aux = aux->siguiente;
    }
}

stNodoDoble* borrarPrimero(stNodoDoble* lista)
{

    stNodoDoble* aux = lista;

    if(aux)
    {
        lista = lista->siguiente;
        lista->anterior = NULL;
        free(aux);
    }
    else
    {
        printf("LA LISTA ESTA VACIA\n");
    }

    return lista;

}

int capicuaCheck(stNodoDoble* lista)
{
    stNodoDoble* aux = lista;

    int flag=0;
    int i = 0;
    while(aux->siguiente)
    {
        aux=aux->siguiente;
        i++;
    }

    while (aux && flag != 1)
    {

        if(aux->num == lista->num)
        {
            flag = 0;
        }
        else
        {
            return 1;
        }
        aux = aux->anterior;
        lista=lista->siguiente;
        i--;
    }

    return flag;
}

stNodoDoble* borrarMedio (stNodoDoble* lista)
{
    stNodoDoble* aux = lista;
    stNodoDoble* aux2 = lista;
    int i=1;
    int j=1;

    while(aux->siguiente)
    {
        aux=aux->siguiente;
        j++;
    }
    if (j%2==0) ///PAR
    {
        while (j != i+1)
        {
            aux2 = aux2->siguiente;
            aux = aux->anterior;
            i++;
            j--;
        }
        if(aux->num > aux2->num)
        {
            aux2=aux->anterior;
            aux2->siguiente = aux->siguiente;
            aux2 = aux->siguiente;
            aux2->anterior = aux->anterior;
            aux = NULL;
            free(aux);
        }
        else
        {
            aux->anterior=aux2->anterior;
            aux= aux2->anterior;
            aux->siguiente = aux2->siguiente;
            aux2 = NULL;
            free(aux2);
        }


    }
    else ///IMPAR
    {
        while (i!=j)
        {
            aux2 = aux2->siguiente;
            aux = aux->anterior;
            i++;
            j--;
        }
        aux2=aux2->anterior;
        aux2->siguiente = aux->siguiente;
        aux2 = aux->siguiente;
        aux2->anterior = aux->anterior;
        aux = NULL;
        free(aux);
    }

    return lista;

}


