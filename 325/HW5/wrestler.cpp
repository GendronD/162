/*
 * Author: Devin Gendron
 * Assignment: Homework 5 - Question 4: Wrestlers
 * Date Due: July 29th - 11:59PM
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>


// Struct for Edge Pairs
struct EdgePairs {
    std::string start;
    std::string end;
};

// Struct for Vertex and it's variables
struct Vertex {
    std::string name;
    std::string color;
    std::string type;
    int num;
};

//CITATION: https://www.geeksforgeeks.org/graph-and-its-representations/
// Adj List is created and used to form a map to update Vertexes
void createAdjacencyList(std::vector<Vertex> adj_list[], std::vector<Vertex> vectors, std::string u, std::string v)
{
    Vertex V;
    int v_num;
    Vertex U;
    int u_num;
    for(int i = 0; i < vectors.size(); i++) // For number of vertexes
    {
        if(u == vectors[i].name)    // if starting point name is equal to current vertex name
        {
            u_num = i;  //set starting num
            V = vectors[i]; //set end vector
        }
        if(v == vectors[i].name)    //if end point name is equal to current vertex name
        {
            v_num = i;  // set ending num
            U = vectors[i]; // set start vector
        }
    }

    adj_list[v_num].push_back(V);   //push to adj list in proper location
    adj_list[u_num].push_back(U);   //push to adj list in proper location
}

//CITATION: https://www.geeksforgeeks.org/graph-and-its-representations/
// Print Graph for debugging while creating algorithm
void printGraph(std::vector<Vertex> adj_list[], std::vector<Vertex> vectors)
{
    for (int v = 0; v < vectors.size(); ++v)
    {
        std::cout << "\n Adjacency list of vertex "
             << vectors[v].name << "\n" << vectors[v].name;

        for(int j = 0; j < adj_list[v].size(); j++)
        {
            std::cout << "-> " << adj_list[v][j].name << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::endl;
}

// Print Queue used for debugging while creating algorithm
void printQueue(std::queue <Vertex> q)
{
    std::cout << "print queue: ";
    while(!q.empty()){
        std::cout << q.front().name <<" ";
        q.pop();
    }
    std::cout << std::endl;
}

//BFS algorithm
int BFS_Good_Bad(std::vector<Vertex> adj_list[], Vertex &wrestler, std::vector<Vertex> &vectors)
{
    Vertex *u;  //current vertex
    wrestler.color = "GRAY";
    wrestler.type = "GOOD";

    //create queue
    std::queue <Vertex> Q;
    Q.push(wrestler);   //push current vertex to queue

    while(!Q.empty())   //while not empty
    {
        u = &Q.front();  //wrestler set to u
        Q.pop();    // pop from queue

        int i = 0;
        for(; i < vectors.size(); i++)
        {
            if(vectors[i].name == u->name)  //if current vertex is equal to name
            {
                for(int j = 0; j < adj_list[i].size(); j++) //read through adjacency list for this vertex
                {
                    if(u->color == "GRAY" && vectors[adj_list[i][j].num].type == u->type)  //if on same team
                    {
                        return 1;
                    }
                    if(vectors[adj_list[i][j].num].color == "WHITE")  //if unvisited
                    {
                        adj_list[i][j].color = "GRAY";   //set to visited
                        vectors[adj_list[i][j].num].color = "GRAY";
                        if(u->type == "GOOD")   //if good set to bad
                        {
                            adj_list[i][j].type = "BAD";
                            vectors[adj_list[i][j].num].type = "BAD";
                        }
                        else if(u->type == "BAD")  //if bad set to good
                        {
                            adj_list[i][j].type = "GOOD";
                            vectors[adj_list[i][j].num].type = "GOOD";
                        }
                        Q.push(vectors[adj_list[i][j].num]);    //push these vectors in adj list to queue
                    }
                }
            }
        }
        wrestler.color = "BLACK";   //mark as completed
        //printQueue(Q);
    }
    return 0;
}


void GoodVsBad(std::vector<Vertex> adj_list[], std::vector<Vertex> &vectors, int &end)
{

    for(int i = 0; i < vectors.size(); i++)
    {
        if(vectors[i].color == "WHITE") //if vectors are white, bfs on them from that source point
        {
            //call bfs function
            end = BFS_Good_Bad(adj_list, vectors[i], vectors);
        }
        if(end == 1)
        {
            i = vectors.size(); //if bipartite graph, force end
        }
    }
}

int main(int argc, char* argv[]) {
    //create file entry portion
    //std::string fileName;
    const char *fileName;

    std::cout << "Accessing wrestler.txt file..." << std::endl;
    //fileName= "wrestlers.txt";
    //fileName = "/Users/devingendron/CLionProjects/HW5/wrestler.txt";

    fileName = argv[1];

    std::ifstream inputFile;
    //inputFile.open(fileName.c_str());
    inputFile.open(fileName);

    if(inputFile.fail()) {
        std::cout << "wrestler.txt Failed to Open." << std::endl;
    }
    else if(!inputFile.fail()) {
        std::cout << "wrestler.txt Opened - Reading..." << std::endl;

        int read;
        std::string readString;
        Vertex currentVertex;
        EdgePairs edge;
        std::vector<Vertex> vectors;
        std::vector<EdgePairs> edges;
        int end = 0;

        //read vectors
        inputFile >> read;
        for(int i = 0; i < read; i++)
        {
            inputFile >> readString;
            currentVertex.name = readString;
            currentVertex.color = "WHITE";
            currentVertex.num = i;
            vectors.push_back(currentVertex);
        }

        //read edges
        inputFile >> read;
        for(int i = 0; i < read; i++)
        {
            inputFile >> edge.start;
            inputFile >> edge.end;
            edges.push_back(edge);
        }

        //initialize adjacency list
        std::vector<Vertex> adj_list[vectors.size()];

        //create the list
        for(int i = 0; i < edges.size(); i++)
        {
            createAdjacencyList(adj_list, vectors, edges[i].start, edges[i].end);
        }

        //printGraph(adj_list, vectors);

        //bfs on all vertexes to determine if possible/impossible and babyfaces/heels
        GoodVsBad(adj_list, vectors, end);

        //if yes
        if(end == 0)
        {
            std::cout << std::endl;
            std::cout << std::endl;
            std::cout << "Yes, possible" << std::endl;
            std::cout << "Babyfaces: ";
            for(int i = 0; i < vectors.size(); i++)
            {
                if(vectors[i].type == "GOOD")
                {
                    std::cout << vectors[i].name << " ";
                }
            }
            std::cout << std::endl;
            std::cout << std::endl;
            std::cout << "Heels: ";
            for(int i = 0; i < vectors.size(); i++)
            {
                if(vectors[i].type == "BAD")
                {
                    std::cout << vectors[i].name << " ";
                }
            }
            std::cout << std::endl;
            std::cout << std::endl;
        }
        else
        {
            //if no
            std::cout << std::endl;
            std::cout << std::endl;
            std::cout << "Impossible" << std::endl;
            std::cout << std::endl;
            std::cout << std::endl;
        }
    }
    std::cout << "BabyFace/Heels Program Ending" << std::endl;

    return 0;
}