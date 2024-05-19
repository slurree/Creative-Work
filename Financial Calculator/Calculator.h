#pragma once
#include <string>
namespace FinancialCalculator {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Calculator
	/// </summary>
	public ref class Calculator : public System::Windows::Forms::Form
	{
	public:
		Calculator(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//оапплгп
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Calculator()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ resultGrossProfit;
	private: System::Windows::Forms::Label^ resultProfitFromSales;
	private: System::Windows::Forms::Label^ resultBalanceProfit;
	private: System::Windows::Forms::Label^ resultNetProfit;



	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	protected:






	private: System::Windows::Forms::TextBox^ revenue;
	private: System::Windows::Forms::TextBox^ costPrice;
	private: System::Windows::Forms::TextBox^ bisnessExpenses;
	private: System::Windows::Forms::TextBox^ administrativeExpenses;
	private: System::Windows::Forms::TextBox^ otherIncome;
	private: System::Windows::Forms::TextBox^ otherExpenses;
	private: System::Windows::Forms::TextBox^ IncomeTax;
	private: System::Windows::Forms::CheckBox^ checkGrossProfit;
	private: System::Windows::Forms::CheckBox^ checkRevenueFromSales;
	private: System::Windows::Forms::CheckBox^ checkBookProfit;
	private: System::Windows::Forms::CheckBox^ checkNetProfit;











	private: System::Windows::Forms::Button^ calculationButton;
private: System::Windows::Forms::Button^ clearButton;



private: System::Windows::Forms::Label^ label3;
private: System::Windows::Forms::Label^ label2;
private: System::Windows::Forms::Label^ label1;









	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->resultGrossProfit = (gcnew System::Windows::Forms::Label());
			this->resultProfitFromSales = (gcnew System::Windows::Forms::Label());
			this->resultBalanceProfit = (gcnew System::Windows::Forms::Label());
			this->resultNetProfit = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->revenue = (gcnew System::Windows::Forms::TextBox());
			this->costPrice = (gcnew System::Windows::Forms::TextBox());
			this->bisnessExpenses = (gcnew System::Windows::Forms::TextBox());
			this->administrativeExpenses = (gcnew System::Windows::Forms::TextBox());
			this->otherIncome = (gcnew System::Windows::Forms::TextBox());
			this->otherExpenses = (gcnew System::Windows::Forms::TextBox());
			this->IncomeTax = (gcnew System::Windows::Forms::TextBox());
			this->checkGrossProfit = (gcnew System::Windows::Forms::CheckBox());
			this->checkRevenueFromSales = (gcnew System::Windows::Forms::CheckBox());
			this->checkBookProfit = (gcnew System::Windows::Forms::CheckBox());
			this->checkNetProfit = (gcnew System::Windows::Forms::CheckBox());
			this->calculationButton = (gcnew System::Windows::Forms::Button());
			this->clearButton = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// resultGrossProfit
			// 
			this->resultGrossProfit->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 25.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->resultGrossProfit->Location = System::Drawing::Point(571, 23);
			this->resultGrossProfit->Name = L"resultGrossProfit";
			this->resultGrossProfit->Size = System::Drawing::Size(336, 48);
			this->resultGrossProfit->TabIndex = 25;
			this->resultGrossProfit->Text = L"0";
			this->resultGrossProfit->TextAlign = System::Drawing::ContentAlignment::BottomRight;
			// 
			// resultProfitFromSales
			// 
			this->resultProfitFromSales->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 25.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->resultProfitFromSales->Location = System::Drawing::Point(577, 93);
			this->resultProfitFromSales->Name = L"resultProfitFromSales";
			this->resultProfitFromSales->Size = System::Drawing::Size(330, 50);
			this->resultProfitFromSales->TabIndex = 26;
			this->resultProfitFromSales->Text = L"0";
			this->resultProfitFromSales->TextAlign = System::Drawing::ContentAlignment::BottomRight;
			// 
			// resultBalanceProfit
			// 
			this->resultBalanceProfit->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 25.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->resultBalanceProfit->Location = System::Drawing::Point(577, 166);
			this->resultBalanceProfit->Name = L"resultBalanceProfit";
			this->resultBalanceProfit->Size = System::Drawing::Size(330, 50);
			this->resultBalanceProfit->TabIndex = 27;
			this->resultBalanceProfit->Text = L"0";
			this->resultBalanceProfit->TextAlign = System::Drawing::ContentAlignment::BottomRight;
			// 
			// resultNetProfit
			// 
			this->resultNetProfit->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 25.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->resultNetProfit->Location = System::Drawing::Point(575, 235);
			this->resultNetProfit->Name = L"resultNetProfit";
			this->resultNetProfit->Size = System::Drawing::Size(332, 50);
			this->resultNetProfit->TabIndex = 28;
			this->resultNetProfit->Text = L"0";
			this->resultNetProfit->TextAlign = System::Drawing::ContentAlignment::BottomRight;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::LightPink;
			this->label4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label4->Font = (gcnew System::Drawing::Font(L"Arial", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(445, 380);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(341, 34);
			this->label4->TabIndex = 39;
			this->label4->Text = L"Управленческие расходы";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::LightPink;
			this->label5->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label5->Font = (gcnew System::Drawing::Font(L"Arial", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(502, 495);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(214, 34);
			this->label5->TabIndex = 40;
			this->label5->Text = L"Прочие доходы";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::LightPink;
			this->label6->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label6->Font = (gcnew System::Drawing::Font(L"Arial", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(502, 608);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(228, 34);
			this->label6->TabIndex = 41;
			this->label6->Text = L"Прочие расходы";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::Color::LightPink;
			this->label7->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label7->Font = (gcnew System::Drawing::Font(L"Arial", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->Location = System::Drawing::Point(867, 382);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(251, 34);
			this->label7->TabIndex = 42;
			this->label7->Text = L"Налог на прибыль";
			// 
			// revenue
			// 
			this->revenue->Location = System::Drawing::Point(87, 417);
			this->revenue->Multiline = true;
			this->revenue->Name = L"revenue";
			this->revenue->Size = System::Drawing::Size(129, 34);
			this->revenue->TabIndex = 43;
			// 
			// costPrice
			// 
			this->costPrice->Location = System::Drawing::Point(58, 530);
			this->costPrice->Multiline = true;
			this->costPrice->Name = L"costPrice";
			this->costPrice->Size = System::Drawing::Size(217, 34);
			this->costPrice->TabIndex = 44;
			// 
			// bisnessExpenses
			// 
			this->bisnessExpenses->Location = System::Drawing::Point(31, 643);
			this->bisnessExpenses->Multiline = true;
			this->bisnessExpenses->Name = L"bisnessExpenses";
			this->bisnessExpenses->Size = System::Drawing::Size(320, 34);
			this->bisnessExpenses->TabIndex = 45;
			// 
			// administrativeExpenses
			// 
			this->administrativeExpenses->Location = System::Drawing::Point(444, 417);
			this->administrativeExpenses->Multiline = true;
			this->administrativeExpenses->Name = L"administrativeExpenses";
			this->administrativeExpenses->Size = System::Drawing::Size(353, 34);
			this->administrativeExpenses->TabIndex = 46;
			// 
			// otherIncome
			// 
			this->otherIncome->Location = System::Drawing::Point(502, 530);
			this->otherIncome->Multiline = true;
			this->otherIncome->Name = L"otherIncome";
			this->otherIncome->Size = System::Drawing::Size(237, 36);
			this->otherIncome->TabIndex = 47;
			// 
			// otherExpenses
			// 
			this->otherExpenses->Location = System::Drawing::Point(502, 643);
			this->otherExpenses->Multiline = true;
			this->otherExpenses->Name = L"otherExpenses";
			this->otherExpenses->Size = System::Drawing::Size(237, 36);
			this->otherExpenses->TabIndex = 48;
			// 
			// IncomeTax
			// 
			this->IncomeTax->Location = System::Drawing::Point(867, 417);
			this->IncomeTax->Multiline = true;
			this->IncomeTax->Name = L"IncomeTax";
			this->IncomeTax->Size = System::Drawing::Size(261, 34);
			this->IncomeTax->TabIndex = 49;
			// 
			// checkGrossProfit
			// 
			this->checkGrossProfit->AutoSize = true;
			this->checkGrossProfit->Font = (gcnew System::Drawing::Font(L"Arial", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->checkGrossProfit->Location = System::Drawing::Point(77, 38);
			this->checkGrossProfit->Name = L"checkGrossProfit";
			this->checkGrossProfit->Size = System::Drawing::Size(336, 42);
			this->checkGrossProfit->TabIndex = 50;
			this->checkGrossProfit->Text = L"Валовая прибыль";
			this->checkGrossProfit->UseVisualStyleBackColor = true;
			// 
			// checkRevenueFromSales
			// 
			this->checkRevenueFromSales->AutoSize = true;
			this->checkRevenueFromSales->Font = (gcnew System::Drawing::Font(L"Arial", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->checkRevenueFromSales->Location = System::Drawing::Point(77, 99);
			this->checkRevenueFromSales->Name = L"checkRevenueFromSales";
			this->checkRevenueFromSales->Size = System::Drawing::Size(366, 42);
			this->checkRevenueFromSales->TabIndex = 51;
			this->checkRevenueFromSales->Text = L"Прибыль от продаж";
			this->checkRevenueFromSales->UseVisualStyleBackColor = true;
			// 
			// checkBookProfit
			// 
			this->checkBookProfit->AutoSize = true;
			this->checkBookProfit->Font = (gcnew System::Drawing::Font(L"Arial", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->checkBookProfit->Location = System::Drawing::Point(77, 166);
			this->checkBookProfit->Name = L"checkBookProfit";
			this->checkBookProfit->Size = System::Drawing::Size(393, 42);
			this->checkBookProfit->TabIndex = 52;
			this->checkBookProfit->Text = L"Балансовая прибыль";
			this->checkBookProfit->UseVisualStyleBackColor = true;
			// 
			// checkNetProfit
			// 
			this->checkNetProfit->AutoSize = true;
			this->checkNetProfit->Font = (gcnew System::Drawing::Font(L"Arial", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->checkNetProfit->Location = System::Drawing::Point(77, 235);
			this->checkNetProfit->Name = L"checkNetProfit";
			this->checkNetProfit->Size = System::Drawing::Size(310, 42);
			this->checkNetProfit->TabIndex = 53;
			this->checkNetProfit->Text = L"Чистая прибыль";
			this->checkNetProfit->UseVisualStyleBackColor = true;
			// 
			// calculationButton
			// 
			this->calculationButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->calculationButton->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->calculationButton->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->calculationButton->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 16.2F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->calculationButton->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->calculationButton->Location = System::Drawing::Point(895, 507);
			this->calculationButton->Name = L"calculationButton";
			this->calculationButton->Size = System::Drawing::Size(193, 59);
			this->calculationButton->TabIndex = 54;
			this->calculationButton->Text = L"Посчитать";
			this->calculationButton->UseVisualStyleBackColor = true;
			this->calculationButton->Click += gcnew System::EventHandler(this, &Calculator::button_Click);
			// 
			// clearButton
			// 
			this->clearButton->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 16.2F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->clearButton->Location = System::Drawing::Point(895, 620);
			this->clearButton->Name = L"clearButton";
			this->clearButton->Size = System::Drawing::Size(193, 59);
			this->clearButton->TabIndex = 55;
			this->clearButton->Text = L"Очистить";
			this->clearButton->UseVisualStyleBackColor = true;
			this->clearButton->Click += gcnew System::EventHandler(this, &Calculator::button2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::LightPink;
			this->label3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->label3->Font = (gcnew System::Drawing::Font(L"Arial", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(35, 608);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(318, 34);
			this->label3->TabIndex = 38;
			this->label3->Text = L"Коммерческие расходы";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::LightPink;
			this->label2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(62, 495);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(215, 34);
			this->label2->TabIndex = 37;
			this->label2->Text = L"Себестоимость";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::LightPink;
			this->label1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(87, 382);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(127, 34);
			this->label1->TabIndex = 36;
			this->label1->Text = L"Выручка";
			// 
			// Calculator
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::MistyRose;
			this->ClientSize = System::Drawing::Size(1156, 707);
			this->Controls->Add(this->clearButton);
			this->Controls->Add(this->calculationButton);
			this->Controls->Add(this->checkNetProfit);
			this->Controls->Add(this->checkBookProfit);
			this->Controls->Add(this->checkRevenueFromSales);
			this->Controls->Add(this->checkGrossProfit);
			this->Controls->Add(this->IncomeTax);
			this->Controls->Add(this->otherExpenses);
			this->Controls->Add(this->otherIncome);
			this->Controls->Add(this->administrativeExpenses);
			this->Controls->Add(this->bisnessExpenses);
			this->Controls->Add(this->costPrice);
			this->Controls->Add(this->revenue);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->resultNetProfit);
			this->Controls->Add(this->resultBalanceProfit);
			this->Controls->Add(this->resultProfitFromSales);
			this->Controls->Add(this->resultGrossProfit);
			this->Name = L"Calculator";
			this->Text = L"Calculator";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void button_Click(System::Object^ sender, System::EventArgs^ e) { // обработка события нажатия на кнопку счета
	if (checkGrossProfit->Checked) { // если нужно рассчитать валовую прибыль
		double value1; // переменная для получения данных
		value1 = Convert::ToDouble(revenue->Text); // получения данных из поля ввода и их преобразование
		double value2; // переменная для получения данных
		value2 = Convert::ToDouble(costPrice->Text);  // получения данных из поля ввода и их преобразование
		this->resultGrossProfit->Text = Convert::ToString(value1 - value2); // запись ответа в поле итогового ответа
	}
	if (checkRevenueFromSales->Checked) {  // если нужно рассчитать прибыль от продаж
		double value3; // переменная для получения данных
		value3 = Convert::ToDouble(revenue->Text);  // получения данных из поля ввода и их преобразование
		double value4; // переменная для получения данных
		value4 = Convert::ToDouble(costPrice->Text);  // получения данных из поля ввода и их преобразование
		double value5; // переменная для получения данных
		value5 = Convert::ToDouble(bisnessExpenses->Text);  // получения данных из поля ввода и их преобразование
		double value6; // переменная для получения данных
		value6 = Convert::ToDouble(administrativeExpenses->Text);  // получения данных из поля ввода и их преобразование
		this->resultProfitFromSales->Text = Convert::ToString(value3 - value4 -  value5 - value6); // запись ответа в поле итогового ответа
	}
	if (checkBookProfit->Checked) {  // если нужно рассчитать балансовую прибыль
		double value7; // переменная для получения данных
		value7 = Convert::ToDouble(revenue->Text);  // получения данных из поля ввода и их преобразование
		double value8; // переменная для получения данных
		value8 = Convert::ToDouble(costPrice->Text);  // получения данных из поля ввода и их преобразование
		double value9; // переменная для получения данных
		value9 = Convert::ToDouble(bisnessExpenses->Text);  // получения данных из поля ввода и их преобразование
		double value10; // переменная для получения данных
		value10 = Convert::ToDouble(administrativeExpenses->Text);  // получения данных из поля ввода и их преобразование
		double value11; // переменная для получения данных
		value11 = Convert::ToDouble(otherIncome->Text);  // получения данных из поля ввода и их преобразование
		double value12; // переменная для получения данных
		value12 = Convert::ToDouble(otherExpenses->Text);
		this->resultBalanceProfit->Text = Convert::ToString(value7 - value8 - value9 - value10 + value11 - value12); // запись ответа в поле итогового ответа
	}
	if (checkNetProfit->Checked) {  // если нужно рассчитать чистую прибыль
		double value13; // переменная для получения данных
		value13 = Convert::ToDouble(revenue->Text); // получения данных из поля ввода и их преобразование
		double value14; // переменная для получения данных
		value14 = Convert::ToDouble(costPrice->Text); // получения данных из поля ввода и их преобразование
		double value15; // переменная для получения данных
		value15 = Convert::ToDouble(bisnessExpenses->Text); // получения данных из поля ввода и их преобразование
		double value16; // переменная для получения данных
		value16 = Convert::ToDouble(administrativeExpenses->Text); // получения данных из поля ввода и их преобразование
		double value17; // переменная для получения данных
		value17 = Convert::ToDouble(otherIncome->Text); // получения данных из поля ввода и их преобразование
		double value18; // переменная для получения данных
		value18 = Convert::ToDouble(otherExpenses->Text); // получения данных из поля ввода и их преобразование
		double value19; // переменная для получения данных
		value19 = Convert::ToDouble(IncomeTax->Text); // получения данных из поля ввода и их преобразование
		this->resultNetProfit->Text = Convert::ToString(value13 - value14 - value15 - value16 + value17 - value18 - value19); // запись ответа в поле итогового ответа
	}
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) { // обработка события нажатия на кнопку очищения полей
	resultGrossProfit->Text = "0"; // установление в поле итогового ответа значения по умолчанию(0)
	resultProfitFromSales->Text = "0"; // установление в поле итогового ответа значения по умолчанию(0)
	resultBalanceProfit->Text = "0"; // установление в поле итогового ответа значения по умолчанию(0)
	resultNetProfit->Text = "0"; // установление в поле итогового ответа значения по умолчанию(0)
	revenue->Clear(); // очищение поля для ввода данных
	costPrice->Clear();  // очищение поля для ввода данных
	bisnessExpenses->Clear(); // очищение поля для ввода данных
	administrativeExpenses->Clear(); // очищение поля для ввода данных
	otherIncome->Clear(); // очищение поля для ввода данных
	otherExpenses->Clear(); // очищение поля для ввода данных
	IncomeTax->Clear(); // очищение поля для ввода данных
}
};
}