#include <iostream>
#include <fstream> //To use ifstream
#include <vector>
#include <algorithm> //To find the minimum element

using namespace std;

void HeapifyDown(vector <int> &v,int n)
{
    int l; //left
    int r; //right
    int k;

    if(2*n>v.size() - 1)
    {
        return;
    }
    else if(2*n<v.size() - 1)
    {
        l=2*n;
        r=2*n+1;
        if(v[l]<v[r])
        {
            k=l;
        }
        else
        {
            k=r;
        }
    }
    else if(2*n==v.size() - 1)
    {
        k=2*n;
    }

    if(v[k]<v[n])
    {
        swap(v[k],v[n]);
        HeapifyDown(v,k);
    }
}


int main()
{
    int i;
	vector <int> Heap; //Create a vector named Heap



    ifstream inputFile("Heap.txt"); //Input file stream object




    if (inputFile.good()) //Check if Heap.txt exists and then open it
     {
	 int y;
	Heap.insert(Heap.begin(), 0);
        int num = 0;
        while (inputFile >> num) // Reads data from file stores the data in an array
        	Heap.push_back(num); //and stores them in the vector Heap

        inputFile.close();  //Close the file

                //Print the vector
		  y=Heap.size();
                cout <<"The list is:"<<endl;
                for(int i = 0; i < y ; i++)
                {
                    cout <<Heap[i] << " ";
                }
                cout<<endl;
     }


     else {   //In case file not found
        cout << "Error file not found!"; //display message
        exit(0);
    }



    cout <<"The minimum element of the list is:"; //print the minimum element
    cout <<*min_element(Heap.begin()+1, Heap.end()) << endl; //use this function to find it



    iter_swap(Heap.begin()+1,Heap.end()-1); //Swap the first and last element

                //Print the vector after swapping
                cout <<"The list after swapping the first and the last element is:"<<endl;
                for(int x = 1; x < Heap.size() ; x++)
                {
                    cout << Heap[x] << " ";
                }
                cout<<endl;



    Heap.erase(Heap.end()-1); //Delete the last element of the vector

                //Print the vector after deleting the last element
                cout <<"The list after deliting the last element is:"<<endl;
                for(int z = 1; z < Heap.size() ; z++)
                {
                    cout << Heap[z] << " ";
                }
                cout<<endl;

    vector <int> h=Heap;

    int s = Heap[1];


     HeapifyDown(h, 1);

    cout<<"Min Heap\n";
    for (i = 1; i <= h.size()-1; i++)
    {
        cout<<h[i]<<endl;
    }


     for (i = 1; i <= h.size()-1; i++)
    {
        if (h[i] == s)
        {
            cout << "Element " << s << " is found in position : " << i << endl;
        }
    }

}
