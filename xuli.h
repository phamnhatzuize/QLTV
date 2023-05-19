#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<iomanip>
#include<conio.h>
#include "setting.h"

using namespace std;

struct Book{
    string MaSoSach;
    string TenSach, TenTacGia, NhaXuatBan;
    string SoLanTaiBan, NamXuatBan, SoTrang;
    string Gia;
    int SoLuongGoc, SoLuong;
    int Location;
}DataChild,Pos[100];

class BookParent{
private:
    string MaSoSach;
    string TenSach, TenTacGia;
    string NhaXuatBan;
    string SoLanTaiBan, NamXuatBan, SoTrang;
    string Gia;
    int SoLuongGoc, SoLuong;
public:
    int count;
    BookParent(){
        SoTrang = "";
        SoLuong = 0;
        SoLanTaiBan = "";
        TenSach = "";
        NhaXuatBan = "";
        TenTacGia = "";
        MaSoSach = "";
       // this->NamXuatBan = "";
        Gia = "";
    }
    void setBookParent(Book DataChild)
    {
        this->MaSoSach = DataChild.MaSoSach;
        this->TenSach =  DataChild.TenSach;
        this->TenTacGia =  DataChild.TenTacGia;
        this->NhaXuatBan =  DataChild.NhaXuatBan;
        this->SoLanTaiBan =  DataChild.SoLanTaiBan;
        this->SoTrang =  DataChild.SoTrang;
        this->Gia = DataChild.Gia;
        this->SoLuongGoc = DataChild.SoLuongGoc;
        this->SoLuong = DataChild.SoLuongGoc;
    }
    string getMSS(){
        return MaSoSach;
    }
    string getTS(){
        return TenSach;
    }
    string getTTG(){
        return TenTacGia;
    }
    string getNXB(){
        return NhaXuatBan;
    }
    string getSLTB(){
        return SoLanTaiBan;
    }
    string getST(){
        return SoTrang;
    }
    string getG(){
        return Gia;
    }
    int getSLG(){
        return SoLuongGoc;
    }
    int getSL(){
        return SoLuong;
    }
    int InputData(BookParent PB[]);
    void MenuMain();
    void ShowInfor(BookParent BP[], int &index );
    void MenuStatus();
    void UpdateData(BookParent BP[]);
    void MenuUtilities();
    bool ReturnFun();
    ~BookParent(){}
};

int ChangeStr_into_Int(string str){
    int x = 0;
    stringstream str2num(str);
    str2num >> x;
    return x;
}
int BookParent::InputData(BookParent PB[]){
    int count = 0;
    int count1 = 0;
    int index = 0;
    string str;
    fstream DataBook;
    DataBook.open("BOOKDATA.csv", ios::in);
    getline(DataBook,str);
    str = "";
    while(!DataBook.eof()){
        getline(DataBook, str);
        str = str + ",";
        // lay vi tri cua cac dau phay
        for(int i = index; i < str.length(); i++){
            if(str[i] == ','){
                count1++;
                Pos[count1].Location = i;
            }

        }
        count1 = 1;
        // cat cac chuoi theo vi tri dau phay gan vao tung phan tu
        DataChild.MaSoSach = str.substr(index,Pos[count1].Location - index);

        index = Pos[count1].Location + 1; count1++;

        DataChild.TenSach = str.substr(index,Pos[count1].Location - index); 

        index = Pos[count1].Location + 1; count1++;

        DataChild.TenTacGia = str.substr(index,Pos[count1].Location - index);

        index = Pos[count1].Location + 1; count1++;

        DataChild.NhaXuatBan = str.substr(index,Pos[count1].Location - index);

        index = Pos[count1].Location + 1; count1++;

        DataChild.SoLanTaiBan = str.substr(index,Pos[count1].Location - index); 
        
        index = Pos[count1].Location + 1; count1++;

        DataChild.SoTrang = str.substr(index,Pos[count1].Location - index); 
        
        index = Pos[count1].Location + 1; count1++;
        
        DataChild.Gia = str.substr(index,Pos[count1].Location - index);

        //DataChild.Gia = (DataChild.Gia).substr(1,((DataChild.Gia).length() - 1) - 1); 
        
        index = Pos[count1].Location + 1; count1++;
        
        DataChild.SoLuongGoc = ChangeStr_into_Int(str.substr(index,Pos[count1].Location - index)); 
        
        PB[count].setBookParent(DataChild); 
        count++;
        index = 0;
        count1 = 0;
    }
    DataBook.close();
    return count;
}
int strLenMAX(string B[], int count){
   int StrLenMax = 0;
   for(int i = 0; i < count; i ++){
        if(B[i].length() > StrLenMax){
            StrLenMax = B[i].length();
        }
    }
   return StrLenMax;
}


