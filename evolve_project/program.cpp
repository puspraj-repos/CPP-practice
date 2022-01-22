#include <bits/stdc++.h>
using namespace std;

// x,y

// 00  01  02  03  04  05 
// 10  11  12  13  14  15
// 20  21  22  23  24  25
// 30  31  32  33  34  35
// 40  41  42  43  44  45
// 50  51  52  53  54  55

// knight's move from (x,y) ==> (x-1, y-2), (x+1, y-2), (x+2,y-1), (x+2, y+1), (x+1,y+2), (x-1, y+2), (x-2, y+1), (x-2, y-1)
// at max we can 8 edges from each node. total number of edges can be 8n
// the BFS or DFS algorithm executes with O(v+e) time complexity.
// The space complexity is O(n), where n is number of nodes




//point is a class which represents specific point 

class point
{
public:
    int x, y;

    //Member function to take inputs
    void input(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};


//Function to check if the specific point lies within the chessboard or not.
bool is_inside(int x, int y)
{
    if((x >= 0 and x < 8) and (y >= 0 and y < 8))
    {
        return true;
    }
    else 
    {
        return false;
    }
}

//while generating neighbours, i represents y coordinate and j represents x coordinate of coordinate axis.

vector<point> generate_neighbours(int x, int y)
{
    vector<point> neighbours;
    point temp_cell;

    for (int i = -2; i <= 2; i++)
    {
        for (int j = -2; j <= 2; j++)
        {
            if(abs(i) != abs(j) and i!= 0 and j != 0)
            {
                if(is_inside(x + j, y + i))
                {
                    temp_cell.input(x + j, y + i);
                    neighbours.push_back(temp_cell);
                }
            }
        }
        
    }
    return neighbours;
}


//Function to find the shortest path
stack<point> shortest_path(point start, point end)
{

    
    // chessboard array is used to check visited cells, previous array is used to track the path

    int chessboard[8][8]={0};
    stack<point> path;
    vector<point> neighbours;
    point temp_cell = start;
    queue<point> cells;
    vector<point> previous[8];
    for (int i = 0; i < 8; i++)
    {
        previous[i].resize(8,{-1, -1});
    }

    cells.push(start);
    int count = 0;
    // do while loop until you explore all vertex or find the end point
    do
    {
        temp_cell = cells.front();
        cells.pop();
        if(chessboard[temp_cell.x][temp_cell.y] == 0)
        {
            chessboard[temp_cell.x][temp_cell.y] = 1;
            neighbours = generate_neighbours(temp_cell.x, temp_cell.y);
            for (int i = 0; i < neighbours.size(); i++)
            {
                if(chessboard[neighbours[i].x][neighbours[i].y] == 0)
                {
                    cells.push(neighbours[i]);
                    if(previous[neighbours[i].x][neighbours[i].y].x == -1)
                    {
                        previous[neighbours[i].x][neighbours[i].y] = temp_cell;
                    }
                }
            }
            
        }
    }while( (temp_cell.x != end.x) or (temp_cell.y != end.y)); // not checking for queue = empty because solution is deterministic.
    
    

    //retracing path
    while(end.x != start.x or end.y != start.y)
    {
        path.push(previous[end.x][end.y]);
        end = previous[end.x][end.y];
    }
    return path;
}


void display_points(stack<point> path, point start, point end)
{
    point temp_cell;
    cout << "one of the shortest path : " << endl;
    while(!path.empty())
    {
        temp_cell = path.top();
        path.pop();
        cout << "(" << temp_cell.x+1 << ", " << temp_cell.y+1 << ")" << "-->";
    }
    cout << "(" << end.x +1 << ", " << end.y + 1<< ")";

}




int main()
{

    //  VARIABLE DECLARATION

    point start, end;
    int x, y;
    do
    {
        cout << "Enter the starting position of knight (x, y)\t";
        cin >> x >> y;

        // clearing screen

        system("cls");
    } while (! is_inside(x-1, y-1));
    start.input(x - 1, y - 1);

    do
    {
        cout << "Enter the final position of the knight (x, y)\t";
        cin >> x >> y;

        //clearing screen

        system("cls");
    } while (! is_inside(x-1, y-1));
    end.input(x-1, y-1);
    
    //DISPLAYING POINTS 
    cout << "Starting point ("<< start.x + 1 << "," << start.y + 1 <<")" << endl;
    cout << "Final point (" << end.x + 1 << "," << end.y + 1 << ")" << endl;

    //CALLING SHORTEST PATH FUNCTION
    stack<point> path = shortest_path(start, end);

    //DISPLAYING SHORTEST PATH
    display_points(path, start, end);

    return 0;
}