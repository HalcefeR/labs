#include <iostream>
#include <initializer_list>
#include <cmath>


using namespace std;


template<typename EL_TYPE>
class CVector {
protected:
	int m_size;
	EL_TYPE* m_pdata;
public:
	~CVector() {
		if (m_pdata) {
			delete[] m_pdata;
		}
	}
	CVector(const int size = 0, const EL_TYPE* pdata = nullptr);
	CVector(const CVector<EL_TYPE>& rv);
	int copy(const int size, const EL_TYPE* pdata);
	void copy(const CVector<EL_TYPE>& rv);
	void print_data();
	template<typename F_EL_TYPE>
		friend F_EL_TYPE scalar_product(const CVector<F_EL_TYPE>& first_vector, const CVector<F_EL_TYPE>& second_vector);
	EL_TYPE length_of_vector();
	template<typename F_EL_TYPE>
		friend CVector<F_EL_TYPE> sum(const CVector<F_EL_TYPE>& first_vector, const CVector<F_EL_TYPE>& second_vector);
	template<typename F_EL_TYPE>
		friend CVector<F_EL_TYPE> difference(const CVector<F_EL_TYPE>& first_vector, const CVector<F_EL_TYPE>& second_vector);
	void add(const CVector<EL_TYPE>& other_vector);
	void subtract(const CVector<EL_TYPE>& other_vector);
	CVector<EL_TYPE>& operator=(const CVector& rv);
	EL_TYPE& operator[](int index);
	const EL_TYPE operator[](int index) const;
	template<typename F_EL_TYPE>
		friend F_EL_TYPE operator*(const CVector<F_EL_TYPE>& first_vector, const CVector<F_EL_TYPE>& second_vector);
	template<typename F_EL_TYPE>
		friend CVector<F_EL_TYPE> operator+(const CVector<F_EL_TYPE>& first_vector, const CVector<F_EL_TYPE>& second_vector);
	template<typename F_EL_TYPE>
		friend CVector<F_EL_TYPE> operator-(const CVector<F_EL_TYPE>& first_vector, const CVector<F_EL_TYPE>& second_vector);
	CVector<EL_TYPE>& operator+=(const CVector<EL_TYPE>& rv);
	CVector<EL_TYPE>& operator-=(const CVector<EL_TYPE>& rv);
	double operator()();
	virtual void v_print_data();
	void move(CVector &rv);
	CVector(CVector &&rv);
	CVector<EL_TYPE>& operator=(CVector&& rv);



public:
	class iterator {
		friend class CVector;
	protected:
		EL_TYPE* m_pItem;
	public:
		iterator() {
			m_pItem = nullptr;
		}
		iterator( const iterator&it ) {
			m_pItem = it.m_pItem;
		}
	protected:
		iterator(EL_TYPE* p) {
			m_pItem = p;
		};
	public:
		EL_TYPE& operator*() {
			return *m_pItem;
		}
		iterator&operator++() {
			m_pItem = m_pItem + 1;
			return *this;
		}
		iterator operator++(int) {
			iterator it( *this );
			m_pItem = m_pItem + 1;
			return it;
		}
		iterator&operator=( const iterator&it ) {
			m_pItem = it.m_pItem;
			return *this;
		}
		bool operator==(const iterator&it) {
			return (m_pItem==it.m_pItem?true:false);
		}
		bool operator!=( const iterator&it ) {
			return (m_pItem!=it.m_pItem?true:false);
		}
	};
public:
	iterator begin();
	iterator end();
	CVector( std::initializer_list<EL_TYPE> init_list );
};



template<typename EL_TYPE>
typename CVector<EL_TYPE>::iterator CVector<EL_TYPE>::begin()
{
	return iterator(&m_pdata[0]);
}



template<typename EL_TYPE>
typename CVector<EL_TYPE>::iterator CVector<EL_TYPE>::end()
{
	return iterator(&m_pdata[0] + m_size);
}