void BookParent::MenuMain(){
    
    cout <<setw(SetOX + 18)<<setfill(' ')<<"QUAN LY THU VIEN"<<endl;
    cout <<setw(SetOX + 20)<<setfill(' ')<< "+--------***-------+"<<endl;
    cout <<setw(SetOX)<<setfill(' ')<<""<< "1. Thong tin sach."<<endl;
    cout <<setw(SetOX)<<setfill(' ')<<""<< "2. Quan ly trang thai."<<endl;
    cout <<setw(SetOX)<<setfill(' ')<<""<< "3. Chuc nang tien ich."<<endl;
    cout <<setw(SetOX)<<setfill(' ')<<""<< "4. Thoat." <<endl;
    cout <<setw(SetOX)<<setfill(' ')<<""<< "Moi lua chon: ";
}
void BookParent::ShowInfor(BookParent BP[], int &index){
    BookParent Bp;
    string TS[Count_MAX], TTG[Count_MAX], NXB[Count_MAX], G[Count_MAX];
    int DisBook , DisAuthor, DisPubComp, DisPrice;
    for(int i = 0 ; i < index; i++){
        TS[i] = BP[i].getTS();
        TTG[i] = BP[i].getTTG();
        NXB[i] = BP[i].getNXB();
        G[i] = BP[i].getG();
    }
    //lay do dai chuoi lon nhat
    DisBook = strLenMAX(TS,index);
    DisAuthor = strLenMAX(TTG,index); 
    DisPubComp = strLenMAX(NXB,index);
    DisPrice = strLenMAX(G,index);
    //TH Do dai phan tu qua ngan
    if(DisBook < 15){ DisBook = 17;}
    if(DisAuthor < 11){ DisAuthor = 12;}
    if(DisPubComp < 12){ DisPubComp = 12;}

    cout <<setw((156-(DisAuthor + DisBook + DisPrice + DisPubComp + 40))/2)<<setfill(' ')<<"";

    cout << setw(DisAuthor + DisBook + DisPrice + DisPubComp + 40)<<setfill('-') <<""<< endl;

    cout <<setw((156-(DisAuthor + DisBook + DisPrice + DisPubComp + 40))/2)<<setfill(' ')<<" ";

    cout << "|"<<setw(6)<<setfill(' ')<<"MSS"<<setw(4)<<setfill(' ')<<"|";

    cout << setw(13)<<setfill(' ')<<"Ten Sach"<< setw(DisBook -10)<<setfill(' ')<<" |";
    
    cout << setw(15)<<setfill(' ')<<" Ten Tac Gia"<<setw(DisAuthor-10)<<setfill(' ')<<"|";

    cout << setw(13)<<setfill(' ')<<"Nha Xuat Ban"<<setw(DisPubComp - 9)<<setfill(' ')<<"|";

    cout << setw(6)<<setfill(' ')<<"Gia"<<setw(DisPrice - 2)<<setfill(' ')<<"|";

    cout << setw(10)<<setfill(' ')<<"So Luong"<<setw(3)<<setfill(' ')<<"|"<<endl;

    cout <<setw((156-(DisAuthor + DisBook + DisPrice + DisPubComp + 40))/2)<<setfill(' ')<<"";

    cout << setw(DisAuthor + DisBook + DisPrice + DisPubComp + 40)<<setfill('-') <<""<< endl;
    
    for(int i = 0; i < index ; i++ ){

        cout <<setw((156-(DisAuthor + DisBook + DisPrice + DisPubComp + 40))/2)<<setfill(' ')<<" ";

        cout << "|  "<<BP[i].getMSS()<<"  | ";

        cout << setw(2)<<setfill(' ')<<BP[i].getTS()<<setw(DisBook - BP[i].getTS().length() + 4)<<setfill(' ')<<"|  ";

        cout << BP[i].getTTG()<<setw(DisAuthor - BP[i].getTTG().length()+ 5) << setfill(' ')<<"|  ";
        
        cout << BP[i].getNXB()<<setw(DisPubComp - BP[i].getNXB().length() + 3)<<setfill(' ')<<"| ";
        
        cout << BP[i].getG()<<setw(DisPrice - BP[i].getG().length()+4)<<setfill(' ')<<"| ";
        
        cout << setw(6)<<setfill(' ')<<BP[i].getSL()<<setw(6)<<setfill(' ')<<"|"<<endl;

        cout <<setw((156-(DisAuthor + DisBook + DisPrice + DisPubComp + 40))/2)<<setfill(' ')<<"";
        
        cout << setw(DisAuthor + DisBook + DisPrice + DisPubComp + 40)<<setfill('-')<<""<<endl;
    }
}
void BookParent::MenuStatus(){
    cout <<setw(SetOX+18)<<setfill(' ')<< "QUAN LY TRANG THAI"<<endl;
    cout <<setw(SetOX)<<setfill(' ')<<""<< "--------***-------"<<endl;
    cout <<setw(SetOX)<<setfill(' ')<<""<< "1. Chinh sua thong tin."<<endl;
    cout <<setw(SetOX)<<setfill(' ')<<""<< "2. Them sach."<<endl;
    cout <<setw(SetOX)<<setfill(' ')<<""<< "3. Xoa thong tin."<<endl;
    cout <<setw(SetOX)<<setfill(' ')<<""<< "4. Quay Lai menu chinh."<<endl;
    cout <<setw(SetOX)<<setfill(' ')<<""<< "Moi lua chon: ";
}
void BookParent::UpdateData(BookParent BP[]){
    string NameCode;
    BookParent P;
    int count = P.InputData(BP);
    bool check = false ,flag = false;
    int pos;
    cout << "Moi nhap ma so sach: ";
    cin.ignore();
    getline(cin,NameCode);
    for(int i = 0 ; i < P.InputData(BP); i++){
        if(NameCode == BP[i].MaSoSach){
            flag = check = true;
            pos = i;
            cout << "1. Ma so sach: " << BP[i].MaSoSach << endl;;
            cout << "2. Ten Sach: " << BP[i].TenSach << endl;
            cout << "3. Ten tac gia: " << BP[i].TenTacGia << endl;
            cout << "4. Nha xuat ban: " << BP[i].NhaXuatBan << endl;
            cout << "5. Gia: " << BP[i].Gia<<endl;
            cout << "6: So luong: "<< BP[i].SoLuongGoc << endl;
        }
    }
    while(check == true){
        int choose ;
        cout << endl<<"Moi ban chon muc can sua doi: "; cin >> choose;
        switch(choose){
            case 1:{
                string MSS;
                cout << "Moi nhap MSS: ";
                cin.ignore(); getline(cin, BP[pos].MaSoSach );
                check = false;
                break;
            }
            case 2:{
                string TS;
                cout << "Moi ban nhap ten sach: ";
                cin.ignore(); getline(cin,BP[pos].TenSach);
                check = false;
                break;
            }
            case 3:{
                string TTG;
                cout << "Moi ban nhap ten tac gia: ";
                cin.ignore(); getline(cin,BP[pos].TenTacGia);
                check = false;
                break;
            }
            case 4:{
                string NXB;
                cout << "Moi ban nhap nha xua ban: ";
                cin.ignore(); getline(cin, BP[pos].NhaXuatBan);
                check = false;
                break;
            }
            case 5:{
                string TG;
                cout << "Moi ban nhap gia sach: ";
                cin.ignore();getline(cin,BP[pos].Gia);
                check = false;
                break;
            }
            case 6:{
                int num;
                cout << "Moi ban nhap so luong: ";
                cin >> num;
                BP[pos].SoLuongGoc = num;
                check = false;
                break;
            }
            default:
                check = true;
                break;
        }
    }
    if(flag == true){
        string newstr;
        fstream DataFile, FakeFile;
        DataFile.open("BOOKDATA.csv", ios::in);
        FakeFile.open("FAKEDATA.txt", ios::out);
        getline(DataFile,newstr); FakeFile << newstr;
        for(int i = 0; i < count; i++){
            newstr = BP[i].MaSoSach + ","+ BP[i].TenSach + ","+BP[i].TenTacGia+","+BP[i].NhaXuatBan+","
                  +BP[i].SoLanTaiBan+","+BP[i].SoTrang+","+BP[i].Gia+",";
            FakeFile << endl << newstr << BP[i].SoLuongGoc;
        }
        DataFile.close();
        FakeFile.close();
        remove("BOOKDATA.csv");
        rename("FAKEDATA.txt","BOOKDATA.csv");
        cout << endl <<"Sua doi thanh cong" ;
    }else{
        cout << endl << "khong tim thay du lieu";
    } 
        
}
void AddData(){
    string NameFile;
    string str;
    cout << "nhap ten file can them: ";
    cin.ignore();
    getline(cin,NameFile);
    fstream AddFile, OrigFile;
    AddFile.open(NameFile.c_str(), ios::in);
    OrigFile.open("BOOKDATA.csv" , ios::out | ios::app);
    if(AddFile.is_open()){
        getline(AddFile,str); str = "";
        while(getline(AddFile,str)){
            OrigFile << endl << str;
            if(AddFile.eof()) OrigFile.close();
        }
        cout << "Da them thanh cong !!!"<<endl;
    }else{
        cout << "Khong tim thay file !!!"<<endl;
    }
}
void DeleData(){
    string NameFile;
    int count = 0;
    string Strtemp[Count_MAX];
    string StrOrig,StrTitle,StrDele;
    cout << "nhap ten file : ";
    cin.ignore();
    getline(cin,NameFile);
    fstream DeleFile, OrigFile, FakeData;
    
    DeleFile.open(NameFile.c_str(), ios::in);
    OrigFile.open("BOOKDATA.csv" , ios :: in);
    
    if(DeleFile.is_open()){
        FakeData.open("FAKEDATA.txt", ios::out);
        
        getline(DeleFile,StrTitle);
        getline(OrigFile,StrTitle); FakeData << StrTitle;
        
        while(!DeleFile.eof()){
            getline(DeleFile, StrDele);
            Strtemp[count++] = StrDele;
        }
        while(!OrigFile.eof()){
            bool Check = true;
            int i = 0;
            getline(OrigFile,StrOrig);
            while(i < count){ 
                if(Strtemp[i] == StrOrig){
                    Check = false;
                    break;
                }
                i++;
            }
            if(Check == true) FakeData << endl << StrOrig;
        }
        DeleFile.close();
        OrigFile.close();
        FakeData.close();
        remove("BOOKDATA.csv");
        rename("FAKEDATA.txt", "BOOKDATA.csv");
        cout << "Da xoa thanh cong !!!"<<endl;
    }else{
        cout << "Khong tim thay file !!!"<<endl;
    }
}

