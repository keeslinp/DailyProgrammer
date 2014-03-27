#include <iostream>
#include <array>
#include <vector>

int max(std::vector<int> nums)
{
	int biggest = 0;
	for(auto it = nums.begin();it<nums.end();it++)
	{
		biggest = (*it<biggest?biggest:*it);
	}
	return biggest;
}

int main() {
	std::array<std::array<int,20>,20> grid;
	for(auto it = grid.begin();it<grid.end();it++)
	{
		for(auto jt = (*it).begin();jt <(*it).end();jt++)
		{
			std::cin >> *jt;
		}
	}
	int biggest =0;
	for(int x = 0;x < 20;x++)
	{
		for(int y=0;y<20;y++)
		{
			std::vector<int> ary;
			int buff = grid[x][y]*grid[x][y+1]*grid[x][y+2]*grid[x][y+3];
			if(y < 17) ary.push_back(buff);
			buff = grid[x][y]*grid[x+1][y+1]*grid[x+2][y+2]*grid[x+3][y+3];
			if(x < 17 && y < 17)ary.push_back(buff);
			buff = grid[x][y]*grid[x-1][y+1]*grid[x-2][y+2]*grid[x-3][y+3];
			if(x >3 && y < 17)ary.push_back(buff);
			buff = grid[x][y]*grid[x+1][y]*grid[x+2][y]*grid[x+3][y];
			if(x < 17)ary.push_back(buff);
			ary.push_back(biggest);
			biggest = max(ary);
		}
	}
	std::cout << biggest<< std::endl;
	return 0;
}
