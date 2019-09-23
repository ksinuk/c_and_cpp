#include <string>
#include <vector>

using namespace std;
void swap(unsigned long long &a, unsigned long long &b){
    long long temp = a;
    a = b;
    b = temp;
}

int sort_officer(unsigned long long officer[][2],int size){
    if(size<2) return 0;
    int step = 1;
    int start = 0;
    unsigned long long stack[100000][2];
    
    while(step<size){
        int start1 = start;
        int start2 = start+step;
        int end1 = start2;
        int end2 = start2+step;
        end2 = end2 < size ? end2 : size;
        
        int idx = 0;
        
        while(start1<end1 && start2<end2){
            if(officer[start1][0]+officer[start1][1]<officer[start2][0]+officer[start2][1]) {
                stack[idx][0] = officer[start1][0];
                stack[idx++][1] = officer[start1++][1];
            }
            else{
                stack[idx][0] = officer[start2][0];
                stack[idx++][1] = officer[start2++][1];
            }
        }
        while(start1<end1){
            stack[idx][0] = officer[start1][0];
            stack[idx++][1] = officer[start1++][1];
        }
        while(start2<end2) {
            stack[idx][0] = officer[start2][0];
            stack[idx++][1] = officer[start2++][1];
        }
        for(int i=0;i<idx;i++){
            officer[start+i][0] = stack[i][0];
            officer[start+i][1] = stack[i][1];
        }
        
        start += step*2;
        if(start+step > size){
            step *= 2;
            start = 0;
        }
    }
    
    return officer[0][0];
}

unsigned long long solution(int n, vector<int> times) {
    unsigned long long answer = 0;
    int size = times.size();
    if(size==1) return n*times[0];
    
    unsigned long long officer[100000][2];//times, last time
    for(int i=0;i<size;i++){
        officer[i][0] = times[i];
        officer[i][1] = 0;
    }
    
    while(n>0){
        sort_officer(officer,size);
        size = size < n ? size:n;
        if(size==1){
            int temp = officer[0][1] + n*officer[0][0];
            return temp < answer ? answer : temp;
        }
        
        int sum_n = 0;
        int temp = officer[0][1] + n*officer[0][0];
        for(int i=1;i<size;i++){
            if(temp < officer[i][1] + officer[i][0]){
                size = i;
                break;
            }
            sum_n = officer[sum_n][0] > officer[i][0] ? sum_n : i;
            int temp_n = n/(i+1)+1;
            temp = officer[i][1] + temp_n*officer[sum_n][0];
        }
        
        unsigned long long post_add[100000];
        for(;;size--){
            int num=0;
            int isdel = 0;
            for(int j=0;j<size-1;j++){
                post_add[j] = (officer[size-1][1]+officer[size-1][0]-officer[j][1])/officer[j][0];
                num += post_add[j];
                if(num > n){
                    isdel = 1;
                    break;
                }
            }

            if(!isdel) {
                for(int j=0;j<size-1;j++){
                    officer[j][1] += post_add[j]*officer[j][0];
                    if(answer < officer[j][1]) answer = officer[j][1];
                    n -= post_add[j];
                }
                if(n>0){
                    officer[size-1][1] += officer[size-1][0];
                    n--;
                    if(answer < officer[size-1][1]) answer = officer[size-1][1];
                }
                    
                break;
            }
        }     
    }
    
    return answer;
}