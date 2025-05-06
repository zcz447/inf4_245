#include<iostream>

using std::cout, std::cin, std::rand;

void Merge(int* array, int left, int mid, int right) {
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    if (leftSize <= 0 || rightSize <= 0) return; 

    int* L = new int[leftSize];
    int* R = new int[rightSize];

    for (int i = 0; i < leftSize; i++)
        L[i] = array[left + i];
    for (int j = 0; j < rightSize; j++)
        R[j] = array[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < leftSize && j < rightSize) {
        array[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    }

    while (i < leftSize) array[k++] = L[i++];
    while (j < rightSize) array[k++] = R[j++];

    delete[] L;
    delete[] R;
}

void MergeSort(int* tab, int left, int right){
    if (left >= right) return;
    
    int mid = (left+right)/2;

    MergeSort(tab, left, mid);
    MergeSort(tab, mid+1, right);
    Merge(tab,left,mid,right);
}

int main(){
    int length=1;

    while(length < 2){
        cout << "ile liczb chcemy posortowac (zakres: 2-200): ";
            cin >> length;
        if(length > 200 || length < 1){
            cout << "no chyba nie\n";
            length = 0;
        }
    }
    
    int randomTab[length];
    int sortedTab[length];

    cout << "Tablica przed posortowaniem:\n";

    for(int i=0;i<length;i++){
        randomTab[i] = rand() % 1001;
        sortedTab[i] = randomTab[i];
        cout << randomTab[i] << " | ";
    }


    MergeSort(sortedTab,0,length-1);

    cout << "\nTablica po posortowaniu:\n";
    for(int o=0;o<length;o++){
        cout << sortedTab[o] << " | ";
    }

}