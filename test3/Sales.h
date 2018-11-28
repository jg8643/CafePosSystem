#pragma once
class Ctest3Dlg;
class SalesData {
public:
	SalesData(char*, char*, char*, char*);       // s_data 생성시 사용
	SalesData(int, CString, CString, CString);   // 계산 후 매출파일 새로 쓸때 사용
	SalesData(CString, int, int);                // t_data 생성시 사용

	int date;
	CString name;
	int number;
	int price;
	CString GetNumber();
	CString GetPrice();
};

class Sales {
public:
	Sales();
	
	SalesData *s_data[1024];   // 매출 파일을 읽어서 담음
	SalesData *t_data[1024];   // 매출 통계 부분에서 매출파일에서 중복부분을 담음
	Ctest3Dlg *ptest3Dlg;
	int count;              // 매출파일의 목록 개수
	int t_count;            // t_data의 목록 개수

	void SetTdata(CString, CString);     // t_data 셋팅
	void ReadSalesFile();                // 매출파일 읽기
	void WriteSalesFile();               // 매출파일 쓰기
	void InitTdata();                    // t_data 초기화
	int startpos(int, int);              // 매출파일과 날짜를 비교후 같은 부분의 매출파일 인덱스 반환
	int AddDate();                       // 날짜 얻어오기
	int SearchFile();                    // s_data의 날짜와 오늘 날짜가 같으면 인덱스 반환
	void ChangeSales();                  // 계산 후 매출파일 수정
};