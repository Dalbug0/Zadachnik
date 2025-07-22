#include "MyForm.h"



using namespace System;
using namespace System::Windows::Forms;

static int NomerZadachi; //// ������ ������ ��������� ������ � �������
static int Colichestvo_Zadach;

int UserOtvet::Col_NEpraevlnix = 0;
int UserOtvet::Col_praevlnix = 0;
int UserOtvet::Col_pravelnix_Otvetov = 0;

bool Otchet, Zadacha; /// ���������������� � ������ ������
bool Main_Display = true; //// ������������� ������ 44

UserOtvet* Otvet = nullptr; ////  �������� � �������� ������������, ������������ � ������ ����� �����
//Zadacha_PoiskPloshadiTrape* Nabor_Zadach = nullptr; /// = nullptr �� ������ ���� ��������� ����� ������� �� ���� ��� ����� ��������� ������

[STAThreadAttribute]
int main(array<String^>^ args) {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	Shablon::MyForm form;
	Application::Run(% form);
}

Shablon::MyForm::~MyForm()
{
	///���� ������ ��� Nabor_Zadach �� ���� ��������, �� Nabor_Zadach ��������� nullptr, � �������� delete[] �� ����� ������.
	/*if (Nabor_Zadach != nullptr)
	{
		delete[] Nabor_Zadach;
		Nabor_Zadach = nullptr; /// = nullptr, ����� �������� �������� ���������(������ �� ������� �� ��������� ���������, �� ��������� �� ��� ����� �������)
	}*/
	if (begin)
	{
		begin->Del_All(&begin);
		begin = end = nullptr;
	}

	if (Otvet != nullptr)
	{
		delete[] Otvet;
		Otvet = nullptr; /// = nullptr, ����� �������� �������� ��������� (������ �� ������� �� ��������� ���������, �� ��������� �� ��� ����� �������)
	}

	if (components)
	{
		delete components;
	}
}

/// ������ ����������� ������ �� p_Colichestvo_Zadach ��������� ���������� ���������������� ��������
void Shablon::MyForm::CreateSpisokNaNZadach(int p_Colichestvo_Zadach)
{
	//Create_Zadacha_PoiskPloshadiTrape(Colichestvo_Zadach);
	Create_UserOtvet(Colichestvo_Zadach);

	SpisokZadach(&begin, &end);
	for (int i = 1; i < p_Colichestvo_Zadach; i++)
	{
		end->Add_Spis2(i);
	}
}

//void Shablon::MyForm::Create_Zadacha_PoiskPloshadiTrape(int p_dlina_massiva)
//
//{
//	/// ����� �������� � ���������� ������� ������
//	Nabor_Zadach = new Zadacha_PoiskPloshadiTrape[p_dlina_massiva];
//}

void Shablon::MyForm::Print_Interfeise_s_Usloviem_Zadachi()

{
	ChetirioxUgolnik* A = begin->GetZadacha_poIndexu(NomerZadachi); /// (���������) ��������� �� ������� �����
	label_main->Text = A->��������_�������();
	//label_main->Text = "������ �" + A->GetNomer_Zadachi_Poshchetu() + "\n�������� ����� ��������� ������,\na = " + A->GetOsnovanie_Nizhnee() + " � b = " + A->GetOsnovanie_Verhnie() + " ��������������. \n������ ������ h = " + A->GetVisota() + ".\n������� ������� ������ ��������.";
	button_main->Text = "��������� �����";
	textBox_DlaOtvetaUsera->Text = "������� ����� ���� ";
	button_main->Enabled = false;
}

void Shablon::MyForm::ProverkaPereiti_na_Otchet_ili_print_next_uslovie(int p_dlina_massiva)

