#include <iostream>
using namespace std;
#include <fstream>
/*
			输入城市数目 n
			对应的路径条数有 n-1 条
			题目求解最优的骑行路径
*/
int main() {
 
 
	fstream filein;
	fstream fileout;
 
	filein.open("jill.in", ios::in);
	fileout.open("jill.out", ios::out);
 
 
 
	int result_road[128][3];					//  3 列 第一列表示数据组号  第二列表示 起点  第三列表示终点
	int length_result = 0;
 
	int road[128];								// 存放路径的兴趣度
 
	int account;
	filein >> account;				//输入数据组的个数
	while (account) {
		int city_num;
		filein >> city_num;		//输入城市的个数
		for (int i = 0; i < city_num - 1; i++) {
			filein >> road[i];
		}
 
		int max = 0;							//定义最大满意度
		int start = 0;							//定义起点
		int end = 0;							//定义终点
 
		for (int i = 0; i < city_num - 1; i++) {	// 假设每一点都是起点
			if (road[i] < 0) {
				continue;
			}
			for (int h = city_num - 2; h >= i; h--) {	//假设每一点都是终点
				if (road[h] < 0) {
					continue;
				}
 
 
				int temp = 0;
				for (int w = i; w <= h; w++) {
					temp += road[w];
				}
				if (temp > max) {
					max = temp;
					start = i + 1;
					end = h + 2;
				}
			}
			//	cout << "---" << max << "---";
		}
 
		result_road[length_result][0] = max;
		result_road[length_result][1] = start;
		result_road[length_result++][2] = end;
		account--;
	}
 
 
	for (int i = 0; i < length_result; i++) {
		if (result_road[i][0] <= 0) {
			fileout << "Route " << i + 1 << " has no nice parts" << endl;
		} else {
			fileout << "The nicest part of route " << i + 1 << " is between stops " << result_road[i][1] << " and " <<
			        result_road[i][2] << endl;
		}
	}
}
 
 
 
 