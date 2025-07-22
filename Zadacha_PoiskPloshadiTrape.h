#pragma once
using namespace System;

class ChetirioxUgolnik
{
public:
    ChetirioxUgolnik();
    ~ChetirioxUgolnik();

    virtual String^ Получить_Условие() const;
    virtual void set_Zadacha(int левая_сторона, int правая_сторона, int нижняя_сторона, int верхняя_сторона, int p_Nomer_zdachi_Poshechetu); //// Думать


    void SetNomer_Zadachi_Poshchetu(int p_Nomer_Zadachi_Poshchetu);
    void SetПериметр(int);
    void SetPloshad(int);
    void SetVisota(int);
    void SetДлины_Сторон(int, int, int, int);

    int GetДлины_Сторон(int index) const;
    int GetNomer_Zadachi_Poshchetu() const;
    int GetPloshad() const;
    int GetVisota() const;



    virtual bool Proverka_otveta_Usera(int p_User_otvet) const;
    virtual int GetОтвет() const;
    virtual String^ GetФормула() const;


private:
    int Периметр;
    int Nomer_Zadachi_Poshchetu;
    int* Длины_Сторон; /// Придумать как заполнить
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

    //// Ответ

    //// Ответ
    int GetOsnovanie_Verhnie() const
    {
        return Osnovanie_Verhnie;
    }
    int GetOsnovanie_Nizhnee() const
    {
        return Osnovanie_Nizhnee;
    }

    int GetОтвет() const;

    void set_Zadacha(int p_osnon_verh, int p_osnov_niz, int p_visota, int _, int p_Nomer_zdachi_Poshechetu);

    bool Proverka_otveta_Usera(int p_User_otvet) const
    {
        return ((p_User_otvet == GetPloshad()) ? true : false);
    }

    String^ Получить_Условие() const;
    String^ GetФормула() const;

private:
    int Osnovanie_Verhnie;
    int Osnovanie_Nizhnee;





    ///int* Colichestvo_Nereshennix_Zadach;
    ///bool Zadacha_Reshena = false; //// Если захочу вывести условие неправельно решонных задач
    /// 
    /// Имеет хотя бы две параллельные стороны.
};




class Priamougolnik : public ChetirioxUgolnik
{
public:
    Priamougolnik();
    ~Priamougolnik();

    String^ Получить_Условие() const;
    void set_Zadacha(int нижняя_сторона0, int верхняя_сторона0, int нижняя_сторона1, int верхняя_сторона1, int p_Nomer_zdachi_Poshechetu);

    bool Proverka_otveta_Usera(int p_User_otvet) const;
    int GetОтвет() const;
    String^ GetФормула() const;
private:

    //Углы прямые (все равны 90 градусов).
};


class Kvadrat : public Priamougolnik
{
public:
    Kvadrat();
    ~Kvadrat();


    String^ Получить_Условие() const;
    String^ GetФормула() const;
    void set_Zadacha(int, int, int, int, int p_Nomer_zdachi_Poshechetu);
private:
    //Все стороны равны между собой.
};