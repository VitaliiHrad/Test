#include <stdio.h>
#include <stdio.h>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iostream>


using namespace std;

int main ()
{
  int FIB[5]={1,2,3,5,8}; //����� �������� � �������
  string line;   //������ �� ��������� �����
  string s; //������ ��� �������� �����
  string t; //������ ��� �������� ������ �����
  ofstream clear_file("output.txt",ios::out); //������� �����
  ifstream myfile ("source.txt");  //������� ����� �����
  if (myfile.is_open())           //��������� ���� ��� ��������
  {
	while (! myfile.eof() )
	{getline (myfile,line);
		  s=line.substr(3);  //���������� � s ����� �� ������� ������
		  t=line.substr(0,3);
		  int num=atoi(s.c_str());//������ ���� ����� �����=������
		  for(int i=0; i<5; i++)   //����� ������ ��� �������� �������
			  if((num!=0)&&(num==FIB[i])) {//�������� ������� �������������� ����� � ������ ��������
				int j=t.size(); //���������� ������� ������
				j++; //�������� �� 1 ��� ��������(������)
				 while(--j!=-1)  {
					 s+=t[j];  //��������� � ����� �������� ������
				 }  //�������� ���� ��� ������
				ofstream fileout; //������� ����� ����� ��� ��������
				fileout.open("output.txt",ios::out | ios::app); //��������� ���� ��� ������
				fileout<<s<<"\n";   //��������� ������ � ����
				fileout.close(); //��������� ���� ��������
			  }
		}
	myfile.close(); //��������� �������� ����
  }
   return 0;
  }
