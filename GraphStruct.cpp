#include<iostream>
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


void insert_edge_w(graph *g, int x, int y, bool directed,int wx, int wy){
  //
  edgenode *p;
  p=(edgenode*)malloc(sizeof(edgenode));

  p->weight=wy;
  p->y = y;
  p->next=g->edges[x];
  g->edges[x]=p;
  g->degree[x]++;

  if(directed==false)
      insert_edge_w(g,y,x,true,wy,wx);
  else
      g->nedges ++;
}


void printGraph(graph *g){
  edgenode *p;
  cout<<"flag\n";
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
