#include <iostream>
#include<bits/stdc++.h>
#include<fstream>
using namespace std;



void SelectionSort(int arr[],int n, int& comparison,int& moves)
{
    comparison=moves=0;
    for(int i=0,min,j;i<n-1;i++)
    {
        for( j=i+1,min=i;j<n;j++) {
            comparison++;
            if (arr[j] < arr[min]) {

                min = j;

            }
        }
        swap(arr[i], arr[min]);
        moves+=3;



    }


}
void Sorting(int arr[], int left, int middel, int right, int& comparison,int& moves)

{  int n1=middel-left+1,n2=right-middel;
    comparison=moves=0;
    int leftarr[n1],rightarr[n2];
    for(int i=0;i<n1;i++)
    {
        leftarr[i]=arr[i+left];
        moves++;  //?

    }
    for(int j=0;j<n2;j++)
    {
        rightarr[j]=arr[middel+1+j];
        moves++;          //?
    }
    int i=0,j=0,k=left;
    while(i<n1 &&j <n2)
    { comparison++;
        if(leftarr[i]<rightarr[j]) {
            comparison++;
            arr[k] = leftarr[i];
            k++;
            i++;
            moves++;
        }
        else
        {
            arr[k] = rightarr[j];
            k++;
            j++;
            moves++;

        }

    }
    while(i<n1) {
        arr[k++] = leftarr[i++];
        moves++;
    }
    while (j<n2) {
        arr[k++] = rightarr[j++];
        moves++;
    }

}

void MergeSort(int arr[],int left,int right,int& comparison, int& moves)
{
    if(right>left)
    { int middel=(left+right)/2;
        MergeSort(arr,left,middel,comparison,moves);
        MergeSort(arr,middel+1,right,comparison,moves);
        Sorting(arr, left, middel, right,comparison,moves);

    }

}

void ShellSort( int arr[], int n,int& comparison ,int& moves)
{ int gap=n/2;
    comparison=0;moves=0;
    while(gap>0)
    {
        int i,j,temp;
        for(i=gap;i<n;i++)
        { temp=arr[i];
            moves++;
            //?
            for(j=i;j>=gap;j-=gap) //? should i write copmarison inside it?
            {   comparison++; //?
                if(arr[j-gap]>temp)
                {
                    arr[j]=arr[j-gap];
                    moves++;
                }
                else{break;}
            }
            arr[j]=temp;
            moves++;
            //?
        }
        gap/=2;
    }
}

void insertionS(int a[], int n,int& co,int& mo)
{

    for (int i = 1;i < n;i++)


    {

        int value = a[i];

        int indx = i-1;

        while (indx >= 0)
        { co++;

            if (a[indx ] > value)
            {


                a[indx+1] = a[indx];
                indx--;
                mo++;
            }
            else
                break;



        }
        a[indx+1] = value;

    }



}





int Binary_RSort(int a[], int key, int l, int h,int& co,int&mo)
{



    int m = (l + h) / 2;


    if (h <= l && key > a[l])
    {

        return l + 1;
    }


    if (h <= l && key < a[l])
    {

        return l;
    }



    if (key > a[m])
    {


        return Binary_RSort(a, key, m + 1, h,co,mo);

    }


    if (key < a[m])
    {


        return Binary_RSort(a, key, l, m - 1,co,mo);

    }



    if (key == a[m])
    {

        return m + 1;
    }

    co=+2;
}



void Isertion(int a[], int n,int&co,int&mo)
{
    int pos, value, p, j;
    for (p = 1;p < n;p++)
    {
        j = p - 1;
        value = a[p];
        pos = Binary_RSort(a, value,0,j,co,mo);

        while (j >= pos)
        {

            a[j + 1] = a[j];
            mo++;
            j--;

        }
        a[j+1] = value;

    }



}







int main()
{ int comparisons, moves;
    string line = "\n";

    int n;
    cout<<"TASK 1 : \n";
    cout << "enter a size" << endl;
    cin >> n ;
    int a[n];
    n = sizeof(a) / sizeof(a[0]);
    cout << "enter array elements " << endl;
    for (int i = 0; i < n; i++)
        cin >>a[i];

    insertionS(a, n,comparisons,moves);
    cout << endl << "Sorted array using linear search: \n";
    for (int i = 0; i < n; i++)
        cout << " " << a[i];
    cout<<endl<<comparisons<<" "<<moves;
    comparisons=moves=0;


    Isertion(a, n,comparisons,moves);
    cout << endl<<"Sorted array using binary search: \n";
    for (int i = 0; i < n; i++)
        cout << " " << a[i];
    cout<<endl<<(comparisons)-1<<" " <<moves;
    comparisons=moves=0;


    ifstream input;
    int count = 0;
    input.open("arrays.txt");
    while (getline(input, line))++count;
    input.close();
cout<<"*******************************************"<<endl;
cout<<"TASK 2 : \n";
    input.open("arrays.txt");
    if (input.is_open()) {
        while (count--) {
            int n;
            input >> n;
            int c[n], a[n], b[n], comparison, moves;

            for (int i = 0; i < n; i++)
                input >> a[i];
            for (int i = 0; i < n; i++) {
                b[i] = a[i];
                c[i] = a[i];
            }

            cout << " Original array" << " : ";
            for (int i = 0; i < n; i++)
                cout << a[i] << " ";
            cout << endl;
            cout << " Selection Sort : " << endl;
            SelectionSort(a, n, comparison, moves);
            cout << "   sorted array" << " : ";
            for (int i = 0; i < n; i++)
                cout << a[i] << " ";
            cout << endl;
            cout << "  Comparisons : " << comparison;
            cout << endl << "   Moves : " << " " << moves << endl;
            comparison = moves = 0;
            cout << endl;
            cout << " Merge Sort : " << endl;
            MergeSort(b, 0, n - 1, comparison, moves);
            cout << "   sorted array" << " : ";
            for (int i = 0; i < n; i++)
                cout << b[i] << " ";
            cout << endl;
            cout << "   Comparisons : " << comparison;
            cout << endl << "   Moves : " << " " << moves << endl;
            comparison = moves = 0;
            cout << endl;
            cout << " Shell Sort : " << endl;
            ShellSort(c, n, comparison, moves);
            cout << "   sorted array " << " : ";
            for (int i = 0; i < n; i++)
                cout << c[i] << " ";
            cout << endl;
            cout << "   Comparisons : " << comparison;
            cout << endl << "   Moves : " << " " << moves << endl;
            comparison = moves = 0;
            cout << " -------------------------------------------------------------" << endl;

        }
        input.close();
    }
    return 0;
}
