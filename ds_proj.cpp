#include<bits/stdc++.h>
#define MAX 10000
#define V 9

using namespace std;
int des;
int src;

using namespace std;
//______________________________________________________________________________________________________________________________________

class metro_card
{
public:
  long metro_id;
  long long mob;
  int bal;
  int array[MAX];

public:
//__________________________________________________________________________________________________________________________________________//
  void create_metro()
{
 cout<<endl;
 cout<<"Enter your mobile no. : ";
 cin>>mob;
 cout<<endl;
 long metro_id= mob%10000;
 cout<<"New metro card created."<<endl;
 //cout<<"Metro card info --> "<<endl;
 cout<<endl<<"Your metro id is : "<<metro_id<<endl;
int amt;

cout<<endl<<"Enter recharge amount : Rs.";

cin>>amt;

array[metro_id]=amt;

cout<<endl<<"Your current balance is Rs."<<array[metro_id];

cout<<endl;

}
//____________________________________________________________________________________________________________________________________________________//
 int cal_bal(int fare)
  {
      int net_bal;
      cout<<bal;
  }
//_________________________________________________________________________________//
int get_bal(int metro_id)
{
    return array[metro_id];
}

void access_info(long long mob)
{
    cout<<"Your metro id is : "<<mob%10000<<endl<<" And your balance is "<<array[mob%10000];
}
//___________________________________________________________________________________________________________________//
void recharge(long long mob)
{
    int recharge_amt;

    cout<<"Your previous balance is : "<<array[mob%10000];
    cout<<"Enter recharge amount : ";
    cin>>recharge_amt;
    array[mob%10000] = array[mob%10000]+recharge_amt;
    cout<<"your new balance is"<<array[mob%10000];
}
//____________________________________________________________________________________________________________________________________________________________//


int minDistance(int dist[], bool sptSet[])
{

    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void printPath(int parent[], int j)
{

    if (parent[j]==-1)
        return;

    printPath(parent, parent[j]);

    printf(" -> %d ", j);
}


int printSolution(int dist[], int n, int parent[],int src)
{
  //  int src = 1;
    printf("Vertex\t         \t\tPath");
   // if(i==dest)
    {
        printf("\n%d -> %d \t\t \t\t%d ", src, des, src);
        printPath(parent, des);
    }
return dist[des];
}

int dijkstra(int graph[V][V], int src)
{
    int dist[V];  // The output array. dist[i] will hold
                  // the shortest distance from src to i

    // sptSet[i] will true if vertex i is included / in shortest
    // path tree or shortest distance from src to i is finalized
    bool sptSet[V];

    // Parent array to store shortest path tree
    int parent[V];

    // Initialize all distances as INFINITE and stpSet[] as false
    for (int i = 0; i < V; i++)
    {
        parent[src] = -1;
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V-1; count++)
    {
        // Pick the minimum distance vertex from the set of
        // vertices not yet processed. u is always equal to src
        // in first iteration.
        int u = minDistance(dist, sptSet);

        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Update dist value of the adjacent vertices of the
        // picked vertex.
        for (int v = 0; v < V; v++)

            // Update dist[v] only if is not in sptSet, there is
            // an edge from u to v, and total weight of path from
            // src to v through u is smaller than current value of
            // dist[v]
            if (!sptSet[v] && graph[u][v] &&
                dist[u] + graph[u][v] < dist[v])
            {
                parent[v]  = u;
                dist[v] = dist[u] + graph[u][v];
            }
    }

    // print the constructed distance array
 int x=   printSolution(dist, V, parent,src);
 return x;
}





};

int main()

{

    metro_card card2;



     cout<<"                                                  "<<"WELCOME TO DELHI METRO"<<endl<<endl;

     while(true)

{
    char x;
    cout<<endl<<endl<<endl;
    cout<<"         "<<"Do you want to access info of your metro card ? : Press ' I '"<<endl<<endl;
    cout<<"         "<<"Get a new metro card :  Press ' M '  "<<endl<<endl;
    cout<<"         "<<" Do you want to travel ? : Press ' T ' "<<endl<<endl;
    cout<<"         "<<"If you want to recharge your metro card : Press ' R '  "<<endl<<endl;
    cout<<endl<<"                              ";
    cin>>x;

    switch(x)

    {


case 'I':
    {
    long long no;
    cout<<"         "<<"Enter your mobile no.";
    cin>>no;
    card2.access_info(no);
    break; }
//_____________________________________________________________________________________________
case 'M':
    {
card2.create_metro();
break;
    }
//_______________________________________________________________________________________________
case 'T':
    {
        cout<<endl<<"            "<<"   Travel in metro!!!!!!"<<endl;
        cout<<endl<<"                              "<<"   Route : "<<endl;
        cout<<"       "<< "     1 -----(10)------- 2 ---(10)--------3  "<<endl;
        cout<<"       "<< "    /|                  |_____           |___ "<<endl;
        cout<<"       "<< "(10) |                 (20)   |__          | |_(10)"<<endl;
        cout<<"       "<< "  /  |                  |       (15)__     |     |"<<endl;
        cout<<"       "<< "0   (20)                8             |    |     4"<<endl;
        cout<<"       "<< "|    |         ___(13)__|             |  (15)    /"<<endl;
        cout<<"       "<< "(14) |________|       (10)            |___|   (10)"<<endl;
        cout<<"       "<< "  |__|                  |                 |___/"<<endl;
        cout<<"       "<< "     7--------(10)------6-------(10)------5"<<endl;


    int graph[V][V] = {{0, 10, 0, 0, 0, 0, 0, 14, 0},   //done0
                       {10, 0, 10, 0, 0, 0, 0, 20, 0},  //done1
                        {0, 10, 0, 10, 0, 15, 0, 0, 20},  //done2
                       {0, 0, 10, 0, 10, 15, 0, 0, 0},     //done 3
                       {0, 0, 0, 10, 0, 10, 0, 0, 0},     //done4
                       {0, 0, 15, 15, 10, 0, 10, 0, 0},     //done5
                       {0, 0, 0, 0, 0, 10, 0, 10, 10},     //done6
                       {14, 20, 0, 0, 0, 0, 10, 0, 13},      //done7
                       {0, 0, 20, 0, 0, 0, 10, 13, 0}
                      };
//int src;
cout<<endl;
cout<<"          "<<"   Enter starting station : ";
cin>>src;
cout<<endl;
cout<<"          "<<"   Enter destination : ";
cin>>des;
cout<<endl;
int y = card2.dijkstra(graph, src);
cout<<endl<<"   Fare : Rs."<<y;
cout<<endl<<"   Please enter your metro_id : ";
cin>>card2.metro_id;
int now = card2.get_bal(card2.metro_id);
cout<<"Fare is : Rs."<<y;
cout<<endl<<"   Your current balance is : Rs."<<now<<endl;
int new_bal = now-y;
if(new_bal>0)
{
card2.array[card2.metro_id] = new_bal;
cout<<endl<<"   Your new balance is : Rs."<<new_bal<<endl;

}
if(new_bal<0)
{
    cout<<endl<<"   Your balance is not enough to travel . Please recharge your metro card ."<<endl;
}
break;

}
//_______________________________________________________________________________________________________

case 'R' :
    {
    long  id;
    cout<<endl;
    cout<<endl<<"   Please enter your metro id :";
    cin>>id;
        card2.recharge(id);
    break;
    }

    }
    cout<<endl<<"   Do you want to continue : Enter 'Y' else 'N'"<<endl;
    char z;
    cin>>z;
    if(z!='Y')
        break;
}

return 0;

}


