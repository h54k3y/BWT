#include "naive.hpp"
using namespace std;
int naive(const string text, const string query, vector<int> &hit_position){
	int hit_cnt=0;
	for(int i=0; i<text.size(); i++){
		for(int j=0; j<query.size(); j++){
			if(text[i+j]!=query[j]){
				break;
			}
			if(query.size()-1==j){
				hit_position[hit_cnt]=i;
				hit_cnt++;
			}
		}
	}
	return hit_cnt;
}