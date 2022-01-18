#include "pch.h"

using namespace System;

//int main(array<System::String ^> ^args)
//{
//    return 0;
//}
#define TAPBAG "tapered baguette"
#include "Form1.h"

using namespace System::Windows::Forms;

//private delegate void DelOpt();
[STAThread]
int main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew CppCLRWinformsProjekt::Form1()); 


	return 0;
}