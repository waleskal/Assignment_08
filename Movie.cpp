#include <iostream>
#include <string>
using namespace std;

class Movie {
private:
    string title;
    int year;
    string director;

public:
    void setTitle(string t) {
        title = t;
    }
    void setYear(int y) {
        year = y;
    }
    void setDirector(string d) {
        director = d;
    }

    void displayMovieInfo() {
        cout << " movie info" << endl;
        cout << "title:    " << title << endl;
        cout << "year:     " << year << endl;
        cout << "director: " << director << endl;
    }
};

int main() {
    Movie myFavoriteMovie;

    myFavoriteMovie.setTitle("The Dark Knight");
    myFavoriteMovie.setYear(2008);
    myFavoriteMovie.setDirector("Christopher Nolan");

    myFavoriteMovie.displayMovieInfo();

    return 0;
}