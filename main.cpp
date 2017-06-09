#include "naive.hpp"
#include "BWT.hpp"
using namespace std;
int main(){
	string select;
	cout<<"Please select naive search or BWT"<<endl;
	cin>>select;
	if(select=="naive"){
		cout<<"Start naive search"<<endl;
		string text;
		cout<<"input text"<<endl;
		cin>>text;
		string query;
		vector<int> hit_position(text.size()+10);
		cout<<"input query"<<endl;
		while(cin>>query){
			if(query=="#q"){
				break;
			}
			int hit_cnt=naive(text,query,hit_position);
			if(hit_cnt==0){
				cout<<"No Hit"<<endl;
			}
			else{
				cout<<hit_cnt<<" "<<"Hit"<<endl;
				for(int i=0;i<hit_cnt;i++){
					cout<<hit_position[i]<<endl;
				}
			}
			cout<<"input query or quit(#q)"<<endl;
		}
	}
	if(select=="BWT"){
		cout<<"Start BWT"<<endl;
		string text;
		string encoded_text;
		cout<<"input text"<<endl;
		cin>>text;
		cout<<"encode text"<<endl;
		BWT_encode(text,encoded_text);
		cout<<encoded_text<<endl;
		cout<<"decode text"<<endl;
		//BWT_decode();
	}
	return 0;
}