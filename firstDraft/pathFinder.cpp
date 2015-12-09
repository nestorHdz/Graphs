#include <iostream>
#include <queue>
#include "LinkedList.cpp"
using namespace std;


/**************
  GRAPH STRUCT
 *************
*/
//Graph using adjency matrix
#define MAXV 1000

//Node Struct
typedef struct edgenode_str{
  int y;
  int weight;
  struct edgenode_str *next;
}edgenode;

typedef struct graph_str{
  edgenode *edges[MAXV+1];  /*adjacency info*/
  int degree[MAXV+1];       /**/
  int nvertices;            /*number of vertices in the graph*/
  int nedges;               /*number of edges in the graph*/
  bool directed;            /*is the graph directed?*/
}graph;

/**************
  Graph Utilities
 *************
*/
void initialize_graph(graph *g, bool directed){

  g->nvertices=0;
  g->nedges=0;
  g->directed=directed;

  for(int i=1;i<=MAXV; i++)g->degree[i]=0;
  for(int i=1;i<=MAXV; i++)g->edges[i]=NULL;


}

void insert_edge(graph *g, int x, int y, bool directed){
  //
  edgenode *p;
  p=(edgenode*)malloc(sizeof(edgenode));

  p->weight=0;

  p->y = y;
  p->next=g->edges[x];
  g->edges[x]=p;
  g->degree[x]++;

  if(directed==false)
      insert_edge(g,y,x,true);
  else
      g->nedges ++;
}


void printGraph(graph *g){
  edgenode *p;
  //cout<<"flag\n";
  for(int i=1; i<=g->nvertices; i++){
    printf("%d: ",i);
    p = g->edges[i];
    while(p !=NULL){
      printf("%d(%d)->",p->y,p->weight);
      p=p->next;
    }
    printf("\n");
  }
}


/**************
  GRAPH traversal
 *************
*/
bool processed [MAXV+1];
bool discovered [MAXV+1];
int parents[MAXV+1];


void initialize_search(graph *g){
  for(int i=1; i<=g->nvertices;i++){
    processed[i]=discovered[i]=false;
    parents[i]=-1;
  }
}

void traversal(graph *g, int start){
  queue <int> q;
  int v;
  int y;
  edgenode *p;

  q.push(start);
  discovered[start] =true;
  while(q.size()!=0){
    v=q.front();
    q.pop();
    //pre processing
    processed[v]=true;
    p=g->edges[v];
    while(p!=NULL){       /*go over adjency list*/
      y=p->y;
      if((processed[y]==false)||g->directed){
        //Process edge  here!
      }
      if(discovered[y]==false){
        q.push(y);
        discovered[y]=true;
        parents[y]=v;
      }
      p=p->next;
    }
    //Post processing Vertex
  }
}

int MAXINT = numeric_limits<int>::max();

void dijkstra(graph *g, int start){
  int i;
  edgenode *p;
  bool intree[MAXV+1];
  int distance[MAXV+1];
  int v;
  int w;
  int weight;
  int dist;

  for(int i=1; i<=g->nvertices; i++){
    intree[i]=false;
    distance[i]=MAXINT;
    parents[i]=-1;
  }
  distance[start]=0;
  v=start;
  while(intree[v]==false){
    intree[v]=true;
    p=g->edges[v];
    while(p!=NULL){
      w=p->y;
      weight=p->weight;
      if(distance[w]>(distance[v]+weight)){
        distance[w]=distance[v]+weight;
        parents[w]=v;
      }
      p=p->next;
    }
    v=1;
    dist=MAXINT;
    for(i=1; i<=g->nvertices;i++){
      if((intree[i]==false)&&(dist>distance[i]) ){
        dist=distance[i];
        v=i;
      }
    }
  }
}

/**************
  Path finder
 *************
*/

void find_path_helper(int start, int end, int parents[]){

  if((start==end)||(end==-1))
    //Recursion base case
    printf("%d->",start);
  else{
    //Track path
    find_path_helper(start,parents[end],parents);
    printf(" %d->", end);
  }

}

void find_path(int start, int end, int parents[]){
  find_path_helper(start,end, parents);
}

void pathFinder(int start, int end, graph *g){
  int numberOfPaths=0;
  edgenode *node=g->edges[end];
  //cout<<"*****Index:"<<end<< "adjacency nodes:"<<node->y<< ","<<node->next->y<<endl;
  while(node!=NULL){
      cout<<"************"<<node->y<<endl;
      numberOfPaths++;
      find_path( start, node->y, parents);cout<<end<<endl;
      node=node->next;
  }
  cout<<"numberOfpaths for end:"<<end<<" is "<<numberOfPaths<<endl;
}

int main(){
  /////////////GRAPH 1
  graph *g3=(graph*)malloc(sizeof(graph));
  initialize_graph(g3,false);
  g3->nvertices=10;
  //construction of graph test 1
  insert_edge(g3,1,2,false);
  insert_edge(g3,2,4,false);
  insert_edge(g3,4,5,false);
  insert_edge(g3,5,7,false);
  insert_edge(g3,1,3,false);
  insert_edge(g3,3,4,false);
  insert_edge(g3,1,6,false);
  insert_edge(g3,6,7,false);
  printGraph(g3);
  traversal(g3,1);
  int start=1;
  int end=7;
  pathFinder(start,end,g3);
  //find_path(1,5,parents);





}