void BookParent::MenuUtilities(){
    cout <<setw(SetOX)<<setfill(' ')<<""<< "CHUC NANG TIEN ICH"<<endl;
    cout <<setw(SetOX)<<setfill(' ')<<""<< "--------***--------"<<endl;
    cout <<setw(SetOX-5)<<setfill(' ')<<""<< "1. Tim kiem sach theo ten tac gia."<<endl;
    cout <<setw(SetOX-5)<<setfill(' ')<<""<< "2. Tim kiem sach theo ten sach." << endl;
    cout <<setw(SetOX-5)<<setfill(' ')<<""<< "3. Loc thong tin nha xuat ban." << endl;
    cout <<setw(SetOX-5)<<setfill(' ')<<""<< "4. Kiem tra tinh trang sach." << endl;
    cout <<setw(SetOX-5)<<setfill(' ')<<""<< "5. Quay Lai menu chinh."<<endl;
    cout <<setw(SetOX)<<setfill(' ')<<""<< "Moi lua chon: ";
}
int FindAuthor(BookParent BP[]){
    int count = 0;
    bool check = false;
    Book ChildTemp;
    BookParent P;
    BookParent Child[Count_MAX];
    string Author;
    cout << " nhap ten tac gia: ";
    cin.ignore();
    getline(cin, Author);
    for(int i = 0 ; i < P.InputData(BP); i++ ){
        if((Author).compare(BP[i].getTTG()) == 0){
            ChildTemp.TenSach = BP[i].getTS();
            ChildTemp.MaSoSach = BP[i].getMSS();
            ChildTemp.TenTacGia = BP[i].getTTG();
            ChildTemp.NhaXuatBan = BP[i].getNXB();
            ChildTemp.Gia = BP[i].getG();
            ChildTemp.SoLuongGoc = BP[i].getSLG();
            Child[count].setBookParent(ChildTemp);
            count++;
            check = true;
        }
    }
    if(check == true){ P.ShowInfor(Child,count);
    }else{ cout <<setw(SetOX-5)<<setfill(' ')<<""<<"khong co du lieu !!!";}
}
int FindNameBook(BookParent BP[]){
    int count = 0;
    bool check = false;
    Book ChildTemp;
    BookParent P;
    BookParent Child[Count_MAX];
    string NameBook;
    cout << " nhap ten sach can tim: ";
    cin.ignore();
    getline(cin, NameBook);
    for(int i = 0 ; i < P.InputData(BP); i++ ){
        if((NameBook).compare(BP[i].getTS()) == 0){
            ChildTemp.TenSach = BP[i].getTS();
            ChildTemp.MaSoSach = BP[i].getMSS();
            ChildTemp.TenTacGia = BP[i].getTTG();
            ChildTemp.NhaXuatBan = BP[i].getNXB();
            ChildTemp.Gia = BP[i].getG();
            ChildTemp.SoLuongGoc = BP[i].getSLG();
            Child[count].setBookParent(ChildTemp);
            count++;
            check = true;
        }
    }
    if(check == true){ P.ShowInfor(Child,count);
    }else{ cout <<setw(SetOX-5)<<setfill(' ')<<""<<"khong co du lieu !!!";}
}
int FindPubComp(BookParent BP[]){
    int count = 0;
    bool check = false;
    Book ChildTemp;
    BookParent P;
    BookParent Child[Count_MAX];
    string NameBook;
    cout << " nhap ten nha xuat ban: ";
    cin.ignore();
    getline(cin, NameBook);
    for(int i = 0 ; i < P.InputData(BP); i++ ){
        if((NameBook).compare(BP[i].getNXB()) == 0){
            ChildTemp.TenSach = BP[i].getTS();
            ChildTemp.MaSoSach = BP[i].getMSS();
            ChildTemp.TenTacGia = BP[i].getTTG();
            ChildTemp.NhaXuatBan = BP[i].getNXB();
            ChildTemp.Gia = BP[i].getG();
            ChildTemp.SoLuongGoc = BP[i].getSLG();
            Child[count].setBookParent(ChildTemp);
            count++;
            check = true;
        }
    }
    if(check == true){ P.ShowInfor(Child,count);
    }else{ cout <<setw(SetOX-5)<<setfill(' ')<<""<<"khong co du lieu !!!";}
}
void CheckBookStatus(BookParent BP[]){
    int choose;
    BookParent P;
    int count = P.InputData(BP);
    cout << "Tim kiem theo : "<<endl;
    cout << "1. Ten sach "<<endl;
    cout << "2. Ten tac gia "<<endl;
    cout << "3. Ma so sach"<<endl;
    cout <<endl<<"Moi lua chon: "; cin >> choose;
    switch(choose){
        case 1:{
            string str;
            cout << "Moi nhap ten sach: ";
            cin.ignore(); getline(cin,str);
            for(int i = 0; i < count; i++){
                if(str == BP[i].getTS()){
                    cout << "1. Ma so sach: "<<BP[i].getMSS()<<endl;
                    cout << "2. Ten sach: "<<BP[i].getTS()<<endl;
                    cout << "3. Nha xuat ban: "<<BP[i].getNXB()<<endl;
                    cout << "4. So lan tai ban: " <<BP[i].getSLTB()<<endl;
                    cout << "5. So luong hien tai: "<<BP[i].getSL()<<endl;
                    cout << "-> Trang thai : ";if(BP[i].getSL() == 0)cout << "Da het"; else cout << "Con Sach";
                    cout << endl;
                }
            }
            break;
        }
        case 2:{
            string str;
            cout << "Moi nhap ten tac gia: ";
            cin.ignore(); getline(cin,str);
            for(int i = 0; i < count; i++){
                if(str == BP[i].getTTG()){
                    cout << "1. Ma so sach: "<<BP[i].getMSS()<<endl;
                    cout << "2. Ten sach: "<<BP[i].getTS()<<endl;
                    cout<< "3. Nha xuat ban: "<<BP[i].getNXB()<<endl;
                    cout <<"4. So lan tai ban: " <<BP[i].getSLTB()<<endl;
                    cout << "5. So luong hien tai: "<<BP[i].getSL()<<endl;
                    cout << "-> Trang thai : ";if(BP[i].getSL() == 0)cout << "Da het"; else cout << "Con Sach";
                    cout << endl;
                }
            }
            break;
        }
        case 3:{
            string str;
            cout << "Moi nhap ma so sach: ";
            cin.ignore(); getline(cin,str);
            for(int i = 0; i < count; i++){
                if(str == BP[i].getMSS()){
                    cout << "1. Ma so sach: "<<BP[i].getMSS()<<endl;
                    cout << "2. Ten sach: "<<BP[i].getTS()<<endl;
                    cout<< "3. Nha xuat ban: "<<BP[i].getNXB()<<endl;
                    cout <<"4. So lan tai ban: " <<BP[i].getSLTB()<<endl;
                    cout << "5. So luong hien tai: "<<BP[i].getSL()<<endl;
                    cout << "-> Trang thai : ";if(BP[i].getSL() == 0)cout << "Da het"; else cout << "Con Sach";
                    cout << endl;
                }
            }
            break;
        }
        default:
            break;
    }
}
// ham bat sư kien tu phim
bool BookParent::ReturnFun(){
    char c;
    cout <<endl<<setw((OXmax-23)/2)<<setfill(' ')<<""<<"Bam phim <- de quay lai";
    while(1){
        if(kbhit()){
            c = getch();
            if(c == 75){
                return true;
            }
        }
    }
}
