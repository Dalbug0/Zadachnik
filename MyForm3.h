#pragma once
#include <fstream>

namespace Shablon {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO; ///// Для работы с файлом


	/// <summary>
	/// Сводка для MyForm3
	/// </summary>
	public ref class MyForm3 : public System::Windows::Forms::Form
	{
		String^ TYJ;

	public:
		MyForm3(String^ p_TYJ)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			this->TYJ = p_TYJ;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm3()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label_info;
	protected:
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;


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
			this->label_info = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->SuspendLayout();
			// 
			// label_info
			// 
			this->label_info->AutoSize = true;
			this->label_info->Font = (gcnew System::Drawing::Font(L"Corbel", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_info->Location = System::Drawing::Point(45, 27);
			this->label_info->Name = L"label_info";
			this->label_info->Size = System::Drawing::Size(170, 24);
			this->label_info->TabIndex = 0;
			this->label_info->Text = L"Введите ваше имя";
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Corbel", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(12, 68);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(169, 27);
			this->textBox1->TabIndex = 1;
			this->textBox1->Text = L"Name";
			this->textBox1->Click += gcnew System::EventHandler(this, &MyForm3::textBox1_Click);
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm3::textBox1_TextChanged);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(10)), static_cast<System::Int32>(static_cast<System::Byte>(115)),
				static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->button2->Enabled = false;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button2->Font = (gcnew System::Drawing::Font(L"Corbel", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->ForeColor = System::Drawing::SystemColors::Control;
			this->button2->Location = System::Drawing::Point(178, 68);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(71, 28);
			this->button2->TabIndex = 8;
			this->button2->TabStop = false;
			this->button2->Text = L"Save";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm3::button2_Click);
			// 
			// MyForm3
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::HighlightText;
			this->ClientSize = System::Drawing::Size(260, 129);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label_info);
			this->Name = L"MyForm3";
			this->Text = L"Файл";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		saveFileDialog1->Filter = "txt files (*. txt)|*.txt";
		saveFileDialog1->FileName = textBox1->Text;
		saveFileDialog1->ShowDialog(); //Нужно выбрать место для создания файла, не папку
		String^ selectedFilePath = saveFileDialog1->FileName; // Получает путь к файлу

		/*try
		{
			chart_main->SaveImage(selectedFilePath, ChartImageFormat::Png);
		}
		catch (...)
		{
			return;
		}*/


		StreamWriter^ file_app = gcnew StreamWriter(selectedFilePath, true);
		file_app->Write("\n\n");
		file_app->Write(textBox1->Text);
		file_app->Write("\n");
		file_app->Write(TYJ);
		file_app->Close();

		this->Close();
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		button2->Enabled = true;
		if (textBox1->Text == "")
		{
			button2->Enabled = false;
		}
	}
	private: System::Void textBox1_Click(System::Object^ sender, System::EventArgs^ e) {
		textBox1->Text = "";
		button2->Enabled = false;
	}
	};
}
