#define HOME 1
// #define DEBBUG 2
#include <iostream>
using namespace std;

struct Atom{
    int x, y, arrow, energy;
};

int is_will_collion(Atom atom1, Atom atom2){
    if(atom1.arrow == atom2.arrow) return 0;

    if(atom1.x == atom2.x){ // same x
        if(atom1.y < atom2.y && atom1.arrow==0 && atom2.arrow==1) return atom2.y - atom1.y;
        if(atom1.y > atom2.y && atom1.arrow==1 && atom2.arrow==0) return atom1.y - atom2.y;
        return 0;
    }
    if(atom1.y == atom2.y){ // same y
        if(atom1.x < atom2.x && atom1.arrow==3 && atom2.arrow==2) return atom2.x - atom1.x;
        if(atom1.x > atom2.x && atom1.arrow==2 && atom2.arrow==3) return atom1.x - atom2.x;
        return 0;
    }

    int dx = atom1.x-atom2.x;
    int dy = atom1.y-atom2.y;

    if(dx != dy && dx != -dy) return 0;
    if(atom1.x<atom2.x){
        if(atom1.y<atom2.y){
            if(atom1.arrow==3 && atom2.arrow==1 || atom1.arrow==0 && atom2.arrow==2 ) return -dx;
            return 0;
        }
        if(atom1.arrow==3 && atom2.arrow==0 || atom1.arrow==1 && atom2.arrow==2 ) return -dx;
        return 0;
    }
    else{
        if(atom1.y<atom2.y) {
            if(atom1.arrow==0 && atom2.arrow==3 || atom1.arrow==2 && atom2.arrow==1 ) return dx;
            return 0;
        }
        if(atom1.arrow==1 && atom2.arrow==3 || atom1.arrow==2 && atom2.arrow==0 ) return dx;
        return 0;
    }

    return 0;
}

int cal_collion(Atom atomList[], int &Num, int &result){
    int atoms_bomb[1000] = {0};
    for(int i=0; i<Num; i++){
        for (int j=i+1; j<Num; j++){
            if(atomList[i].x == atomList[j].x && atomList[i].y == atomList[j].y) atoms_bomb[i] = atoms_bomb[j] = 1;
        }
    }
    for(int i=0;i<Num;i++){
        if(atoms_bomb[i]){
            result += atomList[i].energy;
            atoms_bomb[i] = atoms_bomb[Num-1];
            atomList[i] = atomList[Num-1];
            Num--;
            i--;
        }
    }

    int atoms_ok[1000] = {0};
    int out = (1<<29);
    for(int i=0; i<Num; i++){
        for (int j=i+1; j<Num; j++){
            int ok = is_will_collion(atomList[i], atomList[j]);
            if(ok){
                atoms_ok[i] = atoms_ok[j] = 1;
                out = out < ok ? out : ok;
            }
        }
    }
    for(int i=0;i<Num;i++){
        if(!atoms_ok[i]){
            atoms_ok[i] = atoms_ok[Num-1];
            atomList[i] = atomList[Num-1];
            Num--;
            i--;
        }
    }

    out = out/2;
    return out>1 ? out:1;
}

int move_atom(Atom atomList[], int Num, int time=1){
    int dx[4] = {0,0,-time,time};
    int dy[4] = {time,-time,0,0};

    for(int i=0; i<Num; i++){
        int arrow = atomList[i].arrow;
        atomList[i].x+=dx[arrow];
        atomList[i].y+=dy[arrow];
    }
}

int cal_main(){
    int Num;
    Atom atomList[1000]; //x , y , arrow , energy

    scanf("%d",&Num);
    for(int i=0;i<Num;i++){
        scanf("%d",&atomList[i].x);
        atomList[i].x *= 2;
        scanf("%d",&atomList[i].y);
        atomList[i].y *= 2;
        scanf("%d",&atomList[i].arrow);
        scanf("%d",&atomList[i].energy);
    }
    //--------------------------------------------------
    int result = 0;
    int time = 1;

    while(Num>0){
        move_atom(atomList, Num, time);
        time = cal_collion(atomList, Num, result);
    }

    return result;
}

int main(){
    #ifdef HOME
        freopen("sample_input.txt","r",stdin);
    #endif
    int cnt;
    cin >> cnt;
    for(int i=0; i<cnt; i++){
        printf("#%d %d\n",i+1 , cal_main());
    }
    return 0;
}