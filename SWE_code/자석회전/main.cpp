#include <iostream>
using namespace std;

int cal_not_same(int magnetic[][8], int notSame[]){
    for(int i=0; i<3; i++){
        if(magnetic[i][2] == magnetic[i+1][6]) notSame[i] = 0;
        else notSame[i] = 1;
    }
    return 0;
}

int turnArr(int arr[], int turn, int size=8){
    if(turn == 1){
        int temp = arr[size-1];
        for(int i=size-1; i>0; i--){
            arr[i] = arr[i-1];
        }
        arr[0] = temp;
    }
    else{
        int temp = arr[0];
        for(int i=0; i<size-1; i++){
            arr[i] = arr[i+1];
        }
        arr[size-1] = temp;
    }
    return 0;
}

int cal_main(){
    int cnt;
    int magnetic[4][8];
    int turns[22][2];
    int result = 0;

    //input ----------------------
    scanf("%d",&cnt);
    for(int y=0;y<4;y++){
        for(int x=0;x<8;x++){
            scanf("%d",&magnetic[y][x]);
        }
    }
    for(int i=0; i<cnt; i++){
        scanf("%d",&turns[i][0]);
        scanf("%d",&turns[i][1]);
    }
    // turns ----------------------------------
    for(int idx=0; idx<cnt; idx++){
        int notSame[3];
        cal_not_same(magnetic, notSame);

        int point = turns[idx][0]-1;
        int turn = turns[idx][1];
        int now = turn;
        turnArr(magnetic[point],turn);

        for(int r=point; r<3 ; r++){
            if(notSame[r]){
                now *= -1;
                turnArr(magnetic[r+1],now);
            }
            else break;
        }
        now = turn;
        for(int l=point; l>0 ; l--){
            if(notSame[l-1]){
                now *= -1;
                turnArr(magnetic[l-1],now);
            }
            else break;
        }
    }
    // cal result -----------------------------------
    result = magnetic[3][0]*8 + magnetic[2][0]*4 + magnetic[1][0]*2 + magnetic[0][0];

    return result;
}


int main()
{
    freopen("input.txt", "r", stdin);

    int TestNum = 0;
    cin >> TestNum;

    for(int i=0;i<TestNum;i++){
        cout << '#' << i+1 <<' '<<  cal_main() << endl;
    }

    return 0;
}