template <typename EL_TYPE>
struct CVector2 : public CVector<EL_TYPE> {
	CVector2(const int m_size = 0, const double* pdata = nullptr) : CVector<EL_TYPE>(m_size, pdata) {};
	CVector2(const CVector<EL_TYPE>& rv) : CVector<EL_TYPE>(rv) {};
	void print_data();
};



template <typename EL_TYPE>
struct CVector3 : public CVector<EL_TYPE> {
	CVector3(const int m_size = 0, const double* pdata = nullptr) : CVector<EL_TYPE>(m_size, pdata) {};
	CVector3(const CVector<EL_TYPE>& rv) : CVector<EL_TYPE>(rv) {};
	void v_print_data();
};



template<typename EL_TYPE>
CVector<EL_TYPE>::CVector(const int size, const EL_TYPE* pdata) {
	m_size = 0;
	m_pdata = nullptr;
	copy(size, pdata);
}



template<typename EL_TYPE>
CVector<EL_TYPE>::CVector(const CVector& rv) {
	m_size = 0;
	m_pdata = nullptr;
	copy(rv);
}



template<typename EL_TYPE>
int CVector<EL_TYPE>::copy(const int size, const EL_TYPE* pdata) {
	if (m_pdata == pdata) return m_size;
	if ((!size && pdata) || (size && !pdata)) return -1;
	EL_TYPE* p = nullptr;
	if (size) {
		p = new EL_TYPE[size];
		if (!p) return -1;
		for (int i = 0; i < size; i++)
			p[i] = pdata[i];
	}
	if (m_pdata)
		delete[] m_pdata;
	m_size = size;
	m_pdata = p;
	return m_size;
}



template<typename EL_TYPE>
CVector<EL_TYPE>::CVector( std::initializer_list<EL_TYPE> init_list ) {
	m_size = init_list.size();
	m_pdata = new EL_TYPE[m_size];
	int counter = 0;
	for (auto el: init_list) {
		m_pdata[counter] = el;
		counter++;
	}
}



template<typename EL_TYPE>
void CVector<EL_TYPE>::copy(const CVector<EL_TYPE>& rv) {
	copy(rv.m_size, rv.m_pdata);
}



template<typename EL_TYPE>
void CVector<EL_TYPE>::print_data() {
	cout << "Num: " << m_size << " ";
	cout << "Data: ";

	for (int i = 0; i < m_size; i++) {
		cout << m_pdata[i] << " ";
	}

	cout << endl;
}



template<typename F_EL_TYPE>
F_EL_TYPE scalar_product(const CVector<F_EL_TYPE>& first_vector, const CVector<F_EL_TYPE>& second_vector) {
	F_EL_TYPE sum = 0;
	int min_size;
	first_vector.m_size < second_vector.m_size ? min_size = first_vector.m_size : min_size = second_vector.m_size;
	for (int i = 0; i < min_size; i++){
		sum += first_vector.m_pdata[i] * second_vector.m_pdata[i];
	}
	return sum;
}



template<typename EL_TYPE>
EL_TYPE CVector<EL_TYPE>::length_of_vector() {
	return sqrt(scalar_product(*this, *this));
}



template<typename EL_TYPE>
CVector<EL_TYPE> sum(const CVector<EL_TYPE>& first_vector, const CVector<EL_TYPE>& second_vector) {
	CVector<EL_TYPE> temp_vector;
	if (first_vector.m_size < second_vector.m_size) {
		temp_vector.copy(second_vector);
		for (int i = 0; i < first_vector.m_size; i++) {
			temp_vector.m_pdata[i] += first_vector.m_pdata[i];
		}
	} else {
		temp_vector.copy(first_vector);
		for (int i = 0; i < second_vector.m_size; i++) {
			temp_vector.m_pdata[i] += second_vector.m_pdata[i];
		}
	}
	
	return temp_vector;
}



