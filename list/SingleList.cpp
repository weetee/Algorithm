#include "SingleList.h"
#include <iostream>

using namespace std;

SingleList::SingleList()
{
	m_head = new ListNode();
}

SingleList::~SingleList()
{
	ListNode *tmp;
	while (m_head) {
		tmp = m_head;
		m_head = m_head->m_next;
		delete tmp;
	}
}

size_t SingleList::GetSize() const
{
	return m_head->m_data;
}

int SingleList::FindValuePos(int data) const
{
	ListNode *tmp = m_head->m_next;  // 排除头节点
	int pos = 1; 	// 头节点位置为0，所以元素位置从1开始
	while (tmp) {
		if (tmp->m_data == data)
			return pos;
		tmp = tmp->m_next;
		++pos;
	}
	return -1;  // 未找到返回-1
}

void SingleList::Print() const
{
	ListNode *tmp = m_head->m_next;
	while (tmp) {
		cout << tmp->m_data << " ";
		tmp = tmp->m_next;
	}
}

// 在某个位置之后插入
void SingleList::Insert(size_t pos, int data)
{
	if (pos > m_head->m_data)
	{
		cout << "The insert pos:" << pos << " out of List size!" << endl;
		return;
	}
	
	ListNode *tmp = m_head;
	size_t idx = 0;
	while (tmp->m_next && idx < pos) {
		tmp = tmp->m_next;
		++idx;
	}

	ListNode *new_node = new ListNode(data);
	new_node->m_next = tmp->m_next;
	tmp->m_next = new_node;
	m_head->m_data++;
}

// 移除某个位置的元素
void SingleList::Remove(size_t pos)
{
	// 头节点和超过list长度的节点无法移除
	if (pos == 0 || pos > m_head->m_data) {
		cout << "Remove List pos:" << pos << " error!" << endl;
		return;
	}

	ListNode *prev = m_head;
	ListNode *curr = m_head->m_next;
	size_t idx = 1;
	while (curr && pos < idx) {
		prev = curr;
		curr = curr->m_next;
		++idx;
	}
	if (!curr) {    // 这种情况不应该出现
		cout << "Remove List not find pos:" << pos << endl;
		return;
	}
	prev->m_next = curr->m_next;
	delete curr;
}

void SingleList::Reverse()
{
	ListNode *curr = m_head->m_next;
	if (!curr || !curr->m_next)
		return;  // 空链表和只有一个节点的链表，不需要反转

	ListNode *prev = NULL, *next = curr->m_next;
	while (next) {
		curr->m_next = prev;
		prev = curr;
		curr = next;
		next = next->m_next;
		curr->m_next = prev;
	}

	m_head->m_next = curr;
}