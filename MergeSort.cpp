
void merge(int input[], int start, int mid, int end){
    	int size1 = mid - start + 1;
	int size2 = end - mid;
	int size = size1 + size2;

	
	int array[size];
	int L[size1];
	int R[size2];
	
	for(int i=0;i<size1;i++){
		L[i]=input[start+i];
	}
	
	for(int i=0;i<size2;i++){
		R[i]=input[mid+1+i];
	}

	//Sort the array
	int i=0;
	int j=0;
	int k=0;
	while(i<size1 && j<size2){
		if(L[i]<=R[j]){   		//this means first array have larger value do we put smaller value in the array
			array[k]=L[i];
			i++;
			k++;
		}
		else{
			array[k]=R[j];
			j++;
			k++;
		}
	}

	while(i<size1){
		array[k]=L[i];
		i++;
		k++;
	}

	while(j<size2){
		array[k]=R[j];
		j++;
		k++;
	}

	//Time to make the copy of array into the input array

	for(int index=0;index<size;index++){
		input[start+index]=array[index];
	}
	

}
    


void MergeSort(int arr[],int i, int j){
    if(i>=j){
        return;
    }
    int mid = i +(j-i)/2;
    MergeSort(arr,i,mid);
    MergeSort(arr,mid+1,j);
    
    //now we are going to merge two sorted array
    merge(arr,i,mid,j);
}

void mergeSort(int input[],int size){
	MergeSort(input,0,size-1);
}