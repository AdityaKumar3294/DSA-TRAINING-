#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        int layers = min(m, n) / 2;

        for (int layer = 0; layer < layers; layer++) {

            vector<int> elems;

            int top = layer;
            int left = layer;
            int bottom = m - layer - 1;
            int right = n - layer - 1;

            // top row
            for (int j = left; j < right; j++)
                elems.push_back(grid[top][j]);

            // right column
            for (int i = top; i < bottom; i++)
                elems.push_back(grid[i][right]);

            // bottom row
            for (int j = right; j > left; j--)
                elems.push_back(grid[bottom][j]);

            // left column
            for (int i = bottom; i > top; i--)
                elems.push_back(grid[i][left]);

            int len = elems.size();
            int rot = k % len;

            vector<int> rotated(len);

            for (int i = 0; i < len; i++) {
                rotated[i] = elems[(i + rot) % len];
            }

            int idx = 0;

            // top row
            for (int j = left; j < right; j++)
                grid[top][j] = rotated[idx++];

            // right column
            for (int i = top; i < bottom; i++)
                grid[i][right] = rotated[idx++];

            // bottom row
            for (int j = right; j > left; j--)
                grid[bottom][j] = rotated[idx++];

            // left column
            for (int i = bottom; i > top; i--)
                grid[i][left] = rotated[idx++];
        }

        return grid;
    }
};