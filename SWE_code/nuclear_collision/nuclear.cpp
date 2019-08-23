#define HOME 1
// #define DEBBUG 2
#include <iostream>
using namespace std;

class Atom{
public:
    int index, x, y, arrow, energy;
    Atom(){
        index = x = y = arrow = energy = 0;
    }
    bool operator==(Atom &other){
        if(x==other.x && y==other.y) return true;
        return false;
    }
};

inline int abs(int x){ return x > 0 ? x : -x;}


int is_will_collion(Atom atom1, Atom atom2){
    int ok = 0;
    if(atom1 == atom2) {
        return 0;
    }

    if(atom1.x == atom2.x){ // same x
        if(atom1.y < atom2.y && atom1.arrow==0 && atom2.arrow==1) ok = 1;
        else if(atom1.y > atom2.y && atom1.arrow==1 && atom2.arrow==0) ok = 1;
    }
    else if(atom1.y == atom2.y){ // same y
        if(atom1.x < atom2.x && atom1.arrow==3 && atom2.arrow==2) ok = 1;
        else if(atom1.x > atom2.x && atom1.arrow==2 && atom2.arrow==3) ok = 1;
    }
    else if( abs(atom1.x-atom2.y)==abs(atom1.y-atom2.x) ){
        if(atom1.x<atom2.x && atom1.y<atom2.y){
            if(atom1.arrow==3 && atom2.arrow==1 || atom1.arrow==0 && atom2.arrow==2 ) ok=1;
        }
        else if(atom1.x<atom2.x && atom1.y>atom2.y){
            if(atom1.arrow==3 && atom2.arrow==0 || atom1.arrow==1 && atom2.arrow==2 ) ok=1;
        }
        else if(atom1.x>atom2.x && atom1.y<atom2.y){
            if(atom1.arrow==0 && atom2.arrow==3 || atom1.arrow==2 && atom2.arrow==1 ) ok=1;
        }
        else if(atom1.x>atom2.x && atom1.y>atom2.y){
            if(atom1.arrow==1 && atom2.arrow==3 || atom1.arrow==2 && atom2.arrow==0 ) ok=1;
        }
    }

    return ok;
}

int cal_collion(Atom atomList[], int &Num, int &result){
    #ifdef DEBBUG
        for(int i=0;i<Num;i++){
            printf("index : %d , y : %d , x : %d\n",atomList[i].index,atomList[i].y,atomList[i].x);
        }
        cout<<"----------------------"<<endl;
        
    #endif

    int atoms_bomb[1000] = {0};
    for(int i=0; i<Num; i++){
        for (int j=i+1; j<Num; j++){
            if(atomList[i] == atomList[j]) atoms_bomb[i] = atoms_bomb[j] = 1;
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
    for(int i=0; i<Num; i++){
        for (int j=i+1; j<Num; j++){
            int ok = is_will_collion(atomList[i], atomList[j]);
            if(ok){atoms_ok[i] = atoms_ok[j] = 1;}
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

    return 0;
}

int move_atom(Atom atomList[], int Num){
    for(int i=0; i<Num; i++){
        Atom atom = atomList[i];
        switch (atom.arrow)
        {
            case 0:
                atomList[i].y++;
                break;
            case 1:
                atomList[i].y--;
                break;
            case 2:
                atomList[i].x--;
                break;
            case 3:
                atomList[i].x++;
                break;
        }
    }
}

int cal_main(){
    int Num;
    Atom atomList[1000]; //index , x , y , arrow , energy
    

    scanf("%d",&Num);
    for(int i=0;i<Num;i++){
        atomList[i].index = i;
        scanf("%d",&atomList[i].x);
        scanf("%d",&atomList[i].y);
        scanf("%d",&atomList[i].arrow);
        scanf("%d",&atomList[i].energy);
    }
    //--------------------------------------------------
    int result = 0;

    while(Num>0){
        move_atom(atomList, Num);
        cal_collion(atomList, Num, result);
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