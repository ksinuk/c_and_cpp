#include <iostream>
#define SIZE 16
#define SIZE_in 17
using namespace std;

struct Point {int x,y;};

int select_direct(char map[][SIZE_in] , int arrow , Point now){
    if(map[now.y][now.x+1]!='1' && arrow!=4) return 6;
    else if(map[now.y+1][now.x]!='1' && arrow!=2) return 8;
    else if(map[now.y][now.x-1]!='1' && arrow!=6) return 4; 
    else if(map[now.y-1][now.x]!='1' && arrow!=8) return 2;
    else return 0;
}
int cal_only(char map[][SIZE_in] , Point now){
    int temp=0;
    if(map[now.y][now.x+1]!='1') temp++;if(map[now.y+1][now.x]!='1') temp++;
    if(map[now.y][now.x-1]!='1') temp++;if(map[now.y-1][now.x]!='1') temp++;
    return temp;
}
int next_point(Point &now , int arrow){
    switch(arrow){
        case 6: now.x++;break;
        case 8: now.y++;break;
        case 4: now.x--; break;
        case 2: now.y--; break;
    }
    return 0;
}

int main(){
	freopen("input100.txt", "r", stdin);
    for(int testcase=1 ; testcase<11 ; testcase++){
    	int dumi;cin>>dumi;
    	//cout<<"----------------------------------"<<endl;
    	
        int out=2;
        char map[SIZE][SIZE_in] = {0};
        for(int y=0;y<SIZE;y++) cin>>map[y];
        
        //for(int y=0;y<SIZE;y++) cout<<map[y]<<endl;

        Point now;
        for(int x=0;x<SIZE;x++){
            for(int y=0;y<SIZE;y++)
                if(map[y][x]=='2') { now.y=y; now.x=x; x=SIZE ; break;}
        }
        //------------- 입력완료 --------------------------

        Point history[1000]; 
        int history_size = 0;
        int arrow = 0; //keypad : e=6 , n=8 , w=4 , s=2 , stop=0

        while(out==2){        	
            if(map[now.y][now.x]=='3') {out=1;break;} //도착
            map[now.y][now.x]='1';
			
            int temp=cal_only(map , now); //방향 결정 파트
            if(temp==0) { 
				if( history_size==0){ out=0;break; }
				now = history[history_size-1];history_size--;
				arrow=0;
                continue;
			}
            else if(temp!=1) history[history_size++] = now;
            arrow= select_direct(map , arrow , now);
            
            next_point(now , arrow);
        }
        
        cout<<'#'<<testcase<<' '<<out<<endl;
    }
    return 0;
}
