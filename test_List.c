#include "header_only.h"

void test_push()
{
	List list = { };
	assert(find_List(&list, "a") == NULL);
	push_front_List(&list, "a", "");
	assert(find_List(&list, "") == NULL);
	assert(find_List(&list, "a") != NULL);
	push_front_List(&list, "b", "");
	assert(find_List(&list, "a") != NULL);
}

void test_clear()
{
	List list = { };
	clear_List(&list);
	assert(find_List(&list, "a") == NULL);
	push_front_List(&list, "a", "");
	push_front_List(&list, "a", "");
	push_front_List(&list, "a", "");
	clear_List(&list);
	assert(find_List(&list, "a") == NULL);
}

void test_erase()
{
	List list = { };
	push_front_List(&list, "a", "");
	push_front_List(&list, "a", "");
	push_front_List(&list, "a", "");
	erase_List(&list, "a");
	assert(find_List(&list, "a") != NULL);
	erase_List(&list, "b");
	assert(find_List(&list, "b") == NULL);
	erase_List(&list, "a");
	erase_List(&list, "a");
	assert(find_List(&list, "a") == NULL);
}
