#include<iostream>
#include<string>

using namespace std;

class Tour {

private:
	//Data
	string name_tour;//Название тура
	string country;//страна тура
	string sity;//город
	string name_hotel;//название отеля
	string condition_hotel;//условия проживания 
	string condition_travel;
	string service;
	int excurs;//1-есть, 0-нет
	int price;//цена

public:
	//методы set для всехполей Data
	void set_name_tour(string line)
	{
		name_tour = line;
	}
	void set_country(string line)
	{
		country = line;
	}
	void set_sity(string line)
	{
		sity = line;
	}
	void set_name_hotel(string line)
	{
		name_hotel = line;
	}
	void set_condition_hotel(string line)
	{
		condition_hotel = line;
	}
	void set_condition_travel(string line)
	{
		condition_travel = line;
	}
	void set_service(string line)
	{
		service = line;
	}
	void set_excurs(int n)
	{
		excurs = n;
	}
	void set_price(int n)
	{
		price = n;
	}
	// методы get для всех полей Data
	string get_name_tour()
	{
		return name_tour;
	}
	string get_country()
	{
		return country;
	}
	string get_sity()
	{
		return sity;
	}
	string get_name_hotel()
	{
		return name_hotel;
	}
	string get_condition_hotel()
	{
		return condition_hotel;
	}
	string get_condition_travel()
	{
		return condition_travel;
	}
	string get_service()
	{
		return service;
	}
	int get_excurs()
	{
		return excurs;
	}
	int get_price()
	{
		return price;
	}

	void show_tour()
	{
		cout << "Название тура: " << name_tour << "." << endl << "Страна:" << country << "." << endl << "Город: " << sity << "." << endl << "Название отеля: " << name_hotel << "." << endl << "Условия проживания: " << condition_hotel << "." << endl << "Условия проезда: " << condition_travel << "." << endl << "Сервис: " << service << "." << endl << "Экскусрии(Если 1, то есть, если 0, то нет): " << excurs << "." << endl << "Цена: " << price << "." << endl;
	}

	void show_hotel_list()
	{
		cout << "Название отеля: " << name_hotel << "." << endl << "Условия проживания: " << condition_hotel << "." << endl;
	}
};

void set_data(int i, class Tour *ptr_tour)
{
	string line;
	int k;

	cout << "Введите название тура:";
	getline(cin, line);
	(ptr_tour + i)->set_name_tour(line);
	cout << endl;

	cout << "Введите страну: ";
	getline(cin, line);
	(ptr_tour + i)->set_country(line);
	cout << endl;

	cout << "Введите город: ";
	getline(cin, line);
	(ptr_tour + i)->set_sity(line);
	cout << endl;

	cout << "Введите название отеля: ";
	getline(cin, line);
	(ptr_tour + i)->set_name_hotel(line);
	cout << endl;

	cout << "Введите условия проживания в отеле: ";
	getline(cin, line);
	(ptr_tour + i)->set_condition_hotel(line);
	cout << endl;

	cout << "Введите условия проезда: ";
	getline(cin, line);
	(ptr_tour + i)->set_condition_travel(line);
	cout << endl;

	cout << "Введите сервис: ";
	getline(cin, line);
	(ptr_tour + i)->set_service(line);
	cout << endl;

	cout << "[1] есть экскурсии " << endl << "[0] нет экскурсий";
	cin >> k;
	(ptr_tour + i)->set_excurs(k);
	cout << endl;

	cout << "Введите цену: ";
	cin >> k;
	(ptr_tour + i)->set_price(k);
	cout << endl;

	cin.ignore(100, '\n');
}

void get_inf(int N, class Tour *ptr_tour)//информацию о турах по заданной стране
{
	system("cls");

	string line;
	int i, flag = 0;
	cout << "Введите страну, информацию о турах которой вы хотите получить: ";
	getline(cin, line);
	cout << endl << endl;

	for (i = 0; i < N; i++)
	{
		if (line == (ptr_tour + i)->get_country())
		{
			(ptr_tour + i)->show_tour();
			flag = 1;
		}
		
	}
	if (flag == 0)
	{
		cout << "Такие туров НЕТ!!!СИДИ ДОМА!!!" << endl;
	}
	system("pause");
}

void get_inf_e_p(int N, class Tour *ptr_tour)//информацию о турах по заданной стране с экскурсиями и ценой, не выше заданной;
{
	system("cls");

	string line;
	int i, max_price, flag = 0;
	cout << "Введите страну, информацию о турах которой вы хотите получить: ";
	getline(cin, line);
	cout << "Введите максимальную цену: ";
	cin >> max_price;
	cin.ignore(100, '\n');
	cout << endl << endl;

	for (i = 0; i < N; i++)
	{
		if ((line == (ptr_tour + i)->get_country()) && (max_price >= (ptr_tour + i)->get_price()) && ((ptr_tour + i)->get_excurs() == 1))
		{
			(ptr_tour + i)->show_tour();
			flag = 1;
		}

	}
	if (flag == 0)
	{
		cout << "Такие туров НЕТ!!!СИДИ ДОМА!!!" << endl;
	}
	system("pause");
}

void get_list_hotel(int N, class Tour *ptr_tour)//список отелей в заданном городе.
{
	system("cls");

	string line;
	int i, flag = 0;
	cout << "Введите город, информацию о отелях которого вы хотите получить: ";
	getline(cin, line);
	cout << endl << endl;

	for (i = 0; i < N; i++)
	{
		if (line == (ptr_tour + i)->get_sity())
		{
			(ptr_tour + i)->show_hotel_list();
			flag = 1;
		}
	}
	if (flag == 0)
	{
		cout << "Такие отелей НЕТ!!!СИДИ ДОМА!!!" << endl;
	}
	system("pause");
}

int main()
{
	system("chcp 1251");

	string line;
	int N, i, choice;
	class Tour *ptr_tour;


	cout << "Введите колличество туров: ";
	cin >> N;
	ptr_tour = new class Tour[N];//Выделение памяти для N туров
	cout << endl;
	cin.ignore(100, '\n');
	//Заполнение полей Data для N туров
	for (i = 0; i < N; i++)
	{
		set_data(i, ptr_tour);
	}

	do {
		system("cls");
		cout << "[1] Получить информацию о турах по заданной стране." << endl << "[2] Получить  информацию о турах по заданной стране с экскурсиями и ценой, не выше заданной." << endl << "[3] Получить список отелей в заданном городе." << endl << "[0] Выйти из программы" << endl;
		cin >> choice;
		cin.ignore(100, '\n');
		switch (choice)
		{
		case 1:
			get_inf(N, ptr_tour);
			break;
		case 2:
			get_inf_e_p(N, ptr_tour);
			break;
		case 3:
			get_list_hotel(N, ptr_tour);
			break;
		};
	} while (choice);

	delete[](ptr_tour);//освобождение памяти
	return 0;
}
