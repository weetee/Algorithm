#ifndef SINGLE_LIST_H
#define SINGLE_LIST_H

/*
** 带头节点的单链表实现
** 头节点中的数据域保存链表的长度
*/

typedef struct ListNode {
	int m_data;
	struct ListNode *m_next;
	ListNode(int data = 0, struct ListNode *next = NULL) :
		m_data(data), m_next(next) { }
} ListNode;

class SingleList {
public:
	SingleList();
	~SingleList();

	size_t GetSize() const;
	int FindValuePos(int data) const;
	void Print() const;
	void Insert(size_t pos, int data);
	void Remove(size_t pos);

private:
	ListNode *m_head;
};

#endif // SINGLE_LIST_H