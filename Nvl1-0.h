#pragma once

namespace AiParadoxRemake {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Nvl10
	/// </summary>
	public ref class Nvl10 : public System::Windows::Forms::Form
	{
	public:
		Nvl10(void)
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
		~Nvl10()
		{
			if (components)
			{
				delete components;
			}
		}

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
			this->SuspendLayout();
			// 
			// Nvl10
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1127, 566);
			this->Name = L"Nvl10";
			this->Text = L"Nvl10";
			this->Load += gcnew System::EventHandler(this, &Nvl10::Nvl10_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Nvl10_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
