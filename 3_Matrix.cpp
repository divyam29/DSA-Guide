#include <bits/stdc++.h>
using namespace std;

class Diagonal
{
private:
    int *A;
    int n;

public:
    Diagonal(int n)
    {
        this->n = n;
        A = new int[n];
    }

    ~Diagonal()
    {
        delete[] A;
    }

    void create()
    {
        int i, j, x;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (i == j)
                {
                    cout << "Enter value " << i << " :";
                    cin >> A[i];
                    cout << i << " " << j << " " << A[i] << endl;
                }
                else
                {
                    A[i] = 0;
                    cout << i << " " << j << " " << A[i] << endl;
                }
            }
        }
        for (i = 0; i < n; i++)
        {
            cout << A[i] << endl;
        }
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (i == j)
                {
                    // cout<<endl<<"i "<<i<<" j "<<j<<" "<<A[i]<<endl;
                    cout << A[i] << " ";
                }
                else
                {
                    cout << 0 << " ";
                }
            }
            cout << endl;
        }
    }

void display()
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i == j)
            {
                // cout<<endl<<"i "<<i<<" j "<<j<<" "<<A[i]<<endl;
                cout << A[i] << " ";
            }
            else
            {
                cout << 0 << " ";
            }
        }
        cout << endl;
    }
}
};

int main()
{
    Diagonal *D;
    D = new Diagonal(5);
    D->create();
    D->display();
    return 0;
}