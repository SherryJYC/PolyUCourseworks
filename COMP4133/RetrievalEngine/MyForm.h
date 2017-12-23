#pragma once
#include "../stem.h"
#include "../IInvFile.h"
#include <msclr\marshal_cppstd.h>
#include <ctime>

namespace GUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;
	using namespace System::Threading;
	IInvFile InvFile;
	char *filename = new char[255];

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  panel1;
	protected:

	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label3;

	private: System::Windows::Forms::Panel^  panel4;
	private: System::Windows::Forms::RadioButton^  radioButton5;
	private: System::Windows::Forms::RadioButton^  radioButton4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::RadioButton^  radioFB;

	private: System::Windows::Forms::RadioButton^  radioVS;

	private: System::Windows::Forms::RadioButton^  radioBL;


	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Button^  button2;

	private: System::Windows::Forms::ProgressBar^  progressBar1;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart1;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	internal: System::Windows::Forms::Timer^  timer1;
	private: 

	private: System::ComponentModel::IContainer^  components;




	private:

		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::Threading::Thread^ myThread;

	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::Label^  label6;

		int begin = 0;
		
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::CustomLabel^  customLabel1 = (gcnew System::Windows::Forms::DataVisualization::Charting::CustomLabel());
			System::Windows::Forms::DataVisualization::Charting::CustomLabel^  customLabel2 = (gcnew System::Windows::Forms::DataVisualization::Charting::CustomLabel());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->radioButton5 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioFB = (gcnew System::Windows::Forms::RadioButton());
			this->radioVS = (gcnew System::Windows::Forms::RadioButton());
			this->radioBL = (gcnew System::Windows::Forms::RadioButton());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel1->SuspendLayout();
			this->panel4->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->label6);
			this->panel1->Controls->Add(this->progressBar1);
			this->panel1->Controls->Add(this->button2);
			this->panel1->Controls->Add(this->panel4);
			this->panel1->Controls->Add(this->label5);
			this->panel1->Controls->Add(this->panel3);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->textBox1);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Location = System::Drawing::Point(12, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(460, 322);
			this->panel1->TabIndex = 0;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel1_Paint);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(23, 251);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(0, 20);
			this->label6->TabIndex = 9;
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(8, 284);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(443, 23);
			this->progressBar1->TabIndex = 8;
			// 
			// button2
			// 
			this->button2->Enabled = false;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(365, 245);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(86, 33);
			this->button2->TabIndex = 7;
			this->button2->Text = L"Start";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// panel4
			// 
			this->panel4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel4->Controls->Add(this->radioButton5);
			this->panel4->Controls->Add(this->radioButton4);
			this->panel4->Location = System::Drawing::Point(255, 96);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(89, 65);
			this->panel4->TabIndex = 6;
			// 
			// radioButton5
			// 
			this->radioButton5->AutoSize = true;
			this->radioButton5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->radioButton5->Location = System::Drawing::Point(3, 33);
			this->radioButton5->Name = L"radioButton5";
			this->radioButton5->Size = System::Drawing::Size(47, 24);
			this->radioButton5->TabIndex = 1;
			this->radioButton5->TabStop = true;
			this->radioButton5->Text = L"No";
			this->radioButton5->UseVisualStyleBackColor = true;
			// 
			// radioButton4
			// 
			this->radioButton4->AutoSize = true;
			this->radioButton4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->radioButton4->Location = System::Drawing::Point(3, 3);
			this->radioButton4->Name = L"radioButton4";
			this->radioButton4->Size = System::Drawing::Size(55, 24);
			this->radioButton4->TabIndex = 0;
			this->radioButton4->TabStop = true;
			this->radioButton4->Text = L"Yes";
			this->radioButton4->UseVisualStyleBackColor = true;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(247, 73);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(191, 20);
			this->label5->TabIndex = 2;
			this->label5->Text = L"Term Weight Nomalzation";
			// 
			// panel3
			// 
			this->panel3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel3->Controls->Add(this->radioButton1);
			this->panel3->Controls->Add(this->radioFB);
			this->panel3->Controls->Add(this->radioVS);
			this->panel3->Controls->Add(this->radioBL);
			this->panel3->Location = System::Drawing::Point(7, 96);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(242, 130);
			this->panel3->TabIndex = 5;
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->radioButton1->Location = System::Drawing::Point(3, 63);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(234, 24);
			this->radioButton1->TabIndex = 3;
			this->radioButton1->Text = L"Approximate Term Mataching";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// radioFB
			// 
			this->radioFB->AutoSize = true;
			this->radioFB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->radioFB->Location = System::Drawing::Point(3, 93);
			this->radioFB->Name = L"radioFB";
			this->radioFB->Size = System::Drawing::Size(132, 24);
			this->radioFB->TabIndex = 2;
			this->radioFB->Text = L"Fuzzy Boolean";
			this->radioFB->UseVisualStyleBackColor = true;
			// 
			// radioVS
			// 
			this->radioVS->AutoSize = true;
			this->radioVS->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->radioVS->Location = System::Drawing::Point(3, 33);
			this->radioVS->Name = L"radioVS";
			this->radioVS->Size = System::Drawing::Size(120, 24);
			this->radioVS->TabIndex = 1;
			this->radioVS->Text = L"VectorSpace";
			this->radioVS->UseVisualStyleBackColor = true;
			// 
			// radioBL
			// 
			this->radioBL->AutoSize = true;
			this->radioBL->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->radioBL->Location = System::Drawing::Point(3, 3);
			this->radioBL->Name = L"radioBL";
			this->radioBL->Size = System::Drawing::Size(86, 24);
			this->radioBL->TabIndex = 0;
			this->radioBL->Text = L"Boolean";
			this->radioBL->UseVisualStyleBackColor = true;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(3, 73);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(115, 20);
			this->label4->TabIndex = 4;
			this->label4->Text = L"Retraval model";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(364, 30);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(86, 32);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Browse";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(7, 33);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(351, 26);
			this->textBox1->TabIndex = 2;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(3, 10);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(84, 20);
			this->label3->TabIndex = 1;
			this->label3->Text = L"Query File:";
			// 
			// panel2
			// 
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel2->Controls->Add(this->chart1);
			this->panel2->Controls->Add(this->label14);
			this->panel2->Controls->Add(this->label13);
			this->panel2->Controls->Add(this->label12);
			this->panel2->Controls->Add(this->label11);
			this->panel2->Controls->Add(this->label10);
			this->panel2->Controls->Add(this->label9);
			this->panel2->Controls->Add(this->label2);
			this->panel2->Controls->Add(this->label1);
			this->panel2->Controls->Add(this->label8);
			this->panel2->Controls->Add(this->label7);
			this->panel2->Location = System::Drawing::Point(12, 340);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(460, 384);
			this->panel2->TabIndex = 1;
			// 
			// chart1
			// 
			chartArea1->AxisX->CustomLabels->Add(customLabel1);
			chartArea1->AxisX->MajorGrid->Enabled = false;
			chartArea1->AxisX->Title = L"Interpolated Recall";
			chartArea1->AxisY->CustomLabels->Add(customLabel2);
			chartArea1->AxisY->MajorGrid->Enabled = false;
			chartArea1->AxisY->Title = L"Precision";
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Enabled = false;
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(2, 103);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series1->IsXValueIndexed = true;
			series1->Legend = L"Legend1";
			series1->Name = L"Series1";
			series1->YValuesPerPoint = 2;
			this->chart1->Series->Add(series1);
			this->chart1->Size = System::Drawing::Size(451, 276);
			this->chart1->TabIndex = 19;
			this->chart1->Text = L"chart1";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label14->Location = System::Drawing::Point(84, 84);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(0, 16);
			this->label14->TabIndex = 18;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label13->Location = System::Drawing::Point(4, 84);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(84, 16);
			this->label13->TabIndex = 17;
			this->label13->Text = L"R-Precision: ";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label12->Location = System::Drawing::Point(44, 68);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(0, 16);
			this->label12->TabIndex = 16;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->Location = System::Drawing::Point(4, 68);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(40, 16);
			this->label11->TabIndex = 15;
			this->label11->Text = L"MAP:";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->Location = System::Drawing::Point(44, 42);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(0, 16);
			this->label10->TabIndex = 14;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(4, 42);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(45, 16);
			this->label9->TabIndex = 13;
			this->label9->Text = L"Time: ";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(124, 26);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(0, 16);
			this->label2->TabIndex = 12;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(5, 26);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(126, 16);
			this->label1->TabIndex = 11;
			this->label1->Text = L"Number of Queries: ";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(72, 10);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(0, 16);
			this->label8->TabIndex = 10;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(4, 10);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(72, 16);
			this->label7->TabIndex = 9;
			this->label7->Text = L"Query File:";
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(478, 728);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		this->label6->Text = "Loading inverted file, please wait......";
		this->button2->Enabled = false;
		System::ComponentModel::BackgroundWorker^ backgroundWorker1;
		backgroundWorker1 = gcnew BackgroundWorker();
		backgroundWorker1->DoWork += gcnew DoWorkEventHandler(this, &MyForm::MyThreadFunc);
		backgroundWorker1->RunWorkerCompleted += gcnew RunWorkerCompletedEventHandler(this, &MyForm::enableButton);
		backgroundWorker1->RunWorkerAsync();
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		
		OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;


		openFileDialog1->InitialDirectory = "c:\\";
		openFileDialog1->Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
		openFileDialog1->FilterIndex = 2;
		openFileDialog1->RestoreDirectory = true;
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			this->textBox1->Text = openFileDialog1->FileName;
			/*string str = msclr::interop::marshal_as< std::string >(openFileDialog1->FileName);
			
			char *fname = new char[str.length() + 1];

			strcpy(fname, str.c_str());
			strcpy(filename, fname);
			strcat(filename, "_ASDSD");
			char * temp = new char[255];
			strcpy(temp, "trec_eval_cmd.exe -a judgerobust ");
			strcat(temp, filename);

			printf("command: %s", temp);*/
			
			
		}
	}
