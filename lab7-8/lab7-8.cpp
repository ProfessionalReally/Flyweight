#include "Header.h"


int main()
{
	ExpertMedicalSystem* EXM = new ExpertMedicalSystem();

	int n = 25;
	cout << "CREATE\n\n";
	//Создаем
	for (int i = 0; i < n; i++)
	{
		EXM->CreateDiagnosis(i)->PrintDiagnosis();
	}
	cout << "\n\nCHECKING\n\n";
	//Проходим еще раз
	for (int i = 0; i < n; i++)
	{
		EXM->CreateDiagnosis(i)->PrintDiagnosis();
	}
	return 0;

	delete EXM;
}
