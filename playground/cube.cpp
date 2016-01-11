#include <iostream>
using namespace std;

char canvas[2000][2000] = {{0}};

const char blank = '.';
char cube[][8] = {
    "..+---+", 
    "./   /|",
    "+---+ |",
    "|   | +",
    "|   |/.",
    "+---+..",
    {0}
};

void putCube(int x0, int y0)
{
    for (int y = 0; cube[y][0] != 0; ++y)
    {
        for (int x = 0; cube[y][x] != 0; ++x)
        {
            if (cube[y][x] != blank || canvas[y + y0][x + x0] == 0 || canvas[y + y0][x + x0] == blank)
            {
                canvas[y + y0][x + x0] = cube[y][x];
            }
        }
    }
}

void print(int w, int h)
{
    for (int y = 0; y < h; ++y)
    {
        for (int x = 0; x < w; ++x)
        {
            cout << canvas[y][x];
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    char map[2000][2000] = {{0}};
    int w, h, cw, ch;
    int x0, y0, x1, y1;
    cin >> h >> w;
    for (int y = 0; y < h; ++y)
    {
        cin >> map[y];
    }
    
    bool isBlank = true;
    
    y0 = 0;
    isBlank = true;
    while (isBlank)
    {
        for (int x = 0; x < w; ++x)
        {
            if (map[y0][x] != blank)
            {
                isBlank = false;
                break;
            }
        }
        if (isBlank) ++y0;
    }
    //cout << y0 << endl;
    y1 = h - 1;
    isBlank = true;
    while (isBlank)
    {
        for (int x = 0; x < w; ++x)
        {
            if (map[y1][x] != blank)
            {
                isBlank = false;
                break;
            }
        }
        if (isBlank) --y1;
    }
    //cout << y1 << endl;
    x0 = 0;
    isBlank = true;
    while (isBlank)
    {
        for (int y = 0; y < h; ++y)
        {
            if (map[y][x0] != blank)
            {
                isBlank = false;
                break;
            }
        }
        if (isBlank) ++x0;
    }
    //cout << x0 << endl;
    x1 = w - 1;
    isBlank = true;
    while (isBlank)
    {
        for (int y = 0; y < h; ++y)
        {
            if (map[y][x1] != blank)
            {
                isBlank = false;
                break;
            }
        }
        if (isBlank) --x1;
    }
    //cout << x1 << endl;
    
    cw = 3 + 4 * (x1 - x0 + 1);
    ch = 3 + 3 * (y1 - y0 + 1);
    
    for (int y = 0; y < ch; ++y)
    {
        for (int x = 0; x < cw; ++x)
        {
            canvas[y][x] = blank;
        }
    }
    
    // down to up, left to right
    for (int y = y1; y >= y0; --y)
    {
        int offsety = y - y0;
        for (int x = x0; x <= x1; ++x)
        {
            int offsetx = x - x0;
            if (map[y][x] != blank)
            {
                putCube(4 * offsetx, 3 * offsety);
            }
        }
    }
    
    print(cw, ch);
    
    return 0;
}