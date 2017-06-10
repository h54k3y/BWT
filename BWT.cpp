#include "BWT.hpp"
using namespace std;
int BWT_encode(const string text,string &encoded_text){
	string data=text+"$";
	int data_size=data.size();
	vector <string> data_block(data_size);
	data_block[0]=data;
	for(int i=1;i<data_size;i++){
		data_block[i]=data_block[i-1].substr(1)+data_block[i-1].substr(0,1);
	}
	sort(data_block.begin(),data_block.end());
	for(int i=0;i<data_size;i++){
		encoded_text+=data_block[i][data_size-1];
	}
	return 0;
}
int BWT_decode(const string encoded_text, string &decoded_text){
	int encoded_size=encoded_text.size();
	int alpha[26];
	int pos;
	vector<pair <char,int> > F(encoded_size);
	string L=encoded_text;
	for(int i=0;i<encoded_size;i++){
		if(encoded_text[i]=='$'){
			pos=i;
		}
		F[i]=make_pair(encoded_text[i],i);
	}
	sort(F.begin(),F.end());
	for(int i=0;i<encoded_size-1;i++){
		decoded_text+=F[pos].first;
		pos=F[pos].second;
	}
	return 0;
}