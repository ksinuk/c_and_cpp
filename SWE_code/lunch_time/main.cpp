#define HOME 1
// #define DEBBUG 1
#include <iostream>
using namespace std;

struct Man
{
    int y;
    int x;
    int road;
    int time;
};
struct Road
{
    int y;
    int x;
    int time;
};

inline int calLen(int y1, int x1, int y2, int x2){
    int y = y1 > y2 ? y1-y2 : y2-y1;
    int x = x1 > x2 ? x1-x2 : x2-x1;
    return y+x;
}

inline void sortman(int inlist[], Man data[], int size){
    for(int i=1; i<size; i++){
        for(int j=i; j>0; j--){
            if(data[inlist[j]].time > data[inlist[j-1]].time){
                int temp = inlist[j];
                inlist[j] = inlist[j-1];
                inlist[j-1] = temp;
            }
            else break;
        }
    }
}

inline void make_len_table(Man mans[], Road roads[], int manSize, int table[][11])
{
    for(int i=0; i<manSize; i++){
        table[0][i] = calLen(roads[0].y, roads[0].x, mans[i].y, mans[i].x) + roads[0].time + 1;
        table[1][i] = calLen(roads[1].y, roads[1].x, mans[i].y, mans[i].x) + roads[1].time + 1;
    }
}

int simulrate(Man mans[], Road roads[], int manSize, int roadSize, int lenTable[][11], int minResult = 10000000){
    int road_mans[2][11];
    int road_man_size[2] = {0};
    int max_time = 0;

    for(int i=0; i<manSize; i++){
        mans[i].time = lenTable[mans[i].road][i];
        road_mans[mans[i].road][road_man_size[mans[i].road]++] = i;
        max_time = max_time > mans[i].time ? max_time : mans[i].time;
    }

    if(max_time >= minResult) return minResult;
    if(road_man_size[0] < 4 && road_man_size[1] < 4) return max_time;

    // real test ----------------------------------------------
    int result = max_time;

    for(int road=0; road<2; road++){
        int size = road_man_size[road];
        if(size > 3){
            const int outTime = roads[road].time + 1;
            int time=0;
            int roadcnt = 0;
            sortman(road_mans[road], mans, size);

            for(time=0;size>3 && time < minResult;time++){
                for(int i=size-1; i>=0; i--){
                    int man = road_mans[road][i];

                    if(roadcnt<3 || mans[man].time > outTime || size-1-i<3){
                        mans[man].time--;
                        if(mans[man].time == 0){
                            size--;
                            roadcnt--;
                        }
                        else if(mans[man].time == outTime){
                            roadcnt++;
                        }
                    }
                }
            }

            if(size<4){
                int max = 0;
                for(int i=0;i<size;i++){
                    int man = road_mans[road][i];
                    if(mans[man].time > max) max = mans[man].time;
                }
                time += max;
            }

            result = time > result ? time : result;
            if(result >= minResult) return minResult;
        }
    }

    return result;
}

int cal_main()
{
    int size;
    Man mans[10];
    int manSize = 0;
    Road roads[2];
    int roadSize = 0;

    // input ---------------------------------------
    scanf("%d", &size);
    for(int y=0; y<size; y++){
        for(int x=0; x<size; x++){
            int map;
            scanf("%d", &map);
            if(map == 1){
                mans[manSize++] = {y, x, -1, 0};
            }
            else if(map != 0){
                roads[roadSize++] = {y, x, map};
            }
        }
    }

    // ready ----------------------------------------------
    int result = 0;
    int Num = 1<<manSize;
    int lenTable[2][11];
    make_len_table(mans, roads,  manSize, lenTable);

    for(int i = 0; i<manSize; i++){
        int len0 = lenTable[0][i];
        int len1 = lenTable[1][i];

        if(len0 < len1){
            mans[i].road = 0;
            mans[i].time = len0;
        }
        else {
            mans[i].road = 1;
            mans[i].time = len1;
        }
    }

    if(manSize < 4){ // 인원이 3명 이하이면 빠른 예외처리
        int max = 0;
        for(int i=0; i<manSize; i++){
            if(mans[i].time > max) max = mans[i].time;
        }
        return max;
    }

    result = simulrate(mans, roads, manSize, roadSize, lenTable);

    // start ! --------------------------------------------
    for(int cnt=0; cnt<Num; cnt++){
        int iscontinue = 0;
        for(int i=0; i<manSize; i++){
            mans[i].road = (cnt & 1<<i) ? 1 : 0;
            if(lenTable[mans[i].road][i] >= result){
                iscontinue = 1;
                break;
            }
        }
        if(iscontinue) continue;

        int temp = simulrate(mans, roads, manSize, roadSize, lenTable, result);
        result = temp < result ? temp :  result;
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