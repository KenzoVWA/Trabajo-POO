//#pragma once
//
//namespace JuegoMegaman {
//
//	using namespace System;
//	using namespace System::ComponentModel;
//	using namespace System::Collections;
//	using namespace System::Windows::Forms;
//	using namespace System::Data;
//	using namespace System::Drawing;
//
//	/// <summary>
//	/// Resumen de frmPrincipal
//	/// </summary>
//	public ref class frmPrincipal : public System::Windows::Forms::Form
//	{
//	public:
//		frmPrincipal(void)
//		{
//			InitializeComponent();
//			//
//			//TODO: agregar código de constructor aquí
//			//
//		}
//
//	protected:
//		/// <summary>
//		/// Limpiar los recursos que se estén utilizando.
//		/// </summary>
//		~frmPrincipal()
//		{
//			if (components)
//			{
//				delete components;
//			}
//		}
//
//	private:
//		/// <summary>
//		/// Variable del diseñador requerida.
//		/// </summary>
//		System::ComponentModel::Container ^components;
//
//#pragma region Windows Form Designer generated code
//		/// <summary>
//		/// Método necesario para admitir el Diseñador. No se puede modificar
//		/// el contenido del método con el editor de código.
//		/// </summary>
//		void InitializeComponent(void)
//		{
//			this->SuspendLayout();
//			// 
//			// frmPrincipal
//			// 
//			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
//			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
//			this->ClientSize = System::Drawing::Size(284, 261);
//			this->Name = L"frmPrincipal";
//			this->Text = L"frmPrincipal";
//			this->Load += gcnew System::EventHandler(this, &frmPrincipal::frmPrincipal_Load);
//			this->ResumeLayout(false);
//
//		}
//#pragma endregion
//	private: System::Void frmPrincipal_Load(System::Object^  sender, System::EventArgs^  e) {
//			 }
//	};
//}



#pragma once

namespace JuegoMegaman {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for frmPrincipal
	/// </summary>

	#include "CJuego.h"
	

