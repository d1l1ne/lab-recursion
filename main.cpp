#include <iostream>
#include <string>

using namespace std;

int current_pos=0;
int utemp(0);
bool isRealNumber(string str);
bool isMantissa(string str, int curr_pos);
bool isOrder(string str, int curr_pos);
bool isUnsigned(string str, int curr_pos);
bool isdigit(string str, int curr_pos);
bool isSign(string str, int curr_pos);
bool isEIn(string str, int curr_pos);

int main() {

	string input;
	cout << "Enter a number:" << endl;
	
	cin >> input;

	if (isRealNumber(input)) {
		cout << "Number is real" << endl;
	}
	else {
		cout << "Number is not real" << endl;
	}

	system("pause");
	return 0;

}

bool isRealNumber(string str) {
	bool isM, isO;
	bool strsigned = isSign(str, current_pos);

	if (!isEIn(str, current_pos)) {
		
		return false;

	}

	isM = isMantissa(str, current_pos);
	if(isMantissa)isO = isOrder(str, current_pos);

	return isM && isO;

}

bool isEIn(string str, int curr_pos) {

	int n = curr_pos;
	int length = str.length();
	if (str[n] == 'E' || str[n] == 'e') {
		return true;
	}
	else if (n < length-1) {
		n++;
		isEIn(str, n);
	}
	else {
		cout << "stop 3" << endl;
		return false;
	}

}

bool isSign(string str, int curr_pos) {
	if (str[current_pos] == '+' || str[current_pos] == '-') {
		current_pos++;
		return true;
	}
	else {
		return false;
	}
}

bool isdigit(string str, int curr_pos) {
	if (curr_pos<str.length()&&(str[curr_pos] == '0' || str[curr_pos] == '1' || str[curr_pos] == '2' || str[curr_pos] == '3' || str[curr_pos] == '4' || str[curr_pos] == '5' || str[curr_pos] == '6' || str[curr_pos] == '7' || str[curr_pos] == '8' || str[curr_pos] == '9')) {
		return true;
	}
	else {
		return false;
	}
}

bool isUnsigned(string str, int curr_pos) {
	if (current_pos<str.length()&& isdigit(str, current_pos)) {
		current_pos++;
		utemp++;
		if (current_pos < str.length()) {
			if (isSign(str, current_pos)) {
				return false;
			}
			else {
				return isUnsigned(str, current_pos);
			}
			
		}
		else {
			return true;
		}
	}
	else if (!isdigit(str, current_pos) && utemp > 0) {
		return true;
	}
	else {
		return false;
	}

}

bool isMantissa(string str, int curr_pos) {
	if (str[current_pos] == '.'&&current_pos<str.length()-1) {
		current_pos++;
		return isUnsigned(str, current_pos);
	}
	else {
		return false;
	}

}

bool isOrder(string str, int curr_pos) {
	utemp = 0;
	bool temp;
	if (current_pos<str.length()&&(str[current_pos] == 'E' || str[current_pos] == 'e')) {
		current_pos++;
		temp = isSign(str, current_pos);
		if (current_pos < str.length()) {
			return isUnsigned(str, current_pos);
		}
		else {
			return true;
		}
	}
	else {
		return false;
	}
}
