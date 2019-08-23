#define HOME 1
// #define DEBBUG 1
#include <iostream>
using namespace std;

inline void copy_table(int pre[][12], int now[][12], int width, int height){
    for(int y=0;y<height;y++){
        for(int x=0;x<width;x++){
            now[y][x] = pre[y][x];
        }
    }
}
inline int check_block(int table[][12], int width, int height){
    int out = 0;
    for(int y=0;y<height;y++){
        for(int x=0;x<width;x++){
            if(table[y][x] != 0) out++;
        }
    }
    return out;
}
inline int search_y(int table[][12], int height, int x){
    if(table[0][x]) return 0;
    else if(table[height-1][x] == 0) return -1;

    int start = 0;
    int end = height-1;

    while(start<=end){
        int mid = (start+end)/2;
        if(table[mid][x] == 0)start = mid+1;
        else if(table[mid-1][x] == 0) return mid;
        else end = mid-1;
    }

    // for(int y=0; y<height; y++){
    //     if(table[y][x] != 0){
    //         return y;
    //     }
    // }

    return -1;
}
inline int check_bomb_block(int table[][12], int width, int height, int stack[][3], int index, int y, int x){
    if(x>=0 && x<width && y>=0 && y<height){
        if(table[y][x] == 1){
            table[y][x] = 0;
        }
        else if(table[y][x]){
            stack[index][0] = y;
            stack[index][1] = x;
            stack[index++][2] = table[y][x];
            table[y][x] = 0;
        }
    }
    return index;
}
int down_block(int table[][12], int height, int width)
{
    for(int x=0; x<width; x++){
        int nbsp=0;
        for(int y=height-1; y>=0; y--){
            if(table[y][x] == 0) nbsp++;
            else{
                table[y+nbsp][x] = table[y][x];
                if(nbsp)table[y][x] = 0;
            }
        }
    }
    return 0;
}

int shooting(int table[][12], int height, int width, int start_x)
{
    int start_y = search_y(table,height,start_x);
    if(start_y < 0) return -1;
    int start_num = table[start_y][start_x];
    if(start_num <= 1){
        table[start_y][start_x] = 0;
        return 0;
    }


    int stack[200][3];//point, {y,x,num}
    int index = 0;

    stack[index][1] = start_x;
    stack[index][0] = start_y;
    stack[index++][2] = start_num;
    table[start_y][start_x] = 0;

    while(index>0){
        int y = stack[--index][0];
        int x = stack[index][1];
        int num = stack[index][2];

        for(int i=1; i<num; i++){
            index = check_bomb_block(table, width, height, stack, index, y, x-i);
            index = check_bomb_block(table, width, height, stack, index, y, x+i);
            index = check_bomb_block(table, width, height, stack, index, y+i, x);
            index = check_bomb_block(table, width, height, stack, index, y-i, x);
        }
    }
    down_block(table, height, width);

    return 0;
}

// int game(int table[][12], int shoot_cnt, int Num, int result, int width, int height)
// {
//     if(shoot_cnt == Num){
//         int now_cnt = check_block(table, width, height);
//         return now_cnt < result ? now_cnt : result;
//     }

//     int zero = 0;
//     for(int x=0; x<width; x++){
//         if(table[height-1][x] == 0){
//             zero++;
//             continue;
//         }

//         int new_table[15][12];
//         copy_table(table,new_table,width,height);

//         shooting(new_table, height, width, x);
//         result = game(new_table,shoot_cnt+1,Num,result,width,height);
//     }

//     return zero == width ? 0 : result;
// }

int cal_main()
{
    int Num, width, height;
    int table[15][12];
    //--------------------------------------------------
    scanf("%d %d %d",&Num, &width, &height);
    for(int y=0; y<height; y++){
        for(int x=0; x<width; x++){
            scanf("%d",&table[y][x]);
        }
    }
    //--------------------------------------------------------
    int result = 1000;
    // return game(table, 0, Num, result, width, height);

    int cnt = 0;
    int time[4] = {0};
    int history_table[4][15][12];
    int zeros[5] = {0};
    while(cnt>=0){
        #ifdef DEBBUG
            printf("cnt : %d time : %d %d %d %d zeros : %d %d %d %d %d \n",cnt,time[0],time[1],time[2],time[3],zeros[0],zeros[1],zeros[2],zeros[3],zeros[4]);
        #endif
        if(cnt == Num){
            int now_out = check_block(history_table[cnt-1], width, height);
            result = now_out < result ? now_out : result;

            while(cnt>=0){
                if(--cnt < 0)break;
                time[cnt]++;
                if(time[cnt]>=width) time[cnt] = 0;
                else break;
            }
            continue;
        }

        if(cnt==0 && table[height-1][time[cnt]] == 0 || cnt && history_table[cnt-1][height-1][time[cnt]] == 0){
            zeros[cnt]++;

            while(cnt>=0){
                time[cnt]++;
                if(time[cnt]==width){
                    if(zeros[cnt] == width){
                        return 0;
                    }
                    else{
                        zeros[cnt] = 0;
                        time[cnt--] = 0;
                    }
                }
                else break;
            }
            continue;
        }
        else{
            if(cnt == 0) copy_table(table,history_table[cnt],width,height);
            else copy_table(history_table[cnt-1], history_table[cnt], width, height);
            shooting( history_table[cnt], height, width, time[cnt]);
            cnt++;
            zeros[cnt] = 0;
        }
    }

    return result;
}

int main()
{
    #ifdef HOME
        freopen("sample_input.txt", "r", stdin);
    #endif

    int testCase;
    cin >> testCase;

    for(int i=0; i<testCase; i++){
        printf("#%d %d\n",i+1, cal_main());
    }

    return 0;
}