#include<iostream>
using namespace std;
int main(){
int a[10];
for(int i=0; i<10 ; i++)
{
a[i] = -1;
}
int flag = 0;
int n;
start :
cout<<"\n Enter 1 to insert element and 0 to stop inserting"<<endl;
cin>>n;
while(n){
if(flag == 10)
{
cout<<"overloading";
cout<<"\n Resultant hash table is :"<<endl;
for(int i=0; i<10 ; i++)
{
cout<<"\t"<<a[i]<<endl;
}
return 0;
}
int k;
cout<<"\n Enter Element =>"; cin>>k;
int temp = k%10;
middle :
if(a[temp]== -1)
{
a[temp] = k;
flag++;
goto start;
}
else
{
while(a[temp] != -1 && flag != 10)
{
if(temp == 9)
{
temp = 0;
}
else
temp++;
goto middle;
}
}
}
cout<<"\n Resultant hash table is :"<<endl;
for(int i=0; i<10 ; i++)
{
cout<<"\t"<<i<<". "<<a[i]<<endl;
} }

PART B
#include<iostream>
using namespace std;
int main()
{
 int parking[10];
 // Initialize all parking slots as empty
 for(int i = 0; i < 10; i++)
 {
 parking[i] = -1;
 } int flag = 0;
 int n;
 start:
 cout << "\nEnter 1 to park vehicle and 0 to stop: ";
 cin >> n;
 while(n)
 {
 if(flag == 10)
 {
 cout << "Parking is full!";
 break;
 }
 int vehicle;
 cout << "\nEnter Vehicle Number => ";
 cin >> vehicle;
 int temp = vehicle % 10;
 // Linear probing to find an empty slot
 while(parking[temp] != -1)
 {
 if(temp == 9)
 temp = 0;
 else temp++;
 }
 parking[temp] = vehicle;
 flag++;
 cout << "Vehicle parked at Slot " << temp << endl;
 goto start;
 }
 cout << "\nFinal Parking Slot Allocation:\n";
 for(int i = 0; i < 10; i++)
 {
 if(parking[i] == -1)
 cout << "Slot " << i << " -> Empty" << endl;
 else
 cout << "Slot " << i << " -> Vehicle " << parking[i] << endl;
 }
 return 0;
}