{
	if (NomerZadachi != p_dlina_massiva) ///// ��������� ������� ���������� 5 �� ������� � �������
	{
		Print_Interfeise_s_Usloviem_Zadachi();
	}
	else
	{
		Zadacha = false;
		Otchet = true;
		button_main->Enabled = true;

		textBox_DlaOtvetaUsera->Text = "������� ���������� �����\n������� �� ������ ������.";
		textBox_DlaOtvetaUsera->Visible = false;

		button1->Visible = true;

		TYJ = "�����:\n����� �����: " + Colichestvo_Zadach + "\n���������� ����� �������� � ������ �������: " + UserOtvet::GetCol_praevlnix() + "\n���������� �������� �����: " + UserOtvet::GetCol_pravelnix_Otvetov() + "\n����� ���������� ������������ �������: " + UserOtvet::GetCol_NEpraevlnix(); button_main->Text = "�������� � ����"; /// ��� �����(��� ���� �������) �������� "6" ����� ����� ���������� ����� ��������
		label_main->Text = TYJ;

	}
}

void Shablon::MyForm::Create_UserOtvet(int p_dlina_massiva)

{
	/// ����� �������� � ���������� ������� ������
	Otvet = new UserOtvet[p_dlina_massiva];
}

int Shablon::MyForm::Poluchit_Znachenie_textBox()

