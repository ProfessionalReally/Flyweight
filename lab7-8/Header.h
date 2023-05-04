#pragma once

#include <iostream>
#include <conio.h>
#include <string.h>
#include <string>
#include <map>

using namespace std;

//Диагноз
class Diagnosis
{
protected:
	int ID;
public:
	Diagnosis(int id) { this->ID = id; }
	virtual void PrintDiagnosis() = 0;
};

//Диагноз диабет
class DiabetesDiagnosis : public Diagnosis
{
public:	
	DiabetesDiagnosis(int id) : Diagnosis(id) {}
	virtual void PrintDiagnosis() { cout << "Diabetes Diagnosis" << endl; }
};

//Диагноз ОРВИ
class SARSDiagnosis : public Diagnosis
{
public:
	SARSDiagnosis(int id) : Diagnosis(id) {}
	virtual void PrintDiagnosis() { cout << "SARS Diagnosis" << endl; }
};

//МЭС - фабрика диагнозов
class ExpertMedicalSystem
{
private:
	typedef map<int, Diagnosis*> ArrayDiagnosis;
	ArrayDiagnosis arrayDiagnosis;
public:
	//Создать и получить диагноз
	Diagnosis* CreateDiagnosis(int id)
	{
		cout << id << ": ";
			ArrayDiagnosis::iterator it = arrayDiagnosis.find(id);
			//Если не найден, то создаем новый
			if (arrayDiagnosis.end() == it) 
			{
				cout << "(new)    - ";
				Diagnosis* diagnosis;
				//Если четный id
				if (id % 2 == 0) 
				{ 
					diagnosis = new DiabetesDiagnosis(id);
				}
				//Иначе
				else 
				{
					diagnosis = new SARSDiagnosis(id);
				}
				arrayDiagnosis[id] = diagnosis;
				return diagnosis;
			}
			//Если найден, то возвращаем
			else {
				cout << "(Was created before) - ";
				return it->second;
			}
	}

	//Деструктор
	~ExpertMedicalSystem()
	{
		ArrayDiagnosis::iterator it = arrayDiagnosis.begin();
		for (int i = 0; it != arrayDiagnosis.end(); it++, i++)
		{
			delete arrayDiagnosis[i];
		}
	}
};

