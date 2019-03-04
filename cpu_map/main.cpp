#include <iostream>
using namespace std;

class Cpu{
public:
    int x,y;
    int arrow[4];// key pad
    int now;

    Cpu(int i=-1,int j=-1){
        x = j;
        y = i;
        now = 0;
        for(int i=0;i<4;i++)
            arrow[i] = 0;
    }
    void inCpu(int i,int j){
        x = j;
        y = i;
        now = 0;
        for(int i=0;i<4;i++)
            arrow[i] = 0;
    }

    void printf(){
        cout<<"x : "<<x<<" , y : "<<y<<endl;
        cout<<"arrow : "<<arrow[0]<<" "<<arrow[1]<<" "<<arrow[2]<<" "<<arrow[3]<<endl;
    }

    int map_1(int *map, int size,int dir=-1,int write_ok = 1){
        if(dir<0){
            for(int i=0;i<4;i++)
                if(arrow[i]) {dir=i;break; }
        }
        int start,end;
        switch (dir) {
            case 0: start = x;end = size-1; break;
            case 1: start = 0;end = y; break;
            case 2: start = 0;end = x; break;
            case 3: start = y;end = size-1; break;
        }
		if (write_ok) {
			if (dir % 2)
				for (int my = start; my <= end; my++)
					*(map + my * size + x) = 1;
			else
				for (int mx = start; mx <= end; mx++)
					*(map + y * size + mx) = 1;
		}

        return end+1-start;
    }
    int check_line(int *map, int size){
        int temp=1 ,out=0;
        for(int mx=x+1;mx<size;mx++)
            if(*(map+mx+size*y)) {temp=0;break;}
        arrow[0] = temp;out+=temp;
        temp=1;
        for(int mx=0;mx<x;mx++)
            if(*(map+mx+size*y)) {temp=0;break;}
        arrow[2] = temp;out+=temp;
        temp=1;
        for(int my=0;my<y;my++)
            if(*(map+x+size*my)) {temp=0;break;}
        arrow[1] = temp;out+=temp;
        temp=1;
        for(int my=y+1;my<size;my++)
            if(*(map+x+size*my)) {temp=0;break;}
        arrow[3] = temp;out+=temp;

        return out;
    }
};

inline int if_cpu_in(Cpu cpu[] , int cpu_cnt , int thisis , char xy){
    if (xy=='y'){
        for(int c=0;c<cpu_cnt;c++)
            if(cpu[c].y==thisis) { return 1; } 
        return 0;   
    }
    if (xy=='x'){
        for(int c=0;c<cpu_cnt;c++)
            if(cpu[c].x==thisis) { return 1; } 
        return 0;   
    }
}

int check_dfs(int *map , int size , Cpu cpu[] , int cpu_cnt , int dfs[]){
    for(int c=0;c<cpu_cnt;c++){
        if(cpu[c].arrow[dfs[c]]==0) return -c;
    }
    
    int out=0;
    for(int c=0;c<cpu_cnt;c++){
        int temp = cpu[c].check_line(map,size);
        if(temp==0) return 1-cpu_cnt;
        out+=cpu[c].map_1(map, size,dfs[c],0);
    }

    return out;
}

int main() {
    freopen("cpu_map.txt", "r", stdin);
    int testcase;
    cin>>testcase;
    
    for(int test_index=1;test_index<=testcase;test_index++) {
        int out=0 , size , cpu_cnt=0;
        Cpu cpu[12];
        cin>>size;
        int *map = new int[size*size];
        
        for(int i=0;i<size;i++)
            for(int j=0;j<size;j++) {   
                int temp; cin>>temp;
                *(map+i*size+j)=temp;
                if(temp==1 && i%(size-1)!=0 && j %(size-1)!=0 ) { 
                    cpu[cpu_cnt++].inCpu(i,j);              
                }
            }
        //for(int c=0;c<cpu_cnt;c++) cpu[c].printf();
        
        // ------------------- 입력 완료 ---------------------------------
        for(int y=1;y<(size+1)/2;y++){
            if(if_cpu_in(cpu , cpu_cnt , y-1 , 'y' )) break;   
            for(int c=0;c<cpu_cnt;c++)
        		if(cpu[c].y==y && *(map+cpu[c].x)==0) {
                    out+=y;
                    for(int wy=0;wy<y;wy++) *(map+wy*size+cpu[c].x) = 1;
                    cpu[c--] = cpu[--cpu_cnt]; 
        		}
        }
        for(int y=size-1;y>=size/2;y--){
            if(if_cpu_in(cpu , cpu_cnt , y+1 , 'y' )) break;       
            for(int c=0;c<cpu_cnt;c++)
        		if(cpu[c].y==y && *(map+cpu[c].x+size*(size-1))==0) {
                    out+=size-y-1;
                    for(int wy=y;wy<size;wy++) *(map+wy*size+cpu[c].x) = 1;
                    cpu[c--] = cpu[--cpu_cnt]; 
        		}
        }
        for(int x=1;x<(size+1)/2;x++){
            if(if_cpu_in(cpu , cpu_cnt , x-1 , 'x' )) break;     
            for(int c=0;c<cpu_cnt;c++)
        		if(cpu[c].x==x && *(map+size*cpu[c].y)==0) {
                    out+=x;
                    for(int wx=0;wx<x;wx++) *(map+wx+size*cpu[c].y) = 1;
                    cpu[c--] = cpu[--cpu_cnt]; 
        		}
        }
        for(int x=size-1;x>=size/2;x--){
            if(if_cpu_in(cpu , cpu_cnt , x+1 , 'x' )) break;       
            for(int c=0;c<cpu_cnt;c++)
        		if(cpu[c].x==x && *(map+cpu[c].y*size+(size-1))==0) {
                    out+=size-x-1;
                    for(int wx=x;wx<size;wx++) *(map+wx+size*cpu[c].y) = 1;
                    cpu[c--] = cpu[--cpu_cnt]; 
        		}
        }
        //-------- 전처리 완료 -------------------------------------------
        while(1){
            int case_1=0;
            for(int c=0;c<cpu_cnt;c++){
                int temp = cpu[c].check_line(map,size);
                if(temp==0) {
                    cpu[c--] = cpu[--cpu_cnt];
                }
                else if(temp==1){
                    case_1++;
                    out+=cpu[c].map_1(map, size);
                    cpu[c--] = cpu[--cpu_cnt];
                } 
            }
            if(case_1==0)break;
        }
        //for(int c=0;c<cpu_cnt;c++) cpu[c].printf();
        // --------- 방향 계산 완료 ------------------------
        //cout<<"cpu_cnt : "<<cpu_cnt<<endl;
        if(cpu_cnt){
            int *dfs= new int[cpu_cnt];
            int min = 12*size , while_now=1;
            while(while_now){
                int c_fisrt = cpu_cnt-1;
                int temp = check_dfs(map , size , cpu , cpu_cnt , dfs);
                
                if(temp>0 && min>temp) min = temp;
                else c_fisrt = -temp;
                
                for(int i=c_fisrt;i>=0;i--){
                    if(dfs[i]!=3){
                        dfs[i]++;
                        break;
                    }
                    else if(i==0)while_now=0;
                    else dfs[i]=0;
                }
            }
            out+=min;

            delete [] dfs;
        }

        delete [] map;
        cout<<'#'<<test_index<<' '<<out<<endl;
    } 
    return 0;    
}