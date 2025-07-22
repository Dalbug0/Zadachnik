#include "MyForm.h"



using namespace System;
using namespace System::Windows::Forms;

static int NomerZadachi; //// Помнит индекс следующей задачи в массиве
static int Colichestvo_Zadach;

int UserOtvet::Col_NEpraevlnix = 0;
int UserOtvet::Col_praevlnix = 0;
int UserOtvet::Col_pravelnix_Otvetov = 0;

bool Otchet, Zadacha; /// Инициализировать в первой кнопку
bool Main_Display = true; //// инициализация строка 44

UserOtvet* Otvet = nullptr; ////  Работает с ответами пользователя, поучавствует в отчете после задач
//Zadacha_PoiskPloshadiTrape* Nabor_Zadach = nullptr; /// = nullptr на случай если программа будет закрыта до того как будет выделенна память

[STAThreadAttribute]
int main(array<String^>^ args) {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	Shablon::MyForm form;
	Application::Run(% form);
}

Shablon::MyForm::~MyForm()
{
	///если память для Nabor_Zadach не была выделена, то Nabor_Zadach останется nullptr, и оператор delete[] не будет вызван.
	/*if (Nabor_Zadach != nullptr)
	{
		delete[] Nabor_Zadach;
		Nabor_Zadach = nullptr; /// = nullptr, чтобы избежать висячего указателя(Данные на который он указывает очищенный, но указатель на это место остался)
	}*/
	if (begin)
	{
		begin->Del_All(&begin);
		begin = end = nullptr;
	}

	if (Otvet != nullptr)
	{
		delete[] Otvet;
		Otvet = nullptr; /// = nullptr, чтобы избежать висячего указателя (Данные на который он указывает очищенный, но указатель на это место остался)
	}

	if (components)
	{
		delete components;
	}
}

/// Должен создаваться список на p_Colichestvo_Zadach элементов заполненый сгенерированными задачами
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
//	/// Важно объявить в глобальной области памяти
//	Nabor_Zadach = new Zadacha_PoiskPloshadiTrape[p_dlina_massiva];
//}

void Shablon::MyForm::Print_Interfeise_s_Usloviem_Zadachi()

{
	ChetirioxUgolnik* A = begin->GetZadacha_poIndexu(NomerZadachi); /// (ПОставить) Указатель на базовый класс
	label_main->Text = A->Получить_Условие();
	//label_main->Text = "Задача №" + A->GetNomer_Zadachi_Poshchetu() + "\nТрапеция имеет основания равные,\na = " + A->GetOsnovanie_Nizhnee() + " и b = " + A->GetOsnovanie_Verhnie() + " соответственно. \nВысоту равную h = " + A->GetVisota() + ".\nНайдите площадь данной трапеции.";
	button_main->Text = "Проверить ответ";
	textBox_DlaOtvetaUsera->Text = "Введите ответ сюда ";
	button_main->Enabled = false;
}

void Shablon::MyForm::ProverkaPereiti_na_Otchet_ili_print_next_uslovie(int p_dlina_massiva)

{
	if (NomerZadachi != p_dlina_massiva) ///// Последней задачей считаеться 5 по индексу в массиве
	{
		Print_Interfeise_s_Usloviem_Zadachi();
	}
	else
	{
		Zadacha = false;
		Otchet = true;
		button_main->Enabled = true;

		textBox_DlaOtvetaUsera->Text = "Введите количество задач\nкоторое вы хотите решить.";
		textBox_DlaOtvetaUsera->Visible = false;

		button1->Visible = true;

		TYJ = "Отчет:\nВсего задач: " + Colichestvo_Zadach + "\nКоличество задач решенных с первой попытки: " + UserOtvet::GetCol_praevlnix() + "\nКоличество решённых задач: " + UserOtvet::GetCol_pravelnix_Otvetov() + "\nОбщее количество неправельных ответов: " + UserOtvet::GetCol_NEpraevlnix(); button_main->Text = "Вернутся в меню"; /// Для лейбл(под этой строкой) изменить "6" когда выбор количества задач появится
		label_main->Text = TYJ;

	}
}

void Shablon::MyForm::Create_UserOtvet(int p_dlina_massiva)

{
	/// Важно объявить в глобальной области памяти
	Otvet = new UserOtvet[p_dlina_massiva];
}

int Shablon::MyForm::Poluchit_Znachenie_textBox()

