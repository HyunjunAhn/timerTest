static System::Windows::Forms::Timer^ myTimer = gcnew System::Windows::Forms::Timer();

myTimer->Tick += gcnew EventHandler(this, &MyForm::TimerEventProcessor);
myTimer->Interval = 1000;
myTimer->Start();

System::Void TimerEventProcessor(System::Object^ sender, System::EventArgs^ myEventArgs){
  // -- your source code --
}
