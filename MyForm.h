#pragma once
#include "MyForm1.h"
#include "MyForm2.h"
#include "MyForm3.h"
#include "UserOtvet.h"
#include "Zadacha_PoiskPloshadiTrape.h"
#include "SpisokZadach.h"


///#include "Zadacha_PoiskPloshadiTrape.h"
///#include "UserOtvet.h"
//#include "SpisokZadach.h"



//#include <cstdlib>
//#include <ctime>


//static int NomerZadachi; //// Помнит индекс следующей задачи в массиве
//static int Colichestvo_Zadach;
//
//int UserOtvet::Col_NEpraevlnix = 0;
//int UserOtvet::Col_praevlnix = 0;
//int UserOtvet::Col_pravelnix_Otvetov = 0;



namespace Shablon {


	//UserOtvet* Otvet = nullptr; ////  Работает с ответами пользователя, поучавствует в отчете после задач
	//Zadacha_PoiskPloshadiTrape* Nabor_Zadach = nullptr; /// = nullptr на случай если программа будет закрыта до того как будет выделенна память

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	//bool Otchet, Zadacha; /// Инициализировать в первой кнопку
	//bool Main_Display = true; //// инициализация строка 44

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		String^ TYJ;

	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm();
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button_main;
	private: System::Windows::Forms::TextBox^ textBox_DlaOtvetaUsera;
	private: System::Windows::Forms::Label^ label_main;

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label_Button_info;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;


	public: void CreateSpisokNaNZadach(int);

	public: void Print_Interfeise_s_Usloviem_Zadachi();

	public: void ProverkaPereiti_na_Otchet_ili_print_next_uslovie(int p_dlina_massiva);
		  //public: void Create_Zadacha_PoiskPloshadiTrape(int p_dlina_massiva);
	public: void Create_UserOtvet(int p_dlina_massiva);
	public: int Poluchit_Znachenie_textBox();
	public: void Обнулить_отчёт();
	public: String^ Вывести_формулу_для_решения(ChetirioxUgolnik*);

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button_main = (gcnew System::Windows::Forms::Button());
			this->textBox_DlaOtvetaUsera = (gcnew System::Windows::Forms::TextBox());
			this->label_main = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label_Button_info = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(10)), static_cast<System::Int32>(static_cast<System::Byte>(115)),
				static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Font = (gcnew System::Drawing::Font(L"Corbel", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->button3->Location = System::Drawing::Point(572, 355);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(133, 60);
			this->button3->TabIndex = 2;
			this->button3->TabStop = false;
			this->button3->Text = L"Об авторе";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(10)), static_cast<System::Int32>(static_cast<System::Byte>(115)),
				static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Corbel", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->button2->Location = System::Drawing::Point(572, 289);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(133, 60);
			this->button2->TabIndex = 2;
			this->button2->TabStop = false;
			this->button2->Text = L"О программе";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button_main
			// 
			this->button_main->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(10)), static_cast<System::Int32>(static_cast<System::Byte>(115)),
				static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->button_main->Enabled = false;
			this->button_main->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_main->Font = (gcnew System::Drawing::Font(L"Corbel", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_main->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->button_main->Location = System::Drawing::Point(29, 366);
			this->button_main->Name = L"button_main";
			this->button_main->Size = System::Drawing::Size(324, 39);
			this->button_main->TabIndex = 3;
			this->button_main->Text = L"Начать";
			this->button_main->UseVisualStyleBackColor = false;
			this->button_main->Click += gcnew System::EventHandler(this, &MyForm::button_main_Click);
			// 
			// textBox_DlaOtvetaUsera
			// 
			this->textBox_DlaOtvetaUsera->Font = (gcnew System::Drawing::Font(L"Corbel", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox_DlaOtvetaUsera->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->textBox_DlaOtvetaUsera->Location = System::Drawing::Point(29, 289);
			this->textBox_DlaOtvetaUsera->Multiline = true;
			this->textBox_DlaOtvetaUsera->Name = L"textBox_DlaOtvetaUsera";
			this->textBox_DlaOtvetaUsera->Size = System::Drawing::Size(324, 60);
			this->textBox_DlaOtvetaUsera->TabIndex = 4;
			this->textBox_DlaOtvetaUsera->Text = L"Введите количество задач\r\nкоторое вы хотите решить.";
			this->textBox_DlaOtvetaUsera->Click += gcnew System::EventHandler(this, &MyForm::textBox_DlaOtvetaUsera_Click);
			this->textBox_DlaOtvetaUsera->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox_DlaOtvetaUsera_TextChanged);
			// 
			// label_main
			// 
			this->label_main->AutoSize = true;
			this->label_main->Font = (gcnew System::Drawing::Font(L"Corbel", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_main->ForeColor = System::Drawing::Color::White;
			this->label_main->Location = System::Drawing::Point(25, 29);
			this->label_main->Name = L"label_main";
			this->label_main->Size = System::Drawing::Size(415, 96);
			this->label_main->TabIndex = 5;
			this->label_main->Text = L"Для того что бы начать:\r\n  *  Введите, в нижнем окне, количество задач\r\n      кот"
				L"орые вы хотите решить.\r\n  *  Нажмите \"Начать\"\r\n";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(10)), static_cast<System::Int32>(static_cast<System::Byte>(115)),
				static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Corbel", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->button1->Location = System::Drawing::Point(572, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(133, 61);
			this->button1->TabIndex = 7;
			this->button1->TabStop = false;
			this->button1->Text = L"Сохранить\r\n в файл";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Visible = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label_Button_info
			// 
			this->label_Button_info->Location = System::Drawing::Point(12, 9);
			this->label_Button_info->Name = L"label_Button_info";
			this->label_Button_info->Size = System::Drawing::Size(100, 23);
			this->label_Button_info->TabIndex = 8;
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::SystemColors::HotTrack;
			this->textBox1->Enabled = false;
			this->textBox1->Location = System::Drawing::Point(-6, 159);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(555, 276);
			this->textBox1->TabIndex = 9;
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->textBox2->Enabled = false;
			this->textBox2->Location = System::Drawing::Point(540, -6);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(196, 441);
			this->textBox2->TabIndex = 10;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(93)),
				static_cast<System::Int32>(static_cast<System::Byte>(153)));
			this->ClientSize = System::Drawing::Size(732, 431);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->button_main);
			this->Controls->Add(this->textBox_DlaOtvetaUsera);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label_main);
			this->Controls->Add(this->label_Button_info);
			this->Name = L"MyForm";
			this->Text = L"S_трапеции_";
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		////Print_Interfeise_s_Usloviem_Zadachi
#pragma endregion

	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		MyForm1^ r = gcnew MyForm1();
		r->ShowDialog();

	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		MyForm2^ rl = gcnew MyForm2();
		rl->ShowDialog();
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		MyForm3^ rlr = gcnew MyForm3(TYJ);
		rlr->ShowDialog();
		button1->Enabled = false;
	}
	private: System::Void button_main_Click(System::Object^ sender, System::EventArgs^ e);


	private: System::Void textBox_DlaOtvetaUsera_Click(System::Object^ sender, System::EventArgs^ e) {
		textBox_DlaOtvetaUsera->Text = "";
		button_main->Enabled = false;
	}

	private: System::Void textBox_DlaOtvetaUsera_TextChanged(System::Object^ sender, System::EventArgs^ e);
	};
}
