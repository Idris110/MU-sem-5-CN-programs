// C++ program for the above approach

#include <bits/stdc++.h>
using namespace std;

// Function to generate hamming code
vector<int> generateHammingCode(vector<int> msgBits, int m, int r)
{
	// Stores the Hamming Code
	vector<int> hammingCode(r + m);

	// Find positions of redundant bits
	for (int i = 0; i < r; ++i) {

		// Placing -1 at redundant bits
		// place to identify it later
		hammingCode[pow(2, i) - 1] = -1;
	}

	int j = 0;

	// Iterate to update the code
	for (int i = 0; i < (r + m); i++) {

		// Placing msgBits where -1 is
		// absent i.e., except redundant
		// bits all positions are msgBits
		if (hammingCode[i] != -1) {
			hammingCode[i] = msgBits[j];
			j++;
		}
	}

	for (int i = 0; i < (r + m); i++) {

		// If current bit is not redundant
		// bit then continue
		if (hammingCode[i] != -1)
			continue;

		int x = log2(i + 1);
		int one_count = 0;

		// Find msg bits containing
		// set bit at x'th position
		for (int j = i + 2; j <= (r + m); ++j) {
			if (j & (1 << x)) {
				if (hammingCode[j - 1] == 1)
					one_count++;
			}
		}

		if (one_count % 2 == 0) 
			hammingCode[i] = 0;
		else 
			hammingCode[i] = 1;
	}
	return hammingCode;
}

vector<int> parityOut(vector<int> hammingCode, int r)
{
	vector<int> outParity(r);

	for (int k = 0; k < r; k++) {

		int i = pow(2, k) - 1;

		int x = log2(i + 1);
		int one_count = 0;

		for (int j = i + 1; j <= hammingCode.size(); ++j) {
			if (j & (1 << x)) {
				if (hammingCode[j - 1] == 1)
					one_count++;
			}
		}
		if (one_count % 2 == 0) 
			outParity[k] = 0;
		else 
			outParity[k] = 1;
	}
	return outParity;
}

void findHammingCode(vector<int>& msgBit, int m)
{
	srand(time(0));
	int r = 1;
	// Find no. of redundant bits
	while (pow(2, r) < (m + r + 1)) {
		r++;
	}

	cout << "r = "<<r<<endl;
	vector<int> ans = generateHammingCode(msgBit, m, r);

	cout << "Hamming code is: ";
	for (int i = ans.size()-1; i>=0  ; i--)
		cout << ans[i] << " ";

	vector<int> recCode = ans;

	cout<<"\n\nAn random error is generated \n";
	int errBit = rand() % ans.size();
	cout<<"Codeword received by the receiver : ";
	recCode[errBit] = (ans[errBit] == 1) ? 0 : 1; // gen error
	for (int i = ans.size()-1; i>=0  ; i--)
		cout << recCode[i] << " ";
	
	cout<<"\nMessage received : ";
	for (int i = ans.size()-r-1 ; i>=0  ; i--)
		cout << recCode[i] << " ";
	
	vector<int> outParity = parityOut(recCode, r);

	cout<<"\nOutput parity : ";
	int dec = 0;
	for(int i=outParity.size()-1 ;i>=0;i--){
		cout << outParity[i] << " ";
		if(outParity[i] == 1){
			dec += pow(2, i);
		}
	}
	cout<<"\nThe error is generated in bit : "<< dec <<"\n";
	
	cout<<"Corrected message : ";
	
	recCode[dec] = (ans[dec] == 1) ? 0 : 1; // gen error
	for (int i = ans.size()-r-1 ; i>=0  ; i--)
		cout << recCode[i] << " ";
	
	
}

int main()
{
	int m;
	cout<<"Enter the length of message : ";
	cin>>m;
	vector<int> msgBit(m);
	cout<<"Enter the message in binary : ";

	for(int i=0; i<m; i++)
		cin>>msgBit[i];

	findHammingCode(msgBit, m);

	return 0;
}
