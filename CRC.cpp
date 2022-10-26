#include<bits/stdc++.h>
using namespace std;

string xor1(string a, string b)
{
	string result = "";
	
	int n = b.length();
	
	for(int i = 1; i < n; i++)
	{
		if (a[i] == b[i])
			result += "0";
		else
			result += "1";
	}
	return result;
}


string mod2div(string divident, string divisor){
	
	int pick = divisor.length();
	int n = divident.length();
	string tmp = divident.substr(0, pick);
	cout<<tmp<<endl;
	
	while (pick < n)
	{
		if (tmp[0] == '1'){
			tmp = xor1(divisor, tmp) + divident[pick];
			cout<<"1: "<<tmp<<endl;
			}
		else{
			tmp = tmp.substr(1,tmp.size()-1) + divident[pick];
			cout<<"0: "<<tmp<<endl;
			}
		
		pick += 1;
	}

	if (tmp[0] == '1')
		tmp = xor1(divisor, tmp);
	else
		tmp = xor1(std::string(pick, '0'), tmp);
		
	return tmp;
}

void encodeData(string data, string key)
{
	int l_key = key.length();
	
	// Appends n-1 zeroes at end of data
	string appended_data = (data + std::string(l_key - 1, '0'));
	
	string remainder = mod2div(appended_data, key);
	
	// Append remainder in the original data
	string codeword = data + remainder;
	cout << "Remainder : "
		<< remainder << "\n";

	// cout << "Encoded Data (Data + Remainder) :"
	// 	<< codeword << "\n";

	// int errBit = rand() % codeword.size();
	// cout<<"An random error is generated\n";
	// codeword[errBit] = (codeword[errBit] == '1') ? '0' : '1';


	// cout<<"Codeword received by the receiver : "<<codeword;
	// cout<<"\nMessage received : ";
	// for(int i=0 ;i<data.size() ; i++)
	// 	cout<<codeword[i];

	// remainder = mod2div(codeword, key);
	// cout << "\nRemainder : "<< remainder << "\n";
	
	// if(stoi(remainder)) cout<<"Error detected\n\n";
	// else cout<<"Hence no error detected\n";
}

int main()
{
	string data, key;
	cout<<"Enter the data : ";
	cin>>data;
	cout<<"Enter the key : ";
	cin>>key;
	encodeData(data, key);
	
	return 0;
}

