#include "Array.h"
#include <iostream>
#include <stdexcept>

using namespace std;

// 只能在尾部插入
void Array::Insert(size_t pos, int value)
{
	if (pos > m_size) {
		throw out_of_range("Array Insert out of range");
	}
	m_data[pos] = value;
	++m_size;
}

void Array::Delete(size_t pos)
{
	if (pos > m_size) {
		throw out_of_range("Array Delete out of range");
	}
	for (size_t idx = pos; idx < m_size - 1; ++idx) {
		m_data[idx] = m_data[idx + 1];
	}
	--m_size;
}

// 返回-1表示未找到值
int Array::FindValue(int value) const
{
	int idx = -1;
	for (size_t i = 0; i < m_size; ++i) {
		if (value == m_data[i]) {
			idx = i;
			break;
		}
	}

	return idx;
}


// 获取位置pos的值
int Array::GetPosValue(size_t pos) const
{
	if (pos > m_size)
		throw out_of_range("Array GetPosValue out of range");
	return m_data[pos];
}