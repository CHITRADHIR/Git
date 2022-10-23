#include <iostream>

using namespace std;

void merge(int *part1, int size1, int *part2, int size2, int*output, int n)
{
    int i=0;
    int j=0;
	
    int k=0;
	int lol=0;
    while(i<size1&&j<size2)
    {
        if(part1[i]<part2[j])
        {
            output[k++]=part1[i++];
        }
        else
        {
            output[k++]=part2[j++];
		
        }
    }
    while(j<size2)
    {
        output[k++]=part2[j++];
	    
    }
    while(i<size1)
    {
        output[k++]=part1[i++];
    }
}
void mergeSort(int input[], int size)
{
	if(size==1)
	{
		return;
	}
    int *part1=new int [size/2];
    int size1=size/2;
    int *part2=new int [size-size/2];
    int size2=size-size/2;
    for(int i=0; i<size1; i++)
    {
        part1[i]=input[i];
    }
    int k=0;
    for(int i=size1; i<size; i++)
    {
        part2[k++]=input[i];
    }
    mergeSort(part1, size1);
    mergeSort(part2, size2);
    merge(part1, size1, part2, size2, input, size);
}

int main() {
  int length;
  cin >> length;
  int* input = new int[length];
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}
