// 1. Karena untuk mempermudah menyelesaikan suatu masalah 
// 2. Selection dan Repitition 
// 3. Struktur data yang tepat, ada output, tidak memakan banyak memori 
// 4. QuickSort, Karena tidak memakan banyak waktu 
// 5. Quadratic : Menampilkan bilangan kuadrat 
//    Loglinear : Mengetahui hubungan antar variabel



#include <iostream>
using namespace std;

int arr[20];
int cmp_count = 0;
int mov_count = 0;
int n;

void input() {
    while (true)
    {
        cout << "Masukan panjang element Array: ";
        cin >> n;

        if (n <= 20)
            break;
        else
            cout << "\nMaksimum panjang Array adalah 20" << endl;
    }

    cout << "\n----------------------" << endl;
    cout << "\nEnter Array Element" << endl;
    cout << "\n----------------------" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "<" << (i + 1) << ">";
        cin >> arr[i];
    }
}

void swap(int x, int y)
{
    int temp;

    temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}

void SelectionSort(int low, int high)
{
    int pivot, i, j;
    if (low > high)
        return;

    pivot = arr[low];

    i = low + 1;
    j = high;


    while (i <= j)
    {
        while ((arr[i] <= pivot) && (i <= high))
        {
            i++;
            cmp_count++;
        }
        cmp_count++;

        while ((arr[j] > pivot) && (j >= low))
        {
            j--;
            cmp_count++;
        }
        cmp_count++;

        if (i < j)
        {
            swap(i, j);
            mov_count++;
        }
    }
    if (low < j)
    {
        swap(low, j);
        mov_count++;

    }
    SelectionSort(low, j - 1);
    SelectionSort(j + 1, high);
}

void display() {
    cout << "\n------------" << endl;
    cout << "Sorted Array" << endl;
    cout << "\n------------" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << "\n\nNumber of comparasions: " << cmp_count << endl;
    cout << "Number of data movements" << mov_count << endl;
}


int main()
{
    input();
    SelectionSort(0, n - 1);
    display();
    system("pause");

    return 0;
}



