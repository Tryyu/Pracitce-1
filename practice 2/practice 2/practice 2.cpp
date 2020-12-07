// practice 2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <chrono>

using namespace std;

const int Num = 100;

void bubbleSorting(int* Mas) {
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 99; j++) {
			if (Mas[j] > Mas[j + 1]) {
				swap(Mas[j], Mas[j + 1]);
			}
		}
	}
}

void quicksort(int* Mas, int  end, int begin)
{
	int mid;
	int f = begin;
	int l = end;
	mid = Mas[(f + l) / 2];
	while (f < l)
	{
		while (Mas[f] < mid) f++;
		while (Mas[l] > mid) l--;
		if (f <= l)
		{
			swap(Mas[f], Mas[l]);
			f++;
			l--;
		}
	}
	if (begin < l) quicksort(Mas, l, begin);
	if (f < end) quicksort(Mas, end, f);
}

void RandomMas(int* Mas)
{
    for (int i = 0; i < Num; i++)
    {
        Mas[i] = rand() % 201 - 100;
    }
    for (int i = 0; i < Num; i++)
    {
        cout << Mas[i] << endl;
    }
}

void averageValue(int max, int min, int* Mass) 
{
	int coincidences = 0;
	int average;

	average = (max + min) / 2;

	for (int i = 0; i < 100; i++)
	{
		if (Mass[i] == average) {
			coincidences++;
			cout << "Индекс числа в массиве равного среднему " << i << "\n" << endl;
		}
	}

	cout << "Среднее значение максимального и минимального: " << average << " Количество совпадений: " << coincidences << "\n" << endl;
}

void findMaxMinAverage(int max, int min, int* Mas) {


	for (int i = 0; i < 100; i++) {
		if (Mas[i] > max) {
			max = Mas[i];
		}
	}

	for (int j = 99; j >= 0; j--) {
		if (Mas[j] < min) {
			min = Mas[j];
		}
	}
	averageValue(max, min, Mas);
	cout <<"Максимальное значение: " <<  max << " Минимальное значение: " << min << "\n" << endl;
}

void alreadysort(int* Mas)
{
	int max = 0, min = 0;

	auto startmaxmin = chrono::system_clock::now();
	findMaxMinAverage(min, max, Mas);
	auto endmaxmin = chrono::system_clock::now();
	chrono::duration<double> elapsedmm = endmaxmin - startmaxmin;
	cout << "Затраченное время на поиск минимального и максмального занчения: " << elapsedmm.count() << " секунд" << "\n" << endl;

	int end = Num - 1, begin = 0;
	auto start = chrono::system_clock::now();
	quicksort(Mas, end, begin);
	auto endtime = chrono::system_clock::now();
	chrono::duration<double> elapsed = endtime - start;
	cout << "Затраченное время на быструю сортировку: " << elapsed.count() << " секунд" << "\n" << endl;

	auto startmaxminafter = chrono::system_clock::now();
	findMaxMinAverage(min, max, Mas);
	auto endmaxminafter = chrono::system_clock::now();
	chrono::duration<double> elapsedmmafter = endmaxminafter - startmaxminafter;
	cout << "Затраченное время на поиск минимального и максмального занчения в отсортированном массиве: " << elapsedmmafter.count() << " секунд" << "\n" << endl;

	for (int a = 0; a < Num; a++)
	{
		cout << Mas[a] << endl;
	}
}

void moreThem(int a, int* Mas) {
	int count = 0;
	for (int i = 0; i < 100; i++) {
		if (Mas[i] > a) {
			count++;
		}
	}
	cout << "Количесво элементов больше введенного числа: " << count << endl;
}

void lessThem(int b, int* Mas) {
	int count = 0;
	for (int i = 0; i < 100; i++) {
		if (Mas[i] < b) {
			count++;
		}
	}
	cout << "Количесво элементов меньше введенного числа: " << count << endl;
}

void binarysearch(int c, int* Mas)
{
	int left = 0, right = 99;
	bool flag = false;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (c == Mas[mid])
		{
			flag = true;
			cout << "Значение найдено" << endl;
			break;
		}
		if (c > Mas[mid])
		{
			left = mid + 1;
		}
		if (c < Mas[mid])
		{
			right = mid - 1;
		}
	}
	if (flag == false) 
	{
		cout << "Значение не найдено" << endl;
	}
}

void bruteforceofnumber(int c, int *Mas)
{
	bool flag = false;
	for (int a = 0; a < 100; a++)
	{	
		if (c == Mas[a])
		{
			flag = true;
			cout << "Число найдено" << endl;
			break;
		}
	}
	if (flag == false)
	{
		cout << "Число не найдено" << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");

	int a, b, c,
		Mas[Num],MasBubble[Num];

	RandomMas(Mas);
	
	for (int i = 0; i < 100; i++)
	{
		MasBubble[i] = Mas[i];
	}

	auto startbubble = chrono::system_clock::now();
	bubbleSorting(MasBubble);
	auto endbubble = chrono::system_clock::now();
	chrono::duration<double> elapsedbubble = endbubble - startbubble;
	cout << "Затраченное время на сортировку пузырьком: " << elapsedbubble.count() << " секунд" << "\n" << endl;

	alreadysort(Mas);

	cout << "Введите число для поиска в массиве количества элементов больше чем это число" << endl;
	cin >> a;
	moreThem(a, Mas);

	cout << "Введите число для поиска в массиве количества элементов меньше чем это число" << endl;
	cin >> b;
	lessThem(b, Mas);

	cout << "Введите чило для бинарного/переборного поиска: " << endl;
	cin >> c;

	auto startBin = chrono::system_clock::now();
	binarysearch(c, Mas);
	auto endBin = chrono::system_clock::now();
	chrono::duration<double> elapsedBin = endBin - startBin;
	cout << "Затраченное время на бинарный поиск: " << elapsedBin.count() << " секунд" << "\n" << endl;

	auto startBrute = chrono::system_clock::now();
	bruteforceofnumber(c, Mas);
	auto endBrute = chrono::system_clock::now();
	chrono::duration<double> elapsedBrute = endBrute - startBrute;
	cout << "Затраченное время на поиск перебором: " << elapsedBrute.count() << " секунд" << "\n" << endl;

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
