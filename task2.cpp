#include<iostream>
#include<windows.h>
#include<array>
#include<string>
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
    //star start position setup
    star.y = A.y;
    if (A.x < B.x)
    {
        star.x = A.x + 1;
    }
    if (A.x > B.x)
    {
        star.x= A.x - 1;
    }
    if (A.y < B.y && A.x == B.x)
    {
        star.y = A.y + 1;
        star.x = A.x;
    }
    if (A.y > B.y && A.x == B.x)
    {
        star.y = A.y - 1;
        star.x = A.x;
    }
    if (A.y == B.y && A.x < B.x) {
        star.x = A.x + 1;
        star.y = A.y;
    }
    if (A.y == B.y && A.x > B.x) {
        star.x = A.x -1;
        star.y = A.y;
    }

    static string matrix[20][40];
    array<dot, 10> obstacles;
    bool check = true;
    for (size_t i = 0; i < obstacles.size(); i++)
    {
        obstacles[i].x = 15;
        obstacles[i].y = i;
    }
    

    //output
    do
    {
    //checking if the task is done
    if (star.y == B.y  && star.x == B.x)
    {
        check = false;
    }
    //setup
    bool swap = false;
    Sleep(50);
    system("cls");

        for (int i = 0; i < 20; i++)
        {
            for (int j = 0; j < 40; j++)
            {
            if (A.y == i && A.x == j)
            {
                matrix[i][j] = "A";
            }
            else if (B.y == i && B.x == j)
            {
                matrix[i][j] = "B";
            }
            else
            matrix[i][j] = "-";
            if (star.y==i && star.x == j)
            {
                 matrix[i][j]="x";
            }
            for(int n = 0; n < obstacles.size(); n++)
            {
                if (obstacles[n].x == j && obstacles[n].y == i)
                {
                    matrix[i][j] = "*";
                }
                
            }
            
            
            cout << matrix[i][j];
            }
            cout << endl;
        }

        //swaping star position
        if (star.x < B.x && swap == false)
        {
            star.x = star.x + 1;
            swap = true;
        }
        if (star.x > B.x && swap == false)
        {
            star.x = star.x - 1;
            swap = true;
        }
        if (star.y < B.y && swap == false)
        {
            star.y = star.y + 1;
            swap = true;
        }
        if (star.y > B.y && swap == false)
        {
            star.y = star.y - 1;
            swap = true;
        }        
        
        
    } while (check);
    return 0;
}