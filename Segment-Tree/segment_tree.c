#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "segment_tree.h"

int findMiddle(int start, int end){
	return (end - start) / 2 + start;
}

int *construct(int arr[], int n){
	int height = (int) ceil(log2(n));
	int treeSize = 2 * (int) pow(2, height) - 1;

	int *segmentTree = (int *)malloc(sizeof(int) * treeSize);
	constructUtil(arr, 0, n - 1, segmentTree, 0);
	return segmentTree;
}

int constructUtil(int arr[], int arrayStart, int arrayEnd, int *segmentTree, int currentNodePosition){
	if(arrayStart == arrayEnd){
		segmentTree[currentNodePosition] = arr[arrayStart];
		return arr[arrayStart];
	}
	int mid = findMiddle(arrayStart, arrayEnd);
	segmentTree[currentNodePosition] = 
	constructUtil(arr, arrayStart, mid, segmentTree, 2 * currentNodePosition + 1) +
	constructUtil(arr, mid + 1, arrayEnd, segmentTree, 2 * currentNodePosition + 2);
	return segmentTree[currentNodePosition];
}

int getSum(int *segmentTree, int n, int queryStart, int queryEnd){
	if(queryStart < 0 || queryEnd >= n - 1 || queryStart > queryEnd){
		fprintf(stderr, "%s\n", "Invalid query");
		return -1;
	}
	return getSumUtil(segmentTree, 0, n - 1, queryStart, queryEnd, 0);
}

int getSumUtil(int *segmentTree, int arrayStart, int arrayEnd, int queryStart, int queryEnd, int currentNodePosition){
	if(queryStart <= arrayStart && queryEnd >= arrayEnd) return segmentTree[currentNodePosition];
	if(queryEnd < arrayStart || queryStart > arrayEnd) return 0;
	int mid = findMiddle(arrayStart, arrayEnd);
	return getSumUtil(segmentTree, arrayStart, mid, queryStart, queryEnd, 2 * currentNodePosition + 1) +
	getSumUtil(segmentTree, mid + 1, arrayEnd, queryStart, queryEnd, 2 * currentNodePosition + 2);
}

void update(int arr[], int n, int *segmentTree, int insertIndex, int insertValue){
	if(insertIndex < 0 || insertIndex > n - 1){
		fprintf(stderr, "%s\n", "Invalid input array");
		return;
	}
	int different = insertValue - arr[insertIndex];
	arr[insertIndex] = insertValue;
	updateUtil(segmentTree, 0, n - 1, 0, insertIndex, different);
}

void updateUtil(int *segmentTree, int arrayStart, int arrayEnd, int currentNodePosition, int insertIndex, int different){
	if(insertIndex < arrayStart || insertIndex > arrayEnd) return;
	segmentTree[currentNodePosition] += different;
	if(arrayStart != arrayEnd){
		int mid = findMiddle(arrayStart, arrayEnd);
		updateUtil(segmentTree, arrayStart, mid, 2 * currentNodePosition + 1, insertIndex, different);
		updateUtil(segmentTree, mid + 1, arrayEnd, 2 * currentNodePosition + 2, insertIndex, different);

	}
}