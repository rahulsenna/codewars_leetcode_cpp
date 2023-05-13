// #include <bits/stdc++.h>
#include <vector>
#include <unordered_map>

using namespace std;

bool does_exist(unordered_map<char, int> &map, char c)
{
    if (c != '.')
    {
        if (map[c] > 0)
        {
            return true;
        }
        map[c]++;
    }

    return false;
}

bool isValidSudoku(vector<vector<char>> &board)
{
    // Horizontal lines
    for (auto &line : board)
    {
        unordered_map<char, int> map;
        for (auto &c : line)
        {
            if (does_exist(map, c))
            {
                return false;
            }
        }
    }
    // Vertical lines
    for (size_t x = 0; x < 9; ++x)
    {
        unordered_map<char, int> map;
        for (size_t y = 0; y < 9; ++y)
        {
            char c = board[y][x];
            if (does_exist(map, c))
            {
                return false;
            }
        }
    }

    // 3x3
    for (size_t i = 0; i < 9; ++i)
    {
        size_t ix = (i / 3) * 3;
        size_t iy = (i % 3) * 3;
        unordered_map<char, int> map;
        for (int y = iy; y < iy + 3; ++y)
        {
            for (int x = ix; x < ix + 3; ++x)
            {
                char c = board[y][x];
                if (does_exist(map, c))
                {
                    return false;
                }
            }
        }
    }


#if 0
    // My 3x3 sudoku traversal
    for (size_t y = 0; y < 9; y+=3)
    {
        for (size_t x = 0; x < 9; x+=3)
        {
            unordered_map<char, int> map;
            for (size_t i = 0; i < 3; ++i)
            {
                for (size_t j = 0; j < 3; ++j)
                {
                    char c = board[i+y][j+x];
                    if (c != '.')
                    {
                        if (map[c] > 0)
                        {
                            return false;
                        }
                        map[c]++;
                    }
                }

            }
        }
    }
#endif

    return true;
}

int main()
{
    vector<vector<char>> in =
    {{'5', '3', '.', '.', '7', '.', '.', '.', '.'}, {'6', '.', '.', '1', '9', '5', '.', '.', '.'}, {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, {'8', '.', '.', '.', '6', '.', '.', '.', '3'}, {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, {'7', '.', '.', '.', '2', '.', '.', '.', '6'}, {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, {'.', '.', '.', '4', '1', '9', '.', '.', '5'}, {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    auto res = isValidSudoku(in);

    return (0);
}