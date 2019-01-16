//
// Created by zy234 on 1/16/19.
//
using namespace std;

#include <vector>
#include <set>
#include <iostream>
//24ms 100%
class Solution {
private:
    void fillPixel(vector<vector<int>>& image, int rol, int col, int oldColor, int newColor, set<pair<int, int>> *filledPixelSet){
        //cout<<rol<<" "<<col<<" "<<endl;
        if(rol < 0 || rol >= image.size())
            return;
        if(col < 0 || col >= image[rol].size())
            return;
        if(image[rol][col] != oldColor)
            return;
        if(filledPixelSet->find(make_pair(rol, col))!=filledPixelSet->end())
            return;
        //cout<<rol<<" "<<col<<" "<<newColor<<endl;
        image[rol][col] = newColor;
        filledPixelSet->insert(make_pair(rol, col));
        fillPixel(image, rol-1, col, oldColor, newColor, filledPixelSet);
        fillPixel(image, rol+1, col, oldColor, newColor, filledPixelSet);
        fillPixel(image, rol, col-1, oldColor, newColor, filledPixelSet);
        fillPixel(image, rol, col+1, oldColor, newColor, filledPixelSet);
        return;
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        set<pair<int, int>> filledPixelSet;
        int oldColor = image[sr][sc];
        fillPixel(image, sr, sc, oldColor, newColor, &filledPixelSet);
        return image;
    }
};

int main(){
    Solution test;
    vector<vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}};
    int sr = 1;
    int sc = 1;
    int newColor = 2;
    test.floodFill(image, sr, sc, newColor);
    for(int i = 0; i < image.size(); i++){
        for(int j = 0; j < image[i].size(); j++){
            cout<<image[i][j]<<"  ";
        }
        cout<<endl;
    }
    return 0;
}