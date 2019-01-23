#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <limits.h>
#include <cstdio>
#include "GRAPH.h"
using namespace std;
GRAPH_ADJ_LIST AdjLgraph;

int main(){
    
    int i_op;
    int N;
    printf("Select an opotion\n");
    printf("1.- Read from file\n");
    printf("2.- Ingress values manually\n");
    scanf("%d", &i_op);
    if (i_op == 1)
    {
        printf("Reading from file :)\n");
        AdjLgraph = GRAPH_ADJ_LIST("graph_input/AdjList_input.txt");
    }
    else
    {
        scanf("%d", &N);
        AdjLgraph = GRAPH_ADJ_LIST(N);
        
    }
    AdjLgraph.PrintGraph();
    system("pause");
    system("cls");
    
    while(true){
        printf("\nQue deseas hace con el grafo?\n\n");
        printf("1.\tCalcular y mostrar el grado de cada nodo de un grafo.\n");
        printf("2.\tDeterminar si un grafo dado es conexo. \n");
        printf("3.\tReportar el numero de nodos con grado par e impar \n\t\tde un grafo G para determinar si es o no un grafo euleriano. (Ver propiedad)\n");
        printf("4.\tReportar si un grafo G es susceptible de ser recorrido (traversable).\n");
        printf("5.\tMuestre si dos grafos dados son o no isomorfos. (Ver propiedad)\n");
        printf("6.\tSALIR\n");
        scanf("%d",&i_op);
        bool IsConvex;
        ii gn;
        if(i_op==6)
            break;
        switch (i_op){
            case 1:
                AdjLgraph.PrintGradeNodes();
                break;
            case 2:
                AdjLgraph.IsConvex(1) ? printf("Es convexo\n") : printf("No es convexo\n");
                break;
            case 3:
                IsConvex = AdjLgraph.IsConvex(1);
                gn = AdjLgraph.GetGradeNodes();
                printf("El grafo tiene: %d Nodos Impares\n",gn.first);
                printf("El grafo tiene: %d Nodos Pares\n",gn.second);
                printf("POR LO TANTO: ");
                if(IsConvex && !gn.first)
                    printf("El grafo es Euleriano\n");
                else
                    printf("El grafo NO es Eucleriano\n");
                break;
            case 4:
                IsConvex = AdjLgraph.IsConvex(1);
                gn = AdjLgraph.GetGradeNodes();
                printf("El grafo tiene: %d Nodos Impares\n",gn.first);
                printf("El grafo tiene: %d Nodos Pares\n",gn.second);
                printf("POR LO TANTO: ");
                if(IsConvex && !gn.second)
                    printf("El grafo es susceptible de ser recorrido (traversable) \n");
                else
                    printf("El grafo NO es susceptible de ser recorrido (traversable)\n");
                break;
            case 5: 
                
                break;
        }
        system("pause");
        system("cls");
    }
    return 0;
}