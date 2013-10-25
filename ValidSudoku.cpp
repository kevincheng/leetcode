/**
* question: Valid Sudoku  
* link: http://oj.leetcode.com/problems/valid-sudoku/
* Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
* The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
*/
#include <iostream>
#include <cmath>
#include "Solution.h"
using namespace std;

const int N = 9;
const int SqrtN=sqrt(N*1.0);
void initArray(int *array, unsigned int length) {
	for(int i=0; i<length; i++)
		array[i] = 0;
}

bool Solution::isValidSudoku(vector<vector<char> > &board) {
	int *occurence = new int[N];
	// check each row
	for(int i=0; i<N; i++) {
		initArray(occurence, N);
		for(int j=0; j<N; j++) {
			if(board[i][j] != '.') {
				int value = board[i][j] - '1';
				if(occurence[value] == 1)
					return false;
				else
					occurence[value] = 1;
			}
		}
	}
	// check each column
	for(int i=0; i<N; i++) {
		initArray(occurence, N);
		for(int j=0; j<N; j++) {
			if(board[j][i] != '.') {
				int value = board[j][i] - '1';
				if(occurence[value] == 1)
					return false;
				else
					occurence[value] = 1;
			}
		}
	}
	// check each square
	for(int i=0; i<SqrtN; i++) {
		for(int j=0; j<SqrtN; j++) {
			int startX = i*SqrtN;
			int startY= j*SqrtN;
			initArray(occurence, N);
			for(int p=0; p<SqrtN; p++) {
				for(int q=0; q<SqrtN; q++) {
					if(board[startX+p][startY+q] != '.') {
						int value = board[startX+p][startY+q] - '1';
						if(occurence[value] == 1)
							return false;
						else
							occurence[value] = 1;
					}
				}
			}
		}
	}
	delete []occurence;
	return true;
}