#include <iostream>
#include <omp.h>
#include <stdio.h>

//N comes from external compile define

using namespace std;

int main(){

	int a[N];
	int sum=0;
	for(int t=0;t<N;t++) a[t] = t+1;

	#pragma omp parallel for reduction(+:sum)
	for (int i = 0; i < N; i++)
	{
		sum += a[i];
		printf("Thread %d, itteration %d : sum = %d\n"
			,omp_get_thread_num(),i,sum);
	}
	
	cout << "Sum of first "<<N<<" numbers is "<<sum<<endl;

	return 0;	

}