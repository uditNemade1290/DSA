#include <iostream>
using namespace std;
void heapify(int a[], int n, int i)
{
 int largest = i;
 int l = 2 * i + 1;
 int r = 2 * i + 2;
 if (l < n && a[l] > a[largest])
 largest = l;
 if (r < n && a[r] > a[largest])
 largest = r;
 if (largest != i)
 {
 int t = a[i];
 a[i] = a[largest];
 a[largest] = t;
 heapify(a, n, largest);
 }
}
int main()
{
 int a[50], n, i;
 cout << "Enter number of elements: ";
 cin >> n;
if (n <= 0 || n > 50)
 {
 cout << "Invalid size!";
 return 0;
 }
 cout << "Enter " << n << " numbers: ";
 for (i = 0; i < n; i++)
 cin >> a[i];
 // Build Max Heap
 for (i = n / 2 - 1; i >= 0; i--)
 heapify(a, n, i);
 // Heap Sort
 for (i = n - 1; i > 0; i--)
 {
 int t = a[0];
 a[0] = a[i];
 a[i] = t;
 heapify(a, i, 0);
 }
 cout << "Sorted numbers (Ascending): ";
 for (i = 0; i < n; i++)
 cout << a[i] << " ";
 return 0;
}

PART B

#include <iostream>
using namespace std;
void heapify(int a[], int n, int i)
{
 int smallest = i;
 int l = 2 * i + 1;
 int r = 2 * i + 2;
 if (l < n && a[l] < a[smallest])
 smallest = l;
 if (r < n && a[r] < a[smallest])
 smallest = r;
 if (smallest != i)
 {
 int t = a[i];
a[i] = a[smallest];
 a[smallest] = t;
 heapify(a, n, smallest);
 }
}
int main()
{
 int score[50], n, i;
 cout << "Enter number of players: ";
 cin >> n;
 if (n <= 0 || n > 50)
 {
 cout << "Invalid number of players!";
 return 0;
 }
