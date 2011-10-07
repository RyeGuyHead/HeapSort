//
// Implementing a heap sort with <int, int> maps
//
// Created by Ryan Johnson on 7/18/11.
//

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <map>

using namespace std;

// Each function returns a more sorted map
map<int, int> heap_Sort(map<int, int>, int);
map<int, int> heapify(map<int,int>, int);
map<int, int> siftDown(map<int,int>, int, int);



int main (int argc, const char * argv[])
{
   
    int total;
    map<int, int> unordered;
    map<int, int> ordered;
    map<int,int>::iterator it;
    it = unordered.begin();
    
    // Get the total amount of numbers to sort from the user
    std::cout << "Enter how many numbers you want to sort: ";
    std::cin >> total;
    std::cout << "Sorting " << total << " numbers.\n";
    
    // Get a time seed and prompt the user about what's happening
    srand(time(NULL));
    std::cout << "Generating random numbers..." << endl;
    
    // Makes the program look like its REALLY trying...
    sleep(2);
    
    // Fill the hash map with random numbers
    for(int i = 0; i < total; i++)
    {
        unordered[i] = rand() % 100;
    }
    
    // Display the contents
    for(int i = 0; i < total; i++)
    {
        std::cout << "#" << (i+1) << " = "<< unordered[i] << endl;
    }
    
    std::cout << "Organizing the numbers from lowest -> highest..." << endl;
    sleep(2);
    
    // Organize the map
    ordered = heap_Sort(unordered, total);
    
    // Display the re-ordered contents
    for(int i = 0; i < total; i++)
    {
        std::cout << ordered[i] << endl;
    }
    
    // Closing statement
    std::cout << "FIN!";
    return 0;
}

map<int, int> heap_Sort(map<int, int> numbers, int count)
{
    
    // Puts them in top down order
    numbers = heapify(numbers, count);
    
    int end = count - 1;
    
    while(end > 0)
    {
        int temp = numbers[0];
        numbers[0] = numbers[end];
        numbers[end] = temp;
        numbers = siftDown(numbers, 0, end - 1);
        end--;
    }
    return numbers;
    
    
}


map<int, int> heapify(map<int, int> numbers, int count)
{
    int start = count;
    start /= 2;
    start--;
    while(start >= 0)
    {
        numbers = siftDown(numbers, start, count);
        start--;
        count++;
    }
    return numbers;

}

map<int, int> siftDown(map<int, int> numbers, int start, int count)
{    
    // Traverse the tree, putting the biggest on top
    int root = start;
    while( (root * 2 + 1) <= count)
    {
        int child = root * 2 + 1;
        int swap = root;
        if(numbers[swap] < numbers[child])
        {
            swap = child;
        }
        if( (child + 1 <= count) && (numbers[swap] < numbers[child + 1]))
        {
            swap = child + 1;
        }
        if (swap != root)
        {
            int temp = numbers[root];
            numbers[root] = numbers[swap];
            numbers[swap] = temp;
            root = swap;
        }
        else return numbers;
    }
    return numbers;
}
