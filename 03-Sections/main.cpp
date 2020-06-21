#include <iostream>
#include <omp.h>
#include <stdio.h>
#include <unistd.h>

//N comes from external compile define

using namespace std;

void foo1(){
	sleep(2);
	printf("foo1 in thread %d\n",omp_get_thread_num());
}

void foo2(){
	sleep(3);
	printf("foo2 in thread %d\n",omp_get_thread_num());	
}

void foo3(){
	sleep(5);
	printf("foo3 in thread %d\n",omp_get_thread_num());
}

int main(){

	#pragma omp parallel sections 
	{    
		#pragma omp section
			foo1();
		#pragma omp section
			foo2();
		#pragma omp section
			foo3();
		#pragma omp section
			foo1();
		#pragma omp section
			foo2();
		#pragma omp section
			foo3();
		#pragma omp section
			foo1();
		#pragma omp section
			foo2();
		#pragma omp section
			foo3();
	}
}