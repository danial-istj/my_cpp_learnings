#include <iostream>
#include<cstdlib>
#include<ctime>
#include<fstream>
using namespace std;
const int n=10;
char playerboard[n][n];
char aiboard[n][n];
char povaiboard[n][n];
int powerupsinplayerboardx[(n/2)];
int powerupsinplayerboardy[(n/2)];
void initBoards (){
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        playerboard[i][j]='W';
        aiboard[i][j]='W';
        povaiboard[i][j]='W';
    }
}
}
void displayBoards(){
    cout<<"  Player's Board"<<"                   "<<"AI's Board"/*<<"                   "<<" Actual AI's Board"*/<<endl;;
    cout<<"  ";
    for(int k=0;k<n;k++){
        cout<<k<<" ";
    }
    cout<<"             ";
    for(int k=0;k<n;k++){
        cout<<k<<" ";
    }
    // cout<<"             ";//column numbering for actual ai board
    // for(int k=0;k<n;k++){
    //     cout<<k<<" ";
    // }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<char(i+97)<<" ";
        for(int j=0;j<n;j++){
            cout<<playerboard[i][j]<<" ";
        }
        cout<<"           "<<char(97+i)<<" ";
        for(int j=0;j<n;j++){
            cout<<povaiboard[i][j]<<" ";
        }
        // cout<<"           "<<char(97+i)<<" ";//row numbering for actual ai board
        // for(int j=0;j<n;j++){//actual ai board
        //     cout<<aiboard[i][j]<<" ";
        // }
        cout<<endl;
    }
}
void placeplayerships(){
    cout<<"You can place 5 ships on the board:"<<endl;
for(int d=0;d<5;d++){
     bool skipouterloop=false;

cout<<"Select the ship type:"<<endl;
cout<<"A for Aircraft covers 5 cells"<<endl<<"B for Battleship covers 5 cells"<<endl;
cout<<"C for Submarine covers 4 cells"<<endl<<"D for Patrol Boat covers 3 cells"<<endl;
cout<<"Choose the direction and the coordinates"<<endl;
cout<<"like, A H c 6 "<<endl;
char shiptype;
int shipsize;
char direction;
char z;
int y;
cin>>shiptype>>direction>>z>>y; 
int x;
if (z>='a'&& z<='z'){
x =int (z)-97;
}
if (z>='A'&&z<='Z'){
    x=int(z)-65;
}
switch (shiptype){
case 'A':
case 'a':
shipsize=5;
break;
case 'B':
case 'b':
shipsize=5;
break;
case 'C':
case 'c':
shipsize=4;
break;
case 'D':
case 'd':
shipsize=3;
break;
default:
cout<<"invlaid input "<<endl<<"choose again"<<endl;
d--;
continue;
break;
}

if(direction=='H'||direction=='h'){
    if(x<n && y+shipsize<=n &&x>=0&&y>=0){
        for(int j=y;j<shipsize+y;j++){//loop for checkin validity
                if(playerboard[x][j]!='W'){
                   cout<<"invlaid input "<<endl<<"choose again"<<endl;
                   skipouterloop= true;
                }
        }
        if(skipouterloop==true){
            d--;
            continue;
                }
        for(int j=y;j<shipsize+y;j++){//loop for puttin values
                playerboard[x][j]='S';
        }
    }
    else{
        cout<<"invlaid input "<<endl<<"choose again"<<endl;
        d--;
        continue;
    }
}
else if(direction=='V'||direction=='v'){
    if(y<n && x+shipsize<=n&&y>=0&&x>=0){
           for(int j=x;j<shipsize+x;j++){//loop for checkin validity
                if(playerboard[j][y]!='W'){
                    cout<<"invlaid input "<<endl<<"choose again"<<endl;
                   skipouterloop=true; 
                }
            }
        if(skipouterloop==true){
            d--;
            continue;
        }
        for(int j=x;j<shipsize+x;j++){//loop for puttin values
                playerboard[j][y]='S';
        }
    } 
    else{
        cout<<"invlaid input "<<endl<<"choose again"<<endl;
        d--;
        continue;
    }
}
else{
        cout<<"invlaid input "<<endl<<"choose again"<<endl;
        d--;
        continue;
    }
    displayBoards();
}
}
void placeaiships(){
    cout<<"AI is placing ships..."<<endl;
    for(int d=0;d<5;d++){
        bool skipouterloop=false;
char shiptype;
char arrst[4]={'A','B','C','D'};
char arrdi[2]={'H','V'};
int shipsize;
char direction;
shiptype=arrst[rand()%4];
switch (shiptype){
case 'A':
shipsize=5;
break;
case 'B':
shipsize=5;
break;
case 'C':
shipsize=4;
break;
case 'D':
shipsize=3;
break;
default:
break;
}
direction=arrdi[rand()%2];
int x= rand()%n;
int y= rand ()%n;
if(direction=='H'){
    if(y+shipsize<=n){
        for(int j=y;j<shipsize+y;j++){//loop for checkin validity
                if(aiboard[x][j]!='W'){
                    skipouterloop=true;
                }
        }
        if(skipouterloop==true){
            d--;
            continue;
        }
        for(int j=y;j<shipsize+y;j++){//loop for puttin values
                aiboard[x][j]='S';
        }
    }
    else{
        d--;
        continue;
    }
}
else /*(direction=='V')*/{
    if(x+shipsize<=n){
           for(int j=x;j<shipsize+x;j++){//loop for checkin validity
                if(aiboard[j][y]!='W'){
                    skipouterloop=true;
                }
        }
        if(skipouterloop==true){
            d--;
            continue;
        }
        for(int j=x;j<shipsize+x;j++){//loop for puttin values
                aiboard[j][y]='S';
        }
    } 
    else{
        d--;
        continue;
    }
}
}
}
void setpowerupsinaiboard(){
    // cout<<"settingup p in aiboard"<<endl;
    //setting in ai board
    int arrx[(n/2)];
    int arry[(n/2)];
    bool foundShip;

    while (true) {
        // Generate random positions
        for (int i = 0; i < (n/2); i++) {
            arrx[i] = rand() % n;
            arry[i] = rand() % n;
        }

        // Check if these positions are valid 
        foundShip = false;
        for (int i = 0; i < (n/2); i++) {
            if (aiboard[arrx[i]][arry[i]] == 'S') {
                foundShip = true;
                break;
            }
        }

        if (!foundShip) {
            break; 
        }
    }

    //placing powerups
    for (int i = 0; i < (n/2); i++) {
        aiboard[arrx[i]][arry[i]] = 'P';
    }
}
void setpowerupsinplayerboard(){
    // cout<<"setting up p in player board"<<endl;
    //setting in ai board
    int arrx[(n/2)];
    int arry[(n/2)];
    bool foundShip;

    while (true) {
        // Generate random positions
        for (int i = 0; i < (n/2); i++) {
            arrx[i] = rand() % n;
            arry[i] = rand() % n;
        }

        // Check if these positions are valid 
        foundShip = false;
        for (int i = 0; i < (n/2); i++) {
            if (playerboard[arrx[i]][arry[i]] == 'S') {
                foundShip = true;
                break;
            }
        }

        if (!foundShip) {
            break; 
        }
    }

    //placing powerups
    for (int i = 0; i < (n/2); i++) {
        powerupsinplayerboardx[i] = arrx[i];
        powerupsinplayerboardy[i]=  arry[i];
    }
}
void playerturn(){
cout<<"Player's turn(select coordinates to attack like, a 6):"<<endl;
bool check =true;
while(check){
char z;
int x;
int y;
cin>>z>>y;
if (z>='a'&& z<='z'){
x =int (z)-97;
}
else if (z>='A'&&z<='Z'){
    x=int(z)-65;
}
else{
    cout<<"invlaid input"<<endl;
    continue;
}
if(x<10&&y<10&&x>=0&&y>=0){
    if (aiboard[x][y]=='S'){
        aiboard[x][y]='H';
        povaiboard[x][y]='H';
        check= false;
    }
    else if(aiboard[x][y]=='P'){
        aiboard[x][y]='H';
        povaiboard[x][y]='H';
        cout<<"You got a power up"<<endl;
        while(true){
            int a=rand()%n;
            int b=rand()%n;
            if(playerboard[a][b]!='S' && playerboard[a][b]!='H' ){
                playerboard[a][b]='S';
                break;
            }
            }
            check=false;
    }
    else{
        aiboard[x][y]='M';
        povaiboard[x][y]='M';
        check =false;
    }
}
else{
    cout<<"invalid iput try again"<<endl;
}
}
}
void aiturn(){
    cout<<"AI's turn"<<endl;
    int x=rand()%n;
    int y=rand()%n;
    if (playerboard[x][y]=='S'){
        playerboard[x][y]='H';
    }
    for(int i=0;i<(n/2);i++){
        if(x==powerupsinplayerboardx[i]&&y==powerupsinplayerboardy[i]){
            playerboard[x][y]='H';
            powerupsinplayerboardx[i]=-1;
            powerupsinplayerboardy[i]=-1;
            cout<<"AI got a powerup"<<endl;
            while(true){
            int a=rand()%n;
            int b=rand()%n;
            if(aiboard[a][b]!='S'||aiboard[a][b]!='P' ){
                aiboard[a][b]='S';
                break;
            }
            }
        }
    }
}
void checkwin(bool &announce){
    bool checkforplayerwin =true;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if(aiboard[i][j]=='S'){
                checkforplayerwin=false;
            }
        }
    }
    if(checkforplayerwin==true){
        announce=true;
        cout<<"Player wins!"<<endl;
    }
     bool checkforaiwin =true;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if(playerboard[i][j]=='S'){
                checkforaiwin=false;
            }
        }
    }
    if(checkforaiwin==true){
        announce=true;
        cout<<"AI wins!"<<endl;
    }
}
void savegame(){
    ofstream fout;
    fout.open("battleships.txt");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
        fout<<playerboard[i][j];
        }
        fout<<endl;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
        fout<<aiboard[i][j];
        }
        fout<<endl;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
        fout<<povaiboard[i][j];
        }
        fout<<endl;
    }
    fout.close();
}
void gameloop(){
    bool announce=false;
    while(announce==false){
        playerturn();
        aiturn();
        displayBoards();
        cout<<"Press # to save the game and any other character to contine: ";
        char a;
        cin>>a;
        if(a=='#'){
            savegame();
            return;
        }
        checkwin(announce);
    }
}
bool setboardsforsavedgame(){
    ifstream fin;
        fin.open("battleships.txt");
    // if(!fin.is_open()|| fin.tellg()==0){
      if((!fin.is_open())|| fin.peek()==EOF){
    cout<<"No game is stored"<<endl;
    return false;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
        fin>>playerboard[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
        fin>>aiboard[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
        fin>>povaiboard[i][j];
        }
    }
    fin.close();
    return true;
}
void newgame(){
    initBoards();
    displayBoards();
    placeplayerships();
    placeaiships();
    setpowerupsinaiboard();
    setpowerupsinplayerboard();
    displayBoards();
    gameloop();
}
void startsavedgame(){
   if(setboardsforsavedgame()){
    displayBoards();
    gameloop();   
   }
}
int main(){
    srand(time(0));
    bool status=true;
    while(status){
    cout<<"            Welcome To Battleships Game!"<<endl;
    cout<<"            1 to start a new game."<<endl;
    cout<<"            2 to start from the saved game."<<endl;
    cout<<"            3 to end the game."<<endl;
    int a;
    cin>>a;
    switch (a)
    {
    case 1:
    newgame();
        break;
    case 2:
    startsavedgame();
    break;
    case 3:
    cout<<"            Thanks for Playing "<<endl;
    status =false;
    break;
    default:
    cout<<"invalid input try again";
        break;
    }
    }
    return 0;
}