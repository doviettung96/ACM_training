int *construct(int arr[], int n);
int constructUtil(int arr[], int arrayStart, int arrayEnd, int *segmentTree, int currentNodePosition);
int getSum(int *segmentTree, int arrayLength, int queryStart, int queryEnd);
int getSumUtil(int *segmentTree, int arrayStart, int arrayEnd, int queryStart, int queryEnd, int currentNodePosition);
void update(int arr[], int n, int *segmentTree, int insertIndex, int insertValue);
void updateUtil(int *segmentTree, int arrayStart, int arrayEnd, int currentNodePosition, int insertIndex, int different);