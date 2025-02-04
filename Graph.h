#include<limits>
#define ExpertiseGroups(V) V->ExpertiseGroups
#define NextVertex(V) V->NextVertex
#define FirstEdge(V) V->FirstEdge
#define Name(E) E->Name
#define NextEdge(E) E->NextEdge
#define FirstVertex(E) E.FirstVertex

using namespace std;

typedef struct Vertex* adrVertex;
typedef struct Edge* adrEdge;

struct Edge {
    string Name;
    adrEdge NextEdge;
};

struct Vertex {
    string ExpertiseGroups;
    adrVertex NextVertex;
    adrEdge FirstEdge;
};

struct Graph {
    adrVertex FirstVertex;
};

void createGraph(Graph& G);
bool isEmpty(Graph G);
adrVertex createVertex(string expertiseGroup);
adrEdge createEdge(string name);
void addVertex(Graph& G, string expertiseGroup);
adrVertex findVertex(Graph G, string expertiseGroup);
void addEdge(Graph& G, string expertiseGroup, string name);
void insertEdge(adrVertex& V, string name);
void displayGroupMembers(Graph& G, string expertiseGroup);
void displayAllGroups(Graph G);
void displayGroupByName(Graph G, string name);
string deleteEdge(Graph& G, string expertiseGroup, string name);
void deleteEdgeInAllVertex(Graph& G, string name);
string deleteVertex(Graph& G, string expertiseGroup);
void menu();
int getIntInput(const string& message);
string getStringInput(const string& message);
