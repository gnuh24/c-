/* Đề bài 2.2
2.2 Trong kỳ thi tốt nghiệp đại học có n thí sinh tham dự. Mỗi thí sinh cần quản lý các thông tin được mô tả như sau:
    - MSSV
    - Họ và tên
    - Điểm môn cơ bản
    - Điểm chuyên ngành 1
    - Điểm chuyên ngành 2
        a) Hãy khai báo kiểu dữ liệu cho bài toán như mô tả trên. Nhập thông tin cho n thí sinh.
        b) Xuất danh sách với các thông tin gồm 5 thông tin trên; tổng điểm 3 môn
        c) Tìm những thí sinh có ít nhất một môn thi có điểm nhỏ hơn 5
        d) Tìm những thứ sinh có tổng điểm ba môn thi lớn nhất
        e) Sắp xếp danh sách theo chiều tổng điểm 2 môn chuyên ngành tăng dần.
*/

#include<iostream>
#include<windows.h>
using namespace std;

//a) Hãy khai báo kiểu dữ liệu cho bài toán như mô tả trên. Nhập thông tin cho n thí sinh.
struct Alumnus{
    long long student_code;
    string name;
    float basic_subject_score;
    float specialized_subject_score_1;
    float specialized_subject_score_2;
};
void input(Alumnus *&a, int &n);

//b) Xuất danh sách với các thông tin gồm 5 thông tin trên; tổng điểm 3 môn
void output(Alumnus *a, int n);
//c) Tìm những thí sinh có ít nhất một môn thi có điểm nhỏ hơn 5
void find_c(Alumnus *a, int n);
//d) Tìm những thứ sinh có tổng điểm ba môn thi lớn nhất
Alumnus *find_d(Alumnus *a, int n);
//e) Sắp xếp danh sách theo chiều tổng điểm 2 môn chuyên ngành tăng dần.
void Sort(Alumnus *&a, int n);
void swap(Alumnus *a, Alumnus *b);



int main(){
    SetConsoleOutputCP(CP_UTF8);
    Alumnus *a;
    int n;
    input(a,n);
    output(a,n);
    find_c(a,n);
    
    cout <<"Thì sinh "<< find_d(a,n)->name <<" có tổng điểm 3 môn cao nhất là " << find_d(a,n)->basic_subject_score + find_d(a,n)-> specialized_subject_score_1  + find_d(a,n)->specialized_subject_score_2 << endl;
    Sort(a,n);
    output(a,n);
    return 0;
}

void input(Alumnus *&a, int &n){
    cout << "Enter n = "; cin >> n;
    a = new Alumnus[n];
    for (int i=0; i < n; i++){
        cout <<"Student code = "; cin >> (a+i)->student_code;
        cin.ignore();
        cout <<"Name: "; getline(cin , (a+i) -> name);
        cout <<"Basic subject score = "; cin >> (a+i) -> basic_subject_score;
        cout <<"Specialized subject score 1 = "; cin >> (a+i) -> specialized_subject_score_1;
        cout <<"specialized subject score 2 = "; cin >> (a+i) -> specialized_subject_score_2;
    }
}

void output(Alumnus *a, int n){
    for (int i=0; i < n; i++){
        cout <<"Student code = " << (a+i)->student_code << endl;
        cout <<"Name: " << (a+i) -> name << endl;
        cout <<"Basic subject score = " << (a+i) -> basic_subject_score << endl;
        cout <<"Specialized subject score 1 = "<< (a+i) -> specialized_subject_score_1 << endl;
        cout <<"specialized subject score 2 = "<< (a+i) -> specialized_subject_score_2 << endl;
    }
}

void find_c(Alumnus *a, int n){
    for (int i=0; i < n; i++){
        if ((a+i) -> basic_subject_score < 5 || (a+i) -> specialized_subject_score_1 < 5 || (a+i) -> specialized_subject_score_2 < 5){
            cout << (a+i) -> name << " có môn dưới 5 điểm" << endl;
        }
    }
}

Alumnus *find_d(Alumnus *a, int n){
    Alumnus *max = (a+0);
    for (int i=1; i < n; i++){
        if ( (a+i) -> basic_subject_score + (a+i) -> specialized_subject_score_1  + (a+i) -> specialized_subject_score_2 > max -> basic_subject_score + max -> specialized_subject_score_1  + max -> specialized_subject_score_2){
            max = (a+i);
        }
    }
    return max;

}

void swap(Alumnus *a, Alumnus *b){
    Alumnus temp = *a;
    *a = *b;
    *b = temp;
}

void Sort(Alumnus *&a, int n){
    for (int i=0; i < n-1; i++){
        for (int j=i+1; j < n; j++){
            if ( (a+i)-> specialized_subject_score_1 + (a+i)-> specialized_subject_score_1 > (a+j)-> specialized_subject_score_1 + (a+j)-> specialized_subject_score_1){
                swap((a+i), (a+j));
            }
        }
    }
}
