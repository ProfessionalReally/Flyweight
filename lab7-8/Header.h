#pragma once

#include <iostream>
#include <conio.h>
#include <string.h>
#include <string>
#include <map>

using namespace std;

//�������
class Diagnosis
{
protected:
	int ID;
public:
	Diagnosis(int id) { this->ID = id; }
	virtual void PrintDiagnosis() = 0;
};

//������� ������
class DiabetesDiagnosis : public Diagnosis
{
public:	
	DiabetesDiagnosis(int id) : Diagnosis(id) {}
	virtual void PrintDiagnosis() { cout << "Diabetes Diagnosis" << endl; }
};

//������� ����
class SARSDiagnosis : public Diagnosis
{
public:
	SARSDiagnosis(int id) : Diagnosis(id) {}
	virtual void PrintDiagnosis() { cout << "SARS Diagnosis" << endl; }
};

//��� - ������� ���������
class ExpertMedicalSystem
{
private:
	typedef map<int, Diagnosis*> ArrayDiagnosis;
	ArrayDiagnosis arrayDiagnosis;
public:
	//������� � �������� �������
	Diagnosis* CreateDiagnosis(int id)
	{
		cout << id << ": ";
			ArrayDiagnosis::iterator it = arrayDiagnosis.find(id);
			//���� �� ������, �� ������� �����
			if (arrayDiagnosis.end() == it) 
			{
				cout << "(new)    - ";
				Diagnosis* diagnosis;
				//���� ������ id
				if (id % 2 == 0) 
				{ 
					diagnosis = new DiabetesDiagnosis(id);
				}
				//�����
				else 
				{
					diagnosis = new SARSDiagnosis(id);
				}
				arrayDiagnosis[id] = diagnosis;
				return diagnosis;
			}
			//���� ������, �� ����������
			else {
				cout << "(Was created before) - ";
				return it->second;
			}
	}

	//����������
	~ExpertMedicalSystem()
	{
		ArrayDiagnosis::iterator it = arrayDiagnosis.begin();
		for (int i = 0; it != arrayDiagnosis.end(); it++, i++)
		{
			delete arrayDiagnosis[i];
		}
	}
};

