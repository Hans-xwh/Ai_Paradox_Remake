#pragma once

namespace AiParadoxRemake {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btn_sexo;
	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btn_sexo = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btn_sexo
			// 
			this->btn_sexo->Location = System::Drawing::Point(102, 120);
			this->btn_sexo->Name = L"btn_sexo";
			this->btn_sexo->Size = System::Drawing::Size(75, 23);
			this->btn_sexo->TabIndex = 0;
			this->btn_sexo->Text = L"Sexo\?";
			this->btn_sexo->UseVisualStyleBackColor = true;
			this->btn_sexo->Click += gcnew System::EventHandler(this, &MainForm::btn_sexo_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->btn_sexo);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btn_sexo_Click(System::Object^ sender, System::EventArgs^ e) {
		MessageBox::Show("Sexo.");
	}
	};
}