template<typename EL_TYPE>
CVector<EL_TYPE> difference(const CVector<EL_TYPE>& first_vector, const CVector<EL_TYPE>& second_vector) {
	CVector<EL_TYPE> temp_vector;
	if (first_vector.m_size < second_vector.m_size) {
		temp_vector.copy(second_vector);
		for (int i = 0; i < first_vector.m_size; i++) {
			temp_vector.m_pdata[i] += first_vector.m_pdata[i];
		}
		for (int i = 0; i < second_vector.m_size; i++) {
			temp_vector.m_pdata[i] -= second_vector.m_pdata[i] * 2;
		}
	} else {
		temp_vector.copy(first_vector);
		for (int i = 0; i < second_vector.m_size; i++) {
			temp_vector.m_pdata[i] -= second_vector.m_pdata[i];
		}
	}

	return temp_vector;
}




template<typename EL_TYPE>
void CVector<EL_TYPE>::add(const CVector<EL_TYPE>& other_vector) {
	copy(sum(*this, other_vector));
}



template<typename EL_TYPE>
void CVector<EL_TYPE>::subtract(const CVector<EL_TYPE>& other_vector) {
	copy(difference(*this, other_vector));
}



template<typename EL_TYPE>
CVector<EL_TYPE>& CVector<EL_TYPE>::operator=(const CVector<EL_TYPE>& rv) {
	copy(rv);
	return *this;
}



template<typename EL_TYPE>
EL_TYPE& CVector<EL_TYPE>::operator[](int index) {
	return m_pdata[index];
}



template<typename EL_TYPE>
const EL_TYPE CVector<EL_TYPE>::operator[](int index) const {
	return m_pdata[index];
}



template<typename F_EL_TYPE>
F_EL_TYPE operator*(const CVector<F_EL_TYPE>& first_vector, const CVector<F_EL_TYPE>& second_vector) {
	return scalar_product(first_vector, second_vector);
}



template<typename EL_TYPE>
CVector<EL_TYPE> operator+(const CVector<EL_TYPE>& first_vector, const CVector<EL_TYPE>& second_vector) {
	return sum(first_vector, second_vector);
}



template<typename EL_TYPE>
CVector<EL_TYPE> operator-(const CVector<EL_TYPE>& first_vector, const CVector<EL_TYPE>& second_vector) {
	return difference(first_vector, second_vector);
}



template<typename EL_TYPE>
double CVector<EL_TYPE>::operator()() {
	return length_of_vector();
}



template<typename EL_TYPE>
CVector<EL_TYPE>& CVector<EL_TYPE>::operator+=(const CVector<EL_TYPE>& rv) {
	this->add(rv);
	return *this;
}



template<typename EL_TYPE>
CVector<EL_TYPE>& CVector<EL_TYPE>::operator-=(const CVector<EL_TYPE>& rv) {
	this->subtract(rv);
	return *this;
}



template<typename EL_TYPE>
void CVector<EL_TYPE>::v_print_data() {
	print_data();
}



template<typename EL_TYPE>
void CVector2<EL_TYPE>::print_data() {

	cout << "Num: " << this->m_size << endl;

	for (int i = 0; i < this->m_size; i++)
		cout << i << ": " << this->m_pdata[i] << endl;
}



template<typename EL_TYPE>
void CVector3<EL_TYPE>::v_print_data() {

	cout << "Num: " << this->m_size << endl;

	for (int i = 0; i < this->m_size; i++)
		cout << i << ": " << this->m_pdata[i] << endl;
}



template<typename EL_TYPE>
void CVector<EL_TYPE>::move(CVector<EL_TYPE> &rv) {
	if (m_pdata == rv.m_pdata)
		return;
	delete[] m_pdata;
	m_pdata = rv.m_pdata;
	m_size = rv.m_size;
	rv.m_size = 0;
	rv.m_pdata = nullptr;
}



template<typename EL_TYPE>
CVector<EL_TYPE>::CVector(CVector<EL_TYPE> &&rv) {
	move(rv);
}



template<typename EL_TYPE>
CVector<EL_TYPE>& CVector<EL_TYPE>::operator=(CVector<EL_TYPE>&& rv) {
	move(rv);
	return *this;
}