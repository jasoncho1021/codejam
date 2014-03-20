
#include <stdio.h>
#include <math.h>
#include <limits.h>

#define MAX_N 17
#define MAX_PERMUTATION 131072 // 2^17
int N=MAX_N;
int cache[MAX_N][MAX_PERMUTATION];
int parent[MAX_PERMUTATION];

int tsp(int cost[MAX_N][MAX_N], int n, int end){
	int min = INT_MAX, cur;
	int p;
    //int n = powl(2, N);

	if(n==0){
		return cost[end][0];
	}

	if (cache[end][n]!= -1) {
        return cache[end][n];
    }

	int i, mask;
	int setCount = 0;


	for(i=0;i<MAX_N;i++){
		mask = 1<<i;
		int temp = n&mask;
		if(temp == mask){
			cur = cost[end][i] + tsp(cost, n-mask, i);
			if(cur < min){
				min = cur;
				parent[n]= i;
			}
		}		
	}

	printf("%d,%d=%d\n", end,n,min);
	cache[end][n] = min;

	return min;
}



int main(){
    int c[4][4] = {
            {0, 12, 11, 16},
            {15, 0, 15, 10},
            {8,14,0,8},
            {9,11,17,0}
    };

    int d[15][15] = {
	  {0,       29,        82,        46,        68,        52,        72,        42,        51,        55,        29,        74,        23,        72,        46},
	  {29,         0,        55,        46,        42,        43,        43,        23,        23,        31,        41,        51,        11,        52,        21},
	  {82,        55,         0,        68,        46,        55,        23,        43,        41,        29,        79,        21,        64,        31,        51},
    {46,        46,        68,         0,        82,        15,        72,        31,        62,        42,        21,        51,        51,        43,        64},
    {68,        42,        46,        82,         0,        74,        23,        52,        21,        46,        82,        58,        46,        65,        23},
    {52,        43,        55,        15,        74,         0,        61,        23,        55,        31,        33,        37,        51,        29,        59},
    {72,        43,        23,        72,        23,        61,         0,        42,        23,        31,        77,        37,        51,        46,        33},
    {42,        23,        43,        31,        52,        23,        42,         0,        33,        15,        37,        33,        33,        31,        37},
    {51,        23,        41,        62,        21,        55,        23,        33,         0,        29,        62,        46,        29,        51,        11},
    {55,        31,        29,        42,        46,        31,        31,        15,        29,         0,        51,        21,        41,        23,        37},
    {29,        41,        79,        21,        82,        33,        77,        37,        62,        51,         0,        65,        42,        59,        61},
    {74,        51,        21,        51,        58,        37,        37,        33,        46,        21,        65,         0,        61,        11,        55},
    {23,        11,        64,        51,        46,        51,        51,        33,        29,        41,        42,        61,         0,        62,        23},
    {72,        52,        31,        43,        65,        29,        46,        31,        51,        23,        59,        11,        62,         0,        59},
    {46,        21,        51,        64,        23,        59,        33,        37,        11,        37,        61,        55,        23,        59,         0}};

	int e[17][17] = {
	  {0, 633, 257,  91, 412, 150,  80, 134, 259, 505, 353, 324,  70, 211, 268, 246, 121},
	  {633,   0, 390, 661, 227, 488, 572, 530, 555, 289, 282, 638, 567, 466, 420, 745, 518},
	  {257, 390,   0, 228, 169, 112, 196, 154, 372, 262, 110, 437, 191,  74,  53, 472, 142},
	  {91, 661, 228,   0, 383, 120,  77, 105, 175, 476, 324, 240,  27, 182, 239, 237,  84},
	  {412, 227, 169, 383,   0, 267, 351, 309, 338, 196,  61, 421, 346, 243, 199, 528, 297},
	  {150, 488, 112, 120, 267,   0,  63,  34, 264, 360, 208, 329,  83, 105, 123, 364,  35},
	  {80, 572, 196,  77, 351,  63,   0,  29, 232, 444, 292, 297,  47, 150, 207, 332,  29},
	  {134, 530, 154, 105, 309,  34,  29,   0, 249, 402, 250, 314,  68, 108, 165, 349,  36},
	  {259, 555, 372, 175, 338, 264, 232, 249,   0, 495, 352,  95, 189, 326, 383, 202, 236},
	  {505, 289, 262, 476, 196, 360, 444, 402, 495,   0, 154, 578, 439, 336, 240, 685, 390},
	  {353, 282, 110, 324,  61, 208, 292, 250, 352, 154,   0, 435, 287, 184, 140, 542, 238},
	  {324, 638, 437, 240, 421, 329, 297, 314,  95, 578, 435,   0, 254, 391, 448, 157, 301},
	  {70, 567, 191,  27, 346,  83,  47,  68, 189, 439, 287, 254,   0, 145, 202, 289,  55},
	  {211, 466,  74, 182, 243, 105, 150, 108, 326, 336, 184, 391, 145,   0,  57, 426,  96},
	  {268, 420,  53, 239, 199, 123, 207, 165, 383, 240, 140, 448, 202,  57,   0, 483, 153},
	  {246, 745, 472, 237, 528, 364, 332, 349, 202, 685, 542, 157, 289, 426, 483,   0, 336},
	  {121, 518, 142,  84, 297,  35,  29,  36, 236, 390, 238, 301,  55,  96, 153, 336,   0}
	};

    int i, j;
    for(i=0;i<MAX_N;i++){
        for (j=0;j<MAX_PERMUTATION;j++ ){
            cache[i][j]=-1;
        }
    }

    //int min = tsp(c, pow((long double)2, 4) -2, 0);
    int min = tsp(e, pow((long double)2, 17)-2, 0);
    printf("%d\n", min);

    int cur = pow((long double)2, 17)-2;
    for (i = 0; i < MAX_N; ++i) {
        printf("%d ", parent[cur]);
        cur -= 1<<parent[cur];
    }

}
