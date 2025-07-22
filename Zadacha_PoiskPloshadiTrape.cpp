#include "Zadacha_PoiskPloshadiTrape.h"


ChetirioxUgolnik::ChetirioxUgolnik()
{
}

ChetirioxUgolnik::~ChetirioxUgolnik()
{
	delete[] �����_������;
}

String^ ChetirioxUgolnik::��������_�������() const
{
	String^ str = "������ �" + this->GetNomer_Zadachi_Poshchetu() + "\n��������������� ����� ������� ������,\n " + this->Get�����_������(0) + ", " + this->Get�����_������(1) + ", " + this->Get�����_������(2) + ", " + this->Get�����_������(3) + ".\n������� �������� ������� ����������������.";
	return str;
}

void ChetirioxUgolnik::set_Zadacha(int �����_�������, int ������_�������, int ������_�������, int �������_�������, int p_Nomer_zdachi_Poshechetu)
{
	Set�����_������(�����_�������, ������_�������, ������_�������, �������_�������);
	Set��������(�����_������� + ������_������� + ������_������� + �������_�������);
	SetNomer_Zadachi_Poshchetu(p_Nomer_zdachi_Poshechetu);
}

int ChetirioxUgolnik::GetNomer_Zadachi_Poshchetu() const
{
	return Nomer_Zadachi_Poshchetu;
}

int ChetirioxUgolnik::GetPloshad() const
{
	return Ploshad;
}

int ChetirioxUgolnik::GetVisota() const
{
	return Visota;
}

void ChetirioxUgolnik::Set��������(int p_��������)
{
	�������� = p_��������;
}

void ChetirioxUgolnik::SetPloshad(int p_Ploshad)
{
	Ploshad = p_Ploshad;
}

void ChetirioxUgolnik::SetVisota(int p_Visota)
{
	Visota = p_Visota;
}

void ChetirioxUgolnik::Set�����_������(int �����_�������, int ������_�������, int ������_�������, int �������_�������)
{
	�����_������ = new int[4];
	�����_������[0] = �����_�������;
	�����_������[1] = ������_�������;
	�����_������[2] = ������_�������;
	�����_������[3] = �������_�������;
}

bool ChetirioxUgolnik::Proverka_otveta_Usera(int p_User_otvet) const
{
	return ((p_User_otvet == ��������) ? true : false);
}

int ChetirioxUgolnik::Get�����() const
{
	return ��������;
}

String^ ChetirioxUgolnik::Get�������() const
{
	return "P = a + b + c + d";
}

void ChetirioxUgolnik::SetNomer_Zadachi_Poshchetu(int p_Nomer_Zadachi_Poshchetu)
{
	Nomer_Zadachi_Poshchetu = p_Nomer_Zadachi_Poshchetu;
}

int ChetirioxUgolnik::Get�����_������(int index) const
{
	return �����_������[index];
}

Zadacha_PoiskPloshadiTrape::Zadacha_PoiskPloshadiTrape(int p_osnon_verh, int p_osnov_niz, int p_visota, int p_ploshad_trap, int p_Nomer_zdachi_Poshechetu)
{
	Osnovanie_Nizhnee = p_osnov_niz;
	Osnovanie_Verhnie = p_osnon_verh;
	SetVisota(p_visota);
	SetPloshad(p_ploshad_trap);
	SetNomer_Zadachi_Poshchetu(p_Nomer_zdachi_Poshechetu);
}

int Zadacha_PoiskPloshadiTrape::Get�����() const
{
	return GetPloshad();
}

void Zadacha_PoiskPloshadiTrape::set_Zadacha(int p_osnon_verh, int p_osnov_niz, int p_visota, int _, int p_Nomer_zdachi_Poshechetu)
{
	Osnovanie_Verhnie = p_osnon_verh * 2;
	Osnovanie_Nizhnee = p_osnov_niz * 2;
	SetVisota(p_visota);
	SetPloshad((Osnovanie_Verhnie + Osnovanie_Nizhnee) / 2 * GetVisota());

	SetNomer_Zadachi_Poshchetu(p_Nomer_zdachi_Poshechetu);
}

String^ Zadacha_PoiskPloshadiTrape::��������_�������() const
{
	String^ str = "������ �" + this->GetNomer_Zadachi_Poshchetu() + "\n�������� ����� ��������� ������,\na = " + this->GetOsnovanie_Nizhnee() + " � b = " + this->GetOsnovanie_Verhnie() + " ��������������. \n������ ������ h = " + this->GetVisota() + ".\n������� ������� ������ ��������.";
	return str;
}

String^ Zadacha_PoiskPloshadiTrape::Get�������() const
{
	return "S = (a+b)/2*h";
}

Priamougolnik::Priamougolnik()
{
}

Priamougolnik::~Priamougolnik()
{
}

String^ Priamougolnik::��������_�������() const
{
	/// Get�����_������(1) - �����! ������ ������
	String^ str = "������ �" + this->GetNomer_Zadachi_Poshchetu() + "\n������������� ����� ������� ������,\na = " + this->Get�����_������(1) + " � b = " + this->GetVisota() + ".\n������� ������� ������� ��������������.";
	return str;
}

void Priamougolnik::set_Zadacha(int ������_�������0, int �������_�������0, int ������_�������1, int �������_�������1, int p_Nomer_zdachi_Poshechetu)
{
	if ((������_�������0 == �������_�������0) ? �������_�������0++ : false);
	Set�����_������(������_�������0, �������_�������0, ������_�������0, �������_�������0);
	SetVisota(������_�������0);
	Set��������(������_�������0 + �������_�������0 + ������_�������1 + �������_�������1);
	SetPloshad(GetVisota() * �������_�������0);
	SetNomer_Zadachi_Poshchetu(p_Nomer_zdachi_Poshechetu);
}

bool Priamougolnik::Proverka_otveta_Usera(int p_User_otvet) const
{
	return ((p_User_otvet == GetPloshad()) ? true : false);
}

int Priamougolnik::Get�����() const
{
	return GetPloshad();
}

String^ Priamougolnik::Get�������() const
{
	return "S = a * b";
}

Kvadrat::Kvadrat()
{
}

Kvadrat::~Kvadrat()
{
}

String^ Kvadrat::��������_�������() const
{
	String^ str = "������ �" + this->GetNomer_Zadachi_Poshchetu() + "\n������� �������� ����� a = " + this->GetVisota() + ".\n������� ������� ������� ��������.";
	return str;
}

String^ Kvadrat::Get�������() const
{
	return "S = a * a";
}

void Kvadrat::set_Zadacha(int �����_�������, int _0, int _1, int _2, int p_Nomer_zdachi_Poshechetu)
{
	Set�����_������(�����_�������, �����_�������, �����_�������, �����_�������);
	SetVisota(�����_�������);
	Set��������(�����_������� + �����_������� + �����_������� + �����_�������);
	SetPloshad(GetVisota() * �����_�������);
	SetNomer_Zadachi_Poshchetu(p_Nomer_zdachi_Poshechetu);
}

