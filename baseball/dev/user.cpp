#define N 4
#include <iostream>
using namespace std;


typedef struct {
           int strike;
           int ball;
} Result;

// API
extern Result query(int guess[]);

int pointset(int guess[] , int ok_num[] , int not_num[]) {
    int inx[4]={not_num[0] , not_num[1] , not_num[2] , not_num[3]};
    int set_up=3 , set_down=0 , strike=4;
    for(int i=0;i<4;i++)
        if(guess[i]>=0) set_down++;
        else break;
    for(int i=3;i>=0;i--)
        if(guess[i]>=0) set_up--;
        else break;
    
    for(int i=0;i<4; i++){
        if(guess[i]>=0){
            strike--;
            continue;
        }
    }
    if(strike==0) return 0;

    for(int i=0;i<4;i++){
        int now = ok_num[i];
        if(now == guess[i]) continue;
        
        for(int p = set_down ; p<=set_up ; p++){
            if(guess[p] >=0) continue;
            if(p==set_up){
                strike--;
                guess[set_up--] = now;
                break;
            }
            if(strike==1){
                guess[p] = now;
                return 0;
            }
            
            inx[p] = now;
            Result result = query(inx);
            inx[p] = not_num[p];
            
            if(result.strike){
                strike--;
                if(p==set_down)set_down++;
                else if(p==set_up)set_up--;
                guess[p] = now;
                break;    
            }
        }   
    }

    return 0;
}

int baseball1(int not_num[] , int q_num[] , int n , int guess[])
{
    int num=-1 , temp = 0 , start=0;
    for(int i=0;i<4;i++){
        if(guess[i]<0){
            start = i;
            break;
        }
    }
    temp = not_num[start];

    for(int i=0;i<n;i++){
        not_num[start] = q_num[i];
        Result result = query(not_num);
        if(result.strike) {
            guess[start] = q_num[i];
            return start;    
        }
        else if(result.ball) {
            num = q_num[i];
            break;  
        }
    }
    if(num<0) return -1;
    not_num[start] = temp;

    for(int i=start+1;i<4;i++){
        if(guess[i]>=0)continue;
        
        temp = not_num[i];
        not_num[i] = num;
        Result result = query(not_num);
        not_num[i] = temp;
        if(result.strike) {
            guess[i] = num;
            return i;
        }
    }
    return -1;
}

int part_cal(int inx[],int guess[],Result result){
    if(result.strike==4) {
        guess[0]=inx[0] ; guess[1]=inx[1] ; guess[2]=inx[2] ; guess[3]=inx[3]; 
        return 1;
    }
    int ok0123 = result.strike+result.ball;
    if(ok0123==4){
        int ok_num[4] = {inx[0],inx[1],inx[2],inx[3]};
        int not_num[4],no=0;
        for(int i=0;i<10;i++){
            if(i==inx[0] || i==inx[1] || i==inx[2] || i==inx[3]) continue;
            not_num[no++] = i;
            if(no==4) break;
        } 

        pointset(guess , ok_num , not_num);
        return 1;
    }
    else if(ok0123==0){
        int set=3 , set_down=0 , ok=0;
        for(int i=9;i>=0;i--){
            if(i==inx[0] || i==inx[1] || i==inx[2] || i==inx[3]) continue;

			int temp_inx = inx[set];
            inx[set] = i;
            Result result = query(inx);
            inx[set] = temp_inx;
            if(result.strike) {
                guess[set--]=i;
                ok++; continue;
            }
            else if(result.ball){
                for(int j=set-1;j>=0;j--){
                    if(guess[j]>=0) continue;
                    if(j != set_down){
                        int temp = inx[j];
                        inx[j]=i; 
                        result = query(inx); 
                        inx[j]=temp;
                    }
                    else{
                        guess[set_down++]=i;
                        ok++; break;
                    }
                    
                    if(result.strike){
                        guess[j]=i;
                        ok++; break;
                    }
                } 
            } 
            if(ok==4) return 1;
        }
    }

    return 0;
}

void doUserImplementation(int guess[]) {
    guess[0]=-1 ; guess[1]=-1 ; guess[2]=-1 ; guess[3]=-1;
    int inx[4]={0,1,2,3};
    Result result = query(inx);
    int ok0123 = result.strike+result.ball;
    if(part_cal(inx,guess,result)) return;
    
    int in2345[4]={2,3,4,5};
    result = query(in2345);
    int ok2345 = result.strike+result.ball;
    if(part_cal(in2345,guess,result)) return;
    
    int in4567[4]={4,5,6,7};
    result = query(in4567);
    int ok4567 = result.strike+result.ball;
    if(part_cal(in4567,guess,result)) return;
    
    int in6789[4]={6,7,8,9};
    result = query(in6789);
    int ok6789 = result.strike+result.ball;
    if(part_cal(in6789,guess,result)) return;

    int in8901[4]={8,9,0,1};
    result = query(in8901);
    int ok8901 = result.strike+result.ball;
    if(part_cal(in8901,guess,result)) return;

    int ok=0 , no=0, cal_i=0 , ok_num[4] , not_num[4] , cal_num[4];
    int ok01=4-ok2345-ok6789;
    int ok23=4-ok4567-ok8901;
    int ok45=4-ok6789-ok0123;
    int ok67=4-ok8901-ok2345;
    int ok89=4-ok0123-ok4567;
    int oks_5[5] = {ok01,ok23,ok45,ok67,ok89};


    for(int i=0;i<5;i++){
        if(oks_5[i]==2){
            ok_num[ok++] = i*2;
            ok_num[ok++] = i*2+1;
        }
        else if(oks_5[i]==0){
            if(no==4) continue;
            not_num[no++] = i*2;
            not_num[no++] = i*2+1;
        }
        else{
            cal_num[cal_i++] = i;
        }
    }
    if(ok==4){
        pointset(guess , ok_num , not_num);
        return;
    }
    else if(ok==2){
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++){
                ok_num[2] = cal_num[0]*2+i;
                ok_num[3] = cal_num[1]*2+j;
                result = query(ok_num);
                if(part_cal(ok_num,guess,result)) return;
            }
    }
    else if(no==4){
        Result temp={0,0};
        part_cal(not_num,guess,temp);
        return ;
    }

    for(int i=0;i<16;i++){
        for(int j=0;j<4;j++){
            ok_num[j] = cal_num[j]*2;
            if(i & 1<<j) ok_num[j]++;
        }
        result = query(ok_num);
        if(part_cal(ok_num,guess,result)) return;
    }

    return ;
}

