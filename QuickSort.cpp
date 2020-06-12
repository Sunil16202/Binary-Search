int parition(int input[],int start,int end){
	int pivot = input[start];
	int CountSmaller = 0;
	for(int i=start+1;i<=end;i++){
		if(input[i]<=pivot){
			CountSmaller++;
		}
	}
	int PivotIndex = CountSmaller + start;
	input[start] = input[PivotIndex];
	input[PivotIndex] = pivot;

	//internal swapping, smaller and equal in the left of PivotIndex and larger in the right
	int i=start;
	int j=end;
	while(i<PivotIndex && j>PivotIndex){
		if(input[i]<=pivot){
			i++;
		}
		else if(input[j]>pivot){
			j--;
		}
		else{
			int temp = input[i];
			input[i]=input[j];
			input[j]=temp;
			i++;
			j--;
		}
	}
	return PivotIndex;
}

void quickSort(int input[],int start,int end){
	if(start>=end){
		return;
	}
	int p = parition(input,start,end);
	quickSort(input,start,p-1);
	quickSort(input,p+1,end);
}
void quickSort(int input[], int size){
	
    quickSort(input,0,size-1);


}
