
#include <iostream>
#include <string.h>
#include <iterator>
#include <unordered_set>
#include <queue>
#include <deque>
#include <vector>
#include <set>

using namespace std;

class Node
{
public:
    string state;
    int cost;
    Node(string sState, int iCost)
    {
        state = sState;
        cost = iCost;
    }

};

int goalTest(Node nNode, string strGoalState)
{
    return nNode.state == strGoalState;
}

int checkActions(Node currentState, queue<Node> &frontier, string sGoal, unordered_set<string> &explored,unordered_set<string> &sFrontier)
{
    //get position of #
    int p = currentState.state.find('#');

    //initialise possible move strings
    string l ;
    string u ;
    string d ;
    string r;


    //LEFT
    if (p % 3 > 0)
    {
        //move # to left of board
        l = currentState.state;
        swap(l[p], l[p - 1]);

        //if this configuration doesn't exist already
        if (explored.find(l) == explored.end() && sFrontier.find(l) == sFrontier.end())
        {
            Node lChild(l, currentState.cost + 1);
            //if the configuration is the goal we're looking for
            if (goalTest(lChild, sGoal))
            {
                return lChild.cost;
            }
            frontier.push(lChild);
            sFrontier.insert(l);
        }
    }

    //RIGHT
    if (p % 3 < 2)
    {
        r = currentState.state;
        swap(r[p], r[p + 1]);
        if (explored.find(r) == explored.end() && sFrontier.find(r) == sFrontier.end())
        {
            Node rChild(r, currentState.cost + 1);

            if (goalTest(rChild, sGoal))
            {
               // cout<<"haha"<<endl;
                return rChild.cost;
            }
            frontier.push(rChild);
            sFrontier.insert(r);
        }
    }

    //UP
    if (p - 3 >= 0)
    {
        u = currentState.state;
        swap(u[p], u[p - 3]);
        if (explored.find(u) == explored.end() && sFrontier.find(u) == sFrontier.end())
        {
            Node uChild(u, currentState.cost + 1);
            if (goalTest(uChild, sGoal))
            {
              //  cout<<"haha"<<endl;
                return uChild.cost;
            }
            frontier.push(uChild);
            sFrontier.insert(u);
        }
    }

    //DOWN
    if (p + 3 < 9)
    {
        d = currentState.state;
        swap(d[p], d[p + 3]);
        if (explored.find(d) == explored.end() && sFrontier.find(d) == sFrontier.end())
        {

            Node dChild(d, currentState.cost + 1);
            if (goalTest(dChild, sGoal))
            {
              //  cout<<"haha"<<endl;
                return dChild.cost;
            }
            frontier.push(dChild);
            sFrontier.insert(d);
        }
    }
    return -1;
}

int main()
{

    //get inputs
    string strInitialState, strGoalState;
    cin >> strInitialState >> strGoalState;

    Node nInitial(strInitialState, 0);

    //initialise queue
    queue<Node> frontier;

    frontier.push(nInitial);
    //frontier set to help make searching easier
    unordered_set<string> sFrontier;
    sFrontier.insert(nInitial.state);

    //initialise finding set
    unordered_set<string> explored;
    
    int cost = -1;
    if (goalTest(nInitial, strGoalState))
    {
        cout << nInitial.cost << endl;
    }
    else
    {

        Node currentState = nInitial;
        while (cost == -1 && !frontier.empty())
        {
            currentState = frontier.front();
            sFrontier.erase(sFrontier.find(currentState.state));
            frontier.pop();
            explored.insert(currentState.state);

            cost = checkActions(currentState, frontier, strGoalState, explored, sFrontier);
            if (cost != -1)
            {
                cout << cost << endl;
                break;
            }
        }
    }

    return 0;
}