{
	try /// ��� ������� ����� ������� ������
	{
		int a = Convert::ToInt64(textBox_DlaOtvetaUsera->Text);
		if ((a < 1) && (Main_Display)) /// ����������� ������\���������� � ������ ���� ���������
		{
			throw 0; /// �������� ������� ��� �������� ���������� (� ������ ���������), ����������� �������� int
		}
		return a;
	}
	catch (int) /// ����������� � ����������� ���� ������������� �������� throw
	{
		MessageBox::Show("�� ����� ���� ������ 1", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return 0; ///  0 <=> false
	}
	catch (...) /// ��������� ��� ����� �� ������������ �����������
	{
		MessageBox::Show("������, ������� ������������ �������", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return 0; ///  0 <=> false
	}
}

void Shablon::MyForm::��������_�����()
{
	UserOtvet::SetCol_NEpraevlnix(0);
	UserOtvet::SetCol_praevlnix(0);
	UserOtvet::SetCol_pravelnix_Otvetov(0);
}

String^ Shablon::MyForm::�������_�������_���_�������(ChetirioxUgolnik* p_t)
{
	///// � ������� ����� ���������� ������ ������� ��� 
	return p_t->Get�������();
}

System::Void Shablon::MyForm::button_main_Click(System::Object^ sender, System::EventArgs^ e)
{
	button_main->Enabled = false;

	//// O����, ������, ��������� �����
	if (Main_Display)
	{
		/// �������� �������� ������ � textBox_DlaOtvetaUsera
		int colZadach_������������ = Poluchit_Znachenie_textBox();
		if (colZadach_������������)
		{

			button2->Visible = false;
			button3->Visible = false;
			Colichestvo_Zadach = colZadach_������������;
			//// ��������� � �������� ������
			CreateSpisokNaNZadach(Colichestvo_Zadach);
			/*
			////

			Create_Zadacha_PoiskPloshadiTrape(Colichestvo_Zadach);
			Create_UserOtvet(Colichestvo_Zadach);


			srand(time(0)); // ���������� ������� ����� � �������� ���������� ��������
			for (int i = 0; i < Colichestvo_Zadach; i++)
			{
				Nabor_Zadach[i].set_Zadacha(1 + rand() % (5 - 1 + 1), 6 + rand() % (15 - 6 + 1), 4 + rand() % (12 - 4 + 1), i + 1);  /// int p_osnon_verh, int p_osnov_niz, int p_visota, int p_Nomer_zdachi_Poshechetu
			}

			////
			*/
			NomerZadachi = 0;



			label_main->ForeColor = System::Drawing::SystemColors::Control;
			Print_Interfeise_s_Usloviem_Zadachi(); /// ����� �� �����������


			///
			Main_Display = false;
			Zadacha = true;
			///// ����������� ������������ �� ������ ��� this button
		}
		else
		{
			textBox_DlaOtvetaUsera->Text = L"������� ���������� �����\r\n������� �� ������ ������.";
		}


	}
	else if (Zadacha)
	{
		if (Poluchit_Znachenie_textBox())
		{
			Otvet[NomerZadachi].SetOtvet(Convert::ToInt64(textBox_DlaOtvetaUsera->Text)); /// C����� ����� user

			if (begin->GetZadacha_poIndexu(NomerZadachi)->Proverka_otveta_Usera(Otvet[NomerZadachi].GetOtvet())) /// O���� ������
			{
				UserOtvet::PlusOneCol_pravelnix_Otvetov();
				if (Otvet[NomerZadachi].GetColichestvo_Nepravelnix_Otvetov_V_Ramkax_Dannoi_Zadache() == 0)
				{
					Otvet[NomerZadachi].PlusOne_Col_praevlnix();
				}

				MessageBox::Show("��� �������! �� ���� ���������� �����.", "���������", MessageBoxButtons::OK, MessageBoxIcon::Information);

				++NomerZadachi;
				ProverkaPereiti_na_Otchet_ili_print_next_uslovie(Colichestvo_Zadach);
			}
			else  /// ����� �� ������
			{
				Otvet[NomerZadachi].PlusOne_Colichestvo_Nepravelnix_Otvetov_V_Ramkax_Dannoi_Zadache();
				if (Otvet[NomerZadachi].GetColichestvo_Nepravelnix_Otvetov_V_Ramkax_Dannoi_Zadache() != 3) /// 3 ������������ ������� �� ���� ������
				{
					if ((Otvet[NomerZadachi].GetColichestvo_Nepravelnix_Otvetov_V_Ramkax_Dannoi_Zadache() != 2)) // �� ��������� ������� ����� ��������� �� �������
					{
						MessageBox::Show("����� ��������. � ��� �������� " + (3 - Otvet[NomerZadachi].GetColichestvo_Nepravelnix_Otvetov_V_Ramkax_Dannoi_Zadache()) + " �������.", "���������", MessageBoxButtons::OK, MessageBoxIcon::Warning);
					}
					else
					{
						///MessageBox::Show(, "���������", MessageBoxButtons::OK, MessageBoxIcon::Warning);
						MessageBox::Show("����� ��������. � ��� �������� " + (3 - Otvet[NomerZadachi].GetColichestvo_Nepravelnix_Otvetov_V_Ramkax_Dannoi_Zadache()) + " �������.\n" + �������_�������_���_�������(begin->GetZadacha_poIndexu(NomerZadachi)), "���������", MessageBoxButtons::OK, MessageBoxIcon::Warning);
					}

				}
				else /// 3 ������ � ����� ������
				{
					MessageBox::Show("����� ��������. ���������� ����� = " + begin->GetZadacha_poIndexu(NomerZadachi)->Get�����(), "���������", MessageBoxButtons::OK, MessageBoxIcon::Warning);

					++NomerZadachi;
					ProverkaPereiti_na_Otchet_ili_print_next_uslovie(Colichestvo_Zadach);

				}

			}
		}
		else
		{
			Print_Interfeise_s_Usloviem_Zadachi();
		}
	}
	else if (Otchet)
	{
		Main_Display = true;
		Otchet = false;

		button1->Visible = false;
		button2->Visible = true;
		button3->Visible = true;
		textBox_DlaOtvetaUsera->Visible = true;


		button1->Enabled = true;

		button_main->Text = "������";
		/*label_main->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(254)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
			static_cast<System::Int32>(static_cast<System::Byte>(46)));*/
		label_main->Text = L"��� ���� ��� �� ������:\r\n  *  �������, � ������ ����, ���������� �����\r\n      ���"
			L"���� �� ������ ������.\r\n  *  ������� \"������\"\r\n";

		��������_�����();



		/*if (Nabor_Zadach != nullptr)
		{
			delete[] Nabor_Zadach;
			Nabor_Zadach = nullptr; /// = nullptr, ����� �������� �������� ���������(������ �� ������� �� ��������� ���������, �� ��������� �� ��� ����� �������)
		}*/

		/// �� ������ ������
		if (begin)
		{
			begin->Del_All(&begin);
			begin = end = nullptr;
		}
		if (Otvet != nullptr)
		{
			delete[] Otvet;
			Otvet = nullptr; /// = nullptr, ����� �������� �������� ��������� (������ �� ������� �� ��������� ���������, �� ��������� �� ��� ����� �������)
		}


		/// label_main
	}

}

System::Void Shablon::MyForm::textBox_DlaOtvetaUsera_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	if (textBox_DlaOtvetaUsera->Text != "")
	{
		button_main->Enabled = true;
	}
	else
	{
		button_main->Enabled = false;
	}
}
