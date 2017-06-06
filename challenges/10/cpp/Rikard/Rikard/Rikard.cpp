// Rikard.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cmath>
#include <string>
#include <iostream>
#include <ctime>

std::string deBruijnBreak(int n, int k, int code);
std::string BruteForceBreak(int n, int k, int code);
void deBruijn(int n, int k);

int main()
{
	int n = 4, k = 10, code = 7423;

	//deBruijn(n, k);

	clock_t start = clock();
	std::string returnCode = deBruijnBreak(n, k, code);
	clock_t stop = clock();
	std::cout << "deBruijn returned code: " << returnCode << std::endl;
	std::cout << "It took " << (double)(stop - start)*1000.0/CLOCKS_PER_SEC << "ms" << std::endl;

	start = clock();
	returnCode = BruteForceBreak(n, k, code);
	stop = clock();
	std::cout << "BruteForce returned code: " << returnCode << std::endl;
	std::cout << "It took " << (double)(stop - start)*1000.0/CLOCKS_PER_SEC << "ms" << std::endl;
	
}

std::string deBruijnBreak(int n, int k, int code) {
	int N = (int)pow(k, n);
	std::string deBruijn = "";
	std::string codeStr = std::to_string(code);

	for (int i = 0; i < n; i++)
		deBruijn = deBruijn + "0";

	for (int i = n; i < N + n - 1; i++) {
		std::string suffix = deBruijn.substr((i - n) + 1);
		for (int j = 1; j < k; j++) {
			if (deBruijn.find(suffix + std::to_string(j)) == std::string::npos) {
				deBruijn = deBruijn + std::to_string(j);
				break;
			}
			if (j == k - 1)
				deBruijn = deBruijn + "0";
		}
		std::string lastCode = deBruijn.substr(deBruijn.length() - n);
		if (0 == lastCode.compare(codeStr))
			return lastCode;
	}
	return "";
}

std::string BruteForceBreak(int n, int k, int code) {
	std::string codeStr = std::to_string(code);
	std::string bruteForce = "";
	for (int i = 0; i < n; i++)
		bruteForce = bruteForce + "0";
	
	for (int i = 0; i < (int)pow(k, n); i++)
	{
		int tmpInt = atoi(bruteForce.c_str());
		tmpInt++;
		bruteForce = std::to_string(tmpInt);

	if (0 == bruteForce.compare(codeStr))
		return bruteForce;
	}
	return "";
}


void deBruijn(int n, int k) {
	int N = (int)pow(k, n);
	std::string deBruijn = "";

	for (int i = 0; i < n; i++)
		deBruijn = deBruijn + "0";

	for (int i = n; i < N + n - 1; i++) {
		std::string suffix = deBruijn.substr((i - n) + 1);
		for (int j = 1; j < k; j++) {
			if (deBruijn.find(suffix + std::to_string(j)) == std::string::npos) {
				deBruijn = deBruijn + std::to_string(j);
				break;
			}
			if (j == k - 1)
				deBruijn = deBruijn + "0";
		}
	}
	std::cout << deBruijn;
}