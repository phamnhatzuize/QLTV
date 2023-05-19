#include <bits/stdc++.h>
#include <fstream>
#include <string>
#include "xuli.h"
using namespace std;



int main(){
   int count;
   BookParent P;
   BookParent BP[Count_MAX];
   count = P.InputData(BP);
   int choose,choose1,choose3;
   bool check = true;
   while(check == true ){
        system("cls");
       P.MenuMain();
       cin >> choose;
       switch(choose){
           case 1:{
            system("cls");
            cout <<setw((OXmax-14)/2)<<setfill(' ')<<""<<"THONG TIN SACH"<<endl;
            P.ShowInfor(BP, count);
            check = P.ReturnFun();
            break;
           }
           case 2:{
            bool flag = true;
            while(flag == true){
            	system("cls");
                P.MenuStatus();
                cin >> choose1;
                switch(choose1){
                    case 1:{
                        count = P.InputData(BP);
                        P.UpdateData(BP);
                        flag = P.ReturnFun();
                        break;
                    }
                    case 2:{
                        AddData();
                        count = P.InputData(BP);
                        flag = P.ReturnFun();
                        break;
                        }
                    case 3:{
                        DeleData();
                        count = P.InputData(BP);
                        flag = P.ReturnFun();
                        break;
                    }
                    case 4:{
                        flag = false;   
                    }
                    default:
                        break;
                    }
                }
            }
            break;
           case 3:{
            bool flag = true;
            while(flag == true){
                system("cls");
                P.MenuUtilities();
                cin >> choose3;
                switch(choose3){
                    case 1:{
                        FindAuthor(BP);
                        flag = P.ReturnFun();
                        break;
                    }
                    case 2:{
                        FindNameBook(BP);
                        flag = P.ReturnFun();
                        break;
                    }
                    case 3:{
                        FindPubComp(BP);
                        flag = P.ReturnFun();
                        break;
                    }
                    case 4:{
                        CheckBookStatus(BP);
                        flag = P.ReturnFun();
                        break;
                    }
                    case 5: {
                        flag = false;
                        system("cls");
                        break;
                    }
                    default:
                        flag = true;
                        break;
                }
            }
            break;
           }
           case 4:{
                check = false;
                break;
           }
           default:{   
                check = true;
                break;
            }
       }
   }
   return 0;
}
