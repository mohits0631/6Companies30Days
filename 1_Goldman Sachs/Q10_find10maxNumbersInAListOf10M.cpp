#include <bits/stdc++.h>
using namespace std;

/*
This can be solved by maintaining a min heap of size 10 and push the first 10 elements.
We use a loop for the remaining elements. 
If the current element is greater than the root. Then we remove the root and insert the current element
If the current element is less than or equal to the root. then we ignore it.

At the end, we will have a min heap of 10 largest numbers in the array
*/

// Driver code
int main ()
{
	// create a priority queue to use as a min heap
	priority_queue <int, vector<int>, greater<int>> pq;
	
    // create a list of elements to insert
    vector<int> mylist = {1,20,2,19,3,18,4,17,5,16,6,15,7,14,8,13,9,12,10,11};
  
    // insert the first 10 elements in the priority_queue
    for(int i = 0; i < 10; i++)
        pq.push(mylist[i]);
    
    // loop for the remaining elements
    for(int i = 10; i < mylist.size(); i++)
    {
        if(mylist[i] > pq.top())
        {
            // remove the root
            pq.pop();
            // add the new element
            pq.push(mylist[i]);
        }
    }
  

	// One by one extract items from min heap
	while (pq.empty() == false)
	{
		cout << pq.top() << " ";
		pq.pop();
	}

	return 0;
}