	public ref class frmPrincipal : public System::Windows::Forms::Form
	{
	private:
		CJuego *objJuego;
		Bitmap ^imgFondo;
		Bitmap ^imgFondo2;
		Bitmap ^imgFondo3;
		Bitmap ^imgMegaman;
		Bitmap ^imgEnemigo;
		Bitmap ^imgLogo;
		int auxiliar;

	private: System::Windows::Forms::PictureBox^  pbEnemigo;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::PictureBox^  pbFondo2;
	private: System::Windows::Forms::PictureBox^  pbFondo3;
	private: System::Windows::Forms::Label^  label10;

			 Bitmap ^imgPoder;

	public:
		frmPrincipal(void)
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
		~frmPrincipal()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::PictureBox^  pbMegaman;
	private: System::Windows::Forms::PictureBox^  pbFondo;

	private: System::Windows::Forms::PictureBox^  pbPoder;
	protected: 
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{	 
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(frmPrincipal::typeid));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->pbMegaman = (gcnew System::Windows::Forms::PictureBox());
			this->pbFondo = (gcnew System::Windows::Forms::PictureBox());
			this->pbPoder = (gcnew System::Windows::Forms::PictureBox());
			this->pbEnemigo = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->pbFondo2 = (gcnew System::Windows::Forms::PictureBox());
			this->pbFondo3 = (gcnew System::Windows::Forms::PictureBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbMegaman))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbFondo))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbPoder))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbEnemigo))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbFondo2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbFondo3))->BeginInit();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &frmPrincipal::timer1_Tick);
			// 
			// pbMegaman
			// 
			this->pbMegaman->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pbMegaman.Image")));
			this->pbMegaman->Location = System::Drawing::Point(271, 39);
			this->pbMegaman->Name = L"pbMegaman";
			this->pbMegaman->Size = System::Drawing::Size(100, 50);
			this->pbMegaman->TabIndex = 0;
			this->pbMegaman->TabStop = false;
			this->pbMegaman->Visible = false;
			// 
			// pbFondo
			// 
			this->pbFondo->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pbFondo.Image")));
			this->pbFondo->Location = System::Drawing::Point(377, 39);
			this->pbFondo->Name = L"pbFondo";
			this->pbFondo->Size = System::Drawing::Size(100, 50);
			this->pbFondo->TabIndex = 1;
			this->pbFondo->TabStop = false;
			this->pbFondo->Visible = false;
			// 
			// pbPoder
			// 
			this->pbPoder->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pbPoder.Image")));
			this->pbPoder->Location = System::Drawing::Point(533, 35);
			this->pbPoder->Name = L"pbPoder";
			this->pbPoder->Size = System::Drawing::Size(148, 86);
			this->pbPoder->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbPoder->TabIndex = 3;
			this->pbPoder->TabStop = false;
			this->pbPoder->Visible = false;
			// 
			// pbEnemigo
			// 
			this->pbEnemigo->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pbEnemigo.Image")));
			this->pbEnemigo->Location = System::Drawing::Point(170, 35);
			this->pbEnemigo->Name = L"pbEnemigo";
			this->pbEnemigo->Size = System::Drawing::Size(100, 50);
			this->pbEnemigo->TabIndex = 2;
			this->pbEnemigo->TabStop = false;
			this->pbEnemigo->Visible = false;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(476, 39);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(51, 25);
			this->pictureBox1->TabIndex = 4;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Visible = false;
			// 
			// button1
			// 
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->button1->Font = (gcnew System::Drawing::Font(L"Arial", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button1->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button1->Location = System::Drawing::Point(158, 205);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(112, 47);
			this->button1->TabIndex = 5;
			this->button1->Text = L"Jugar!";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &frmPrincipal::button1_Click_1);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Red;
			this->panel1->Controls->Add(this->label1);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(729, 121);
			this->panel1->TabIndex = 6;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label1->Location = System::Drawing::Point(36, 39);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(392, 55);
			this->label1->TabIndex = 0;
			this->label1->Text = L"TRABAJO FINAL";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(527, 389);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(42, 18);
			this->label2->TabIndex = 7;
			this->label2->Text = L"UPC";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(397, 334);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(280, 18);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Kenzo Van Waerebeek y Esteban Vilca";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(418, 361);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(235, 18);
			this->label4->TabIndex = 9;
			this->label4->Text = L"Profesor: Jaylli Arteaga, Progra II";
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(420, 126);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(220, 205);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pictureBox2->TabIndex = 10;
			this->pictureBox2->TabStop = false;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Arial", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(43, 297);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(91, 15);
			this->label5->TabIndex = 11;
			this->label5->Text = L"Instrucciones :";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(73, 409);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(393, 14);
			this->label6->TabIndex = 12;
			this->label6->Text = L"La letra \'a\' es tu disparo. Recuerda que solo puedes hacer 10 disparos a la vez.";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(72, 338);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(212, 14);
			this->label7->TabIndex = 13;
			this->label7->Text = L"Usa las teclas direccionales para moverte.";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(73, 361);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(200, 14);
			this->label8->TabIndex = 14;
			this->label8->Text = L"Puedes saltar con la barra espaciadora.";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(73, 386);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(290, 14);
			this->label9->TabIndex = 15;
			this->label9->Text = L"La letra \'s\' es un ataque especial, te costara algo de vida...";
			// 
			// pbFondo2
			// 
			this->pbFondo2->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pbFondo2.Image")));
			this->pbFondo2->Location = System::Drawing::Point(12, 35);
			this->pbFondo2->Name = L"pbFondo2";
			this->pbFondo2->Size = System::Drawing::Size(100, 50);
			this->pbFondo2->TabIndex = 16;
			this->pbFondo2->TabStop = false;
			this->pbFondo2->Visible = false;
			// 
			// pbFondo3
			// 
			this->pbFondo3->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pbFondo3.Image")));
			this->pbFondo3->Location = System::Drawing::Point(75, 35);
			this->pbFondo3->Name = L"pbFondo3";
			this->pbFondo3->Size = System::Drawing::Size(100, 50);
			this->pbFondo3->TabIndex = 17;
			this->pbFondo3->TabStop = false;
			this->pbFondo3->Visible = false;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(73, 439);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(397, 14);
			this->label10->TabIndex = 18;
			this->label10->Text = L"Atrapa los bonus azules para recuperar oxígeno y los rojos para recuperar vida.";
			// 
			// frmPrincipal
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 14);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(729, 462);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->pbPoder);
			this->Controls->Add(this->pbEnemigo);
			this->Controls->Add(this->pbFondo);
			this->Controls->Add(this->pbMegaman);
			this->Controls->Add(this->pbFondo3);
			this->Controls->Add(this->pbFondo2);
			this->Font = (gcnew System::Drawing::Font(L"Arial", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->Name = L"frmPrincipal";
			this->Text = L"Trabajo Final";
			this->Load += gcnew System::EventHandler(this, &frmPrincipal::frmPrincipal_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &frmPrincipal::frmPrincipal_KeyDown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbMegaman))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbFondo))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbPoder))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbEnemigo))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbFondo2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbFondo3))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void frmPrincipal_Load(System::Object^  sender, System::EventArgs^  e) {
				 Graphics ^g=this->CreateGraphics();

				 imgLogo = gcnew Bitmap(pictureBox2->Image);
				 imgLogo->MakeTransparent(imgLogo->GetPixel(1,1));
				 Rectangle origen = Rectangle(0,0,imgLogo->Width,imgLogo->Height);
				 Rectangle destino = Rectangle(50,50,50,50);
				 g->DrawImage(imgLogo, destino, origen, GraphicsUnit::Pixel);

				 objJuego = new CJuego(this->ClientRectangle.Width, this->ClientRectangle.Height);
				 imgMegaman = gcnew Bitmap(pbMegaman->Image);
				 imgMegaman -> MakeTransparent(imgMegaman->GetPixel(1, 1));
				 
				 imgEnemigo = gcnew Bitmap(pbEnemigo->Image);
				 imgEnemigo -> MakeTransparent(imgEnemigo->GetPixel(1, 1));

				 imgPoder =gcnew Bitmap(pbPoder->Image);
				 imgPoder -> MakeTransparent(imgPoder->GetPixel(1, 1));

				 imgFondo = gcnew Bitmap(pbFondo->Image);
				 imgFondo2 = gcnew Bitmap(pbFondo2->Image);
				 imgFondo3 = gcnew Bitmap(pbFondo3->Image);
				 			 
			 }
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {

				 Graphics ^g = this->CreateGraphics();
				 int AnchoF = this->ClientRectangle.Width;
				 int LargoF = this->ClientRectangle.Height;
				 

				 BufferedGraphicsContext ^espacioBuffer = BufferedGraphicsManager::Current;
				 espacioBuffer->MaximumBuffer = System::Drawing::Size( AnchoF + 1, LargoF + 1 );

				 BufferedGraphics ^buffer = espacioBuffer->Allocate( g, Rectangle(0, 0, AnchoF, LargoF));

				 if(objJuego->get_puntaje()==50){
					 objJuego->set_nivel(2);objJuego->set_timer(20);
				 }

				 if(objJuego->get_puntaje()==200){
					 objJuego->set_nivel(3);objJuego->set_timer(15);
				 }
				 
				 if(objJuego->get_puntaje()==450){
					 objJuego->set_nivel(4);objJuego->set_timer(10);
				 }

				 if(objJuego->get_vida()>0){
					 if(objJuego->get_puntaje()>450)
						  objJuego->Dibujar(buffer->Graphics, imgMegaman, imgEnemigo, imgPoder, imgFondo3);
					 else if(objJuego->get_puntaje()>200)
						 objJuego->Dibujar(buffer->Graphics, imgMegaman, imgEnemigo, imgPoder, imgFondo2);
					 
					 else
						 objJuego->Dibujar(buffer->Graphics, imgMegaman, imgEnemigo, imgPoder, imgFondo);
				 buffer->Render(g);
				 
				 }
				 else{
					timer1->Stop();
					MessageBox::Show("!Perdiste! Gracias por jugar");
					this->Close();
				 }

				 if(objJuego->get_puntaje()>650){
					 timer1->Stop();
					 MessageBox::Show("!Ganaste! Gracias por jugar");
					this->Close();
				 }

				 delete buffer;
				 delete g;
			 }
	private: System::Void frmPrincipal_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {

 				 if (objJuego->EstaMovimiento())
					 return;
		int anchof=this->ClientRectangle.Width;
		int megamanx=objJuego->get_Megaman()->Get_X();
		int megamandx=objJuego->get_Megaman()->Get_dX();
		int megamanancho=objJuego->get_Megaman()->Get_Ancho();
		if (e->KeyData == Keys::Right && (megamandx+megamanx+megamanancho<anchof-15))
				 {
					 objJuego->Set_Movimiento(Tipo_Movimiento::Caminar_Derecha);
				 }

		if (e->KeyData == Keys::Left&&(megamandx+ megamanx>15))
				 {
					objJuego->Set_Movimiento(Tipo_Movimiento::Caminar_Izquierda);
				 }

				 if (e->KeyData == Keys::Space)
				 {
					 objJuego->Set_Movimiento(Tipo_Movimiento::Poder);
				 }

				 if (e->KeyData == Keys::Up)
				 {
					 objJuego->Set_Movimiento(Tipo_Movimiento::Saltar);
				 }

				 if (e->KeyData == Keys::S)
				 {
					 objJuego->Set_Movimiento(Tipo_Movimiento::Especial);
				 }

			 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void button1_Click_1(System::Object^  sender, System::EventArgs^  e) {

			 delete button1;
			 label1->Visible=false;
			 panel1->Visible=false;
			 label2->Visible=false;
			 label3->Visible=false;
			 label4->Visible=false;
			 label5->Visible=false;
			 label6->Visible=false;
			 label7->Visible=false;
			 label8->Visible=false;
			 label9->Visible=false;
			 label10->Visible=false;
			 pictureBox2->Visible=false;  
			 timer1->Enabled=true;
		

		 }
};
}
