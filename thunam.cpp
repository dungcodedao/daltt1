#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct sv{
	string masv, tensv, lop, ngs,gt;
	double diem, gpa;
	
void in() {
		cout <<"Nhap thong tin sinh vien: \n";
		cout << " Ma sinh vien: " <<masv<<endl;
		cout << " Ten cua sinh vien: " <<tensv<<endl;
		cout <<" Gioi tinh cua sinh vien : " <<gt<<endl;
		cout << " Lop: " <<lop<<endl;
		cout << " Ngay sinh sinh vien: " <<ngs<<endl;
		cout << " GPA cua sinh vien: " << fixed<< setprecision(2)<<gpa<<endl;
    	cout <<" *****************************************************\n";
	}

void nhap() {
		cout << " Ma sinh vien: " ; 	cin.ignore();	
		getline(cin, masv);
		cout << " Ten cua sinh vien: " ; //cin.ignore();	
		getline(cin, tensv);
		cout << " Gioi tinh: " ; //cin.ignore();
		getline(cin, tensv);
		cout << " Lop: " ; //cin.ignore();
		getline(cin, lop);
		cout << " Ngay sinh sinh vien: " ; //cin.ignore();	
		getline(cin, ngs);
		cout << " GPA cua sinh vien: " ; cin>>gpa;	// cin.ignore();	
		getline(cin, ngs);
    	cout <<"\n";
	}	
};

void inds(sv a[], int n){
	cout << " Thong tin danh sach sinh vien: \n";
	for (int i=0; i < n; i++){
	    a[i].in(); 
	}
}
void tkma(sv a[], int n) {
	string masv;
	cout << " Nhap ma sinh vien can tim: "; cin>>masv;
	bool found = false;
	for (int i = 0; i < n; i++){
		if ( a[i].masv.find(masv) != string::npos) {
			a[i].in();
			found = true;
			return;
		}
    }
    if (!found)
	cout << " Khong the tim thay sinh vien nay, vui long nhap lai! \n";
	
}
void lkgpa(sv a[], int n){
	double res = 0;
	for(int i = 0; i < n; i++){
		if(a[i].gpa > res) res = a[i].gpa;
	}
	cout <<" Danh sach sinh vien co diem GPA cao nhat: \n";
  for (int i = 0; i < n; i++){
	    if(res == a[i].gpa){
		  a[i].in();
	    }
    }
}
bool cmp1(sv a, sv b){
	return a.gpa >b.gpa;
}
void lkgpa2(sv a[], int n){
	vector<sv> v;
	for (int i = 0; i < n; i++){
		if(a[i].gpa >= 3) v.push_back(a[i]);
			
	}
	sort(v.begin(), v.end(), cmp1);
	cout << " Danh sach cac sinh vien co diem GPA >=3: \n";
	for (sv x : v){
	    x.in();
    }
}
string chuanhoa(string name){
	stringstream ss(name); vector<string> v;
	string token, res = " ";
	while(ss >> token){
		v.push_back(token);
	}
	res += v[v.size() - 1];
	for(int i = 0; i < v.size(); i++) res += v[i];
	return res;
}

bool cmp2(sv a, sv b){
	string tensv1 = chuanhoa(a.tensv);
	string tensv2 = chuanhoa(b.tensv);
	return tensv1 < tensv2;
}

void sxten(sv a[], int n){
	sort(a, a + n, cmp2);
}
 int main(){
 	sv a[1000];
 	int n;
 	int lc; cin >> lc;
 	 do {
 		cout << "\n";
 		cout << "1. Nhap thong tin sinh vien \n";
 		cout << "2. Hien thi toan bo danh sach sinh vien\n";
 		cout << "3. Tim kiem sinh vien theo masv \n";
 		cout << "4. Liet ke sinh vien co diem GPA cao nhat \n";
 		cout << "5. Liet ke cac sinh vien co diem GPA >= 3 \n";
 		cout << "6. Thoat chuong trinh! \n";
 		switch(lc){
        case 1: {
             a[n].nhap();
             ++n;
             
        case 2:
             inds(a, n);
          break;

        case 3:
             tkma(a, n);
            break;

        case 4:

             lkgpa(a, n);
            break;

        case 5: 
             lkgpa2(a, n);
             break;
        case 0 :
             break;
             		
		default:
				printf("Sai du lieu, vui long chon lai \n");
				break;
            
	 }

           }
} while(lc);
return 0;
}
