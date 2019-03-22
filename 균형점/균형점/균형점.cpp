#define DEBUG
#include <iostream>

double cal_force(double x , double point[] , double mess[] , int size) {
	double force = 0.0;
	for(int i = 0; i<size; i++) {
		double temp = mess[i]/(point[i]-x)/(point[i]-x);
		force += (x<point[i]) ? temp : -temp;
	}

	return force;

}

int cal_main(int size , double out[]) {
	double point[10] = {0};
	double mess[10] = {0};

	for(int i = 0; i<size; i++) {
		scanf("%lf" , point+i);
	}
	for(int i = 0; i<size; i++) {
		scanf("%lf" , mess+i); 
	}

	double d = 0.0000000000001;
	for(int i = 0; i<size-1; i++) {
		double start = point[i];
		double end = point[i+1];
		double mid;
		double pre = 0.0;

		while(1) {
			mid = (start+end)/2.0;
			double force = cal_force(mid , point , mess , size);
			if(-d<force && force<d || pre==force) {
				out[i] = mid;
				break;
			}
			else pre = force;

			if(force<0) start = mid;
			else end = mid;
		}
		
	}


	return 0;
}

int main()
{
#ifdef DEBUG
	freopen("input.txt" , "r" , stdin);
#endif // DEBUG
	int T; scanf("%d" , &T);
	for(int testcase = 1 ; testcase<=T; testcase++) {
		int size; scanf("%d" , &size);
		double out[9] = {0.0};
		cal_main(size,out);

		printf("#%d " , testcase);
		for(int i = 0; i<size-1; i++) printf("%.10lf " , out[i]);
		printf("\n");
	}

	return 0;
}
