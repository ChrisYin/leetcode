//
// Created by zhenguo on 19-3-25.
//

/*
 * dijkstra's shortest path first algorithm
 *
 * goal: find the shortest path between that node and every node
 *
 * 1. create verticeSet and sptSet
 * verticeSet: contains all node
 * sptSet: shortest path tree set
 * 2. create distance value array
 * root: 0
 * other: infinite
 * 3. while sptSet doesn't include all vertices
 *
 * a. pick u which is not in sptSet and has minimum distance value
 * b. include u to sptSet
 * c. update distance value of all adjacent vertices of u
 *    if dist(u) + edge(u, v) < dist(v)
 *    then update dist(v)
 *
 */

#include <stdio.h>
#include <iostream>
using namespace std;

#define V 2
typedef int graph[V][V];


void djikstra(){

}


int main(){
    graph network = {{1,1},{1,1}};
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            cout<<network[i][j]<<endl;
        }
    }
    return 0;
}

