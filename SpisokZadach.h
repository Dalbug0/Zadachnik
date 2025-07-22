#pragma once
#include <cstdlib>
#include <ctime>
#include "Zadacha_PoiskPloshadiTrape.h"



class SpisokZadach
{
private:
	SpisokZadach* next, * prev;
	ChetirioxUgolnik* data; /// (���������) ��������� �� ������� �����
public:
	SpisokZadach();
	~SpisokZadach();
	/// ��������� ���� ��� Zadacha_PoiskPloshadiTrape
	SpisokZadach(SpisokZadach** b, SpisokZadach** e);
	void Add_Spis2(int i);

	/// 
	void Del_All(SpisokZadach** p);
	SpisokZadach* GetNext();
	SpisokZadach* GetPrev();
	ChetirioxUgolnik* GetZadacha_poIndexu(int p_i); /// ���������� ��������� �� ������ �� ������ � ������

	void SetNext(SpisokZadach* b);
	void SetPrev(SpisokZadach* b);

	friend SpisokZadach* �������_������();
}extern* begin, * end, * t;
