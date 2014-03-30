// No. of occurences of every element in an array

#include <iostream>

#define MAX 10

using namespace std;

void numOfOcc(int *arr){
	
	int k = 0, occ;
	int tmpArr[MAX];
	
	for(int i = 0; i < MAX; i++){
		
		bool scanned = false;
		for(int j = 0; j < k; j++){
			
			if(tmpArr[j] == arr[i]){
				
				scanned = true;
				break;
				
			}
		}
		
		if (!scanned){
			
			int count = 0;
			for (int p = i; p < MAX; p++){
			
				if (arr[p] == arr[i])
					count++;
			}
			
			cout << arr[i] << " occurs " << count << " times\n";
			tmpArr[k] = arr[i];
			k++;
		}
	}
}

int main(){
	
	int a[MAX] = {9,1,4,2,6,2,1,6,4,2};
	numOfOcc(a);
	
}
