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

class GRAPH_ADJ_LIST {                         
private:
  vector<vii> AdjList; 
  vi dfs_num;
  int V;
public:
    GRAPH_ADJ_LIST(){}
    GRAPH_ADJ_LIST(string file_name) {
    FILE * fp;
        int id, total_neighbors, weight;
        //fp = fopen("graph_input/AdjList_in.txt","r");
        fp = fopen(file_name.c_str(),"r");
        rewind(fp);
        //---Adjacency List----
        fscanf(fp,"%d", &V);
        AdjList.assign(V+1, vii()); // quick way to initialize AdjList with V entries of vii
        for (int i = 1; i <=V; i++) {
            fscanf(fp,"%d", &total_neighbors);
            for (int j = 0; j < total_neighbors; j++) {
                fscanf(fp,"%d %d", &id, &weight);
                //printf("%d - %d [%d]\n",i,id,weight);
                AdjList[i].push_back(ii(id, weight));
            }
        }
        fclose(fp);
    }
    int getV(){
        return V;
    }
    int GetGraphGrade(){
        int grade = 0;
        for(int i = 1; i <= V; i++){
            grade += (int)AdjList[i].size();
        }
        return grade;
    }
    GRAPH_ADJ_LIST(int N){

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
        for (int i = 1; i <= V; i++) {
            vii aux = AdjList[i];
            printf("%d :\n",i);
            for (int j = 0; j < aux.size(); j++) {
                printf("\t -> %d [%d]\n",aux[j].first, aux[j].second);
            }
        }
    }
    bool IsConvex(int i){
        dfs_num.assign(V+1,UNVISITED);
        DFS(i);
        for(int j=1; j<=V; j++)
            if(dfs_num[j]==UNVISITED)
                return false;
        return true;
    }
    void DFS(int i){
        dfs_num[i]=VISITED;
        for(int j=0; j < (int)AdjList[i].size();j++){
            ii v = AdjList[i][j];
            if(dfs_num[v.first] == UNVISITED)
                DFS(v.first);
        }

    }
    void PrintGradeNodes(){
        for (int i = 1; i <= V; i++) {
            int len= (int)AdjList[i].size();
            printf("nodo: %d grado: %d\n",i,len);
        }
    }
    ii GetGradeNodes(){
        //.first ODD
        //.second EVEN
        int cOdd=0;
        int cEven=0;
        for (int i = 1; i <= V; i++) {
            int s = (int)AdjList[i].size();
            if( s & ((1<<1)-1) ) //Fancy way to calculate s%2 with bit manipulation
                cOdd++;
            else   
                cEven++;
        }

        return make_pair(cOdd,cEven);
    }
    int GetEvenGradeNodes(){
        int cont=0;
        for (int i = 1; i <= V; i++) {
            int len= (int)AdjList[i].size();
            printf("nodo: %d grado: %d\n",i,len);
        }
    }

};
class GRAPH_ADJ_MATRIX{
private:
    int V;
    int AdjMat[100][100];
public:
    GRAPH_ADJ_MATRIX(){}
    GRAPH_ADJ_MATRIX(string file_name){
        FILE *fp;
        fp = fopen(file_name.c_str(),"r");
        rewind(fp);
        //Adjancecy Matrix
        fscanf(fp,"%d", &V);                         // we must know this size first!
                        // remember that if V is > 100, try NOT to use AdjMat!
        for (int i = 1; i <= V; i++)
            for (int j = 1; j<= V; j++)
                fscanf(fp,"%d", &AdjMat[i][j]);
        fclose(fp);
    }
    GRAPH_ADJ_MATRIX(int N){
        //Adjancecy Matrix
        V=N;                         // we must know this size first!
                        // remember that if V is > 100, try NOT to use AdjMat!
        for (int i = 1; i <= V; i++)
            for (int j = 1; j<= V; j++)
                scanf("%d", &AdjMat[i][j]);
    }
    void PrintGraph(){
        for (int i = 1; i <= V; i++)
            for (int j = 1; j<= V; j++)
                if(AdjMat[i][j]!=0)
                    printf("%d - %d [%d]\n",i,j, AdjMat[i][j]);
    
    }

};

class   GRAPH_EDGE_LIST{
private:
    int E;
    priority_queue< pair<int, ii> > EdgeList;   // one way to store Edge List
public:
    GRAPH_EDGE_LIST(){}
    GRAPH_EDGE_LIST(string file_name){
        int a,b,weight;
        FILE *fp = fopen(file_name.c_str(),"r");
        fscanf(fp,"%d",&E);
        for(int i =0; i<E; i++){
            fscanf(fp,"%d %d %d",&a,&b,&weight);
            EdgeList.push(make_pair(-weight,ii(a,b))); //trick to rever sort order 
        }   
    }
    GRAPH_EDGE_LIST(int N){
        int a,b,weight;
        E= N;
        for (int i = 0; i < E; i++) {
            scanf("%d %d %d", &a, &b, &weight);
            EdgeList.push(make_pair(-weight, ii(a, b))); // trick to reverse sort order
        }
    }
    void PrintGraph(){     
        // edges sorted by weight (smallest->largest)
        for (int i = 0; i < E; i++) {
            pair<int, ii> edge = EdgeList.top(); EdgeList.pop();
            // negate the weight again
            printf("weight: %d (%d-%d)\n", -edge.first, edge.second.first, edge.second.second);
        }
    }
};
class GRAPH_LINKED_LIST{
    private:
    

};