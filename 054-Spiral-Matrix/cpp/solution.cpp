/**
* Created by yangyangu
* 2018 / 08
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
    	vector<int> mat;
    	if(matrix.size() == 0) return mat;
        int ul = 0, lc = 0, rc = matrix[0].size() - 1 , dl = matrix.size() - 1;
    	int l = 0, c = 0;
    	int cnt = (rc + 1) * (dl + 1);
    	int ant = 0;
        while(lc <= rc && ul <= dl){
        	

        	for(c = lc; c <= rc && ant < cnt; ++ c){
        		mat.push_back(matrix[l][c]);
        		++ ant;
        		//cout << l << " " << c << endl;
        	}
        	c = rc;
        	++ ul;
        	for(l = ul; l <= dl && ant < cnt; ++ l){
        		mat.push_back(matrix[l][c]);
        		++ ant;
        		//cout << l << " " << c << endl;
        	}
        	l = dl;
        	-- rc;
        	for(c = rc; c >= lc && ant < cnt; -- c){
        		mat.push_back(matrix[l][c]);
        		++ ant;
        		//cout << l << " " << c << endl;
        	}
        	c = lc;
        	-- dl;
        	for(l = dl; l >= ul && ant < cnt; -- l){
        		mat.push_back(matrix[l][c]);
        		++ ant;
        		//cout << l << " " << c << endl;
        	}
        	++ lc;
        	l = ul;
        }

        return mat;
    }
};

int main(){
	Solution solution;
	vector<vector<int>> mat1 = {
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};

	vector<vector<int>> mat2 = {
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12}
	};

	auto res1 = solution.spiralOrder(mat1);
	auto res2 = solution.spiralOrder(mat2);

	for(auto i: res1)
		cout << i << " ";
	cout << endl;

	for(auto i: res2)
		cout << i << " ";
	cout << endl;
	return 0;
}