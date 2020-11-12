#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

class Book{
public:

    string title;
    string author;
    int pages;
    double rating;
    
    Book(string title, string author, int pages, double rating){
        this->title = title;
        this->author = author;
        this->pages = pages;
        this->rating = rating;
    }
};

class Library{
    stack<Book> books;
    
public:
    void add_book(Book my_book){
        this->books.push(my_book);
    }
    void save_as_csv(){
        ofstream my_csv;
        my_csv.open("books.csv");
        
        while(!(books.empty())) {
            my_csv << books.top().title << ", " << books.top().author << ", " << books.top().pages << ", " << books.top().rating << endl;
            books.pop();
        }
        my_csv.close();
    }
};

int main()
{

	Library lib;

    for (int i = 0; i<5; ++i){
		int pages;
		double rating;
		string title, author;
    	cin >> title;
    	cin >> author;
    	cin >> pages;
    	cin >> rating;	
    	Book book = Book(title, author, pages, rating);
    	lib.add_book(book);
    	
	}
	
	lib.save_as_csv();

    return 0;
}

