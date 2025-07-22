#include "Zadacha_PoiskPloshadiTrape.h"


ChetirioxUgolnik::ChetirioxUgolnik()
{
}

ChetirioxUgolnik::~ChetirioxUgolnik()
{
	delete[] Длины_Сторон;
}

String^ ChetirioxUgolnik::Получить_Условие() const
{
	String^ str = "Задача №" + this->GetNomer_Zadachi_Poshchetu() + "\nЧетырехугольник имеет стороны равные,\n " + this->GetДлины_Сторон(0) + ", " + this->GetДлины_Сторон(1) + ", " + this->GetДлины_Сторон(2) + ", " + this->GetДлины_Сторон(3) + ".\nНайдите периметр данного четырехугольника.";
	return str;
}

void ChetirioxUgolnik::set_Zadacha(int левая_сторона, int правая_сторона, int нижняя_сторона, int верхняя_сторона, int p_Nomer_zdachi_Poshechetu)
{
	SetДлины_Сторон(левая_сторона, правая_сторона, нижняя_сторона, верхняя_сторона);
	SetПериметр(левая_сторона + правая_сторона + нижняя_сторона + верхняя_сторона);
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

void ChetirioxUgolnik::SetПериметр(int p_Периметр)
{
	Периметр = p_Периметр;
}

void ChetirioxUgolnik::SetPloshad(int p_Ploshad)
{
	Ploshad = p_Ploshad;
}

void ChetirioxUgolnik::SetVisota(int p_Visota)
{
	Visota = p_Visota;
}

void ChetirioxUgolnik::SetДлины_Сторон(int левая_сторона, int правая_сторона, int нижняя_сторона, int верхняя_сторона)
{
	Длины_Сторон = new int[4];
	Длины_Сторон[0] = левая_сторона;
	Длины_Сторон[1] = правая_сторона;
	Длины_Сторон[2] = нижняя_сторона;
	Длины_Сторон[3] = верхняя_сторона;
}

bool ChetirioxUgolnik::Proverka_otveta_Usera(int p_User_otvet) const
{
	return ((p_User_otvet == Периметр) ? true : false);
}

int ChetirioxUgolnik::GetОтвет() const
{
	return Периметр;
}

String^ ChetirioxUgolnik::GetФормула() const
{
	return "P = a + b + c + d";
}

void ChetirioxUgolnik::SetNomer_Zadachi_Poshchetu(int p_Nomer_Zadachi_Poshchetu)
{
	Nomer_Zadachi_Poshchetu = p_Nomer_Zadachi_Poshchetu;
}

int ChetirioxUgolnik::GetДлины_Сторон(int index) const
{
	return Длины_Сторон[index];
}

Zadacha_PoiskPloshadiTrape::Zadacha_PoiskPloshadiTrape(int p_osnon_verh, int p_osnov_niz, int p_visota, int p_ploshad_trap, int p_Nomer_zdachi_Poshechetu)
{
	Osnovanie_Nizhnee = p_osnov_niz;
	Osnovanie_Verhnie = p_osnon_verh;
	SetVisota(p_visota);
	SetPloshad(p_ploshad_trap);
	SetNomer_Zadachi_Poshchetu(p_Nomer_zdachi_Poshechetu);
}

int Zadacha_PoiskPloshadiTrape::GetОтвет() const
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

String^ Zadacha_PoiskPloshadiTrape::Получить_Условие() const
{
	String^ str = "Задача №" + this->GetNomer_Zadachi_Poshchetu() + "\nТрапеция имеет основания равные,\na = " + this->GetOsnovanie_Nizhnee() + " и b = " + this->GetOsnovanie_Verhnie() + " соответственно. \nВысоту равную h = " + this->GetVisota() + ".\nНайдите площадь данной трапеции.";
	return str;
}

String^ Zadacha_PoiskPloshadiTrape::GetФормула() const
{
	return "S = (a+b)/2*h";
}

Priamougolnik::Priamougolnik()
{
}

Priamougolnik::~Priamougolnik()
{
}

String^ Priamougolnik::Получить_Условие() const
{
	/// GetДлины_Сторон(1) - ПОМНИ! высота четные
	String^ str = "Задача №" + this->GetNomer_Zadachi_Poshchetu() + "\nПрямоугольник имеет стороны равные,\na = " + this->GetДлины_Сторон(1) + " и b = " + this->GetVisota() + ".\nНайдите площадь данного прямоугольника.";
	return str;
}

void Priamougolnik::set_Zadacha(int нижняя_сторона0, int верхняя_сторона0, int нижняя_сторона1, int верхняя_сторона1, int p_Nomer_zdachi_Poshechetu)
{
	if ((нижняя_сторона0 == верхняя_сторона0) ? верхняя_сторона0++ : false);
	SetДлины_Сторон(нижняя_сторона0, верхняя_сторона0, нижняя_сторона0, верхняя_сторона0);
	SetVisota(нижняя_сторона0);
	SetПериметр(нижняя_сторона0 + верхняя_сторона0 + нижняя_сторона1 + верхняя_сторона1);
	SetPloshad(GetVisota() * верхняя_сторона0);
	SetNomer_Zadachi_Poshchetu(p_Nomer_zdachi_Poshechetu);
}

bool Priamougolnik::Proverka_otveta_Usera(int p_User_otvet) const
{
	return ((p_User_otvet == GetPloshad()) ? true : false);
}

int Priamougolnik::GetОтвет() const
{
	return GetPloshad();
}

String^ Priamougolnik::GetФормула() const
{
	return "S = a * b";
}

Kvadrat::Kvadrat()
{
}

Kvadrat::~Kvadrat()
{
}

String^ Kvadrat::Получить_Условие() const
{
	String^ str = "Задача №" + this->GetNomer_Zadachi_Poshchetu() + "\nСторона квадрата равна a = " + this->GetVisota() + ".\nНайдите площадь данного квадрата.";
	return str;
}

String^ Kvadrat::GetФормула() const
{
	return "S = a * a";
}

void Kvadrat::set_Zadacha(int Длина_Стороны, int _0, int _1, int _2, int p_Nomer_zdachi_Poshechetu)
{
	SetДлины_Сторон(Длина_Стороны, Длина_Стороны, Длина_Стороны, Длина_Стороны);
	SetVisota(Длина_Стороны);
	SetПериметр(Длина_Стороны + Длина_Стороны + Длина_Стороны + Длина_Стороны);
	SetPloshad(GetVisota() * Длина_Стороны);
	SetNomer_Zadachi_Poshchetu(p_Nomer_zdachi_Poshechetu);
}

