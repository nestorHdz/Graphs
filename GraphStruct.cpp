#include<iostream>
using namespace std;

/******************************************
  GRAPH STRUCT
  The structure is composed of 2 data structs:
  ----> A Node struct, which holds the information regarding id, weight or any other convenient data.
        It also keeps a pointer to another node. Linking the nodes of a graph is useful when creating
        the adjacency matrix, which holds the information of the nodes that are connected to each node
        in the graph.
        The adjacency matrix looks something like this:

    Array of linkedList       which Nodes have a connection with the node
              [1]             4-->5
              [2]             1-->8-->10
              [.]
              [.]
              [n]             20-->50

     Notice that in the case that the index appears in its own linkedList this means the node its
     connected to itself. And printing the adjacency matrix for that index will look like:
               [1]             4-->5-->1

               This means the Node with id 1 has a conexion with nodes 4, 5 and itself.


----> A graph struct:
      The graph struct wraps the adjacency matrix plus another useful data, like the number of
      vertices (number of nodes), and the number of edges(conexions between nodes). In many algorithm
      texts the graph is often referred as G(V,E).

      There is an important bool value to define if a graph is directed or indirected.
      In this structure the default value is set false for directed, this means that
      everytime you connect a node to another you will have a bidirectional conexion from A-->B
      and B-->A, this will be reflected in the adjacency matrix, where each index will have the
      other in the corresponding linked list.


      Adjacency matrix in a undirected conexion (between A and B)
      [A] B-->D-->F...
      [B] A-->S-->K...

      Adjacency matrix in a directed conexion (between A --> B)
      [A] B-->D-->F...
      [B] S-->K...



 *****************************************
*/
//Graph using adjency matrix
#define MAXV 1000

//Node Struct
typedef struct Node_str{
  int id;                   /*Graph id*/
  int weight;               /*Weight*/
  struct Node_str *next;
}Node;

typedef struct graph_str{
  Node *graphNodes[MAXV+1];  /*adjacency matrix*/
  int degree[MAXV+1];       /*Keeps the number of conexions for each single Node*/
  int nvertices;            /*number of vertices in the graph*/
  int nedges;               /*Number of conexions within thhe whole graph*/
  bool directed;            /*is the graph directed?*/
}graph;

/**************
  Graph Utilities:
  This are the functions that make use of the graph structure.
  The most important is the insert_edge function, which connect two nodes in the graph and can
  be used as a base to read larger data sets to construct a larger graph.

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

  p->id = y;
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
  p->id = y;
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
      printf("%d(%d)->",p->id,p->weight);
      p=p->next;
    }
    printf("\n");
  }
}