private: System::Void fileSystemWatcher1_Changed(System::Object^  sender, System::IO::FileSystemEventArgs^  e) {
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {

	if (this->textBox1->Text == "") {
		MessageBox::Show("Please select a query file.");
		return;
	}
		

	if (this->radioBL->Checked == true) {
		this->button2->Enabled = false;
		System::ComponentModel::BackgroundWorker^ backgroundWorker1;
		backgroundWorker1 = gcnew BackgroundWorker();
		backgroundWorker1->DoWork += gcnew DoWorkEventHandler(this, &MyForm::MyThreadFunc);
		backgroundWorker1->RunWorkerCompleted += gcnew RunWorkerCompletedEventHandler(this, &MyForm::backgroundWorker1_RunWorkerCompleted);
		backgroundWorker1->RunWorkerAsync();
		this->timer1->Start();

	}
	else if (this->radioVS->Checked == true) {
		this->button2->Enabled = false;
		System::ComponentModel::BackgroundWorker^ backgroundWorker1;
		backgroundWorker1 = gcnew BackgroundWorker  ();
		backgroundWorker1->DoWork += gcnew DoWorkEventHandler(this, &MyForm::MyThreadFunc);
		backgroundWorker1->RunWorkerCompleted += gcnew RunWorkerCompletedEventHandler(this,&MyForm::backgroundWorker1_RunWorkerCompleted);
		backgroundWorker1->RunWorkerAsync();
		this->timer1->Start();


	}
	else if (this->radioFB->Checked == true) {
		this->button2->Enabled = false;
		System::ComponentModel::BackgroundWorker^ backgroundWorker1;
		backgroundWorker1 = gcnew BackgroundWorker();
		backgroundWorker1->DoWork += gcnew DoWorkEventHandler(this, &MyForm::MyThreadFunc);
		backgroundWorker1->RunWorkerCompleted += gcnew RunWorkerCompletedEventHandler(this, &MyForm::backgroundWorker1_RunWorkerCompleted);
		backgroundWorker1->RunWorkerAsync();
		this->timer1->Start();

	}
	else if (this->radioButton1->Checked == true) {
		this->button2->Enabled = false;
		System::ComponentModel::BackgroundWorker^ backgroundWorker1;
		backgroundWorker1 = gcnew BackgroundWorker();
		backgroundWorker1->DoWork += gcnew DoWorkEventHandler(this, &MyForm::MyThreadFunc);
		backgroundWorker1->RunWorkerCompleted += gcnew RunWorkerCompletedEventHandler(this, &MyForm::backgroundWorker1_RunWorkerCompleted);
		backgroundWorker1->RunWorkerAsync();
		this->timer1->Start();

	}
	else {
		MessageBox::Show("Please select a model");
	}
	
}
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	this->progressBar1->Increment(1);
	System::Windows::Forms::Application::DoEvents();
}
		 void MyThreadFunc(Object^ sender, DoWorkEventArgs^ e) {
			 System::String ^ managedString = this->textBox1->Text;

			 
			 string str = msclr::interop::marshal_as< std::string >(managedString);
			 begin = time(NULL);
			 char *fname = new char[str.length() + 1];
			 char *temp = new char[255];
			 strcpy(fname, str.c_str());
			 strcpy(temp, fname);
			 temp = strtok(temp, "\\");
			 while (temp != NULL) {
				 strcpy(filename, temp);
				 temp = strtok(NULL, "\\");
			 }
			 //InvFile.LoadInvFile();
			 

			 //InvFile.LoadDocRec();
			 if (InvFile.htable == NULL) {
				 printf("Load Inverted File......\n");
				 
				 InvFile.MakeHashTable(13023973);

				 InvFile.ReadPostFile("InvFile.txt");
				 printf("Load Document Length File.....\n");
				 InvFile.ReadDocFile("DocLen.txt");
				
				 return;
			 }


			 if (this->radioVS->Checked == true && this->radioButton5->Checked) {
				 printf("Begin to retrieve...\n");
				 strcat(filename, "_VSMresult");
				 InvFile.Retrieval(fname,0,false);
			 }
			 else if (this->radioVS->Checked == true && this->radioButton4->Checked) {
				 printf("Begin to retrieve...\n");
				 strcat(filename, "_VSMresult");
				 InvFile.Retrieval(fname, 0, true);

			 }
			 else if (this->radioButton1->Checked == true) {
				 printf("Begin to retrieve...\n");
				 filename = strcat(filename, "_VSMEDresult");
				 InvFile.Retrieval(fname, 1, true);

			 }
			 else if (this->radioBL->Checked == true) {
				 printf("Begin to retrieve...\n");
				 strcat(filename, "_BMresult");
				 InvFile.Retrieval(fname, 3, true);

			 }
			 else if (this->radioFB->Checked == true) {
				 printf("Begin to retrieve...\n");
				 strcat(filename, "_FBMresult");
				 InvFile.Retrieval(fname, 4, true);

			 }
			 
			 


			// delete[] fname;

			 
		 }
		 void enableButton(Object^ /*sender*/, RunWorkerCompletedEventArgs^ e)
		 {
			 this->button2->Enabled = true;
			 this->label6->Text = "Select a query file and a retrival model";
		 }
		 void backgroundWorker1_RunWorkerCompleted(Object^ /*sender*/, RunWorkerCompletedEventArgs^ e)
		 {
			 char   psBuffer[255];
			 int numOfQueries = 0;

			 float map = 0;
			 float rp = 0;
			 float ir[9];
			 float p[9];
			 int curIR = 0;
			 int curP = 0;

			 FILE   *pPipe;
			 this->button2->Enabled = true;
			 char * temp = new char[255];
			 strcpy(temp, "trec_eval_cmd.exe -a judgerobust ");
			 strcat(temp, filename);
			 printf("command: %s", temp);
			 //const char *cstr = temp.c_str();
			 if ((pPipe = _popen(temp, "rt")) == NULL)
				 exit(1);

			 while (fgets(psBuffer, 255, pPipe))
			 {
				 printf("%s", psBuffer);

				 if (strstr(psBuffer, "num_q") != NULL) {

					 char * pch;
					 char temp[255];


					 pch = strtok(psBuffer, " \t");
					 while (pch != NULL) {
						 strcpy(temp, pch);
						 pch = strtok(NULL, " \t");
					 }


					 numOfQueries = atoi(temp);
				 }
				 else if (strstr(psBuffer, "map ") != NULL && strstr(psBuffer, "int_map ") == NULL) {
					 char * pch;
					 char temp[255];
					 pch = strtok(psBuffer, " \t");
					 while (pch != NULL) {
						 strcpy(temp, pch);

						 pch = strtok(NULL, " \t");
					 }
					 map = stof(temp);
				 }
				 else if (strstr(psBuffer, "R-prec ") != NULL && strstr(psBuffer, "0R-prec ") == NULL) {
					 char * pch;
					 char temp[255];
					 pch = strtok(psBuffer, " \t");
					 while (pch != NULL) {
						 strcpy(temp, pch);
						 pch = strtok(NULL, " \t");
					 }

					 rp = stof(temp);
				 }
				 else if (strstr(psBuffer, "ircl_prn") != NULL) {
					 char * pch;
					 char temp[255];
					 pch = strtok(psBuffer, " \t");
					 while (pch != NULL) {
						 strcpy(temp, pch);
						 pch = strtok(NULL, " \t");
					 }
					 ir[curIR++] = stof(temp);
				 }
				 else if (strstr(psBuffer, "P") != NULL && strstr(psBuffer, "infAP") == NULL) {
					 char * pch;
					 char temp[128];
					 pch = strtok(psBuffer, " \t");
					 while (pch != NULL) {
						 strcpy(temp, pch);
						 pch = strtok(NULL, " \t");
					 }
					 p[curP++] = stof(temp);
				 }

			 }
			 int end = time(NULL);
			 this->label8->Text = this->textBox1->Text;

			 printf("number of queries: %d\n", numOfQueries);
			 this->label2->Text = numOfQueries + "";


			 printf("Time: %d min %d s\n", (end - begin) / 60, (end - begin) % 60);
			 this->label10->Text = ((end - begin) / 60) + " min " + ((end - begin) % 60) + " s";


			 printf("MAP: %d%%\n", (int)(map * 100));
			 this->label12->Text = (int)(map * 100) + "%";

			 printf("R-Precision: %d%%\n", (int)(rp * 100));
			 this->label14->Text = (int)(rp * 100) + "%";

			 int i = 0;
			 this->chart1->Series["Series1"]->Points->Clear();
			 for (i = 0; i < 9;i++) {
				 this->chart1->Series["Series1"]->Points->AddXY(ir[i], p[i]);
			 }

			 if (feof(pPipe))
			 {
				 printf("\nProcess returned %d\n", _pclose(pPipe));
			 }
			 else
			 {
				 printf("Error: Failed to read the pipe to the end.\n");
			 }

			 this->timer1->Stop();
			 this->progressBar1->Value = 0;

		 }

private: System::Void panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
}
};
}
