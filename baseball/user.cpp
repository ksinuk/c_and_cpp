#define N 4
typedef struct {
           int strike;
           int ball;
} Result;

// API
extern Result query(int guess[]);

int pointset(int guess[] , int ok_num[] , int not_num[]) {
    int inx[4]={not_num[0] , not_num[1] , not_num[2] , not_num[3]};
    int set_up=3 , set_down=0;
    for(int i=0;i<4;i++)
        if(guess[i]>=0) set_down++;
        else break;
    for(int i=3;i>=0;i--)
        if(guess[i]>=0) set_up--;
        else break;
    
    for(int i=set_down;i<=set_up; i++){
        if(guess[i]>=0)continue;
        inx[i] = ok_num[i];
        Result result = query(inx);
        inx[i] = not_num[i];
        
        if(result.strike){
            guess[i] = ok_num[i];
            if(i==set_down)set_down++;
            else if(i==set_up)set_up--;
        }
    }

    for(int i=0;i<3;i++){
        int now = ok_num[i];
        if(now == guess[i]) continue;
        
        for(int p = set_down ; p<=set_up ; p++){
            if(guess[p] >=0 || p==i ) continue;
            if(p==set_up){
                guess[set_up--] = now;
                break;
            }
            
            inx[p] = now;
            Result result = query(inx);
            inx[p] = not_num[p];
            
            if(result.strike){
                if(p==set_down)set_down++;
                else if(p==set_up)set_up--;
                guess[p] = now;
                break;    
            }
        }   
    }
    for(int i=0;i<4;i++){
        if(guess[i] >=0) continue;
        guess[i] = ok_num[3];
        break;        
    }
    return 0;
}

int baseball1(int not_num[] , int q_num[] , int n , int guess[])
{
    int num=-1 , temp = not_num[0];
    for(int i=0;i<n;i++){
        not_num[0] = q_num[i];
        Result result = query(not_num);
        if(result.strike) {
            guess[0] = q_num[i];
            return q_num[i];    
        }
        else if(result.ball) {
            num = q_num[i];
            break;  
        }
    }
    if(num<0) return -1;
    not_num[0] = temp;
    for(int i=1;i<4;i++){
        if(i==3){
            guess[3] = num;
            return num;
        }
        if(guess[i]>=0)continue;
        
        temp = not_num[i];
        not_num[i] = num;
        Result result = query(not_num);
        not_num[i] = temp;
        if(result.strike) {
            guess[i] = num;
            return num;
        }
    }
    return -1;
}

void doUserImplementation(int guess[]) {
    guess[0]=-1 ; guess[1]=-1 ; guess[2]=-1 ; guess[3]=-1;
    int ok=0 , ok_num[4]={-1,-1,-1,-1} , not_num[4]={-1,-1,-1,-1};
    int inx[4]={0,1,2,3};
    Result result1 = query(inx);
    if(result1.strike==4) {
        guess[0]=0 ; guess[1]=1 ; guess[2]=2 ; guess[3]=3; 
        return;
    }
    int ok0123 = result1.strike+result1.ball;
    if(ok0123==4){
        not_num[0]=9; not_num[1]=8; not_num[2]=7; not_num[3]=6; 
        ok_num[0]=0; ok_num[1]=1; ok_num[2]=2; ok_num[3]=3; 
        pointset(guess , ok_num , not_num , result1.strike);
        return;
    }
    if(ok0123==0){
        int set=3 , set_down=0 , set_arr[4]={0};
        for(int i=9;i>3;i--){
            inx[set] = i;
            Result result = query(inx);
            inx[set] = set;
            if(result.strike) {
                set_arr[set]=1; guess[set--]=i;
                ok++; continue;
            }
            else if(result.ball){
                for(int j=set-1;j>=0;j--){
                    if(set_arr[j]) continue;
                    if(j != set_down){
                        inx[j]=i; result = query(inx); inx[j]=j;
                    }
                    else{
                        set_arr[set_down]=1; guess[set_down++]=i;
                        ok++; break;
                    }
                    
                    if(result.strike){
                        set_arr[j]=1; guess[j]=i;
                        ok++; break;
                    }
                } 
            } 
            if(ok==4) return;
        }
    }
    else if(ok0123==3){
        inx[0] = 4 ; inx[1] = 5 ; inx[2] = 6 ; inx[3] = 7 ; 
        Result result4567 = query(inx);
        int out4567 = result4567.strike + result4567.ball;
        inx[0] = 8 ; inx[1] = 9 ;
        Result result6789 = query(inx);
        int out6789 = result6789.strike + result6789.ball;
        
        if(out4567==1 && out6789==0){
            not_num[0]=9; not_num[1]=8; not_num[2]=7; not_num[3]=6; 
            int q_num[2] = {4,5};
            ok_num[ok++] = baseball1(not_num , q_num , 2 , guess);
            not_num[0]=9; not_num[1]=8; not_num[2]=7; not_num[3]=6; 
        }
        else if(out4567==1){
            not_num[0]=9; not_num[1]=8; not_num[2]=4; not_num[3]=5; 
            int q_num[2] = {6,7};
            ok_num[ok++] = baseball1(not_num , q_num , 2 , guess);
            not_num[0]=9; not_num[1]=8; not_num[2]=4; not_num[3]=5; 
        }
        else {
            not_num[0]=9; not_num[1]=8; not_num[2]=4; not_num[3]=5; 
            int q_num[2] = {8,9};
            ok_num[ok++] = baseball1(not_num , q_num , 2 , guess);
            not_num[0]=9; not_num[1]=8; not_num[2]=4; not_num[3]=5; 
        }
        
        for(int i=0;i<4;i++){
            not_num[0] = 
            
        }
        
        
        inx[0] = 0 ; inx[1] = 1 ; inx[2] = 2 ; inx[3] = 3 ;
        
    }
    
    /*inx[4]={4,5,6,7};
    Result result2 = query(inx);
    int ok4567 = result2.strike+result2.ball;
    
    inx[4]={8,9,1,0};
    Result result3 = query(inx);
    inx[4]={8,9,2,3};
    Result result4 = query(inx);
    int ok89 = (result3.strike+result3.ball +  result4.strike+result4.ball - ok0123)/2;*/
    
    


}

/*24
0123
0132
0213
0231
0312
0321
1023
1032
1203
1230
1302
1320
2013
2031
2103
2130
2301
2310
3012
3021
3102
3120
3201
3210*/