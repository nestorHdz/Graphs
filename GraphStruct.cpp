#include<iostream>
using namespace std;

/******************************************
  GRAPH STRUCT: The structure is composed of 2 data structs


 *****************************************
*/
//Graph using adjency matrix
#define MAXV 1000

//Node Struct
typedef struct Node_str{
  int y;
  int weight;
  struct Node_str *next;
}Node;

typedef struct graph_str{
  Node *graphNodes[MAXV+1];  /*adjacency info*/
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
  for(int i=1;i<=MAXV; i++)g->graphNodes[i]=NULL;


}

void insert_edge(graph *g, int x, int y, bool directed){
  //
  Node *p;
  p=(Node*)malloc(sizeof(Node));

  p->weight=0;

  p->y = y;
  p->next=g->graphNodes[x];
  g->graphNodes[x]=p;
  g->degree[x]++;

  if(directed==false)
      insert_edge(g,y,x,true);
  else
      g->nedges ++;
}


void insert_edge_w(graph *g, int x, int y, bool directed,int wx, int wy){
  //
  Node *p;
  p=(Node*)malloc(sizeof(Node));

  p->weight=wy;
  p->y = y;
  p->next=g->graphNodes[x];
  g->graphNodes[x]=p;
  g->degree[x]++;

  if(directed==false)
      insert_edge_w(g,y,x,true,wy,wx);
  else
      g->nedges ++;
}


void printGraph(graph *g){
  Node *p;
  cout<<"flag\n";
  for(int i=1; i<=g->nvertices; i++){
    printf("%d: ",i);
    p = g->graphNodes[i];
    while(p !=NULL){
      printf("%d(%d)->",p->y,p->weight);
      p=p->next;
    }
    printf("\n");
  }
}
