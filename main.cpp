#include<iostream>
using namespace std;

struct dot {
    int x, y;
};

int main() {
    dot A;
    dot B;
    
    cout << "A row: ";
    cin >> A.y;
    A.y = A.y - 1;
    cout << "A column: ";
    cin >> A.x;
    A.x = A.x - 1;

    cout << "B row: ";
    cin >> B.y;
    B.y = B.y - 1;
    cout << "B column: ";
    cin >> B.x;
    B.x = B.x - 1;

    dot star{};
    star.y = A.y;

    if (A.y < B.y)
    {
        star.x = A.x + 1;
    }
    if (A.y > B.y)
    {
        star.x = A.x - 1;
    }
    if (A.x == B.x && A.y > B.y) {
        star.y = A.y - 1;
        star.x = A.x;
    }
    if (A.x == B.x && A.y < B.y) {
        star.y = A.y + 1;
        star.x = A.x;
    }

    static string matrix[20][40];
        
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 40; j++) {
            //matrix setup
            if (A.y == i && A.x == j)
            {
                matrix[i][j] = "A";
            }
            else if (B.y == i && B.x == j)
            {
                matrix[i][j] = "B";
            }
            else if (star.y == i && star.x == j) {
                matrix[i][j] = "*";
            }
            else
            matrix[i][j] = "-";


            
        }
    }
    
    bool check;
  
    if (star.y == B.y - 1 || star.y == B.y +1)
    {
        if (star.x == B.x - 1 || star.x == B.x + 1)
        {
            check = false;
        }
        
    }
    
    
    //output
    do
    {
        for (int i = 0; i < 20; i++)
        {
            for (int j = 0; j < 40; j++)
            {
                cout << matrix[i][j];
            }
            cout << endl;
        }

        //swaping star position
        if (A.x < B.x)
        {
            star.x = star.x + 1;
        }
        if (A.x > B.x)
        {
            star.x = star.x - 1;
        }
        if (A.y < B.y)
        {
            star.y = star.y + 1;
        }
        if (A.y > B.y)
        {
            star.y = star.y - 1;
        }
        
        if (star.y == B.y - 1 || star.y == B.y +1)
    {
        if (star.x == B.x - 1 || star.x == B.x + 1)
        {
            check = false;
        }
        
    }
        
    } while (check);
    return 0;
}