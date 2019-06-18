#program once

class Array {
public:
	explicit Array(size_t cap = 1) : m_size(0), m_capacity(cap) {
		if (m_capacity == 0)
			m_capacity = 1;
		m_data = new int[m_capacity];
	}
	~Array()
	{
		delete [] m_data;
	}

	void Insert(size_t pos, int value);
	void Delete(size_t pos);
	size_t FindValue(int value) const;

private:
	size_t m_size;  // 数组已用大小
	size_t m_capacity;  // 数组最大容量
	int *m_data;  // 数据
};
