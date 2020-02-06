#include <stdio.h>
#include <stdio.h>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iostream>


using namespace std;

int main ()
{
  int FIB[5]={1,2,3,5,8}; //числа Фибоначи в массиве
  string line;   //строка из входящего файла
  string s; //строка для хранения числа
  string t; //строка для хранения первго слова
  ofstream clear_file("output.txt",ios::out); //очистка файла
  ifstream myfile ("source.txt");  //создаем поток файла
  if (myfile.is_open())           //открываем файл для проверки
  {
	while (! myfile.eof() )
	{getline (myfile,line);
		  s=line.substr(3);  //записываем в s цыфру из текущей строки
		  t=line.substr(0,3);
		  int num=atoi(s.c_str());//замена типа даних число=строка
		  for(int i=0; i<5; i++)   //обход масива для проверки условий
			  if((num!=0)&&(num==FIB[i])) {//проверка условия принадлежности числа к числам фибоначи
				int j=t.size(); //переменная размера строки
				j++; //увиличим на 1 для пропуска(пробел)
				 while(--j!=-1)  {
					 s+=t[j];  //добавляем к числу обратную строку
				 }  //откріваем файл для записи
				ofstream fileout; //создаем поток файла для выгрузки
				fileout.open("output.txt",ios::out | ios::app); //открываем файл для записи
				fileout<<s<<"\n";   //добавляем строку в файл
				fileout.close(); //закрываем файл выгрузки
			  }
		}
	myfile.close(); //закрываем исходный файл
  }
   return 0;
  }
