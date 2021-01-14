#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

using std::cout;
using std::endl;
using std::string;
using std::vector;

vector<unsigned char> RandomRotor()
{
	vector<unsigned char> randomR = { 0 , 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10 , 11 , 12 , 13 , 14 , 15 , 16 , 17 , 18 , 19 , 20 , 21 , 22 , 23 , 24 , 25 , 26 , 27 , 28 , 29 , 30 , 31 , 32 , 33 , 34 , 35 , 36 , 37 , 38 , 39 , 40 , 41 , 42 , 43 , 44 , 45 , 46 , 47 , 48 , 49 , 50 , 51 , 52 , 53 , 54 , 55 , 56 , 57 , 58 , 59 , 60 , 61 , 62 , 63 , 64 , 65 , 66 , 67 , 68 , 69 , 70 , 71 , 72 , 73 , 74 , 75 , 76 , 77 , 78 , 79 , 80 , 81 , 82 , 83 , 84 , 85 , 86 , 87 , 88 , 89 , 90 , 91 , 92 , 93 , 94 , 95 , 96 , 97 , 98 , 99 , 100 , 101 , 102 , 103 , 104 , 105 , 106 , 107 , 108 , 109 , 110 , 111 , 112 , 113 , 114 , 115 , 116 , 117 , 118 , 119 , 120 , 121 , 122 , 123 , 124 , 125 , 126 , 127 , 128 , 129 , 130 , 131 , 132 , 133 , 134 , 135 , 136 , 137 , 138 , 139 , 140 , 141 , 142 , 143 , 144 , 145 , 146 , 147 , 148 , 149 , 150 , 151 , 152 , 153 , 154 , 155 , 156 , 157 , 158 , 159 , 160 , 161 , 162 , 163 , 164 , 165 , 166 , 167 , 168 , 169 , 170 , 171 , 172 , 173 , 174 , 175 , 176 , 177 , 178 , 179 , 180 , 181 , 182 , 183 , 184 , 185 , 186 , 187 , 188 , 189 , 190 , 191 , 192 , 193 , 194 , 195 , 196 , 197 , 198 , 199 , 200 , 201 , 202 , 203 , 204 , 205 , 206 , 207 , 208 , 209 , 210 , 211 , 212 , 213 , 214 , 215 , 216 , 217 , 218 , 219 , 220 , 221 , 222 , 223 , 224 , 225 , 226 , 227 , 228 , 229 , 230 , 231 , 232 , 233 , 234 , 235 , 236 , 237 , 238 , 239 , 240 , 241 , 242 , 243 , 244 , 245 , 246 , 247 , 248 , 249 , 250 , 251 , 252 , 253 , 254 , 255 };
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(0, 255);
	for (int i = 0; i < 1000; i++) {
		int n1 = dis(gen), n2 = dis(gen);
		unsigned char f = randomR[n1], f2 = randomR[n2];
		randomR[n1] = f2;
		randomR[n2] = f;
	}
	return randomR;
}

void TwitchArrayRight(vector<unsigned char>& arr) {
	if (arr.size() == 0) return;
	unsigned char f = arr[arr.size() - 1];
	for (int i = arr.size() - 1; i > 0; i--) arr[i] = arr[i - 1];
	arr[0] = f;
}

void TwitchArrayLeft(vector<unsigned char>& arr) {
	if (arr.size() == 0) return;
	unsigned char f = arr[0];
	for (int i = 0; i < arr.size()-1; i++) arr[i] = arr[i + 1];
	arr[arr.size() - 1] = f;
}

int IndexOf(vector<unsigned char> arr, unsigned char val) {
	for (int i = 0; i < arr.size(); i++) if (arr[i] == val) return i;
}

struct fbinigma {
private:

	vector<vector<unsigned char>> rotors;
	vector<vector<unsigned char>> OriginalRotors;
	vector<int> rotorsStartingPositions;
	bool stabilized = false;

	void rotate_rotor(int rotor = 0) {
		for (; rotor < rotors.size(); rotor++) {
			if (rotor == 0) {
				TwitchArrayRight(rotors[rotor]);
				TwitchArrayLeft(rotors[rotor + 1]);
			}
			else TwitchArrayRight(rotors[rotor]);
			if (rotors[rotor][0] == rotorsStartingPositions[rotor]) {
				if (rotor == 0) rotor += 1;
				continue;
			}
			else break;
		}
	}

	void rotate_rotors(int times) {
		if (!stabilized) return;
		for (int i = 0; i < times; i++) rotate_rotor(0);
	}

public:

	void AddRotor(vector<unsigned char> _rotor) {
		if(_rotor.size() == 256) rotors.push_back(_rotor);
	}

	void ToOriginalRotors() {
		rotors = OriginalRotors;
	}

	void StabilizeRotors() {
		rotorsStartingPositions.clear();
		if (rotors.size() < 2) {
			stabilized = false;
			return;
		}
		OriginalRotors = rotors;
		for (vector<unsigned char> rotor : rotors) rotorsStartingPositions.push_back(rotor[0]);
		stabilized = true;
	}

	string EncryptString(string _in) {
		if (!stabilized) return _in;
		for (int i = 0; i < _in.size(); i++) {
			unsigned int val = _in[i];
			for (vector<unsigned char> rotor : rotors) {
				val = rotor[val];
				_in[i] = val;
			}
			rotate_rotors(1);
		}
		return _in;
	}

	string DecryptString(string _in) {
		if (!stabilized) return _in;
		for (int i = 0; i < _in.size(); i++) {
			for (int j = rotors.size() - 1; j >= 0; j--) _in[i] = (unsigned char)IndexOf(rotors[j], _in[i]);
			rotate_rotors(1);
		}
		return _in;
	}
};

void functest() {

	fbinigma fnigma;
	//input as much rotors as the vector library gives you
	int rotornum = 10;
	for (int i = 0; i < rotornum; i++) fnigma.AddRotor(RandomRotor());

	fnigma.StabilizeRotors();

	//encryption
	string toEncrypt = "this is not a test!";
	string enc = fnigma.EncryptString(toEncrypt);
	fnigma.ToOriginalRotors();

	//decryption
	string dec = fnigma.DecryptString(enc);
	fnigma.ToOriginalRotors();

	cout << "Original: " << toEncrypt << endl << "Encrypted: " << enc << endl << "Decrypted: " << dec << endl;

	//output:
	//Original: this is not a test!
	//Encrypted : ClŻń*řFf%úÔŰśń«FŹS (depends on the rotors positions)
	//Decrypted : this is not a test!
}
