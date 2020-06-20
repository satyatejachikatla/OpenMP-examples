#include <iostream>
#include <omp.h>
#include <stdio.h>

//#define N 32

using namespace std;


void printVar(int* a,int b,int c,int d,int m){
	cout << "------------------------" << endl;
	for(int i=0;i<N;i++){
		cout << "a["<<i<<"] = "<< a[i] <<endl;
	}
	cout << "b = "<<b<<endl;
	cout << "c = "<<c<<endl;
	cout << "d = "<<d<<endl;
	cout << "m = "<<m<<endl;
	cout << "------------------------" << endl;
}


int main(){

	int i;
	int a[N];
	for(int t=0;t<N;t++) a[t] = -1;
	int b =-1,c=-1,d=-1,m=-1;
	cout << "------------------------" << endl;
	cout << "Before parallel for" << endl;
	printVar(a,b,c,d,m);

	#pragma omp parallel for default(none) private(i,b) firstprivate(c) lastprivate(d) shared(m,a) schedule(dynamic,3) //schedule(static,3)
	for (i = 0; i < N; i++)
	{
		b=100;
		d=100;

		printf("Before In Thread %d, itteration %d : b = %d , c = %d , d = %d , m = %d\n"
			,omp_get_thread_num(),i,b,c,d,m);
		a[i] = omp_get_thread_num();
		b = omp_get_thread_num();
		c = omp_get_thread_num();
		d = omp_get_thread_num();
		m = omp_get_thread_num();
		printf("After In Thread %d, itteration %d : b = %d , c = %d , d = %d , m = %d\n"
			,omp_get_thread_num(),i,b,c,d,m);
	}
	cout << "------------------------" << endl;
	cout << "After parallel for" << endl;
	printVar(a,b,c,d,m);



	return 0;	

}