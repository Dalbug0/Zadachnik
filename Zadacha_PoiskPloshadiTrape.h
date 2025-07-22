#pragma once
using namespace System;

class ChetirioxUgolnik
{
public:
    ChetirioxUgolnik();
    ~ChetirioxUgolnik();

    virtual String^ ��������_�������() const;
    virtual void set_Zadacha(int �����_�������, int ������_�������, int ������_�������, int �������_�������, int p_Nomer_zdachi_Poshechetu); //// ������


    void SetNomer_Zadachi_Poshchetu(int p_Nomer_Zadachi_Poshchetu);
    void Set��������(int);
    void SetPloshad(int);
    void SetVisota(int);
    void Set�����_������(int, int, int, int);

    int Get�����_������(int index) const;
    int GetNomer_Zadachi_Poshchetu() const;
    int GetPloshad() const;
    int GetVisota() const;



    virtual bool Proverka_otveta_Usera(int p_User_otvet) const;
    virtual int Get�����() const;
    virtual String^ Get�������() const;


private:
    int ��������;
    int Nomer_Zadachi_Poshchetu;
    int* �����_������; /// ��������� ��� ���������
    int Ploshad;
    int Visota;
};

class Zadacha_PoiskPloshadiTrape : public ChetirioxUgolnik
{
public:
    Zadacha_PoiskPloshadiTrape(int p_osnon_verh, int p_osnov_niz, int p_visota, int p_ploshad_trap, int p_Nomer_zdachi_Poshechetu);
    Zadacha_PoiskPloshadiTrape() {}

    ~Zadacha_PoiskPloshadiTrape()
    {
        ///delete Colichestvo_Nereshennix_Zadach;
    }

    //// �����

    //// �����
    int GetOsnovanie_Verhnie() const
    {
        return Osnovanie_Verhnie;
    }
    int GetOsnovanie_Nizhnee() const
    {
        return Osnovanie_Nizhnee;
    }

    int Get�����() const;

    void set_Zadacha(int p_osnon_verh, int p_osnov_niz, int p_visota, int _, int p_Nomer_zdachi_Poshechetu);

    bool Proverka_otveta_Usera(int p_User_otvet) const
    {
        return ((p_User_otvet == GetPloshad()) ? true : false);
    }

    String^ ��������_�������() const;
    String^ Get�������() const;

private:
    int Osnovanie_Verhnie;
    int Osnovanie_Nizhnee;





    ///int* Colichestvo_Nereshennix_Zadach;
    ///bool Zadacha_Reshena = false; //// ���� ������ ������� ������� ����������� �������� �����
    /// 
    /// ����� ���� �� ��� ������������ �������.
};




class Priamougolnik : public ChetirioxUgolnik
{
public:
    Priamougolnik();
    ~Priamougolnik();

    String^ ��������_�������() const;
    void set_Zadacha(int ������_�������0, int �������_�������0, int ������_�������1, int �������_�������1, int p_Nomer_zdachi_Poshechetu);

    bool Proverka_otveta_Usera(int p_User_otvet) const;
    int Get�����() const;
    String^ Get�������() const;
private:

    //���� ������ (��� ����� 90 ��������).
};


class Kvadrat : public Priamougolnik
{
public:
    Kvadrat();
    ~Kvadrat();


    String^ ��������_�������() const;
    String^ Get�������() const;
    void set_Zadacha(int, int, int, int, int p_Nomer_zdachi_Poshechetu);
private:
    //��� ������� ����� ����� �����.
};