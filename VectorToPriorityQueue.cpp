// DataStructures_CPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <queue>

void printPQ(std::priority_queue<int> pq_to_print)
{
    while (!pq_to_print.empty())
    {
        std::cout << pq_to_print.top() << " ";
        pq_to_print.pop();
    }
}


int operate(std::vector<int>& myV, int k)
{
    //transfer the values to the priority queue
    //why PQ? -> we are interested in the finding only the greatest element many times. 
    //          Multiset can also be used, but PQ is better fit in this case (due to only search of greatest).
    //          PQ is implemented using Heap, whereas Multiset is implemented as Tree.

    std::priority_queue<int> myPQ;
    for (int a : myV)
    {
        myPQ.push(a);
    }

    printPQ(myPQ);
    //use myPQ to find the greatest every time
    for (int i = 0; i < k; ++i)
    {
        int elem = myPQ.top();
        myPQ.pop();
        myPQ.push(ceil((float)elem / 2));
        std::cout << "\n";
        printPQ(myPQ);
    }
    
    int result = 0;
    
    while (!myPQ.empty())
    {
        result += myPQ.top();
        myPQ.pop();
    }
    return result;
    
}

int main()
{
    std::cout << "Hello World!\n";

    /*
    * The problem: 1) perform some operations k number of times
    *               a. n/2
    *               b. ceil
    *              2) sum = sum of all elements of array 
    *              Implement such that the sum is minimum.
    */

    std::cout << "Enter the array size: ";
    int n=0;
    std::cin >> n;
    std::vector<int> myVector;
    std::cout << "Enter the array: ";
    for(int i=0; i<n ; ++i)
    {   
        int x;
        std::cin >> x;
        myVector.push_back(x);        
    }

    std::cout << "Enter the iteration count: ";
    int k = 0;
    std::cin >> k;
    std::cout << "The sum is: " << operate(myVector, k);
}