#include <iostream>


template<typename T>
class Point 
{
	T x, y, z;
public:
	//����������� ��� ����������
	Point()
	{
		x = 0;
		y = 0;
		z = 0;
	}

	//����������� � �����������
	Point(T x, T y, T z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	//����������� �����������
	Point(const Point & other)
	{
		this->x = other.x;
		this->y = other.y;
		this->z = other.z;
	}

	//���������� ��������� =
	Point& operator=(const Point & other) 
	{
		this->x = other.x;
		this->y = other.y;
		this->z = other.z;
		return*this;
	}

	//���������� ��������� +
	Point operator+(const Point & other)
	{
		Point tmp;
		tmp.x = this->x + other.x;
		tmp.y = this->y + other.y;
		tmp.z = this->z + other.z;
		return tmp;
	}

	//���������� ��������� +=
	Point& operator+=(const Point & other)
	{
		this->x = this->x + other.x;
		this->y = this->y + other.y;
		this->z = this->z + other.z;
		return *this;
	}

	//���������� ��������� ++ (�������)
	Point  operator++()
	{
		this->x++;
		this->y++;
		this->z++;
		return*this;
	}

	//���������� ��������� ++ (��������)
	Point operator++(int value)
	{
		Point tmp(*this);
		this->x++;
		this->y++;
		this->z++;
		return tmp;
	}
	
	//���������� ��������� <<
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
	//����������� ��� ���������� 
	Matrix() 
	{
		arr = nullptr;
	}

	//����������� � �����������
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

	//����������� �����������
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

	

	//���������� ������� int
	void filling_arr_int()
	{
		for (int i = 0; i <line; i++) {
			for (int j = 0; j < column; j++) {
				 arr[i][j] =i*(line-1) + j;
			}
		
		}
	}

	//���������� ������� char
	void filling_arr_char()
	{
		
		for (int i = 0; i < line; i++) {
			for (int j = 0; j < column; j++) {
				std::cin>>arr[i][j];
			}

		}
	}

	//�������� ��������� <<
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

	//����������
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