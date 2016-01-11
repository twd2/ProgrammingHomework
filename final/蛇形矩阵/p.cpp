#include <iostream>
using namespace std;

int main()
{
    int canvas[100][100] = {{0}};
    int n;
    cin >> n;
    int x = 0, y = 0;
    if ((n & 1) == 1)
    {
        int num = 1;
        for (int i = 1; i <= n; ++i)
        {
            if ((i & 1) == 1) //down, left
            {
                for (int j = 1; j <= i; ++j)
                {
                    //cout << x << "," << y << endl;
                    canvas[y][x] = num;
                    ++num;
                    ++y;
                    --x;
                }
                ++x;
            }
            else //up, right
            {
                for (int j = 1; j <= i; ++j)
                {
                    //cout << "b" << endl;
                    //cout << x << "," << y << endl;
                    canvas[y][x] = num;
                    ++num;
                    --y;
                    ++x;
                }
                ++y;
            }
        }
        ++x;
        --y;
        for (int i = n - 1; i >= 1; --i)
        {
            if ((i & 1) == 1) //down, left
            {
                for (int j = 1; j <= i; ++j)
                {
                    //cout << x << "," << y << endl;
                    canvas[y][x] = num;
                    ++num;
                    ++y;
                    --x;
                }
                ++x;
                ++x;
                --y;
            }
            else //up, right
            {
                for (int j = 1; j <= i; ++j)
                {
                    //cout << "b" << endl;
                    //cout << x << "," << y << endl;
                    canvas[y][x] = num;
                    ++num;
                    --y;
                    ++x;
                }
                ++y;
                ++y;
                --x;
            }
        }
    }
    else
    {
        int num = 1;
        for (int i = 1; i <= n; ++i)
        {
            if ((i & 1) == 1) //down, left
            {
                for (int j = 1; j <= i; ++j)
                {
                    //cout << x << "," << y << endl;
                    canvas[y][x] = num;
                    ++num;
                    ++y;
                    --x;
                }
                ++x;
            }
            else //up, right
            {
                for (int j = 1; j <= i; ++j)
                {
                    //cout << "b" << endl;
                    //cout << x << "," << y << endl;
                    canvas[y][x] = num;
                    ++num;
                    --y;
                    ++x;
                }
                ++y;
            }
        }
        --x;
        ++y;
        for (int i = n - 1; i >= 1; --i)
        {
            if ((i & 1) == 1) //down, left
            {
                for (int j = 1; j <= i; ++j)
                {
                    //cout << x << "," << y << endl;
                    canvas[y][x] = num;
                    ++num;
                    ++y;
                    --x;
                }
                ++x;
                ++x;
                --y;
            }
            else //up, right
            {
                for (int j = 1; j <= i; ++j)
                {
                    //cout << "b" << endl;
                    //cout << x << "," << y << endl;
                    canvas[y][x] = num;
                    ++num;
                    --y;
                    ++x;
                }
                ++y;
                ++y;
                --x;
            }
        }        
    }
    
    for (y = 0; y < n; ++y)
    {
        for (x = 0; x < n; ++x)
        {
            cout << canvas[y][x] << " ";
        }
        cout << endl;
    }
    
    return 0;
}