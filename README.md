#include <iostream>  
#include <string>  

#define MAX 35  

using namespace std;

int main()
{
    int n;
    while (cin >> n)//循環讀取 n 組數據
        while (n--)
        {
            string t; cin >> t;  //將每個大數讀入一個 string 變量中
            int x[MAX] = { 0 };//將每個大數從低位到高位的每一位轉換為一個 int 變量，存儲到一個 int 陣列中
            for (int i = 0; i < t.length(); i++)
                x[MAX - 1 - i] = t[t.length() - 1 - i] - '0';
            //逐位相加，將進位的數字傳遞到高位，再取模得到當前位上的數字
            cin >> t; 
            int y[MAX] = { 0 };
            for (int i = 0; i < t.length(); i++)
                y[MAX - 1 - i] = t[t.length() - 1 - i] - '0';

            for (int i = MAX - 1; i > -1; i--)
                x[i] += y[i];
            for (int i = MAX - 1; i > 0; i--)
            {
                x[i - 1] += x[i] / 10;
                x[i] %= 10;
            }
            //從高位到低位輸出每一位的數字，注意判斷高位的 0 是否需要輸出
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