{
	try /// Код который может вызвать ошибку
	{
		int a = Convert::ToInt64(textBox_DlaOtvetaUsera->Text);
		if ((a < 1) && (Main_Display)) /// Собственная ошибка\исключение в рамках моей программы
		{
			throw 0; /// Сообщаем системе что вызванно исключение (в рамках программы), возврщаемое значение int
		}
		return a;
	}
	catch (int) /// Выбераеться в зависимости типа возвращаемого значения throw
	{
		MessageBox::Show("Не может быть меньше 1", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return 0; ///  0 <=> false
	}
	catch (...) /// Вызывется при любом не обработанном исключениии
	{
		MessageBox::Show("Ошибка, введены некорректные символы", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return 0; ///  0 <=> false
	}
}

void Shablon::MyForm::Обнулить_отчёт()
{
	UserOtvet::SetCol_NEpraevlnix(0);
	UserOtvet::SetCol_praevlnix(0);
	UserOtvet::SetCol_pravelnix_Otvetov(0);
}

String^ Shablon::MyForm::Вывести_формулу_для_решения(ChetirioxUgolnik* p_t)
{
	///// В будущем будет возвращать разные формулы для 
	return p_t->GetФормула();
}

System::Void Shablon::MyForm::button_main_Click(System::Object^ sender, System::EventArgs^ e)
{
	button_main->Enabled = false;

	//// Oтчет, задача, начальный экран
	if (Main_Display)
	{
		/// Проверка введеных данных в textBox_DlaOtvetaUsera
		int colZadach_изТекстБокса = Poluchit_Znachenie_textBox();
		if (colZadach_изТекстБокса)
		{

			button2->Visible = false;
			button3->Visible = false;
			Colichestvo_Zadach = colZadach_изТекстБокса;
			//// Перенести в создание списка
			CreateSpisokNaNZadach(Colichestvo_Zadach);
			/*
			////

			Create_Zadacha_PoiskPloshadiTrape(Colichestvo_Zadach);
			Create_UserOtvet(Colichestvo_Zadach);


			srand(time(0)); // Используем текущее время в качестве начального значения
			for (int i = 0; i < Colichestvo_Zadach; i++)
			{
				Nabor_Zadach[i].set_Zadacha(1 + rand() % (5 - 1 + 1), 6 + rand() % (15 - 6 + 1), 4 + rand() % (12 - 4 + 1), i + 1);  /// int p_osnon_verh, int p_osnov_niz, int p_visota, int p_Nomer_zdachi_Poshechetu
			}

			////
			*/
			NomerZadachi = 0;



			label_main->ForeColor = System::Drawing::SystemColors::Control;
			Print_Interfeise_s_Usloviem_Zadachi(); /// Чтобы не повторяться


			///
			Main_Display = false;
			Zadacha = true;
			///// Отслеживаем происходящее на экране для this button
		}
		else
		{
			textBox_DlaOtvetaUsera->Text = L"Введите количество задач\r\nкоторое вы хотите решить.";
		}


	}
	else if (Zadacha)
	{
		if (Poluchit_Znachenie_textBox())
		{
			Otvet[NomerZadachi].SetOtvet(Convert::ToInt64(textBox_DlaOtvetaUsera->Text)); /// Cчитал ответ user

			if (begin->GetZadacha_poIndexu(NomerZadachi)->Proverka_otveta_Usera(Otvet[NomerZadachi].GetOtvet())) /// Oтвет верный
			{
				UserOtvet::PlusOneCol_pravelnix_Otvetov();
				if (Otvet[NomerZadachi].GetColichestvo_Nepravelnix_Otvetov_V_Ramkax_Dannoi_Zadache() == 0)
				{
					Otvet[NomerZadachi].PlusOne_Col_praevlnix();
				}

				MessageBox::Show("Так держать! Вы дали правильный ответ.", "Результат", MessageBoxButtons::OK, MessageBoxIcon::Information);

				++NomerZadachi;
				ProverkaPereiti_na_Otchet_ili_print_next_uslovie(Colichestvo_Zadach);
			}
			else  /// Ответ не верный
			{
				Otvet[NomerZadachi].PlusOne_Colichestvo_Nepravelnix_Otvetov_V_Ramkax_Dannoi_Zadache();
				if (Otvet[NomerZadachi].GetColichestvo_Nepravelnix_Otvetov_V_Ramkax_Dannoi_Zadache() != 3) /// 3 неповторимых ответов за одну задачу
				{
					if ((Otvet[NomerZadachi].GetColichestvo_Nepravelnix_Otvetov_V_Ramkax_Dannoi_Zadache() != 2)) // На последней попытке дадим подсказку по решения
					{
						MessageBox::Show("Ответ неверный. У вас осталось " + (3 - Otvet[NomerZadachi].GetColichestvo_Nepravelnix_Otvetov_V_Ramkax_Dannoi_Zadache()) + " попыток.", "Результат", MessageBoxButtons::OK, MessageBoxIcon::Warning);
					}
					else
					{
						///MessageBox::Show(, "Результат", MessageBoxButtons::OK, MessageBoxIcon::Warning);
						MessageBox::Show("Ответ неверный. У вас осталось " + (3 - Otvet[NomerZadachi].GetColichestvo_Nepravelnix_Otvetov_V_Ramkax_Dannoi_Zadache()) + " попыток.\n" + Вывести_формулу_для_решения(begin->GetZadacha_poIndexu(NomerZadachi)), "Результат", MessageBoxButtons::OK, MessageBoxIcon::Warning);
					}

				}
				else /// 3 ошибки в одной задаче
				{
					MessageBox::Show("Ответ неверный. Правильный ответ = " + begin->GetZadacha_poIndexu(NomerZadachi)->GetОтвет(), "Результат", MessageBoxButtons::OK, MessageBoxIcon::Warning);

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

		button_main->Text = "Начать";
		/*label_main->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(254)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
			static_cast<System::Int32>(static_cast<System::Byte>(46)));*/
		label_main->Text = L"Для того что бы начать:\r\n  *  Введите, в нижнем окне, количество задач\r\n      кот"
			L"орые вы хотите решить.\r\n  *  Нажмите \"Начать\"\r\n";

		Обнулить_отчёт();



		/*if (Nabor_Zadach != nullptr)
		{
			delete[] Nabor_Zadach;
			Nabor_Zadach = nullptr; /// = nullptr, чтобы избежать висячего указателя(Данные на который он указывает очищенный, но указатель на это место остался)
		}*/

		/// На всякий случай
		if (begin)
		{
			begin->Del_All(&begin);
			begin = end = nullptr;
		}
		if (Otvet != nullptr)
		{
			delete[] Otvet;
			Otvet = nullptr; /// = nullptr, чтобы избежать висячего указателя (Данные на который он указывает очищенный, но указатель на это место остался)
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
