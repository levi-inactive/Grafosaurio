#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <limits.h>
#include <cstdio>
using namespace std;
#define VISITED  1
#define UNVISITED -1
#define INF INT_MAX
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef stack<int> si;
using namespace std;
struct puente_visited {
    int x;
    int y;
    bool visited;
};
int N,V;
vector<puente_visited> puentes_visited;
vector<vii> AdjList;
si ruta;
int ThereIsAPath_Puentes(int x, int y){
    puente_visited aux;
    printf("looking for: %d %d\n",x,y);
    for(int i=0; i<(int)puentes_visited.size();i++){
        aux= puentes_visited[i];
        //printf("%d %d %d\n",puentes_visited[i].x,puentes_visited[i].y, puentes_visited[i].visited);
        if((x == aux.x && y == aux.y && !aux.visited) ||  (y == aux.x && x == aux.y && !aux.visited)){
            //printf("path [%d]\n", i);
            return i;
        }
    }
    printf("no path path\n");
    return -1;
}
void PuentesKonigsberg_DFS(int start, int current){
    if(current == start){
        bool solution =true;
        for(int i = 0; i < (int)puentes_visited.size();i++)
            if(!puentes_visited[i].visited)
                solution=false;
        if(solution){
            ruta.push(current);
            printf("SOLUTION: \n");
            si solution;
            while(!ruta.empty()){
                solution.push(ruta.top());
                ruta.pop();
            }
            while(!solution.empty()){
                printf("%d",solution.top());
                solution.pop();
                if(solution.size())
                    printf("->");
                else    
                    printf("\n");
            }
        }
    }
    printf("Nodo actual: %d\n",current);
    ruta.push(current);
    for(int j=0; j < (int)AdjList[current].size(); j++){
        ii v= AdjList[current][j];
        int tiap =ThereIsAPath_Puentes(current,v.first);
        if(tiap>-1){
            puentes_visited[tiap].visited=true;
            //printf("dfs(s, %d)\n",v.first);
            PuentesKonigsberg_DFS(start,v.first);
            puentes_visited[tiap].visited=false;
        }
    }
    ruta.pop();

} 
void GRAPH_ADJ_LIST(string file_name) {
        FILE * fp;
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
void GRAPH_ADJ_LIST(int N){
     int id, total_neighbors, weight;
        //---Adjacency List----
        V=N;
        AdjList.assign(V+1, vii()); // quick way to initialize AdjList with V entries of vii
        for (int i = 1; i <=V; i++) {
            scanf("%d", &total_neighbors);
            for (int j = 0; j < total_neighbors; j++) {
                scanf("%d %d", &id, &weight);
                //printf("%d - %d [%d]\n",i,id,weight);
                AdjList[i].push_back(ii(id, weight));
            }
        }
}
void PrintGraph() {
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
void LeerPuentes(int key){
    int P, x,y;
    if(key==1){
        GRAPH_ADJ_LIST("parte3_input/puentes_nodos_input.txt");
        //GRAPH_ADJ_LIST("parte3_input/pwsv_input.txt");
        FILE *fp;
        fp = fopen("parte3_input/puentes_edges_input.txt","r");
        //fp = fopen("parte3_input/pwse_input.txt","r");
        rewind(fp);
        fscanf(fp, "%d", &P);
        puente_visited aux;
        for (int i = 0; i < P; i++)
        {
            fscanf(fp, "%d %d", &x, &y);
            aux.x = x;
            aux.y = y;
            aux.visited = false;
            puentes_visited.push_back(aux);
        }
        fclose(fp);
    }else{
        scanf("%d", &N);
        GRAPH_ADJ_LIST(N);
        scanf("%d", &P);
        puente_visited aux;
        for (int i = 0; i < P; i++)
        {
            scanf("%d %d", &x, &y);
            aux.x = x;
            aux.y = y;
            aux.visited = false;
            puentes_visited.push_back(aux);
        }
    }
    printf("GRAPH: \n");
    PrintGraph();
    printf("PUENTES : \n");
    for(int i=0;i <P;i++)
        printf("%d %d %d\n",puentes_visited[i].x,puentes_visited[i].y, puentes_visited[i].visited);
}
int main(){

    int i_op;
    printf("Select an opotion\n");
    printf("1.- Read from file\n");
    printf("2.- Ingress values manually\n");
    scanf("%d", &i_op);
    system("pause");
    system("cls");
    LeerPuentes(i_op);
            //for(int i=1;i<AdjList_graph.getV();i++)
                //for(int j =0;j<(int)AdjList[i].size();j++){
                    ruta.push(1);
                    puentes_visited[0].visited=true;
                    //PuentesKonigsberg_DFS(i,AdjList[i][j].first);
                    PuentesKonigsberg_DFS(1,2);
                //}
    return 0;
}