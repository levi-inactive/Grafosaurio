#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <limits.h>
#include <cstdio>
using namespace std;
#define VISITED 1
#define UNVISITED -1
#define INF INT_MAX
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef stack<int> si;
using namespace std;
struct nodo_visited
{
    int x;
    int y;
    bool visited;
};
int N, V;
vector<nodo_visited> trazos_visited;
vector<vii> AdjList;
si ruta;
int ThereIsAPath_trazos(int x, int y)
{
    nodo_visited aux;

    printf("looking for: %d %d\n", x, y);
    for (int i = 0; i < (int)trazos_visited.size(); i++)
    {
        aux = trazos_visited[i];
        //printf("%d %d %d\n",trazos_visited[i].x,trazos_visited[i].y, trazos_visited[i].visited);
        if ((x == aux.x && y == aux.y && !aux.visited) || (y == aux.x && x == aux.y && !aux.visited))
        {
            //printf("path [%d]\n", i);
            return i;
        }
    }
    printf("no path path\n");
    return -1;
}
void trazos_DFS(int current)
{
    bool solution = true;
    for (int i = 0; i < (int)trazos_visited.size(); i++)
        if (!trazos_visited[i].visited)
            solution = false;
    if (solution)
    {
        ruta.push(current);
        printf("SOLUTION: \n");
        si solution;
        while (!ruta.empty())
        {
            solution.push(ruta.top());
            ruta.pop();
        }
        while (!solution.empty())
        {
            printf("%d", solution.top());
            solution.pop();
            if (solution.size())
                printf("->");
            else
                printf("\n");
        }
    }
    printf("Nodo acutal:  %d\n", current);
    ruta.push(current);
    for (int j = 0; j < (int)AdjList[current].size(); j++)
    {
        ii v = AdjList[current][j];
        int tiap = ThereIsAPath_trazos(current, v.first);
        if (tiap > -1)
        {
            trazos_visited[tiap].visited = true;
            //printf("trazos_DFS(s, %d)\n", v.first);
            trazos_DFS(v.first);
            trazos_visited[tiap].visited = false;
        }
    }
    ruta.pop();
}
void GRAPH_ADJ_LIST(string file_name)
{
    FILE *fp;
    int id, total_neighbors, weight;
    //fp = fopen("graph_input/AdjList_in.txt","r");
    fp = fopen(file_name.c_str(), "r");
    rewind(fp);
    //---Adjacency List----
    fscanf(fp, "%d", &V);
    AdjList.assign(V + 1, vii()); // quick way to initialize AdjList with V entries of vii
    for (int i = 1; i <= V; i++)
    {
        fscanf(fp, "%d", &total_neighbors);
        for (int j = 0; j < total_neighbors; j++)
        {
            fscanf(fp, "%d %d", &id, &weight);
            //printf("%d - %d [%d]\n",i,id,weight);
            AdjList[i].push_back(ii(id, weight));
        }
    }
    fclose(fp);
}
void GRAPH_ADJ_LIST(int N)
{
    int id, total_neighbors, weight;
    //---Adjacency List----
    V = N;
    AdjList.assign(V + 1, vii()); // quick way to initialize AdjList with V entries of vii
    for (int i = 1; i <= V; i++)
    {
        scanf("%d", &total_neighbors);
        for (int j = 0; j < total_neighbors; j++)
        {
            scanf("%d %d", &id, &weight);
            //printf("%d - %d [%d]\n",i,id,weight);
            AdjList[i].push_back(ii(id, weight));
        }
    }
}
void PrintGraph()
{
    for (int i = 1; i <= V; i++)
    {
        vii aux = AdjList[i];
        printf("%d :\n", i);
        for (int j = 0; j < aux.size(); j++)
        {
            printf("\t -> %d [%d]\n", aux[j].first, aux[j].second);
        }
    }
}
void LeerTrazos(int key)
{
    int P, x, y;
    nodo_visited aux;
    if (key == 1)
    {
        //GRAPH_ADJ_LIST("parte3_input/tv_input.txt");
        GRAPH_ADJ_LIST("parte3_input/twsv_input.txt");
        FILE *fp;
        //fp = fopen("parte3_input/te_input.txt", "r");
        fp = fopen("parte3_input/twse_input.txt","r");
        rewind(fp);
        fscanf(fp, "%d", &P);
        for (int i = 0; i < P; i++)
        {
            fscanf(fp, "%d %d", &x, &y);
            aux.x = x;
            aux.y = y;
            aux.visited = false;
            trazos_visited.push_back(aux);
        }
        fclose(fp);
    }
    else
    {
        scanf("%d", &N);
        GRAPH_ADJ_LIST(N);
        scanf("%d", &P);
        for (int i = 0; i < P; i++)
        {
            scanf("%d %d", &x, &y);
            aux.x = x;
            aux.y = y;
            aux.visited = false;
            trazos_visited.push_back(aux);
        }
    }
    PrintGraph();
    for (int i = 0; i < (int)trazos_visited.size(); i++)
        printf("%d %d %d\n", trazos_visited[i].x, trazos_visited[i].y, trazos_visited[i].visited);
}
int main()
{
    int i_op;
    printf("Select an opotion\n");
    printf("1.- Read from file\n");
    printf("2.- Ingress values manually\n");
    scanf("%d", &i_op);
    system("pause");
    system("cls");
    LeerTrazos(i_op);
    /*ruta.push(4);
    trazos_visited[5].visited = true;
    trazos_DFS(3);
    */
   ruta.push(1);
   trazos_visited[0].visited = true;
   trazos_DFS(2);
    return 0;
}