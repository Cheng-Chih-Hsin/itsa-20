#include <iostream>  
#include <string>  

#define MAX 35  

using namespace std;

int main()
{
    int n;
    while (cin >> n)
        while (n--)
        {
            //input x  
            string t; cin >> t;
            //split to bit  
            int x[MAX] = { 0 };
            for (int i = 0; i < t.length(); i++)
                x[MAX - 1 - i] = t[t.length() - 1 - i] - '0';

            //input y  
            cin >> t;
            //split to bit  
            int y[MAX] = { 0 };
            for (int i = 0; i < t.length(); i++)
                y[MAX - 1 - i] = t[t.length() - 1 - i] - '0';

            //add  
            for (int i = MAX - 1; i > -1; i--)
                x[i] += y[i];
            for (int i = MAX - 1; i > 0; i--)
            {
                x[i - 1] += x[i] / 10;
                x[i] %= 10;
            }

            //output  
            bool print = false;
            for (int i = 0; i < MAX; i++)
            {
                if (x[i] != 0)
                    print = true;
                if (print)
                    cout << x[i];
            }
            cout << endl;
        }
    return 0;
}