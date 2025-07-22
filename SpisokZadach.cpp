#include "SpisokZadach.h" //////////////////////////////////////////////////////////////////// ��������


SpisokZadach* �������_������() {
	SpisokZadach* t = new SpisokZadach;

	int ���������_����� = rand() % 101;

	if (���������_����� >= 0 && ���������_����� < 25) { // 0 - 24
		t->data = new Zadacha_PoiskPloshadiTrape;
	}
	else if (���������_����� >= 25 && ���������_����� <= 49) { // 25 - 49
		t->data = new ChetirioxUgolnik;
	}
	else if (���������_����� >= 50 && ���������_����� <= 74) { // 50 - 74
		t->data = new Priamougolnik;
	}
	else if (���������_����� >= 75 && ���������_����� <= 99) { // 75 - 99
		t->data = new Kvadrat;
	}

	return t;
}

SpisokZadach* begin;
SpisokZadach* end;
SpisokZadach* t;

SpisokZadach::SpisokZadach()
{
}

SpisokZadach::~SpisokZadach()
{
}

SpisokZadach::SpisokZadach(SpisokZadach** b, SpisokZadach** e)
{
	int NomerZadachi = 1;

	srand(time(0));
	t = �������_������();

	t->data->set_Zadacha(1 + rand() % (5 - 1 + 1), 6 + rand() % (15 - 6 + 1), 4 + rand() % (12 - 4 + 1), 4 + rand() % (12 - 4 + 1), NomerZadachi);
	//
	t->next = t->prev = nullptr;
	*b = *e = t;
}

void SpisokZadach::Add_Spis2(int i)
{
	int NomerZadachi = i + 1;
	t = �������_������();

	t->data->set_Zadacha(1 + rand() % (5 - 1 + 1), 6 + rand() % (15 - 6 + 1), 4 + rand() % (12 - 4 + 1), 4 + rand() % (12 - 4 + 1), NomerZadachi);  /// int p_osnon_verh, int p_osnov_niz, int p_visota, int p_Nomer_zdachi_Poshechetu
	//
	t->SetNext(nullptr);
	t->SetPrev(end);
	end->SetNext(t);
	end = t;
}

void SpisokZadach::Del_All(SpisokZadach** p)
{
	while (*p != nullptr) {
		t = *p;
		*p = (*p)->next;
		t->~SpisokZadach();

	}
}

SpisokZadach* SpisokZadach::GetNext()
{
	return next;
}

SpisokZadach* SpisokZadach::GetPrev()

{
	return prev;
}

ChetirioxUgolnik* SpisokZadach::GetZadacha_poIndexu(int p_i)
{
	t = begin;
	for (int i = 0; i < p_i; i++)
	{
		t = t->next;
	}
	return t->data;
}

void SpisokZadach::SetNext(SpisokZadach* b)
{
	next = b;
}

void SpisokZadach::SetPrev(SpisokZadach* b)
{
	prev = b;
}
