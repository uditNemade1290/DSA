#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cstdlib>
using namespace std;
class Employee
{
private:
 int id;
 string name;
 double salary;
public:
 Employee(int i = 0, string n = "", double s = 0.0)
 {
 id = i;
 name = n;
 salary = s;
 }
 int getId() const
 {
 return id;
 } string getName() const
 {
 return name;
 }
 double getSalary() const
 {
 return salary;
 }
};
void writeToFile(const string &filename, const Employee &e)
{
 ofstream fout(filename, ios::app);
 if(!fout)
 {
 cout << "Cannot open file for writing!" << endl;
 exit(EXIT_FAILURE);
 }
 fout << e.getId() << " "
 << e.getName() << " "
 << e.getSalary() << endl;
 fout.close();
} void readFromFile(const string &filename)
{
 ifstream fin(filename);
 if(!fin)
 {
 cout << "Cannot open file for reading!" << endl;
 exit(EXIT_FAILURE);
 }
 int id;
 string name;
 double salary;
 cout << "\n----------------------------------\n";
 cout << left << setw(10) << "ID"
 << setw(15) << "NAME"
 << "SALARY\n";
 cout << "----------------------------------\n";
 while(fin >> id >> name >> salary)
 {
 cout << left << setw(10) << id
 << setw(15) << name
 << fixed << setprecision(2)
 << salary << endl;
 } cout << "----------------------------------\n";
 fin.close();
}
int main()
{
 const string filename = "payroll.dat";
 Employee e1(101, "Mickey", 5600.00);
 Employee e2(102, "Donald", 2635.00);
 Employee e3(103, "Zairo", 1200.00);
 writeToFile(filename, e1);
 writeToFile(filename, e2);
 writeToFile(filename, e3);
 readFromFile(filename);
 return 0;
}

PART B
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;
class Book
{
private:
 int id;
 string title;
 string author; public:
 Book(int i = 0, string t = "", string a = "")
 {
 id = i;
 title = t;
 author = a;
 }
 int getId() const
 {
 return id;
 }
 string getTitle() const
 {
 return title;
 }
 string getAuthor() const
 {
 return author;
 }
};
void writeBook(const string &filename, const Book &b)
{
 ofstream fout(filename, ios::app); fout << b.getId() << " "
 << b.getTitle() << " "
 << b.getAuthor() << endl;
 fout.close();
}
void createIndex(const string &dataFile, const string &indexFile)
{
 ifstream fin(dataFile);
 ofstream idx(indexFile);
 int id;
 string title, author;
 int position = 0;
 while(fin >> id >> title >> author)
 {
 idx << id << " " << position << endl;
 position++;
 }
 fin.close();
 idx.close();
}
void displayBooks(const string &filename) {
 ifstream fin(filename);
 int id;
 string title, author;
 cout << "\nBook Records:\n";
 cout << "-----------------------------------\n";
 cout << "ID\tTitle\t\tAuthor\n";
 cout << "-----------------------------------\n";
 while(fin >> id >> title >> author)
 {
 cout << id << "\t"
 << title << "\t\t"
 << author << endl;
 }
 fin.close();
}
void searchBook(const string &dataFile, const string &indexFile, int searchID)
{
 ifstream idx(indexFile);
 ifstream fin(dataFile);
 int id, position;
 bool found = false; while(idx >> id >> position)
 {
 if(id == searchID)
 {
 fin.clear();
 fin.seekg(0);
 int bookID;
 string title, author;
 for(int i = 0; i <= position; i++)
 {
 fin >> bookID >> title >> author;
 }
 cout << "\nBook Found!\n";
 cout << "Book ID: " << bookID << endl;
 cout << "Title: " << title << endl;
 cout << "Author: " << author << endl;
 found = true;
 break;
 }
 }
 if(!found)
 cout << "\nBook not found!\n"; idx.close();
 fin.close();
}
int main()
{
 const string dataFile = "books.dat";
 const string indexFile = "books_index.dat";
 // Create sample book records
 writeBook(dataFile, Book(101, "Cplusplus", "Bjarne"));
 writeBook(dataFile, Book(102, "Python", "Guido"));
 writeBook(dataFile, Book(103, "Java", "James"));
 // Create index file
 createIndex(dataFile, indexFile);
 displayBooks(dataFile);
 int searchID;
 cout << "\nEnter Book ID to search: ";
 cin >> searchID;
 searchBook(dataFile, indexFile, searchID);
 return 0;
}
