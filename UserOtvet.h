#pragma once

class UserOtvet
{
public:

    UserOtvet() {}
    UserOtvet(int p_Otvet) : Otvet(p_Otvet) {}
    ~UserOtvet()
    {

    }

    int GetOtvet() const
    {
        return Otvet;
    }
    int GetColichestvo_Nepravelnix_Otvetov_V_Ramkax_Dannoi_Zadache() const
    {
        return Colichestvo_Nepravelnix_Otvetov_V_Ramkax_Dannoi_Zadache;
    }
    static int GetCol_praevlnix()
    {
        return Col_praevlnix;
    }
    static int GetCol_NEpraevlnix()
    {
        return Col_NEpraevlnix;
    }
    static int GetCol_pravelnix_Otvetov()
    {
        return Col_pravelnix_Otvetov;
    }

    void SetOtvet(int p_User_otvet)
    {
        Otvet = p_User_otvet;
    }
    static void SetCol_praevlnix(int p_Col_praevlnix)
    {
        Col_praevlnix = p_Col_praevlnix;
    }
    static void SetCol_NEpraevlnix(int p_Col_NEpraevlnix)
    {
        Col_NEpraevlnix = p_Col_NEpraevlnix;
    }
    static void SetCol_pravelnix_Otvetov(int p_Col_pravelnix_Otvetov)
    {
        Col_pravelnix_Otvetov = p_Col_pravelnix_Otvetov;
    }

    static void PlusOneCol_pravelnix_Otvetov()
    {
        ++Col_pravelnix_Otvetov; ///+1
    }
    static void PlusOne_Col_praevlnix()
    {
        ++Col_praevlnix; ///+1
    }

    static void PlusOne_Col_NEpraevlnix() /// ����� ���������� ������������ �������
    {
        ++Col_NEpraevlnix; ///+1
    }
    void PlusOne_Colichestvo_Nepravelnix_Otvetov_V_Ramkax_Dannoi_Zadache() // ��� ��������� (�� ����������� ������ ��� �������� ���� �������): �� ������ ������ ������ ������� �������, ������� ������ ����� ���������� �� ��������
    {
        ++Colichestvo_Nepravelnix_Otvetov_V_Ramkax_Dannoi_Zadache; ///+1
        UserOtvet::PlusOne_Col_NEpraevlnix();
    }

private:
    static int Col_praevlnix; /// � ������ �������
    static int Col_NEpraevlnix;
    static int Col_pravelnix_Otvetov; /// ����� ����������

    int Otvet; /// ����� ������� �������� (���������� ��� ������ � ������ ������) �������� "3"
    int Colichestvo_Nepravelnix_Otvetov_V_Ramkax_Dannoi_Zadache = 0;
};
