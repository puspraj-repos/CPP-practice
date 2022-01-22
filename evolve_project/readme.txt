Contact : pujaiswa@microsoft.com

OVERVIEW

This is a C++ program and it takes two points as inputs, starting point and ending point and gives one of the shortest path from starting point to endpoint point.
Every point can be mapped with x and y value in coordinate axis starting with (1,1)

11 12 13 14 15 16 17 18
21 22 23 24 25 26 27 28
31 32 33 34 35 36 37 38
41 42 43 44 45 46 47 48
51 52 53 54 55 56 57 58
61 62 63 64 65 66 67 68
71 72 73 74 75 76 77 78
81 82 83 84 85 86 87 88

Every point represents one verte of the graph with 64 vertices in total.




VALIDATIONS : 

If the starting point user enters falls outside of above mentioned coordinates then the point is not accepted and user is supposed to enter that point again.
If the endpoint point user enters falls outside of above mentioned coordinates then the point is not accepted and user is supposed to enter that point again.


INPUTS 

Starting point in the form of (x,y) starting from (1,1) to (8,8)
Endpoint point in the form of (x,y) starting from (1,1) to (8,8)


FLOW OF PROGRAM 

Once the user enters the point, the program validates if those points lies within the specified range ( here (1,1) to (8,8)) 
After entering the points shortest_path function is called which is doint BFS with starting point until it finds the endpoint point and returns a stack of points to retrace the path.
At the end the path is displayed and program terminates.





PROBLEM UNDERSTANDING

The graph is a connected undirected graph with constant weight as 1, we can also ignore the weight as it is constant for every edge.
We needed to find the shortest path from starting node to ending node, both BFS and DFS can be used here, but BFS seems better option because it explores it's
neighbors first and the moment we reached end point, we can guarantee it is one of the shortest path. BFS algorithm is like a propagation from any specific point in all direction.
If we used DFS we might also require one extra variable to check the minimum steps taken and we might end up exploring entire graph which is unnecessary in most cases.


SPACE COMPLEXITY ALANYSIS 

For a chess board of size N X N we have N^2 vertices. Every vertex can have at max 8 edges, so we have 8N^2 edges, which is O(N^2).
For checking if the node is visited or not, I used a 2D array of size N X N.
I used a queue while performing BFS, as the size of queue cannot go more than the number of nodes, moreover I'm simultaneously popping the nodes once their neighbours are collected
We can say the space complexity of this problem is O(Vextex), considering N as 8, the space complexity will be O(N^2).


TIME COMPLEXITY ANALYSIS

At max we might end up exploring the entire graph, hence time complexity also becomes O(N^2) where N is 8. we are also using sometime to compute the neighbours of the node,
but that is computed in constant time. If we are computing neighbour for all node, then it will be kN^2, where k is constant. which results in O(N^2).



SAMPLE INPUT
Enter the starting position of knight (x, y)    8 8
Enter the final position of the knight (x, y)   4 5

SAMPLE OUTPUT

Starting point (8,8)
Final point (4,5)
one of the shortest path :
(8, 8)-->(7, 6)-->(6, 4)-->(4, 5)