#include <iostream>
#include <string>
using namespace std;
struct Student {//建立一個名為Student的結構型態,裡面包含int、string等不同類型的資料型態
	int id;
	string name;
	int chinese;
	int english;
	int math;
	int social;
	int science;
};
void updateMath(Student &s) { //改成取address而不是複製
	s.math = 100;
}
void printStudent(Student &s) {
	//此行是否改成取address而不是複製體其實無太多差別，因為沒有改變數值
	cout << "學生編號: " << s.id << endl;
	cout << "姓名: " << s.name << endl;
	cout << "數學成績: " << s.math << endl;
}
int main() {
	Student one;
	//利用前面所建立的名為 Student 的結構來宣告一個名為 one 的結構變數
	one.id = 1; //對新宣告的結構變數 one 中的元素賦值
	one.name = "張小美";
	one.chinese = 77;
	one.english = 83;
	one.math = 86;
	one.social = 68;
	one.science = 91;
	updateMath(one);
	printStudent(one);
	return 0;
}
