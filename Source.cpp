#include <iostream>


template<typename T>
class Point 
{
	T x, y, z;
public:
	//конструктор без параметров
	Point()
	{
		x = 0;
		y = 0;
		z = 0;
	}

	//конструктор с параметрами
	Point(T x, T y, T z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	//конструктор копирования
	Point(const Point & other)
	{
		this->x = other.x;
		this->y = other.y;
		this->z = other.z;
	}

	//перегрузка оператора =
	Point& operator=(const Point & other) 
	{
		this->x = other.x;
		this->y = other.y;
		this->z = other.z;
		return*this;
	}

	//перегрузка оператора +
	Point operator+(const Point & other)
	{
		Point tmp;
		tmp.x = this->x + other.x;
		tmp.y = this->y + other.y;
		tmp.z = this->z + other.z;
		return tmp;
	}

	//перегрузка оператора +=
	Point& operator+=(const Point & other)
	{
		this->x = this->x + other.x;
		this->y = this->y + other.y;
		this->z = this->z + other.z;
		return *this;
	}

	//перегрузка оператора ++ (префикс)
	Point  operator++()
	{
		this->x++;
		this->y++;
		this->z++;
		return*this;
	}

	//перегрузка оператора ++ (постфикс)
	Point operator++(int value)
	{
		Point tmp(*this);
		this->x++;
		this->y++;
		this->z++;
		return tmp;
	}
	
	//перегрузка оператора <<
	friend std::ostream& operator<<(std::ostream& stream, const Point& other)
	{
		stream << other.x << " " << other.y << " " << other.z;
		return stream;
	}
};





template <typename T>
class Matrix
{
	T** arr;
	int line;
	int column;
public:
	//конструктор без параметров 
	Matrix() 
	{
		arr = nullptr;
	}

	//конструктор с параметрами
	Matrix(int line, int column)
	{
		this->line = line;
		this->column = column;
		arr = new T* [line];
		for (int i = 0; i < line; i++)
		{
			arr[i] = new T[column];
		}
	}

	//конструктор копирования
	Matrix(const Matrix & other)
	{
		this->line = other.line;
		this->column = other.column;
		this->arr = new T * [line];
		for (int i = 0; i < line; i++)
		{
			this->arr[i] = new T[column];
		}
		for (int i = 0; i < line; i++) {
			for (int j = 0; j < column; j++) {
				this->arr[i][j] = other.arr[i][j];
			}
		}
	}

	

	//заполнение массива int
	void filling_arr_int()
	{
		for (int i = 0; i <line; i++) {
			for (int j = 0; j < column; j++) {
				 arr[i][j] =i*(line-1) + j;
			}
		
		}
	}

	//заполнение массива char
	void filling_arr_char()
	{
		
		for (int i = 0; i < line; i++) {
			for (int j = 0; j < column; j++) {
				std::cin>>arr[i][j];
			}

		}
	}

	//пегрузка оператора <<
	friend std::ostream& operator<<(std::ostream& out, const Matrix<T>& other)
	{
		for (int i = 0; i < other.line; i++) {
			for (int j = 0; j < other.column; j++) {
				out << other.arr[i][j] << "\t";
			}
			out << std::endl;
		}
		return out;
	}

	//деструктор
	~Matrix()
	{
		for (int i = 0; i < line; i++)
		{	
			delete[] arr[i];
		}
	}
};







int main()
{
	Point<double> z(1, 2, 3);
	Point<double> w(3, 2, 1);
	Point<double> y;
	y = z + w;
	std::cout << y;

	Matrix<int> a(2,3);
	a.filling_arr_int();
	std::cout << a<<std::endl;

	Matrix<int> b = a;
	std::cout << b;
	return 0;
}