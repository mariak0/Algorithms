#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<int> Merge(vector<int>& V_1, vector<int>& V_2)
{
vector<int> V_3;

int k, l, z, w;
k=l=0;
z=V_1.size();
w=V_2.size();

while (k<z && l<w)
    {
if (V_1[k] <= V_2[l])
{
V_3.push_back(V_1[k]);
++k;
}
else
{
V_3.push_back(V_2[l]);
++l;
}
}
while (k < z) {
V_3.push_back(V_1[k]);
++k;
}
while (l < w) {
V_3.push_back(V_2[l]);
++l;
}
return V_3;
}

int binarySearch(vector<int> &arr,int l,int h,int toSearch) /*h for high, l for low*/
    {
        if (h >= l) {
            int m = (h + l) / 2; //m for mid

            if (arr[m] == toSearch) return 1;
            else if (arr[m] > toSearch) return binarySearch(arr, l, m - 1, toSearch);

            else return binarySearch(arr, m + 1, h, toSearch);}
        return 0;}

int main()
{
vector<int> array1, array2;
vector<int> merged;
int number1, number2 = 0;
int m, n, t;

    ifstream input_file_1("Array1.txt"); //ανάγνωση αρχείου
    ifstream input_file_2("Array2.txt"); //ανάγνωση αρχείου

    if (input_file_1.good())
     {
        while (input_file_1>>number1) array1.push_back(number1);
        input_file_1.close();

        //Εκτύπωση λίστας 1
        cout << "Numbers of array1: ";
        for (int count =0; count < array1.size(); count++){
            cout << array1[count] << " ";
        }
        cout<<endl;

    }else {
        cout<<"File not found!"; //μη εύρεση αρχείου
    }

    if (input_file_2.good())
     {
        while (input_file_2 >> number2) array2.push_back(number2);
        input_file_2.close();

        for(n=0; n<array2.size(); n++)
        {
            for(m=n+1; m<array2.size(); m++)
            {
                if(array2[n]>array2[m])
                {
                    t=array2[n];
                    array2[n]=array2[m];
                    array2[m]=t;
                }
            }
        }

        // Εκτύπωση λίστας 2
        cout << "\nNumbers of array2: ";
        for (int count=0; count<array2.size(); count++) cout << array2[count]<< " "; 
        cout << endl;

    }else {
        cout <<"File not found!";  //μη εύρεση αρχείου
        exit(0);
    }

    merged=Merge(array1, array2); //συγχώνευση λίστας 1 και λίστας 2

    // Εκτύπωση συγχωνευμένης λίστας και αναζήτηση του αριθμού που ζητάει ο χρήστης
    cout << "\nNumbers of merged array: ";
    for (int count=0; count<merged.size(); count++) cout << merged[count]<< " ";
    cout << endl;

    int number;
    cout << "\n\n Type a number of the merged array : ";
    cin >> number; //εισαγωγή αριθμού απο τον χρήστη για αναζήτηση

    int l=0;
    int h=array1.size() + array2.size() - 1; //μέγεθος της νέας λίστας για την αναζήτηση

    int result=binarySearch(merged, l, h, number); /*διαδική αναζήτηση για την εύρεση του αριθμού που ζητά ο χρήστης*/
    if (result==1) cout << "\nNumber Found";
    else cout << "\nNumber Not found";
}
